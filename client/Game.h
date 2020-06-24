#pragma once
#include "Player.h"
#include "Ball.h"
#include "StructData.h"
#include <SFML/Network.hpp>

class Game
{
public:
	Game();
	void draw(RenderWindow *winPtr);
	
	void InitPos(Packet init); // these both is the same
	void SetPos(Packet pos); //it is just for better reading the code
	
	Packet GetData(Packet data);
	void doSmthOnKey(TcpSocket *sock);
	void setPlayerWithSocket(TcpSocket *player);
	

private:
	void setPlayer(int num_of);
	
	Player* RPlayer;
	Player* LPlayer;
	Ball* ball;
	int num_of_player;
};

