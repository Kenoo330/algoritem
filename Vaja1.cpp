#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

bool Branje_Stevil(vector<unsigned char> &vec, const char s[]) {
    ifstream input(s);
    unsigned char st;

    if (!input.is_open()) {
        return false;
    }

    while (input >> st) {
        vec.push_back(st);
    }

    input.close();
    return true;
}

int main(int argc, const char *argv[]) {
    vector<unsigned char> A;

    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    if (!Branje_Stevil(A, argv[1])) {
        cout << "Error: Unable to read input file.\n";
        return 1;
    }

    return 0;
}
