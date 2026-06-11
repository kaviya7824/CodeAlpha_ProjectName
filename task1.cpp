#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Check if username already exists
bool usernameExists(string username) {
    ifstream file("users.txt");
    string user, pass;

    while (file >> user >> pass) {
        if (user == username) {
            return true;
        }
    }
    return false;
}

// Registration function
void registerUser() {
    string username, password;

    cout << "\nEnter Username: ";
    cin >> username;

    if (usernameExists(username)) {
        cout << "Username already exists! Try another one.\n";
        return;
    }

    cout << "Enter Password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration Successful!\n";
}

// Login function
void loginUser() {
    string username, password;
    string user, pass;

    cout << "\nEnter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    ifstream file("users.txt");

    while (file >> user >> pass) {
        if (user == username && pass == password) {
            cout << "Login Successful! Welcome, " << username << ".\n";
            file.close();
            return;
        }
    }

    file.close();
    cout << "Invalid Username or Password!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== Login & Registration System =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}