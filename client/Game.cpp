#include "Game.h"
#include <iostream>


Game::Game()
{
	RPlayer = new Player();
	LPlayer = new Player();
	ball = new Ball();
	num_of_player = 0;

	RPlayer->SetPosition(0, 0);
	LPlayer->SetPosition(780, 0);
	ball->SetPosition(400, 200);
}

void Game::draw(RenderWindow* win_ptr)
{
	RPlayer->drawIt(win_ptr);
	LPlayer->drawIt(win_ptr);
	ball->DrawIt(win_ptr);
}

void Game::InitPos(Packet init)
{
	StructData data;
	init >> data.Rx >> data.Ry >> data.Lx >> data.Ly >> data.Bx >> data.By;

	RPlayer->SetPosition(data.Rx, data.Ry);
	LPlayer->SetPosition(data.Lx, data.Ly);
	ball->SetPosition(data.Bx, data.By);

}

void Game::SetPos(Packet pos)
{
	StructData data;
	pos >> data.Rx >> data.Ry >> data.Lx >> data.Ly >> data.Bx >> data.By;

	RPlayer->SetPosition(data.Rx, data.Ry);
	LPlayer->SetPosition(data.Lx, data.Ly);
	ball->SetPosition(data.Bx, data.By);
}

Packet Game::GetData(Packet data)
{
	data << RPlayer->body->getPosition().x << RPlayer->body->getPosition().y << LPlayer->body->getPosition().x << LPlayer->body->getPosition().y << ball->ball->getPosition().x << ball->ball->getPosition().y;
	return data;
}

void Game::doSmthOnKey(TcpSocket *sock)
{
	Keyboard key_events;
	Packet pack_key;

	if (key_events.isKeyPressed(Keyboard::Up))
	{
		pack_key << int(Direction::Up);
		sock->send(pack_key);
		pack_key.clear();
	}
	else if (key_events.isKeyPressed(Keyboard::Down))
	{
		pack_key << int(Direction::Down);
		sock->send(pack_key);
		pack_key.clear();
	}
	else
	{
		pack_key << int(Direction::ZERO);
		sock->send(pack_key);
		pack_key.clear();
	}

}

void Game::setPlayer(int num_of)
{
	num_of_player = num_of;
}

void Game::setPlayerWithSocket(TcpSocket* server)
{
	Packet num_player_pack;
	server->receive((Packet &)num_player_pack);
	int player;
	num_player_pack >> player;
	this->setPlayer(player);

	std::cout << this->num_of_player << endl;
}

