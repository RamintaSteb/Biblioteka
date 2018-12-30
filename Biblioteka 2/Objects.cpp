#include "stdafx.h"
#include "Objects.h"
#include <string>


Objects::Objects()
{
}
Objects::~Objects()
{
}

void Indikatorius::Set_Console()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	RECT r;
	GetWindowRect(console, &r);
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
}

void Indikatorius::MouseClick(bool &i, int &horizontal, int &vertical)
{
	bool leftMouseDown = GetKeyState(VK_LBUTTON) & 0x8000;

	if (leftMouseDown) {
		POINT cursorPos;
		GetCursorPos(&cursorPos);
		Sleep(200);
		horizontal = cursorPos.x/7.18;
		vertical = cursorPos.y/16;
		i = true;
	}
}



void Indikatorius::Colors(int txtColor, int backgroundColor)
{
	//Fono ir teksto spalvos
	SetConsoleTextAttribute(hConsole, backgroundColor * 16 + txtColor);
}

void Indikatorius::Coordinates(int xPos, int yPos)
{
	//Nusikelia i kordinates
	COORD pos = { (short)xPos, (short)yPos };
	SetConsoleCursorPosition(hConsole, pos);
}

void Indikatorius::Write(int txtColor, int backgroundColor, int xPos, int yPos, int size, std::string info) {

	Colors(txtColor, backgroundColor);
	Coordinates(xPos, yPos);
	//Isveda teksta
	std::cout << info;
	//Grazina spalvas tekstui ir fonui
	Colors(7, 0);
}

void Langas::Drawing(int backgroundColor, int frameColor, int xPos, int yPos, int xSize, int ySize, int tipas) {
	char A[3][6] = { 218, 196, 191, 179, 217, 192, 201, 205, 187, 186, 188, 200, ' ', ' ' , ' ' , ' ' , ' ' , ' ' }; //Pasidaryt private?

	Colors(frameColor, backgroundColor);
	Coordinates(xPos, yPos);
	xSize = xSize - 2;
	ySize = ySize - 1;
	//-------------------------------------------------------------
	//virsutine eilute:
	std::cout << (char)A[tipas-1][0];
	for (int s = 0; s < xSize; s++)
	{
		std::cout << (char)A[tipas - 1][1];
	}
	std::cout << (char)A[tipas - 1][2] << std::endl;
	//sonai:
	for (int s = 0; s < ySize; s++)
	{
		Coordinates(xPos, yPos + s + 1);
		std::cout << (char)A[tipas - 1][3];
		for (int k = 0; k < xSize; k++)
			std::cout << " ";
		std::cout << (char)A[tipas - 1][3];
	}
	//Apacia:
	Coordinates(xPos, yPos + ySize);

	std::cout << (char)A[tipas - 1][5];
	for (int s = 0; s < xSize; s++)
	{
		std::cout << (char)A[tipas - 1][1];
	}
	std::cout << (char)A[tipas - 1][4] << std::endl;
	//-------------------------------------------------------------
	//Grazina konsoles spalva:
	Colors(7, 0);
}

void Txt_Langas::Show(int backgroundColor, int frameColor, int txtColor, int xPos, int yPos, int xSize, int ySize, int tipas, std::string info) {
	Drawing(backgroundColor, frameColor, xPos, yPos, xSize, ySize, tipas);
	WriteWindow(txtColor, backgroundColor, xPos + 1, yPos + 1, xSize - 1, ySize - 1, info);
}

void Txt_Langas::WriteWindow(int txtColor, int backgroundColor, int xPos, int yPos, int xSize, int ySize, std::string info) {
	Colors(txtColor, backgroundColor);
	for (int i = 0; i < ySize-1; i++)
	{
		Coordinates(xPos, yPos+i);
		for (int j = 0; j < xSize-1; j++)
		{
			if ((xSize*i -i+ j) <= info.length())
			std::cout << info[xSize*i-i + j];
		}
	}
	Coordinates(xPos, yPos+ySize+1); 
	Colors(7, 0);
}

void Mygtukas::nulinimas() {
	for (int i = 0; i < 214; i++)
	{
		for (int j = 0; j < 54; j++)
		{
			Button[i][j] = 0;
		}
	}
};
void Mygtukas::Map(int number, int xPos, int yPos, int xSize, int ySize) {
	for (int i = yPos; i < yPos + ySize; i++)
	{
		for (int j = xPos; j < xPos + xSize; j++)
		{
			Button[j][i] = number;
		}
	}
}

void Mygtukas::CreateMeniu(int number, int backgroundColor, int frameColor, int txtColor, int xPos, int yPos, int xSize, int ySize, int tipas, std::string info) {
	Show(backgroundColor, frameColor, txtColor, xPos, yPos, xSize, ySize, tipas, info);
	Map(number, xPos, yPos, xSize, ySize);
	
	
}
void Mygtukas::showMap() {
	for (int i = 0; i < 54; i++)
	{
		for (int j = 0; j < 214; j++)
		{
			std::cout << Button[j][i];
		}
		std::cout << std::endl;
	}
}

void Mygtukas::chosen(int &choice, int xPos, int yPos)
{
	if (Button[xPos][yPos]>0) choice = Button[xPos][yPos];
	else choice = 0;
}

