#include <iostream>
using namespace std;

// Node structure for Binary Tree
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Recursive function to calculate height of a tree using DFS
int getHeight(Node* node) {
    if (node == NULL)
        return -1; // or return 0 if you prefer height in terms of number of nodes

    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);

    return 1 + max(leftHeight, rightHeight);
}

int main() {
    /*
          10
         /  \
       20    30
         \
         40
    */

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->right = new Node(40);

    int leftSubtreeHeight = getHeight(root->left);
    int rightSubtreeHeight = getHeight(root->right);

    cout << "Left Subtree Height: " << leftSubtreeHeight << endl;
    cout << "Right Subtree Height: " << rightSubtreeHeight << endl;

    return 0;
}
