#include "MainClass.h"

MainClass::MainClass()
{
	game = new Game();
	socket = new TcpSocket();
	window = new RenderWindow(VideoMode(800, 400), "Pong Online");
	cfg = new Config("config.txt");
	
	if (socket->connect(IpAddress(*cfg->IP), 1234) != 0)
		window->close();
	game->setPlayerWithSocket(socket);
	
	// receiving data and initialization position of game's objects 
	Packet initPosWithServer;
	socket->receive(initPosWithServer);
	game->InitPos(initPosWithServer);
	initPosWithServer.clear();
	

	Packet DataPos;
	Event m_event;
	while (window->isOpen())
	{
		while (window->pollEvent(m_event))
		{
			if (m_event.type == Event::Closed)
			{
				window->close();
			}
		}
		
		// reaction on pushing keys
		game->doSmthOnKey(socket); // this func also sends data to server

		// getting and posting data to/from server
		socket->receive(DataPos);
		game->SetPos(DataPos);
		DataPos.clear();

		// drawing
		window->clear(Color::Black);
		game->draw(window);
		window->display();


		Sleep(5);
	}


}
