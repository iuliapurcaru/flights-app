#include "AddFlight.h"

AddFlight::AddFlight()
{
    cout << endl << "--ADDING A NEW FLIGHT--" << endl;

    cout << endl << "PLACE OF DEPARTURE" << endl;
    cout << "Enter departure place: ";
    cin.ignore(INT_MAX, '\n');
    getline(cin, origin);
    addCountry();

    cout << endl << "PLACE OF ARRIVAL" << endl;
    cout << "Enter arrival place: ";
    cin.ignore(INT_MAX, '\n');
    getline(cin, destination);
    addCountry();

    //

    while (origin == destination)
    {
        cerr << "Place of arrival and departure must be different!" << endl;

        cout << endl << "PLACE OF DEPARTURE" << endl;
        cout << "Enter departure place: ";
        cin.ignore(INT_MAX, '\n');
        getline(cin, origin);
        addCountry();

        cout << endl << "PLACE OF ARRIVAL" << endl;
        cout << "Enter arrival place: ";
        cin.ignore(INT_MAX, '\n');
        getline(cin, destination);
        addCountry();
    }

    addToFile(origin, "TextFiles/Origins.txt");
    addToFile(destination, "TextFiles/Destinations.txt");

    addDate();
}

void AddFlight::addCountry()
{
    string confirmation;
    int k1 = 0, k2 = 0;

    while (!k1)
    {
        k2 = 0;

        cout << "Confirmati ca este corecta denumirea? (da/nu)" << endl;
        cin >> confirmation;

        while (!k2)
        {
            if (confirmation == "yes" ||
                confirmation == "Yes" ||
                confirmation == "YES")
            {
                k1 = 1;
                k2 = 1;
                break;
            }
            else if (confirmation == "no" ||
                confirmation == "No" ||
                confirmation == "NO")
            {
                k2 = 1;
            }
            else
            {
                cout << "Invalid option. Choose another option: ";
                cin >> confirmation;
            }
        }
    }
}

void AddFlight::addToFile(string input_string, const char* filename)
{
    ofstream file;
    file.open(filename, fstream::app);

    file << input_string << endl;

    file.close();
}

void AddFlight::addDate()
{
    cout << endl << "DATE" << endl;

    int input_day;
    int input_month;
    int input_year;

    int today_month = dateConversion(0, 1);
    int today_day = dateConversion(3, 4);
    int today_year = dateConversion(6, 7);

    cout << "Select day: ";
    cin >> input_day;
    cout << "Select month: ";
    cin >> input_month;
    cout << "Select year: ";
    cin >> input_year;

    //

    while ((input_day > 31 || input_month > 12) ||
        (input_year < today_year) ||
        (input_year == today_year && input_month < today_month) ||
        (input_year == today_year && input_month == today_month && input_day <= today_day))
    {
        cerr << "Invalid date!" << endl << endl;

        cout << "Select day: ";
        cin >> input_day;
        cout << "Select month: ";
        cin >> input_month;
        cout << "Select year: ";
        cin >> input_year;
    }

    //

    ofstream dates;

    dates.open("TextFiles/Dates.txt", fstream::app);

    dates << input_day << "/" << input_month << "/" << input_year << endl;

    dates.close();
}

int AddFlight::dateConversion(int i1, int i2)
{
    char date[9];
    _strdate_s(date);

    int d1 = date[i1] - '0';
    int d2 = date[i2] - '0';

    int number = d1 * 10 + d2;

    return number;
}
