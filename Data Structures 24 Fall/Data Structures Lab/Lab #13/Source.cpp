#include <iostream>
using namespace std;

const int MAX_N = 100000; // Maximum number of keys
const int MAX_C = 100;    // Maximum number of colors

struct BTreeNode {
    int keys[MAX_C];       // Keys in the node
    int children[MAX_C];   // Indices of child nodes
    int numKeys;           // Number of keys in this node
    bool isLeaf;           // Is this a leaf node
};

BTreeNode nodes[MAX_N]; // Array to store all nodes
int colors[MAX_N + 1];  // Colors of keys
int parent[MAX_N + 1];  // Parent of each node
int result[MAX_N + 1];  // Result array to store closest ancestors
int lastOccurrence[MAX_C + 1]; // Last occurrence of each color

void initializeNodes(int n) {
    for (int i = 1; i <= n; ++i) {
        nodes[i].numKeys = 0;
        nodes[i].isLeaf = true;
    }
    for (int i = 1; i <= MAX_C; ++i) {
        lastOccurrence[i] = -1; // Initialize last occurrence to -1
    }
}

void constructBTree(int n) {
    for (int i = 2; i <= n; ++i) { // Start from 2 as root has no parent
        int parentIndex = parent[i];
        nodes[parentIndex].children[nodes[parentIndex].numKeys] = i; // Add child
        nodes[parentIndex].numKeys++;
        nodes[parentIndex].isLeaf = false; // Parent node is not a leaf
    }
}

void findClosestAncestor(int nodeIndex) {
    int color = colors[nodeIndex];

    // Find the closest ancestor with the same color
    if (lastOccurrence[color] != -1) {
        result[nodeIndex] = lastOccurrence[color];
    }
    else {
        result[nodeIndex] = 1; // Default to root index
    }

    // Update the last occurrence of this color
    lastOccurrence[color] = nodeIndex;

    // Recursively visit all children
    for (int i = 0; i < nodes[nodeIndex].numKeys; ++i) {
        findClosestAncestor(nodes[nodeIndex].children[i]);
    }

    // Backtrack: Restore the state for other branches
    lastOccurrence[color] = -1;
}

int main() {
    int n, c, t;
    cin >> n >> c >> t;

    initializeNodes(n);

    // Input the parent array
    for (int i = 1; i <= n; ++i) {
        cin >> parent[i];
    }

    // Input the colors array
    for (int i = 1; i <= n; ++i) {
        cin >> colors[i];
    }

    // Construct the B-Tree
    constructBTree(n);

    // Start from the root (index 1)
    findClosestAncestor(1);

    // Output the results
    for (int i = 1; i <= n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
