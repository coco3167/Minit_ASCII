#include "Sprite.h"
#include <fstream>
#include <iostream>
#include <codecvt>
#include <locale>

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
    while (std::getline(file, line))
        data.push_back(line);

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
