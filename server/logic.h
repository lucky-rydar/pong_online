#pragma once
#include <iostream>
#include <SFML/Network.hpp>
#include "StructData.h"

using namespace std;
using namespace sf;

const int speed_plate = 5;

void player_logic(TcpSocket sock[], StructData* data, int num_player);
void ball_logic(StructData* data, int* x_speed, int* y_speed);
