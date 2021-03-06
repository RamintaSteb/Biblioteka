/*
Programos veikimas paremtas peles paspaudimais todel svarbu konsoles nustatymuose panaikinti konsoles darbo sustabdyma kai paspaudziamas kairys peles mygtukas.
Taip pat norint, kad veiktu langu piesimas teisingose vietose reikia isitikinti, kad atitinka skaiciai is kuriu dalinama po peles paspaudimo gautu pikseliu skaicius. Objects.cpp faile MouseClick funkcija.
Desinio apatinio kampo koordinates padalint reikia is simboliu kiekio telpancio isdidintoje konsoleje vertikaliai ir horizontaliai. 
Kuriant programa naudotas 16x8 konsoles srifto dydis, 1920x1080 rezoliucija, 125% teksto dydis.

Bibliotekoje sukeltos funkcijos, kurias kvieciant su tam tikrais parametrais atliekamos uzduotys. 
Main funkcija skirta vaizdiniam apipavidalinimui.
*/
#include "stdafx.h"
#include "Objects.h"
#include <iostream>
#include <string>
struct POS {
	int x;
	int y;
};
int main()
{
	Indikatorius indi;
	Langas window;
	Txt_Langas txt;
	Mygtukas Meniu;
	int choice, kiek;
	int txtColor, backgroundColor, size;
	int frameColor, tipas;
	POS place, Size;
	std::string info;
	bool i = false;

	//---------------------------------------------------------------------
	std::string A[4] = { "  Indikatorius", "     Langas", "  Teksto Langas", "      Meniu" };
	Mygtukas MainMeniu;
	MainMeniu.nulinimas();
	MainMeniu.Set_Console();
	place.y = 16;
	for (int j = 0; j < 4; j++)
	{
		MainMeniu.CreateMeniu(j + 1, 0, 7, 7, 96, place.y, 18, 3, 2, A[j]);
		place.y = place.y + 4;
	}

	MainMeniu.Drawing(7, 7, 34, 45, 140, 5, 3);
	MainMeniu.Write(0, 7, 95, 47, 19, "Pasirinkite veiksma");
	//Pasirenkamas punktas
	while (!i)
	{
		MainMeniu.MouseClick(i, place.x, place.y);
		if (i) {
			MainMeniu.chosen(choice, place.x, place.y);
			if (choice == 0) i = false;
		}
	}
	i = false;
	//MainMeniu.Write(0, 7, 95, 47, 19, "                   ");
	system("CLS");


	MainMeniu.nulinimas();
	//Kiek meniu punktu kurs
	if (choice == 4) {
		MainMeniu.Drawing(7, 7, 34, 45, 140, 5, 3);
		MainMeniu.Write(0, 7, 40, 46, 45, "Iveskite kiek noresite sukurti meniu elementu:");
		std::cin >> kiek;
	}
	else kiek = 1;

	for (int kelintas = 0; kelintas < kiek; kelintas++) {
		MainMeniu.nulinimas();
		MainMeniu.Drawing(7, 7, 34, 45, 140, 5, 3);
		//Renkasi spalvas
		//------------------------------------------
		//Teksto
		if (choice != 2) {
			place.x = 40;
			MainMeniu.Write(0, 7, 40, 46, 30, "Pasirinkite teksto spalva:    ");
			for (int j = 0; j < 16; j++)
			{
				MainMeniu.CreateMeniu(j + 1, j, 7, 0, place.x, 48, 8, 1, 3, "     ");
				place.x = place.x + 8;
			}
			while (!i)
			{
				MainMeniu.MouseClick(i, place.x, place.y);
				if (i) {
					MainMeniu.chosen(txtColor, place.x, place.y);
					if (txtColor == 0) i = false;
					else txtColor--;
				}
			}
			i = false;
		}

		//Fono
		place.x = 40;
		MainMeniu.Write(0, 7, 40, 46, 30, "Pasirinkite fono spalva:      ");
		for (int j = 0; j < 16; j++)
		{
			MainMeniu.CreateMeniu(j + 1, j, 7, 0, place.x, 48, 8, 1, 3, "     ");
			place.x = place.x + 8;
		}
		while (!i)
		{
			MainMeniu.MouseClick(i, place.x, place.y);
			if (i) {
				MainMeniu.chosen(backgroundColor, place.x, place.y);
				if (backgroundColor == 0) i = false;
				else backgroundColor--;
			}
		}
		i = false;
		//Remelio
		if (choice != 1) {
			place.x = 40;
			MainMeniu.Write(0, 7, 40, 46, 30, "Pasirinkite remelio spalva:   ");
			for (int j = 0; j < 16; j++)
			{
				MainMeniu.CreateMeniu(j + 1, j, 7, 0, place.x, 48, 8, 1, 3, "     ");
				place.x = place.x + 8;
			}
			while (!i)
			{
				MainMeniu.MouseClick(i, place.x, place.y);
				if (i) {
					MainMeniu.chosen(frameColor, place.x, place.y);
					if (frameColor == 0) i = false;
					else frameColor--;
				}
			}
			i = false;
		}
		MainMeniu.nulinimas();
		//---------------------------------------------------------------------
		//Remelio tipas
		if (choice != 1) {
			MainMeniu.Drawing(7, 7, 34, 45, 140, 5, 3);
			MainMeniu.Write(0, 7, 40, 47, 30, "Pasirinkite remelio tipa:     ");
			MainMeniu.CreateMeniu(1, 0, 7, 7, 70, 46, 6, 3, 1, " ");
			MainMeniu.CreateMeniu(2, 0, 7, 7, 80, 46, 6, 3, 2, " ");
			MainMeniu.CreateMeniu(3, 0, 7, 7, 90, 46, 6, 3, 3, " ");
			while (!i)
			{
				MainMeniu.MouseClick(i, place.x, place.y);
				if (i) {
					MainMeniu.chosen(tipas, place.x, place.y);
					if (tipas == 0) i = false;
				}
			}
			i = false;
		}
		MainMeniu.nulinimas();
		//---------------------------------------------------------------------
		//Pradines koordinates
		MainMeniu.Drawing(7, 7, 34, 45, 140, 5, 3);
		MainMeniu.Write(0, 7, 70, 47, 68, "Pazymekite juodam ekrane kur norite, kad prasidetu langas/eilute");
		while (!i)
		{
			MainMeniu.MouseClick(i, place.x, place.y);
		}
		i = false;
		//Dydis
		int x, y;
		if (choice != 1) {
			MainMeniu.Drawing(7, 7, 39, 45, 140, 5, 3);
			MainMeniu.Write(0, 7, 70, 47, 62, "Pazymekite juodam ekrane kur norite, kad pasibaigtu langas");
			while (!i)
			{
				MainMeniu.MouseClick(i, x, y);
			}
			i = false;
			Size.x = x - place.x+1;
			Size.y = y - place.y+1;
		}
		//---------------------------------------------------------------------
		//Tekstas
		if (choice != 2) {
			MainMeniu.Drawing(7, 7, 34, 45, 140, 5, 3);
			MainMeniu.Write(0, 7, 93, 46, 22, "Iveskite norima teksta:");
			if (choice == 4 && kelintas == 0) std::cin.ignore();
			std::getline(std::cin, info);

		}

		if (choice == 1) indi.Write(txtColor, backgroundColor, place.x, place.y, info.length(), info);
		else if (choice == 2) window.Drawing(backgroundColor, frameColor, place.x, place.y, Size.x, Size.y, tipas);
		else if (choice == 3) txt.Show(backgroundColor, frameColor, txtColor, place.x, place.y, Size.x, Size.y, tipas, info);
		else if (choice == 4) Meniu.CreateMeniu(kelintas+1, backgroundColor, frameColor, txtColor, place.x, place.y, Size.x, Size.y, tipas, info);
	}
	if (choice == 4)
	{
		
		MainMeniu.Drawing(7, 7, 34, 45, 140, 5, 3);
		MainMeniu.Write(0, 7, 92, 46, 30, "Pasirinkite meniu punkta");
		
		while (!i)
		{
			Meniu.MouseClick(i, place.x, place.y);
			if (i) {
				Meniu.chosen(choice, place.x, place.y);
				if (choice == 0) i = false;
			}
		}
		i = false;
		MainMeniu.Drawing(7, 7, 34, 45, 140, 5, 3);
		MainMeniu.Write(0, 7, 92, 47, 30, "Pasirinkote meniu punkta: ");
		std::cout << choice;
	}
	MainMeniu.Coordinates(0,53);
	system("Pause");
	

    return 0;
}

