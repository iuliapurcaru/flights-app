#include "DeleteFlight.h"

DeleteFlight::DeleteFlight()
{
    cout << endl << "--DELETING A FLIGHT--" << endl << endl;

    string input_origin;
    string input_destination;
    string input_date;

    string confirmation;
    int k1 = 0, k2 = 0;

    //

    while (!k1)
    {
        k2 = 0;

        cout << "Introduceti locul de plecare: ";
        cin.ignore(INT_MAX, '\n');
        getline(cin, input_origin);
        while (!findString(input_origin, "TextFiles/Origins.txt"))
        {
            cout << "Introduceti locul de plecare: ";
            getline(cin, input_origin);
        }

        //

        cout << "Introduceti destinatia: ";
        getline(cin, input_destination);
        while (!findString(input_destination, "TextFiles/Destinations.txt"))
        {
            cout << "Introduceti destinatia: ";
            getline(cin, input_destination);
        }

        //

        cout << "Introduceti data: ";
        getline(cin, input_date);
        while (!findString(input_date, "TextFiles/Dates.txt"))
        {
            cout << "Introduceti data: ";
            getline(cin, input_date);
        }

        //

        cout << "Confirmati stergerea zborului " << input_origin << " - " << input_destination << " " << input_date << "? (da/nu)" << endl;
        cin >> confirmation;

        while (!k2)
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
                cout << "Optiune invalida. Alegeti alta optiune: ";
                cin >> confirmation;
            }
        }
    }

    deleteString(input_origin, "TextFiles/Origins.txt");
    deleteString(input_destination, "TextFiles/Destinations.txt");
    deleteString(input_date, "TextFiles/Dates.txt");

}

void DeleteFlight::deleteString(string input_string, const char* filename)
{
    string temp;
    int found = 0;

    ifstream file;
    file.open(filename);

    ofstream file_alt;
    file_alt.open("TextFiles/alt.txt");

    while (getline(file, temp))
    {
        if (temp != input_string || found)
        {
            file_alt << temp << endl;
        }

        if (temp == input_string)
        {
            found = 1;
        }
    }

    file.close();
    file_alt.close();

    remove(filename);
    rename("TextFiles/alt.txt", filename);

}

int DeleteFlight::findString(string input_string, const char* filename)
{
    string temp;
    int found = 0;

    ifstream file;
    file.open(filename);

    while (getline(file, temp))
    {
        if (temp == input_string)
        {
            found = 1;
            return 1;
        }
    }

    file.close();

    if (!found)
    {
        cerr << "Termenul cautat nu exista." << endl << endl;
        return 0;
    }

}
