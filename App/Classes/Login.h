#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Login

class Login
{
public:

    Login();

    string type;    // defines the type of the login

protected:

    int findEmail(string input_email);

    int findPassword(string input_email, string input_password, int k);

};
