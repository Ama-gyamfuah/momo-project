#include <iostream>
#include <string>

using namespace std;

// Declare variables for default PIN and balance
const string DEFAULT_PIN = "0000";
const int DEFAULT_BALANCE = 1000;

// Function to display the menu options
void displayMenu() {
    cout << "Welcome to Mobile Money Service" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Send Money" << endl;
    cout << "3. Reset/Change PIN" << endl;
    cout << "4. Exit" << endl;
    cout << "Please select an option: ";
}

// Function to authenticate the user
bool authenticateUser(string phone_number, string pin) {
    // Check if phone number and pin match the stored data
    if (phone_number == "1234567890" && pin == DEFAULT_PIN) {
        return true;
    } else {
        return false;
    }
}

// Function to check balance
void checkBalance(int balance) {
    cout << "Your balance is: " << balance << endl;
}

// Function to send money
void sendMoney(int& balance) {
    string recipient_phone_number;
    int amount;
    cout << "Enter recipient's phone number: ";
    cin >> recipient_phone_number;
    cout << "Enter amount to send: ";
    cin >> amount;
    // Check if balance is sufficient to complete the transaction
    if (balance >= amount) {
        balance -= amount;
        cout << "Transaction successful!" << endl;
        cout << "Your new balance is: " << balance << endl;
    } else {
        cout << "Insufficient balance!" << endl;
    }
}

// Function to reset/change PIN
void resetPin(string& pin) {
    string current_pin, new_pin;
    cout << "Enter current PIN: ";
    cin >> current_pin;
    // Check if current PIN is correct
    if (current_pin == pin) {
        cout << "Enter new PIN: ";
        cin >> new_pin;
        pin = new_pin;
        cout << "PIN changed successfully!" << endl;
    } else {
        cout << "Invalid PIN!" << endl;
    }
}

int main() {
    // Declare variables for phone number, PIN, and balance
    string phone_number, pin;
    int balance = DEFAULT_BALANCE;
    int attempts = 0;

    // Loop until the user selects the Exit option
    while (true) {
        // Prompt the user to enter phone number and PIN
        cout << "Enter phone number: ";
        cin >> phone_number;
        cout << "Enter PIN: ";
        cin >> pin;
        // Authenticate the user
        if (authenticateUser(phone_number, pin)) {
            // Reset the number of attempts if authentication is successful
            attempts = 0;
            cout << "Authentication successful!" << endl;
            // Display the menu and get the user's choice
            int choice;
            do {
                displayMenu();
                cin >> choice;
                switch (choice) {
                    case 1:
                        checkBalance(balance);
                        break;
                    case 2:
                        sendMoney(balance);
                        break;
                    case 3:
                        resetPin(pin);
                        break;
                    case 4:
                        cout << "Thank you for using Mobile Money Service!" << endl;
                        return 0;
                    default:
                        cout << "Invalid choice!" << endl;
                        break;
                }
            } while (choice != 4);
        } else {
            // Increment the number of attempts if authentication fails
            attempts++;
            cout << "Authentication failed!" << endl;
}}}            // Exit the

