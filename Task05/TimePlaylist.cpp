#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Time
{
private:
    int hours;
    int minutes;
    int seconds;

public:

    Time(int h = 0, int m = 0, int s = 0)
    {
        long long total = h * 3600LL + m * 60LL + s;

        hours = static_cast<int>(total / 3600);
        minutes = static_cast<int>((total % 3600) / 60);
        seconds = static_cast<int>(total % 60);
    }

    Time& operator++()
    {
        seconds++;

        if (seconds == 60)
        {
            seconds = 0;
            minutes++;
        }

        if (minutes == 60)
        {
            minutes = 0;
            hours++;
        }

        return *this;
    }

    Time operator++(int)
    {
        Time old = *this;

        ++(*this);

        return old;
    }

    bool operator==(const Time& other) const
    {
        return hours == other.hours &&
               minutes == other.minutes &&
               seconds == other.seconds;
    }

    bool operator<(const Time& other) const
    {
        if (hours != other.hours)
            return hours < other.hours;

        if (minutes != other.minutes)
            return minutes < other.minutes;

        return seconds < other.seconds;
    }

    long long totalSeconds() const
    {
        return hours * 3600LL +
               minutes * 60LL + seconds;
    }

    friend ostream& operator<<(ostream& out, const Time& t)
    {
        out << setfill('0')
            << setw(2) << t.hours << ":"
            << setw(2) << t.minutes << ":"
            << setw(2) << t.seconds;

        return out;
    }
};

class Playlist
{
private:
    string tracks[4];
    int size;

public:

    Playlist()
    {
        tracks[0] = "Shape of You";
        tracks[1] = "Perfect";
        tracks[2] = "Believer";
        tracks[3] = "Memories";

        size = 4;
    }

    string& operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Error: Invalid playlist index "
                 << index << endl;

            static string invalidTrack = "Invalid Track";

            return invalidTrack;
        }

        return tracks[index];
    }

    const string& operator[](int index) const
    {
        if (index < 0 || index >= size)
        {
            cout << "Error: Invalid playlist index "
                 << index << endl;

            static const string invalidTrack = "Invalid Track";

            return invalidTrack;
        }

        return tracks[index];
    }

    int getSize() const
    {
        return size;
    }
};

int main()
{
    cout << "====================================\n";
    cout << "       MUSIC PLAYER SYSTEM\n";
    cout << "====================================\n\n";

    Time t(0, 0, 5);

    Time a = t++;

    Time b = ++t;

    cout << "1. INCREMENT OPERATORS\n";

    cout << "Original starting time: 00:00:05\n";
    cout << "a after t++ : " << a << endl;
    cout << "b after ++t : " << b << endl;
    cout << "Current t  : " << t << "\n\n";

    Time t1(0, 1, 10);
    Time t2(0, 1, 20);

    cout << "2. COMPARISON OPERATORS\n";

    cout << "Time 1: " << t1 << endl;
    cout << "Time 2: " << t2 << endl;

    cout << "Time 1 == Time 2: "
         << boolalpha << (t1 == t2) << endl;

    cout << "Time 1 < Time 2: "
         << (t1 < t2) << "\n\n";

    Playlist playlist;

    cout << "3. PLAYLIST TRACKS\n";

    for (int i = 0; i < playlist.getSize(); i++)
    {
        cout << "Track " << i << ": "
             << playlist[i] << endl;
    }

    cout << endl;

    cout << "4. MODIFY PLAYLIST\n";

    playlist[1] = "New Favorite Song";

    cout << "Updated Track 1: "
         << playlist[1] << "\n\n";

    const Playlist fixedPlaylist;

    cout << "5. CONST PLAYLIST ACCESS\n";

    cout << "Track 0: "
         << fixedPlaylist[0] << "\n\n";

    cout << "6. RANGE CHECK TEST\n";

    cout << "Negative index:\n";
    cout << playlist[-1] << endl;

    cout << "Index equal to size:\n";
    cout << playlist[playlist.getSize()] << "\n\n";

    cout << "7. TIME ROLL-OVER\n";

    Time rollMinute(0, 0, 59);

    cout << "Before increment: "
         << rollMinute << endl;

    ++rollMinute;

    cout << "After increment : "
         << rollMinute << endl;

    Time rollHour(0, 59, 59);

    cout << "\nBefore hour roll-over: "
         << rollHour << endl;

    ++rollHour;

    cout << "After hour roll-over : "
         << rollHour << "\n\n";

    cout << "8. PLAYBACK SIMULATION\n";

    Time position(0, 0, 0);
    Time duration(0, 0, 5);

    cout << "Now Playing: "
         << playlist[0] << endl;

    while (position < duration)
    {
        cout << "Playback Position: "
             << position << endl;

        ++position;
    }

    cout << "Playback Completed at: "
         << position << endl;

    cout << "\n====================================\n";
    cout << "       PROGRAM COMPLETED\n";
    cout << "====================================\n";

    return 0;
}