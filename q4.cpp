#include <iostream> 
#include <cstdlib> // for exit()
#include <cctype>  // for tolower()

using namespace std;

class Month
{
public:
  //constructor to set month based on first 3 chars of the month name
  Month(char c1, char c2, char c3);   // done, debugged
  //a constructor to set month base on month number, 1 = January etc.
  Month( int monthNumber);           // done, debugged
  //a default constructor (what does it do? nothing)
  Month(); // done, no debugging to do
  //an input function to set the month based on the month number
  void getMonthByNumber(istream&); // done, debugged
  //input function to set the month based on a three character input
  void getMonthByName(istream&);   // done, debugged
  //an output function that outputs the month as an integer,
  void outputMonthNumber(ostream&); // done, debugged
  //an output function that outputs the month as the letters.
  void outputMonthName(ostream&);   // done, debugged
  //a function that returns the next month as a month object
  Month nextMonth(); //
  //NB: each input and output function have a single formal parameter
  //for the stream
   
  int monthNumber();

private:
  int mnth;
   // Function to help set month based on three-letter month name
    void setMonthByName(const char* monthName);
};
// Implementation of the member functions

// Default constructor
Month::Month() : mnth(1) {} // Default to January
// Constructor to set month based on first 3 chars of the month name
Month::Month(char c1, char c2, char c3) {
    char monthName[4] = {tolower(c1), tolower(c2), tolower(c3), '\0'};
    setMonthByName(monthName);
}
// Constructor to set month based on month number, 1 = January etc.
Month::Month(int monthNumber) {
    if (monthNumber >= 1 && monthNumber <= 12) {
        mnth = monthNumber;
    } else {
        cerr << "Invalid month number. Setting to January." << endl;
        mnth = 1;
    }
}
// Input function to set the month based on the month number
void Month::getMonthByNumber(istream& in) {
    int number;
    in >> number;
    if (number >= 1 && number <= 12) {
        mnth = number;
    } else {
        cerr << "Invalid month number." << endl;
    }
}
// Input function to set the month based on a three character input
void Month::getMonthByName(istream& in) {
    char monthName[4];
    in >> monthName;
    if (monthName[3] == '\0') {
        setMonthByName(monthName);
    } else {
        cerr << "Invalid month name." << endl;
    }
}
// Output function that outputs the month as an integer
void Month::outputMonthNumber(ostream& out) {
    out << mnth << endl;
}
// Output function that outputs the month as the letters
void Month::outputMonthName(ostream& out) {
    const char* monthNames[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                 "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    out << monthNames[mnth - 1] << endl;
}
// Function that returns the next month as a Month object
Month Month::nextMonth() {
    return Month((mnth % 12) + 1);
}
// Function to get the month number
int Month::monthNumber() {
    return mnth;
}
// Helper function to set month based on three-letter month name
void Month::setMonthByName(const char* monthName) {
    const char* monthNames[] = {"jan", "feb", "mar", "apr", "may", "jun",
                                "jul", "aug", "sep", "oct", "nov", "dec"};
    for (int i = 0; i < 12; ++i) {
        if (tolower(monthName[0]) == monthNames[i][0] &&
            tolower(monthName[1]) == monthNames[i][1] &&
            tolower(monthName[2]) == monthNames[i][2]) {
            mnth = i + 1; // Set month number
            return;
        }
    }
    cerr << "Invalid month name. Setting to January." << endl;
    mnth = 1; // Default to January if invalid
}

int main() {
    Month month;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Set month by number\n";
        cout << "2. Set month by name\n";
        cout << "3. Output month number\n";
        cout << "4. Output month name\n";
        cout << "5. Get next month\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter month number (1-12): ";
                month.getMonthByNumber(cin);
                break;
            case 2:
                cout << "Enter month name (first 3 letters): ";
                month.getMonthByName(cin);
                break;
            case 3:
                cout << "Current month number: ";
                month.outputMonthNumber(cout);
                break;
            case 4:
                cout << "Current month name: ";
                month.outputMonthName(cout);
                break;
            case 5:
                {
                    Month next = month.nextMonth();
                    cout << "Next month number: ";
                    next.outputMonthNumber(cout);
                    cout << "Next month name: ";
                    next.outputMonthName(cout);
                }
                break;
            case 6:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
