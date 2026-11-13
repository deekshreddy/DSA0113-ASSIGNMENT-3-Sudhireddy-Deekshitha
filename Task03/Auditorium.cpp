#include <iostream>
#include <string>
using namespace std;

class Auditorium
{
private:
    int rows;
    int seats;
    char** seatMap;
    string eventName;

public:
    Auditorium(string name, int r, int s)
    {
        eventName = name;
        rows = r;
        seats = s;
        seatMap = nullptr;

        cout << "Constructor: " << eventName << endl;

        if (rows > 0 && seats > 0)
        {
            seatMap = new char*[rows];

            for (int i = 0; i < rows; i++)
            {
                seatMap[i] = new char[seats];

                for (int j = 0; j < seats; j++)
                {
                    seatMap[i][j] = 'O';
                }
            }
        }
    }

    void bookSeat(int r, int s)
    {
        if (r >= 0 && r < rows &&
            s >= 0 && s < seats)
        {
            if (seatMap[r][s] == 'O')
            {
                seatMap[r][s] = 'B';
                cout << "Seat booked: "
                     << r << "," << s << endl;
            }
            else
            {
                cout << "Seat already booked!" << endl;
            }
        }
        else
        {
            cout << "Invalid seat position!" << endl;
        }
    }

    void cancelSeat(int r, int s)
    {
        if (r >= 0 && r < rows &&
            s >= 0 && s < seats)
        {
            if (seatMap[r][s] == 'B')
            {
                seatMap[r][s] = 'O';
                cout << "Booking cancelled: "
                     << r << "," << s << endl;
            }
            else
            {
                cout << "Seat is not booked!" << endl;
            }
        }
        else
        {
            cout << "Invalid seat position!" << endl;
        }
    }

    void displaySeats() const
    {
        cout << "\nSeat Map - " << eventName << endl;

        if (rows == 0 || seats == 0)
        {
            cout << "No seats available." << endl;
            return;
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < seats; j++)
            {
                cout << seatMap[i][j] << " ";
            }

            cout << endl;
        }
    }

    ~Auditorium()
    {
        int booked = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < seats; j++)
            {
                if (seatMap[i][j] == 'B')
                {
                    booked++;
                }
            }

            delete[] seatMap[i];
        }

        delete[] seatMap;

        cout << "Destructor: " << eventName << endl;
        cout << "Booked seats at closing: "
             << booked << endl;
        cout << "Memory released successfully.\n\n";
    }
};

void showMemory(int rows, int seats)
{
    long long seatMemory =
        1LL * rows * seats * sizeof(char);

    long long pointerMemory =
        1LL * rows * sizeof(char*);

    cout << rows << " x " << seats
         << " = "
         << seatMemory + pointerMemory
         << " bytes" << endl;
}

int main()
{
    cout << "AUDITORIUM SEAT BOOKING SYSTEM\n";
    cout << "==============================\n\n";

    cout << "1. STACK OBJECT\n";

    Auditorium event1("Music Event", 2, 3);

    event1.bookSeat(0, 1);
    event1.bookSeat(1, 2);
    event1.cancelSeat(0, 1);
    event1.displaySeats();

    cout << "\n2. BLOCK-SCOPE OBJECT\n";

    {
        Auditorium event2("Drama Event", 2, 2);

        event2.bookSeat(0, 0);
        event2.displaySeats();

        cout << "Leaving the block...\n";
    }

    cout << "3. HEAP OBJECT\n";

    Auditorium* event3 =
        new Auditorium("Dance Event", 3, 2);

    event3->bookSeat(1, 1);
    event3->displaySeats();

    cout << "Deleting heap object...\n";

    delete event3;

    cout << "4. ZERO-ROW EVENT\n";

    Auditorium event4("Empty Event", 0, 5);

    event4.displaySeats();

    cout << "\n5. MEMORY ALLOCATION ESTIMATES\n";

    showMemory(10, 20);
    showMemory(100, 200);
    showMemory(1000, 2000);

    cout << "\nEnd of main function.\n";

    return 0;
}
