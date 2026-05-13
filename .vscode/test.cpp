#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float celsius, fahrenheit;

    cout << "Temperature in Celsius: ";
    cin >> celsius;

    fahrenheit = celsius * 9/5 + 32;

    cout << "Fahrenheit: "  << fahrenheit << fixed << setprecision(2) << endl;

    return 0;
}