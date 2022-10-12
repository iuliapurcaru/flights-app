#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// stergere zboruri

class DeleteFlight
{
public:

    DeleteFlight();

protected:

    void deleteString(string input_string, const char* filename);
    int findString(string input_string, const char* filename);

};