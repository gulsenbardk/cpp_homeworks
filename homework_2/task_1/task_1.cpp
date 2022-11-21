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
    do {
        cin >> guessed_number;
        if (cin.fail()) {
            cerr << "Error encountered, exiting..." << endl << target_number << endl;
            return EXIT_FAILURE;
        }
        if (guessed_number > 0 && guessed_number < 99) {
            if (guessed_number == target_number) {
                cout << "Congratulations!!" << target_number << endl;
            } else if (guessed_number < target_number) {
                cout << "Your guessed number " << guessed_number
                     << " is smaller than target number " << endl;
            } else if (guessed_number > target_number) {
                cout << "Your guessed number " << guessed_number << " is larger then target number "
                     << endl;
            }
        } else if (0 > guessed_number || guessed_number > 99) {
            cerr << "[WARNING] : Number must be between 0 and 99" << endl;
        } else {
            cerr << "ERROR" << endl;
        }
    } while (target_number != guessed_number);
    // ---------------------------------------------------------------------------------------
    // //
    return EXIT_SUCCESS;
}
