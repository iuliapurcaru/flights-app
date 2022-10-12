#include "Login.h"

Login::Login()
{
    string input_email;
    string input_password;

    string temp;
    int k;

    cout << endl << "--AUTENTIFICARE--" << endl << endl;

    cout << "EMAIL: ";
    cin >> input_email;
    k = findEmail(input_email);

    while (!k)
    {
        cout << "EMAIL: ";
        cin >> input_email;
        k = findEmail(input_email);
    }

    //

    string operator_check = "@flights.com";

    if (input_email.find(operator_check) != string::npos)
    {
        type = "operator";
    }
    else
    {
        type = "user";
    }

    cout << "PAROLA: ";
    cin >> input_password;

    while (!findPassword(input_email, input_password, k))
    {
        cout << "PAROLA: ";
        cin >> input_password;
    }

    cout << "--Logare reusita!--" << endl << endl;

}

int Login::findEmail(string input_email)
{
    string temp;
    int found = 0;
    int k = 1;
    string operator_check = "@flights.com";

    ifstream Emails;

    if (input_email.find(operator_check) != string::npos)
    {
        Emails.open("TextFiles/OperatorsEmails.txt");
    }
    else
    {
        Emails.open("TextFiles/UsersEmails.txt");
    }

    while (Emails >> temp)
    {
        if (input_email == temp)
        {
            found = 1;
            break;
        }
        k++;
    }

    Emails.close();

    if (!found)
    {
        cout << "--Nu exista cont cu acest email!--" << endl << endl;
        return 0;
    }

    return k;
}

int Login::findPassword(string input_email, string input_password, int k)
{
    int i;
    string temp;

    string operator_check = "@flights.com";

    ifstream Passwords;

    if (input_email.find(operator_check) != string::npos)
    {
        Passwords.open("TextFiles/OperatorsPasswords.txt");
    }
    else
    {
        Passwords.open("TextFiles/UsersPasswords.txt");
    }

    for (i = 1; i <= k; i++)
    {
        Passwords >> temp;
    }

    Passwords.close();

    try
    {
        if (input_password == temp)
        {
            return 1;
        }
        else throw 0;
    }
    catch (...)
    {
        cout << "--Parola gresita!--" << endl << endl;
        return 0;
    }

}
