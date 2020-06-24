#include "logic.h"

void player_logic(TcpSocket sock[], StructData* data, int num_player)
{
	Packet pack;
	int dir;

	
	sock[num_player - 1].receive(pack);
	pack >> dir;
	
	// platforms logic
	if (dir == Direction::Up)
	{
		if (num_player == 1)
		{
			if (data->Ry > 0)
			{
				data->Ry -= speed_plate;
			}
		}
		else if(num_player == 2)
		{
			if (data->Ly > 0)
			{
				data->Ly -= speed_plate;
			}
		}
	}
	else if (dir == Direction::Down)
	{
		if (num_player == 1)
		{
			if (data->Ry < 400 - 80)
			{
				data->Ry += speed_plate;
			}
		}
		else if(num_player == 2)
		{
			if (data->Ly < 400 - 80)
			{
				data->Ly += speed_plate;
			}
		}
	}
		
		pack.clear();

}


void ball_logic(StructData* data, int *x_speed, int *y_speed)
{	
	if (data->By == 0 || data->By == 400 - 20)
	{
		*y_speed = *y_speed * (-1);
	}
	
	
	if (data->Bx <= 20 && data->Bx >= 0 && data->By + 10 >= data->Ly && data->By + 10 <= data->Ly + 80)
	{
		*x_speed = *x_speed * (-1);
		
	}
	else if (data->Bx + 20 >= 800 - 20 && data->Bx + 20 <= 800 && data->By + 10 >= data->Ry && data->By + 10 <= data->Ry + 80)
	{
		*x_speed = *x_speed * (-1);

		
	}
	else if (data->Bx < 0 || data->Bx + 20 >= 800)
	{
		cout << "game over" << endl;
		return;
	}
	

	data->Bx += *x_speed;
	data->By += *y_speed;
}

