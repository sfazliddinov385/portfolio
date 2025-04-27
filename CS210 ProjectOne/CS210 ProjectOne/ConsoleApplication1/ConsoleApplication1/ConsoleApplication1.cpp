#include <iostream>
#include <iomanip>
#include <string>
#include <limits> 

using namespace std;


class Clock {
private:
    int hour;   
    int minute;
    int second;

public:
    // Constructor to initialize time
    Clock(int h = 0, int m = 0, int s = 0) {
        setTime(h, m, s);
    }

    // Set the time (with basic validation and adjustments)
    void setTime(int h, int m, int s) {
        hour = (h >= 0 && h < 24) ? h : 0;
        minute = (m >= 0 && m < 60) ? m : 0;
        second = (s >= 0 && s < 60) ? s : 0;
    }

    // Add one hour, handle rollover (e.g., 23 -> 0)
    void addHour() {
        hour = (hour + 1) % 24;
    }

    // Add one minute, handle rollover
    void addMinute() {
        minute = (minute + 1);
        if (minute >= 60) {
            minute = 0;
            addHour();
        }
    }

    // Add one second, handle rollover
    void addSecond() {
        second = (second + 1);
        if (second >= 60) {
            second = 0;
            addMinute();
        }
    }

    // Display time in 24-hour format (HH:MM:SS)
    void display24HourFormat() const {
        cout << setw(2) << setfill('0') << hour << ":"
            << setw(2) << setfill('0') << minute << ":"
            << setw(2) << setfill('0') << second;
    }

    // Display time in 12-hour format (HH:MM:SS AM/PM)
    void display12HourFormat() const {
        int displayHour = hour % 12;
        if (displayHour == 0) {
            displayHour = 12;
        }
        string am_pm = (hour >= 12) ? "PM" : "AM";

        cout << setw(2) << setfill('0') << displayHour << ":"
            << setw(2) << setfill('0') << minute << ":"
            << setw(2) << setfill('0') << second << " " << am_pm;
    }
};

int main() {
    // 1. Get initial time from user
    int h, m, s;
    cout << "Enter initial time (24-hour format):\n";
    cout << "Hour   (0-23): ";
    cin >> h;
    cout << "Minute (0-59): ";
    cin >> m;
    cout << "Second (0-59): ";
    cin >> s;

    Clock myClock(h, m, s);

    // 2. Main loop: display menu and respond
    bool exitProgram = false;
    while (!exitProgram) {
        // Display both 12-hour and 24-hour clocks:
        cout << "\n----------------------------------------\n";
        cout << "    12-Hour Clock:  ";
        myClock.display12HourFormat();
        cout << "\n"
            << "    24-Hour Clock:  ";
        myClock.display24HourFormat();
        cout << "\n----------------------------------------\n\n";

        // this shows the menu
        cout << "Menu Options:\n"
            << "1) Add One Hour\n"
            << "2) Add One Minute\n"
            << "3) Add One Second\n"
            << "4) Exit\n";

        // repeats the prompt until we get a valid integer in [1..4]
        int choice;
        while (true) {
            cout << "Enter your choice: ";
            cin >> choice;

            // cheks if parsing failed (non-numeric input)
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input, please try again.\n";
            }
            // cheks if choice is out of the valid range
            else if (choice < 1 || choice > 4) {
                cout << "Invalid input, please try again.\n";
            }
            else {
                break;
            }
        }

        // List of choices
        switch (choice) {
        case 1:
            myClock.addHour();
            break;
        case 2:
            myClock.addMinute();
            break;
        case 3:
            myClock.addSecond();
            break;
        case 4:
            exitProgram = true;
            cout << "Exiting program...\n";
            break;
        }
    }

    return 0;
}
