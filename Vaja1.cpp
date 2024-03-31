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

void countingSort(vector<unsigned char> &A, int n, int k) {
    vector<int> count(2, 0);
    vector<unsigned char> output(n);

    // Count the occurrences of each bit
    for (int i = 0; i < n; ++i) {
        ++count[(A[i] >> k) & 1];
    }

    // Calculate cumulative counts
    for (int i = 1; i < 2; ++i) {
        count[i] += count[i - 1];
    }

    // Place the elements in sorted order
    for (int i = n - 1; i >= 0; --i) {
        output[count[(A[i] >> k) & 1] - 1] = A[i];
        --count[(A[i] >> k) & 1];
    }

    // Copy sorted elements back to the original array
    for (int i = 0; i < n; ++i) {
        A[i] = output[i];
    }
}

void radixSort(vector<unsigned char> &A) {
    for (int k = 0; k < 8; ++k) {
        countingSort(A, A.size(), k);
    }
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

    radixSort(A);

    return 0;
}
