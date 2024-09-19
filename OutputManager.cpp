#include "OutputManager.h"


OutputManager::OutputManager(Player& player) : player{ player }
{
}

void OutputManager::clearBuffer()
{
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            buffer.getScreenBuffer()[i*WIDTH + j].Char.UnicodeChar = 0x2588;  // Full block
            buffer.getScreenBuffer()[i*WIDTH + j].Attributes = 0;  // black color
        }
        
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
    if (hWnd != nullptr)
        ShowWindow(hWnd, SW_MAXIMIZE);  // Maximise the window
}

void OutputManager::setConsoleStyle()
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void OutputManager::setFixedConsoleSize(SHORT width, SHORT height)
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
    windowSize.Right = static_cast<SHORT>(width - 1);
    windowSize.Bottom = static_cast<SHORT>(height - 1);
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);

    // 3. Disable window manual resizing
    HWND hwndConsole = GetConsoleWindow();
    LONG style = GetWindowLong(hwndConsole, GWL_STYLE);
    style &= ~WS_SIZEBOX;  // Disable redimensionning
    style &= ~WS_MAXIMIZEBOX;  // Disable maximize button
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

    // 5. Move window to its new pos
    MoveWindow(hwndConsole, posX, posY, consoleWidthInPixels, consoleHeightInPixels, TRUE);
}

void OutputManager::display(Entity const& entity)
{
    Sprite const& sprite{ entity.getSprite() };
    Vector2 entityPos{ entity.getPosition() };
    Vector2 playerPos{ player.getPosition() };
    Hitbox playerBox{ player.getHitbox() };
    Vector2 playerCenter{ playerPos.x + playerBox.w / 2, playerPos.y + playerBox.h / 2 };
    Vector2 pos{entityPos.x - playerCenter.x + WIDTH/2, entityPos.y - playerCenter.y + HEIGHT/2};
    for (int i = 0; i < sprite.size(); i++)
    {
        for (int j = 0; j < sprite[i].size(); j++)
        {
            if (pos.x + i >= 0 and pos.x + i < WIDTH and pos.y + j >= 0 and pos.y + j < HEIGHT)
            {
                CHAR_INFO& pixel = buffer.at(pos.x + i, pos.y + j);
                pixel.Char.UnicodeChar = sprite[i][j];
                pixel.Attributes = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
            }
        }
    }
}
