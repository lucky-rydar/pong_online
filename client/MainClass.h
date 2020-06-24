#pragma once
#include "Game.h"
#include "Config.h"
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Main.hpp>
#include "SFML/Config.hpp"
#include <iostream>
#include <Windows.h>
#pragma warning(disable: 4244)


using namespace std;
using namespace sf;

class MainClass
{
public:
	MainClass();


	
private:
	TcpSocket* socket;
	Game* game;
	RenderWindow* window;
	Config* cfg;
};

