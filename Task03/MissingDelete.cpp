#include <iostream>
using namespace std;

class Auditorium
{
private:
    int rows;
    char** seatMap;

public:
    Auditorium(int r, int s)
    {
        rows = r;

        seatMap = new char*[rows];

        for (int i = 0; i < rows; i++)
        {
            seatMap[i] = new char[s];

            for (int j = 0; j < s; j++)
            {
                seatMap[i][j] = 'O';
            }
        }

        cout << "Constructor called." << endl;
    }

    ~Auditorium()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] seatMap[i];
        }

        delete[] seatMap;

        cout << "Destructor called." << endl;
    }
};
int main()
{
    Auditorium* event = new Auditorium(10, 20);

    cout << "Event created on heap." << endl;


    cout << "Main function ending." << endl;

    return 0;
}
