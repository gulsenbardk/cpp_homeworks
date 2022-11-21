#include <cstdlib>
#include <iostream>
#include <random>
using namespace std;

int main() {
    // ------------------------------------------------- //
    random_device device;
    int target_number = 0;
    mt19937 generator(device());
    uniform_int_distribution<int> distribution(0, 99);
    target_number = distribution(generator);
    // ------------------------------------------------- //
    // --------------------------------------------------------------------------------------- //
    int guessed_number = 0;
    while (target_number != guessed_number) {
        cin >> guessed_number;
        cout << "Target number was: " << target_number << endl;

        if (cin.fail()) {
            cerr << "Error encountered, exiting..." << endl << target_number << endl;
            return EXIT_FAILURE;
        }
        if ((target_number <= 0) || (target_number >= 99)) {
            cerr << "[WARNING] : Number must be between 0 and 99" << endl << target_number << endl;
        } else if (guessed_number < target_number) {
            cout << "Your guessed number is smaller than target number"
                    "target number "
                 << endl
                 << target_number << endl;
        } else if (guessed_number > target_number) {
            cout << " Your guessed number is smaller than target number"
                    "target number "
                 << endl
                 << target_number << endl;
        } else if (guessed_number == target_number) {
            cerr << "Congratulations!!!! " << endl << target_number << endl;
        } else {
            cerr << "ERROR" << endl;
        }
    }
    // --------------------------------------------------------------------------------------- //
    return EXIT_SUCCESS;
}
