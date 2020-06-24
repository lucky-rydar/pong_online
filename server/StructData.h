#pragma once
#include <string>
#include <SFML/Network.hpp>

using namespace std;
using namespace sf;

enum Direction
{
	Up = 1,
	Down,
	ZERO
};

struct StructData
{
	int Rx, Ry, Lx, Ly, Bx, By;
};