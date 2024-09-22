#include "Sprite.h"
#include <fstream>
#include <iostream>
#include <codecvt>
#include <locale>

Sprite::Sprite(int w, int h)
{
    for (int i = 0; i < w; i++)
    {
        data.emplace_back();
        for (int j = 0; j < h; j++)
        {
            data[i] += 0x2588;
        }
    }
}

Sprite::Sprite(std::string ressourcePath)
{
    std::wifstream file("assets/sprites/"+ressourcePath); // Open the file in wide mode
    file.imbue(std::locale(file.getloc(), new std::codecvt_utf8<wchar_t>)); // Define encoding on UTF-8

    if (!file.is_open())
    {
        std::cerr << "Erreur : impossible d'ouvrir le fichier " << ressourcePath << std::endl;
        return;
    }
    std::wstring line;
    std::vector<std::wstring> buffer;
    while (std::getline(file, line))
        buffer.push_back(line);

    for (int i = 0; i < buffer[0].size(); i++)
    {
        data.emplace_back();
        for (int j = 0; j < buffer.size(); j++)
        {
            data[i] += buffer[j][i];
        }
    }

    file.close();
}

std::wstring const& Sprite::operator[](int key) const
{
    return data[key];
}

int Sprite::size() const
{
    return data.size();
}

int Sprite::getWidth() const
{
    return size();
}

int Sprite::getHeight() const
{
    return data[0].size();
}
