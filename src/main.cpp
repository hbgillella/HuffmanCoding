#include "HuffmanTree.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string S;
    int N;

    cout << "Enter the string of distinct characters: ";
    cin >> S;

    N = S.size();
    vector<int> freq(N);

    cout << "Enter the frequencies of the characters: ";
    for (int i = 0; i < N; ++i) {
        cin >> freq[i];
    }

    buildHuffmanTree(S, freq);

    return 0;
}
