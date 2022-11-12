#include <bits/stdc++.h>
using namespace std;
#define ll long long

class passanger
{

public:
    string name;
    int source;
    int destination;
    int seat_number;
};

class seatdetails
{

public:
    string name;
    int destination;
    int source;
};

vector<passanger> passen(100);
vector<seatdetails> seats(5);

int passNum = 0, seatN = 0;

void solve()
{
}

void addticket()
{

    string name;
    int source, destination, seatnumber;

    cout << "Your passenger number is :- " << passNum << endl;

    cout << "Please Enter Your Name :- ";
    cin >> name;

    passen[passNum].name = name;
    cout << endl;

    cout << "Your Source Station :- ";
    cin >> source;

    if (source < 1 || source > 5)
    {
        cout << "Please enter a valid source :- ";
        cin >> source;
    }

    passen[passNum].source = source;
    cout << endl;

    cout << "Your Destination :- ";
    cin >> destination;

    if (destination < 1 || destination > 5)
    {
        cout << "Please enter a valid destination :- ";
        cin >> destination;
    }
    if (source == destination)
    {
        cout << "Source and destination can't be same :- ";
        cout << "Please enter a valid destination :- ";
        cin >> destination;
    }

    passen[passNum].destination = destination;
    cout << endl;

    // for (int i = 0; i < 5; i++)
    // {
    //     if (seats[i].destination <= source)
    //     {
    //         seats[i].source = source;
    //         seats[i].destination = destination;
    //         seats[i].name = name;
    //         passen[passNum].seat_number = i;

    //         break;
    //     }
    // }

    if (seatN >= 5)
    {
        bool flag = false;
        for (int i = 0; i < 5; i++)
        {
            if (seats[i].destination >= source)
            {
                seats[i].source = source;
                seats[i].destination = destination;
                seats[i].name = name;
                passen[passNum].seat_number = i;
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            cout << "Sorry , No seat available ." << endl;
            return;
        }
    }
    else
    {
        seats[seatN].source = source;
        seats[seatN].destination = destination;
        seats[seatN].name = name;

        passen[passNum].seat_number = seatN;
    }

    cout << "Your seat number is :- " << passen[passNum].seat_number + 1 << endl;

    seatN++;
    passNum++;
}

void showticket(int Pnum)
{
    cout << "Name :- " << passen[Pnum].name << endl;

    cout << "Your seat number is :- " << passen[Pnum].seat_number + 1 << endl;

    cout << "You are Going from " << passen[Pnum].source << " To " << passen[Pnum].destination << endl;
}

void seatchart()
{
    cout << "seat   "
         << "Name    "
         << "source   "
         << "   destintion  " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << "      " << seats[i].name << "        " << seats[i].source << "       " << seats[i].destination << endl;
    }
}

int main()
{

    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    cout << "Press 1 to book a ticket ";
    cout << endl;
    cout << "Press 2 to check Seat Number  ";
    cout << endl;
    cout << "Press 9 to see Seat chart  ";
    cout << endl;
    cout << "Press 0 to exit ";
    cout << endl;

    int code;
    cout << "Your command :- ";
    cin >> code;

    while (1)
    {
        if (code == 0)
        {
            break;
        }

        else if (code == 1)
        {
            addticket();

            cout << endl;

            cout << "Your command :- ";
            cin >> code;
            // break;
        }

        else if (code == 2)
        {
            int Pnum;

            cout << endl
                 << "Enter Your Passenger Number Please :- " << endl;
            cin >> Pnum;
            showticket(Pnum);

            cout << "Your command :- ";
            cin >> code;
            cout << endl;
            // break;
        }
        else if (code == 9)
        {
            seatchart();

            cout << "Your command :- ";
            cin >> code;
            cout << endl;
        }
        else
        {
            cout << "Please Enter a valid command ";
            cout << endl;

            cout << "Your command :- ";
            cin >> code;

            // break;
        }
    }

    // solve();

    return 0;
}