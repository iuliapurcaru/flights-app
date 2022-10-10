#pragma once

#include <iostream>
#include <string>

using namespace std;

// creates new account

class CreateUser
{
public:

    CreateUser();

protected:

    string email;
    string password;

    void inputEmail();    // choosing email

    void inputPassword();   // choosing password

    int checkEmail();     // checks the email format

    int checkPassword();    // checks the validity of the password

    int countCharacter(string input_string, char start_value, char end_value);   // counts characters

    void addToFile(string input_string, const char* filename);

};