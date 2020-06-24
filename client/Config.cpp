#include "Config.h"

Config::Config(string fileName)
{
	file = new fstream(fileName);
	IP = new string();

	*file >> *IP;

}
