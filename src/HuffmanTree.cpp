#include "HuffmanTree.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq) {
        left = right = nullptr;
        this->ch = ch;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return (l->freq > r->freq);
    }
};

void printCodes(Node* root, string str) {
    if (!root)
        return;

    if (root->ch != '$')
        cout << root->ch << ": " << str << "\n";

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void buildHuffmanTree(string S, vector<int> freq) {
    Node *left, *right, *top;
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    for (int i = 0; i < S.size(); ++i)
        minHeap.push(new Node(S[i], freq[i]));

    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    printCodes(minHeap.top(), "");
}
