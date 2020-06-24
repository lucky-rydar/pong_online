#include "Ball.h"

Ball::Ball()
{
	ball = new CircleShape(10, 100);
	ball->setFillColor(Color::White);
}

void Ball::SetPosition(int x, int y)
{
	ball->setPosition(x, y);
}

void Ball::DrawIt(RenderWindow* win_ptr)
{
	win_ptr->draw(*ball);
}
