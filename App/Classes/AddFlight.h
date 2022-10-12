#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <climits>
#include <math.h>

using namespace std;

// audaugare zboruri

class AddFlight
{
public:

    AddFlight();

protected:

    string origin;
    string destination;

    void addDate();

    void addCountry();

    void addToFile(string input_string, const char* filename);

    int dateConversion(int i1, int i2);

};