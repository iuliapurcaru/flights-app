#include "CreateUser.h"

CreateUser::CreateUser()
{
    cout << endl << "--CREATE A NEW ACCOUNT--" << endl << endl;

    inputEmail();
    inputPassword();

    addToFile(email, "TextFiles/UsersEmails.txt");
    addToFile(password, "TextFiles/UsersPasswords.txt");

}

void CreateUser::inputEmail()
{
    cout << "Emailul trebuie sa fie de formatul exemplu@email.com" << endl;
    cout << "EMAIL: ";
    cin >> email;

    while (!checkEmail())
    {
        cout << "EMAIL: ";
        cin >> email;
    }
    cout << "--Email valid--" << endl << endl;
}

void CreateUser::inputPassword()
{

    string confirm_password;

    cout << "Parola trebuie sa aibe cel putin 8 caractere, sa nu contina spatii" << endl << "si sa contina minim o litera mica, o litera mare, o cifra si un caracter special." << endl;
    cout << "PAROLA: ";
    cin.ignore(INT_MAX, '\n');
    getline(cin, password);

    while (!checkPassword())
    {
        cout << "PAROLA: ";
        getline(cin, password);
    }

    //

    cout << "CONFIRMATI PAROLA: ";
    cin >> confirm_password;

    while (password != confirm_password)
    {
        cerr << "--Parolele nu coincid!--" << endl << endl;
        cout << "CONFIRMATI PAROLA: ";
        cin >> confirm_password;
    }

    cout << "--Parola valida--" << endl;

}

int CreateUser::checkEmail()
{
    int found = 0;
    unsigned i;

    try
    {
        char c;
        int int_c;

        c = email[0];
        int_c = (int)c;

        if (int_c < 97 || int_c > 122)
        {
            throw 0;
        }
    }
    catch (...)
    {
        cerr << "--Format email invalid!--" << endl << endl;
        return 0;
    }

    for (i = 0; i < email.length(); i++)
    {
        if (email[i] == '@')
        {
            found++;
            break;
        }
    }

    if (email[i + 1] == '.')
    {
        cerr << "--Format email invalid!--" << endl << endl;
        return 0;
    }

    if (found)
    {
        for (i = i + 2; i < email.length(); i++)
        {
            if (email[i] == '.')
            {
                found++;
                break;
            }
        }
    }

    if (i + 1 == email.length())
    {
        cerr << "--Format email invalid!--" << endl << endl;
        return 0;
    }

    try
    {
        if (found == 2)
        {
            return 1;
        }
        else throw "--Format email invalid!--";
    }
    catch (const char* msg)
    {
        cerr << msg << endl << endl;
        return 0;
    }
}

int CreateUser::checkPassword()
{
    unsigned i;

    try
    {
        for (i = 0; i < password.length(); i++)
        {
            if (password[i] == ' ')
            {
                throw "Parola nu poate contine spatii!";
            }
        }
    }
    catch (const char* msg)
    {
        cout << msg << endl << endl;
        return 0;
    }

    try
    {
        if (password.length() < 8)
        {
            throw "Parola trebuie sa aibe minim 8 caractere!";
        }
    }
    catch (const char* msg)
    {
        cerr << msg << endl << endl;
        return 0;
    }

    try
    {
        for (i = 0; i < password.length(); i++)
        {
            if ((!countCharacter(password, 65, 90)) ||         // verificare litere mari
                (!countCharacter(password, 48, 57)) ||    // verificare cifre
                (!countCharacter(password, 97, 122)) ||    // verificare litere mici
                (!countCharacter(password, 33, 47) &&      // verificare caractere speciale
                    !countCharacter(password, 58, 64) &&
                    !countCharacter(password, 91, 96) &&
                    !countCharacter(password, 123, 126)))
            {
                throw "--Parola prea slaba!--";
            }
        }
    }
    catch (const char* msg)
    {
        cerr << msg << endl << endl;
        return 0;
    }

    return 1;
}

int CreateUser::countCharacter(string input_string, char start_value, char end_value)
{
    int counter = 0;
    int i;

    for (i = start_value; i <= end_value; i++)
    {
        char c = (char)i;
        string str(1, c);

        if (input_string.find(str) != string::npos)
        {
            counter++;
        }
    }
    return counter;
}

void CreateUser::addToFile(string input_string, const char* filename)
{
    ofstream file;
    file.open(filename, fstream::app);

    file << input_string << " ";

    file.close();
}
