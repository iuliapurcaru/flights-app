#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <math.h>
#include <climits>

#include "Classes/AddFlight.h"
#include "Classes/CreateUser.h"
#include "Classes/DeleteFlight.h"
#include "Classes/Login.h"
#include "Classes/SearchFlight.h"

using namespace std;

int main()
{
    char command_input;
    int action = 0;

    string login_type_check;

    cout << "--HOMEPAGE--" << endl;
    cout << "1 - Create a new account" << endl;
    cout << "2 - Log in" << endl;

    while (!action)
    {

        cout << "Choose an option: ";
        cin >> command_input;

        try
        {
            if (command_input == '1')
            {
                CreateUser create_user;
                cout << "Account successfully created." << endl << endl;
            }
            else if (command_input == '2')
            {
                action = 1;
                Login login;
                login_type_check = login.type;
                break;
            }
            else
            {
                throw "Invalid option";
            }
        }
        catch (const char* msg)
        {
            cerr << msg << endl << endl;
        }
    }

    if (login_type_check == "user")
    {
        action = 0;

        while (!action)
        {
            cout << "--USER PROFILE--" << endl;
            cout << "1 - Search for a flight" << endl;
            cout << "2 - Log out" << endl;
            cout << "Choose an option: ";
            cin >> command_input;

            try
            {
                if (command_input == '1')
                {
                    SearchFlight reservation;
                    cout << "Rezervare efectuata cu succes." << endl << endl;
                }
                else if (command_input == '2')
                {
                    cout << "--You have logged out!--" << endl;
                    action = 1;
                    break;
                }
                else
                {
                    throw "Invalid option";
                }
            }
            catch (const char* msg)
            {
                cerr << msg << endl << endl;
            }
        }
    }
    else if (login_type_check == "operator")
    {
        action = 0;

        while (!action)
        {
            cout << "--OPERATOR PROFILE--" << endl;
            cout << "1 - Add a flight" << endl;
            cout << "2 - Cancel a flight" << endl;
            cout << "3 - Log out" << endl;
            cout << "Choose an option: ";
            cin >> command_input;

            try
            {
                if (command_input == '1')
                {
                    AddFlight aflight;
                    cout << "Flight was successfully added." << endl << endl;
                }
                else if (command_input == '2')
                {
                    DeleteFlight dflight;
                    cout << "Flight was successfully cancelled." << endl << endl;
                }
                else if (command_input == '3')
                {
                    cout << "--Ai iesit din cont!--" << endl;
                    action = 1;
                    break;
                }
                else
                {
                    throw "Incalid option. Choose another option: ";
                }
            }
            catch (const char* msg)
            {
                cerr << msg;
                cin >> command_input;
            }
        }
    }

    return 0;
}