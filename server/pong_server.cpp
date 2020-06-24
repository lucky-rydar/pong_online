#include <iostream>
#include <SFML/Network.hpp>
#include "StructData.h"
#include <thread>
#include <Windows.h>
#include "logic.h"


using namespace std;
using namespace sf;

int main() // server
{
	TcpSocket socket[2];
	TcpListener listener;
	Packet pack;
	StructData serverData;

	int num_player = 0;


	listener.listen(1234); // listening
	
	for (int i = 0; i < 2; i++)
	{
		if (listener.accept(socket[i]) == 0)
		{
			cout << "Connected: " << (i + 1) << endl;
			num_player = i + 1;
			pack << num_player;
			socket[i].send((Packet &)pack);
			pack.clear();
		}
	}
	
	//init data of game's objects
	serverData = { 0, 50, 780, 0, 400, 200 }; 
	pack << serverData.Rx << serverData.Ry << serverData.Lx << serverData.Ly << serverData.Bx << serverData.By;

	//sending necessary data to clients
	socket[0].send(pack);
	socket[1].send(pack);
	pack.clear();

	//server message to programmer
	cout << "We are ready to play" << endl;
	cout << "IP of the first player : " << socket[0].getRemoteAddress().toString() << endl;
	cout << "IP of the second player: " << socket[1].getRemoteAddress().toString() << endl;

	Packet buff;
	int x_speed = -2;
	int y_speed = 2;
	while (true)
	{
		ball_logic(&serverData, &x_speed, &y_speed);
		player_logic(socket, &serverData, 1);
		player_logic(socket, &serverData, 2);

		buff << serverData.Rx << serverData.Ry << serverData.Lx << serverData.Ly << serverData.Bx << serverData.By;
		socket[0].send(buff);
		buff.clear();

		buff << serverData.Rx << serverData.Ry << serverData.Lx << serverData.Ly << serverData.Bx << serverData.By;
		socket[1].send(buff);
		buff.clear();


		Sleep(5);
	}



	system("pause");
	listener.close();
	return 0;
}
