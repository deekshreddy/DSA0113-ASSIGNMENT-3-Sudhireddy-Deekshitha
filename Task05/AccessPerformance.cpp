#include <iostream>
#include <string>
#include <chrono>

using namespace std;

class Playlist
{
private:
    string tracks[4];

public:

    Playlist()
    {
        tracks[0] = "Song A";
        tracks[1] = "Song B";
        tracks[2] = "Song C";
        tracks[3] = "Song D";
    }

    string& operator[](int index)
    {
        if (index < 0 || index >= 4)
        {
            throw out_of_range("Invalid playlist index");
        }

        return tracks[index];
    }

    string& uncheckedAccess(int index)
    {
        return tracks[index];
    }
};

int main()
{
    const int COUNT = 10000000;

    Playlist playlist;

    volatile long long checkedChecksum = 0;
    volatile long long uncheckedChecksum = 0;

    auto startChecked =
        chrono::high_resolution_clock::now();

    for (int i = 0; i < COUNT; i++)
    {
        checkedChecksum += playlist[i % 4].size();
    }

    auto endChecked =
        chrono::high_resolution_clock::now();

    auto startUnchecked =
        chrono::high_resolution_clock::now();

    for (int i = 0; i < COUNT; i++)
    {
        uncheckedChecksum +=
            playlist.uncheckedAccess(i % 4).size();
    }

    auto endUnchecked =
        chrono::high_resolution_clock::now();

    double checkedTime =
        chrono::duration<double, milli>(
            endChecked - startChecked).count();

    double uncheckedTime =
        chrono::duration<double, milli>(
            endUnchecked - startUnchecked).count();

    cout << "====================================\n";
    cout << "     PLAYLIST ACCESS PERFORMANCE\n";
    cout << "====================================\n\n";

    cout << "Total Accesses: "
         << COUNT << "\n\n";

    cout << "CHECKED ACCESS\n";
    cout << "Execution Time: "
         << checkedTime << " ms\n";

    cout << "UNCHECKED ACCESS\n";
    cout << "Execution Time: "
         << uncheckedTime << " ms\n\n";

    cout << "Checked Checksum: "
         << checkedChecksum << endl;

    cout << "Unchecked Checksum: "
         << uncheckedChecksum << endl;

    cout << "\n====================================\n";

    return 0;
}
