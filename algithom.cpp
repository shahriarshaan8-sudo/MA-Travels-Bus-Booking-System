#include <iostream>
using namespace std;

int main()
{
    string bus[5] = {
        "Hanif", "Shyamoli", "Green Line",
        "HENA", "Desh Travels"
    };

    string model[5] = {
        "Hino AK1J", "Hino RM2", "Hyundai Universe",
        "Ashok Leyland", "Hino 1J"
    };

    string type[5] = {
        "AC", "Non-AC", "AC", "Non-AC", "AC"
    };

    string passenger[5][20] = {};

    int b, s, n, count;
    string name;

    cout << "        M&A TRAVELS      " << endl;
    cout << "    BUS BOOKING SYSTEM    " << endl;
    cout << endl << "AVAILABLE BUSES:" << endl;

    for (int i = 0; i < 5; i++)
    {
        count = 0;

        for (int j = 0; j < 20; j++)
        {
            if (passenger[i][j] == "")
                count++;
        }

        cout << i+1 << ". " << bus[i]
             << " | Model: " << model[i]
             << " | " << type[i]
             << " | Available Seats: " << count << endl;
    }

    cout << endl << "Select Your Bus (1-5): ";
    cin >> b;

    if (b >= 1 && b <= 5)
    {
        cout << endl << "   BUS DETAILS:  " << endl;

        cout << "Bus Name  : " << bus[b-1] << endl;
        cout << "Bus Model : " << model[b-1] << endl;
        cout << "Bus Type  : " << type[b-1] << endl;

        cout << endl << "   SEAT STATUS:  " << endl;

        for (int i = 0; i < 20; i++)
        {
            cout << "Seat " << i+1 << " : ";

            if (passenger[b-1][i] == "")
                cout << "Available";
            else
                cout << "Booked";

            cout << endl;
        }

        cout << endl << "Enter Passenger Name: ";
        cin >> ws;
        getline(cin, name);

        cout << "How many seats do you want to book: ";
        cin >> n;

        if (n > 0 && n <= 20)
        {
            count = 0;

            for (int i = 0; i < n; i++)
            {
                cout << endl << "Enter Seat Number : ";
                cin >> s;

                if (s >= 1 && s <= 20 && passenger[b-1][s-1] == "")
                {
                    passenger[b-1][s-1] = name;

                    cout << "Seat " << s
                         << " Booked Successfully for "
                         << name << "!" << endl;

                    count++;
                }
                else
                {
                    cout << "Invalid or Already Booked Seat!" << endl;
                    i--;
                }
            }

            cout << endl << "   UPDATED SEAT STATUS   " << endl;

            int available = 0;
            int booked = 0;

            for (int i = 0; i < 20; i++)
            {
                cout << "Seat " << i+1 << " : ";

                if (passenger[b-1][i] == "")
                {
                    cout << "Available";
                    available++;
                }
                else
                {
                    cout << "Booked";
                    booked++;
                }

                cout << endl;
            }

            cout << "Available Seats: " << available << endl;
            cout << "Booked Seats: " << booked << endl;

            cout << endl << "BOOKING SUMMARY" << endl;

            cout << "Passenger Name : " << name << endl;
            cout << "Bus Name       : " << bus[b-1] << endl;
            cout << "Bus Model      : " << model[b-1] << endl;
            cout << "Total Booked   : " << count << endl;

            cout << endl << "Thank You for Choosing M&A Travels!" << endl;
        }
        else
        {
            cout << "Invalid Number of Seats!" << endl;
        }
    }
    else
    {
        cout << "Invalid Bus Number!" << endl;
    }

    return 0;
}
