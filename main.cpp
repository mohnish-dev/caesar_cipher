/*
Description: This program uses Caesar's Cipher to encode and decode messages.
The user can specify the number of shifts, including negative shifts, to encode or decode a message.
*/

#include <iostream>
#include <string>
#include <limits>
#include "cipher.h"

using std::string;
using std::getline;
using std::cout;
using std::cin;
using std::endl;

const int MIN_SHIFT = -25; // Allow negative shifts
const int MAX_SHIFT = 25;

void displayMenu() {
    cout << endl << "0. Exit" << endl;
    cout << "1. Encode a Message" << endl;
    cout << "2. Decode a Message" << endl;
    cout << "Enter your choice: ";
}

bool validateShift(int shift) {
    return shift >= MIN_SHIFT && shift <= MAX_SHIFT;
}

int getShift() {
    int shift;
    while (true) {
        cout << "Enter shift value (" << MIN_SHIFT << " to " << MAX_SHIFT << "): ";
        cin >> shift;
        if (cin.fail() || !validateShift(shift)) {
            cin.clear(); // Clear input buffer to restore cin to a usable state
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore last input
            cout << "Invalid shift number. Try again." << endl;
        }
        else {
            break;
        }
    }
    return shift;
}

int main()
{
    cout << "Welcome to the Caesar Cipher Simulator!" << endl;
    string option;

    while (true)
    {
        displayMenu();
        cin >> option;
        cout << endl;

        if (option == "0") {
            cout << "Good-bye!" << endl;
            break;
        }
        else if (option == "1" || option == "2") {
            string word;
            int shift;
            cin.ignore(); // Ensure getline works properly

            cout << "Enter the message: ";
            getline(cin, word);
            shift = getShift();

            Cipher cipher(word);
            if (option == "1") {
                cipher.encode(shift);
                cout << "Encoded message: " << cipher.getText() << endl;
            }
            else {
                cipher.decode(shift);
                cout << "Decoded message: " << cipher.getText() << endl;
            }
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
