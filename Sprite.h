#pragma once
#include <string>
#include <vector>
class Sprite
{
private:
	std::vector<std::wstring> data;

public:
	Sprite(std::string ressourcePath);
	std::wstring const& operator[](int key) const;
	int size() const;
};

