#include <cstdlib>
#include <iostream>
#include <random>
using namespace std;

int main() {
    // ------------------------------------------------- //
    random_device device;
    int target_number;
    mt19937 generator(device());
    uniform_int_distribution<int> distribution(0, 99);
    target_number = distribution(generator);
    // ------------------------------------------------- //
    // --------------------------------------------------------------------------------------- //
    int guessed_number;
    do {
        // --------------- //
        cout << "Guess: ";
        cin >> guessed_number;
        // --------------- //
        // -----------------------------------------------------------------------------------//
        if (cin.fail()) {
            cout << "Error encountered, exiting...";
            cout << "Target number was " << target_number << "\n";
            return EXIT_FAILURE;
            // exit(1);
        }
        if (guessed_number > 0 && guessed_number < 99) {
            if (guessed_number == target_number) {
                cout << "Congratulations!!"
                     << "\n";
                return EXIT_SUCCESS;
            } else if (guessed_number < target_number) {
                cout << "Your guessed number " << guessed_number
                     << " is smaller than target number "
                     << "\n";
            } else if (guessed_number > target_number) {
                cout << "Your guessed number " << guessed_number << " is larger then target number "
                     << "\n";
            }
        } else if (0 < guessed_number || guessed_number > 99) {
            cout << "[WARNING] : Number must be between 0 and 99"
                 << "\n";
        }
        // -----------------------------------------------------------------------------------//
    } while (guessed_number != target_number);
    // --------------------------------------------------------------------------------------- //
    return 0;
}
