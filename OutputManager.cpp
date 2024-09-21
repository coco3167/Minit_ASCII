#include "OutputManager.h"
#include <iostream>

OutputManager::OutputManager(Player& player, int const fontSize) : player{ player }
{
    setConsoleStyle();
    maximizeConsoleWindow(fontSize);
    buffer = Buffer();
}

void OutputManager::clearBuffer()
{
    for (int i = 0; i < size.Y; ++i)
    {
        for (int j = 0; j < size.X; j++)
        {
          buffer.getScreenBuffer()[i*size.X + j].Char.UnicodeChar = 0x2588;  // Empty space
          buffer.getScreenBuffer()[i*size.X + j].Attributes = 0;  // black color
        }
        
    }
}

void OutputManager::drawBuffer()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    // Blit buffer to the console
    WriteConsoleOutput(hConsole, buffer.getRawData(), buffer.getSize(), buffer.getCoord(), buffer.getWriteRegion());
}

void OutputManager::maximizeConsoleWindow(int const fontSize)
{
    HWND hWnd = GetConsoleWindow();  // Get console window
    if (hWnd != nullptr)
        ShowWindow(hWnd, SW_MAXIMIZE);  // Maximise the window

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    setFont(fontSize);

    // Get console size
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    // Set Window size
    WinSize & winSize = WinSize::getInstance();
    size = {
        SHORT(csbi.srWindow.Right - csbi.srWindow.Left + 1),
        SHORT(csbi.srWindow.Bottom - csbi.srWindow.Top + 1)
    };
    winSize.setSize(size);
    
    // Set buffer to console size
    SetConsoleScreenBufferSize(hConsole, COORD{size.X, size.Y});

    // Disable window manual resizing
    HWND hwndConsole = GetConsoleWindow();
    LONG style = GetWindowLong(hwndConsole, GWL_STYLE);
    style &= ~WS_SIZEBOX;  // D�sactiver le redimensionnement
    style &= ~WS_MAXIMIZEBOX;  // D�sactiver le bouton maximiser
    SetWindowLong(hwndConsole, GWL_STYLE, style);
}

DWORD OutputManager::setFont(int const fontSize)
{
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = fontSize;                   // Width of each character in the font
    cfi.dwFontSize.Y = fontSize;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"Consolas"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    return cfi.nFont;
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

    COORD fontSize = GetConsoleFontSize(hConsole, setFont());

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
    int consoleWidthInPixels = (width)*fontSize.Y*1;
    int consoleHeightInPixels = (height)*fontSize.X*1;
    
    // New window pos
    int posX = (screenWidth - consoleWidthInPixels) / 2;
    int posY = (screenHeight - consoleHeightInPixels) / 2;

    // 5. Move window to its new pos
    MoveWindow(hwndConsole, posX, posY, consoleWidthInPixels, consoleHeightInPixels, TRUE);
}

void OutputManager::display(Entity const& entity)
{
    WinSize const& winSize(WinSize::getInstance());

    Sprite const& sprite{ entity.getSprite() };
    Vector2 entityPos{ entity.getPosition() };
    Vector2 playerPos{ player.getPosition() };
    Hitbox playerBox{ player.getHitbox() };
    Vector2 playerCenter{ playerPos.x + playerBox.w / 2, playerPos.y + playerBox.h / 2 };
    Vector2 pos{entityPos.x - playerCenter.x + winSize.getSize().X/2, entityPos.y - playerCenter.y + winSize.getSize().Y/2};
    for (int i = 0; i < sprite.size(); i++)
    {
        for (int j = 0; j < int(sprite[i].size()); j++)
        {
            if (pos.x + i >= 0 and pos.x + i < winSize.getSize().X and pos.y + j >= 0 and pos.y + j < winSize.getSize().Y)
            {
                CHAR_INFO& pixel = buffer.at(pos.x + i, pos.y + j);
                pixel.Char.UnicodeChar = sprite[i][j];
                pixel.Attributes = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
            }
        }
    }
}

void OutputManager::displayAll(std::unordered_set<Entity*> entities)
{
    for (auto it = entities.begin(); it != entities.end(); ++it)
    {
        WinSize const& winSize(WinSize::getInstance());
        
        Sprite const& sprite{ (*it)->getSprite() };
        Vector2 entityPos{ (*it)->getPosition() };
        Vector2 playerPos{ player.getPosition() };
        Hitbox playerBox{ player.getHitbox() };
        Vector2 playerCenter{ playerPos.x + playerBox.w / 2, playerPos.y + playerBox.h / 2 };
        Vector2 pos{entityPos.x - playerCenter.x + winSize.getSize().X/2, entityPos.y - playerCenter.y + winSize.getSize().Y/2};
        for (int i = 0; i < sprite.size(); i++)
        {
            for (int j = 0; j < int(sprite[i].size()); j++)
            {
                if (pos.x + i >= 0 and pos.x + i < winSize.getSize().X and pos.y + j >= 0 and pos.y + j < winSize.getSize().Y)
                {
                    CHAR_INFO& pixel = buffer.at(pos.x + i, pos.y + j);
                    pixel.Char.UnicodeChar = sprite[i][j];
                    pixel.Attributes = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
                }
            }
        }
    }
}
