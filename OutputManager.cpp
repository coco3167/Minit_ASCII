#include "OutputManager.h"


void OutputManager::clearBuffer()
{
    for (int i = 0; i < WIDTH*HEIGHT; ++i)
    {
        buffer.getScreenBuffer()[i].Char.AsciiChar = '0';  // Empty space
        buffer.getScreenBuffer()[i].Attributes = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;  // White color
    }
}

void OutputManager::drawBuffer()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    // Blit buffer to the console
    WriteConsoleOutput(hConsole, buffer.getRawData(), buffer.getSize(), buffer.getCoord(), buffer.getWriteRegion());
}

void OutputManager::maximizeConsoleWindow()
{
    HWND hWnd = GetConsoleWindow();  // Get console window
    if (hWnd != NULL)
        ShowWindow(hWnd, SW_MAXIMIZE);  // Maximise the window
}

void OutputManager::setFixedConsoleSize(int width, int height)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // 1. Adjust buffer size
    COORD bufferSize;
    bufferSize.X = width;
    bufferSize.Y = height;
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    // 2. Adjust window size
    SMALL_RECT windowSize;
    windowSize.Left = 0;
    windowSize.Top = 0;
    windowSize.Right = width - 1;
    windowSize.Bottom = height - 1;
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);

    // 3. Disable window manual resizing
    HWND hwndConsole = GetConsoleWindow();
    LONG style = GetWindowLong(hwndConsole, GWL_STYLE);
    style &= ~WS_SIZEBOX;  // D�sactiver le redimensionnement
    style &= ~WS_MAXIMIZEBOX;  // D�sactiver le bouton maximiser
    SetWindowLong(hwndConsole, GWL_STYLE, style);

    // 4. Calculate window position to center in screen
    RECT rect;
    GetWindowRect(hwndConsole, &rect);

    // Obtain screen resolution
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    // Pixel size based on character size
    int consoleWidthInPixels = (width + 1) * 7;
    int consoleHeightInPixels = (height) * 17;

    // New window pos
    int posX = (screenWidth - consoleWidthInPixels) / 2;
    int posY = (screenHeight - consoleHeightInPixels) / 2;

    // 5. Move window to it's new pos
    MoveWindow(hwndConsole, posX, posY, consoleWidthInPixels, consoleHeightInPixels, TRUE);
}