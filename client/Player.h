#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>

using namespace sf;

class Player
{
public:
	Player();
	void SetPosition(int x, int y);
	void drawIt(RenderWindow* win_ptr);
	RectangleShape* body;

private:


};

