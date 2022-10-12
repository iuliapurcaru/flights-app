#include "SearchFlight.h"


SearchFlight::SearchFlight()
{
    cout << endl << "--REZERVAREA UNUI ZBOR--" << endl;

    int k1 = 0;
    int k2;
    string confirmation;
    int check;

    while (!k1)
    {
        k2 = 0;

        //

        cout << "Introduceti locul de plecare: ";
        cin.ignore(INT_MAX, '\n');
        check = findString("TextFiles/Origins.txt");
        while (!check)
        {
            cerr << "--Locul de plecare cautat nu exista!--" << endl << endl;
            cout << "Introduceti locul de plecare: ";
            check = findString("TextFiles/Origins.txt");
        }

        cout << "Introduceti destinatia: ";
        check = findString("TextFiles/Destinations.txt");
        while (!check)
        {
            cerr << "--Destinatia cautata nu exista!--" << endl << endl;
            cout << "Introduceti destinatia: ";
            check = findString("TextFiles/Origins.txt");
        }

        //

        cout << "Introduceti data (zz/ll/aa): ";
        check = findString("TextFiles/Dates.txt");
        while (!check)
        {
            cerr << "--Data cautata nu exista!--" << endl << endl;
            cout << "Introduceti data (zz/ll/aa): ";
            check = findString("TextFiles/Dates.txt");
        }

        cout << "Confirmati rezervarea? (da/nu)" << endl;
        cin >> confirmation;

        //

        while (!k2)
        {
            try
            {
                if (confirmation == "da" ||
                    confirmation == "Da" ||
                    confirmation == "DA")
                {
                    k1 = 1;
                    k2 = 1;
                    break;
                }
                else if (confirmation == "nu" ||
                    confirmation == "Nu" ||
                    confirmation == "NU")
                {
                    k2 = 1;
                }
                else
                {
                    throw "Optiune invalida. Alegeti alta optiune: ";
                }
            }
            catch (const char* msg)
            {
                cout << msg;
                cin >> confirmation;
            }
        }
    }
}

int SearchFlight::findString(const char* filename)
{
    string input_string;
    string temp;

    getline(cin, input_string);

    ifstream file;
    file.open(filename);

    while (getline(file, temp))
    {
        if (input_string == temp)
        {
            file.close();
            return 1;
        }
    }

    file.close();

    return 0;
}
