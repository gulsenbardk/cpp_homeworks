#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "This program can only get 2 inputs.."
             << "\n";
        return EXIT_FAILURE;
    }

    stringstream filename_1{argv[1]};
    /*size_t lastindex_1 = filename_1.find_last_of(".");
    string fn_1 = filename_1.substr(0, lastindex_1);
    string ex1 = filename_1.substr(lastindex_1 + 1);
    stringstream s1i(filename_1);*/
    int fn1 = 0;
    string ex1;
    filename_1 >> fn1 >> ex1;

    stringstream filename_2{argv[2]};
    /*size_t lastindex_2 = filename_2.find_last_of(".");
    string fn_2 = filename_2.substr(0, lastindex_2);
    string ex2 = filename_2.substr(lastindex_2 + 1);
    stringstream s2i(filename_2);*/
    int fn2 = 0;
    string ex2;
    filename_2 >> fn2 >> ex2;

    if (ex1 == ".txt" && ex2 == ".txt") {
        int mean = ((fn1 + fn2) / 2);
        cout << mean << "\n";
    } else if (ex1 == ".png" && ex2 == ".png") {
        int total = (fn1 + fn2);
        cout << total << "\n";
    } else if (ex1 == ".txt" && ex2 == ".png") {
        float modulo = (fn1 % fn2);
        cout << modulo << "\n";
    } else {
        cerr << "This file-extension doesn't supported by program";
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}