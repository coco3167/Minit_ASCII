#pragma once
#include <string>
#include <vector>
class Sprite
{
public:
	Sprite(int w, int h);
	Sprite(std::string ressourcePath);
	std::wstring const& operator[](int key) const;
	int size() const;
	int getWidth() const;
	int getHeight() const;

private:
	std::vector<std::wstring> data;
};

