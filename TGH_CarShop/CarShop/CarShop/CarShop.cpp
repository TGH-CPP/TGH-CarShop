// CarShop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Car.h"
#include "TukTuk.h"
#include "VroomVroom.h"
#include "Goodrich.h"
#include "Americus.h"
#include "BlingBling.h"
#include "BrassBrad.h"
#include "Wheelios.h"
#include "Rollos.h"
#include "SwiftRage.h"
#include "Vroomerino.h"

using namespace std;

void section_command(string Cmd, string &wd1, string &wd2)
{
	string sub_str;
	vector<string> words;
	char search = ' ';
	size_t i, j;

	// Split Command into vector
	for (i = 0; i < Cmd.size(); i++)
	{
		if (Cmd.at(i) != search)
		{
			sub_str.insert(sub_str.end(), Cmd.at(i));
		}
		if (i == Cmd.size() - 1)
		{
			words.push_back(sub_str);
			sub_str.clear();
		}
		if (Cmd.at(i) == search)
		{
			words.push_back(sub_str);
			sub_str.clear();
		}
	}
	// Clear out blanks
	for (i = words.size() - 1; i > 0; i--)
	{
		if (words.at(i) == "")
		{
			words.erase(words.begin() + i);
		}
	}
	// Make words upper case
	for (i = 0; i < words.size(); i++)
	{
		for (j = 0; j < words.at(i).size(); j++)
		{
			if (islower(words.at(i).at(j)))
			{
				words.at(i).at(j) = toupper(words.at(i).at(j));
			}
		}
	}
	// Get 2 words.
	if (words.size() == 0)
	{
		cout << "No command given" << endl;
	}
	if (words.size() == 1)
	{
		wd1 = words.at(0);
	}
	if (words.size() == 2)
	{
		wd1 = words.at(0);
		wd2 = words.at(1);
	}
	if (words.size() > 2)
	{
		cout << "Command too long. Only type one or two words (verb and noun)" << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	string command;
	string word_1;
	string word_2;
	bool initialized = false;
	bool hasCar = false;
	Car car = Car();
	while (word_1 != "QUIT"){
		command.clear();
		if (!initialized){
			cout << "Welcome to the official Car Shop Simulator 2014" << endl << "Here you can pretend to be the worlds best console mechanic" << endl;
			cout << "First, start with what car you want, you can get a TukTuk or a VroomVroom (not case sensitive) with the command GET" << endl;
			initialized = true;
		}
		
		if (hasCar){
			if (word_1 == "HELP"){
				cout << "Commands:" << endl << "SHOW (stats, boobs(or gtfo))" << endl;
				cout << "SWITCH (wheels, tire, rim, engine)" << endl << "DRIVE (off(into the sunset), away)" << endl;
				cout << "QUIT" << endl;
			}
			else if (word_1 == "SHOW"){
				if (word_2 == "STATS"){
					cout << "Car: " << car.name << endl << "\tWheels: " << car.wheels.name << endl;
					cout << "\t\tRim: " << car.wheels.rim.name << endl << "\t\t\tRim metal: " << car.wheels.rim.metal << endl;
					cout << "\t\tTire: " << car.wheels.tire.name << endl << "\t\t\tTire diameter: " << car.wheels.tire.diameter << endl;
					cout << "\tEngine: " << car.engine.name << endl << "\t\tHorsepower: " << car.engine.horsePower << endl;
				}
				if (word_2 == "BOOBS"){
					cout << "Mate, this is mechanic simulator 2014...." << endl;
				}
			}
			else if (word_1 == "SWITCH"){
				if (word_2 == "TIRE"){
					if (car.wheels.tire.name == "Goodrich"){
						car.wheels.tire = Americus();
						cout << "Switched tires too Americus" << endl;
					}
					else{
						car.wheels.tire = Goodrich();
						cout << "Switched tires too Goodrich" << endl;
					}
				}
				else if (word_2 == "RIM"){
					if (car.wheels.rim.name == "BlingBling"){
						car.wheels.rim = BrassBrad();
						cout << "Switched rims too BrassBrad" << endl;
					}
					else{
						car.wheels.rim = BlingBling();
						cout << "Switched rims too BlingBling" << endl;
					}
				}
				else if (word_2 == "WHEELS"){
					if (car.wheels.name == "Wheelios"){
						car.wheels = Rollos();
						cout << "Switched wheels too Rollo's" << endl;
					}
					else{
						car.wheels = Wheelios();
						cout << "Switched wheels too Wheelios" << endl;
					}
				}
				else if (word_2 == "ENGINE"){
					if (car.engine.name == "SwiftRage"){
						car.engine = Vroomerino();
						cout << "Switched engine too Vroomerino" << endl;
					}
					else{
						car.engine = SwiftRage();
						cout << "Switched engine too SwiftRage" << endl;
					}
				}
			}
			else if (word_1 == "DRIVE"){
				if (word_2 == "OFF"){
					cout << "You drive off  into the sunset!" << endl;
				}
				else if (word_2 == "AWAY"){
					cout << "You drive away.... far away..... very far away..... very very far away...." << endl;
				}
			}
		}

		if (word_1 == "GET"){
			if (word_2 == "TUKTUK"){
				hasCar = true;
				car = TukTuk();
				cout << "You got a TukTuk!" << endl;
			}
			else if (word_2 == "VROOMVROOM"){
				hasCar = true;
				car = VroomVroom();
				cout << "You got a VroomVroom!" << endl;
			}
		}
		cout << endl;
		getline(cin, command);
		cout << "Your raw command was " << command << endl;
		cout << endl;
		section_command(command, word_1, word_2);
	}
	return 0;
}