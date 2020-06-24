#pragma once
#include <fstream>
#include <string>

using namespace std;

class Config
{
public:
	Config(string fileName);


	string *IP;
private:
	fstream *file;
};

