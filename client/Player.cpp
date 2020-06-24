#include "Player.h"

Player::Player()
{
	body = new RectangleShape(Vector2f(20, 80));
	body->setFillColor(Color::White);

}

void Player::SetPosition(int x, int y)
{
	body->setPosition(x, y);
}

void Player::drawIt(RenderWindow* win_ptr)
{
	win_ptr->draw(*body);
}
