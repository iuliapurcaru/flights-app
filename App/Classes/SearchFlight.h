#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class SearchFlight
{
public:

    SearchFlight();

protected:

    string origin;
    string destination;

    int findString(const char* filename);

};
