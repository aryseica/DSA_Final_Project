#include <iostream>
#include <string>

using namespace std;

int main() {
    string term;
    string definition;

while (true) {
    cout << "Enter term (or type 'quit' to exit): ";
    getline(cin, term);

    if (term == "quit") {
        break;
    }

    cout << "Enter definition: ";
    getline(cin, definition);

    cout << "Added: " << term << "-" << definition << endl;
}

cout << "Exiting program... " << endl;
return 0;
}