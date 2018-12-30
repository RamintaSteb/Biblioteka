#pragma once
#ifndef OBJECTS_H_
#define OBJECTS_H_
#include <iostream>
#include <Windows.h>

class Objects
{
public:
	Objects();

	~Objects();
};

class Indikatorius {
private:
	HWND console = GetConsoleWindow();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
public:	
	void Set_Console();
	void MouseClick(bool &i, int &horizontal, int &vertical);
	void Colors(int txtColor, int backgroundColor);
	void Coordinates(int xPos, int yPos);
	void Write(int txtColor, int backgroundColor, int xPos, int yPos, int size, std::string info);
};

class Langas : public Indikatorius {
public:
	void Drawing(int backgroundColor, int frameColor, int xPos, int yPos, int xSize, int ySize, int tipas);
};

class Txt_Langas : public Langas {
private:
	void WriteWindow(int txtColor, int backgroundColor, int xPos, int yPos, int xSize, int ySize, std::string info);
public:
	void Show(int backgroundColor, int frameColor, int txtColor, int xPos, int yPos, int xSize, int ySize, int tipas, std::string info);
};

class Mygtukas : public Txt_Langas{
private:
	int Button[214][54];
	void Map(int number, int xPos, int yPos, int xSize, int ySize);
public:
	void nulinimas();
	void CreateMeniu(int number, int backgroundColor, int frameColor, int txtColor, int xPos, int yPos, int xSize, int ySize, int tipas, std::string info);
	void showMap();
	void chosen(int &choice, int xPos, int yPos);
};
#endif
