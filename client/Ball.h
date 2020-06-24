#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
public:
	Ball();
	void SetPosition(int x, int y);
	void DrawIt(RenderWindow *win_ptr);
	CircleShape* ball;

private:
	
};

