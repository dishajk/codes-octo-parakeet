#include<iostream>
#include<string.h>
using namespace std;

int main() {
    char msg[100];
    int key, choice;

    cout << "Enter key: ";
    cin >> key;
    cin.ignore(1000, '\n');  // clear buffer

    cout << "Enter the message:\n";
    cin.getline(msg, 100);

    cout << "Enter your choice \n1. Encryption \n2. Decryption \n";
    cin >> choice;

    if (choice == 1) {
        for(int i = 0; msg[i] != '\0'; i++) {
            unsigned char ch = msg[i];
            if (ch >= 'a' && ch <= 'z') {
                ch = (ch - 'a' + key) % 26 + 'a';  // ← cleaner modulo wrap
                msg[i] = ch;
            }
            else if (ch >= 'A' && ch <= 'Z') {
                ch = (ch - 'A' + key) % 26 + 'A';  // ← cleaner modulo wrap
                msg[i] = ch;
            }
        }
        cout << "Encrypted message: " << msg << endl;
    }
    else if (choice == 2) {
        for(int i = 0; msg[i] != '\0'; i++) {
            unsigned char ch = msg[i];
            if (ch >= 'a' && ch <= 'z') {
                ch = (ch - 'a' - key % 26 + 26) % 26 + 'a';  // ← handles negative wrap
                msg[i] = ch;
            }
            else if (ch >= 'A' && ch <= 'Z') {
                ch = (ch - 'A' - key % 26 + 26) % 26 + 'A';  // ← handles negative wrap
                msg[i] = ch;
            }
        }
        cout << "Decrypted message: " << msg << endl;
    }
}