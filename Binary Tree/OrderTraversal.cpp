#include <bits/stdc++.h>
using namespace std;

// Node structure: left pointer, value, right pointer
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Tree {
private:
    Node* root;

public:
    Tree() {
        root = NULL;
    }

    // Build Tree from space-separated level order string
    void BuildTree(string str) {
        if (str.empty() || str[0] == 'N') return;

        vector<string> info;
        stringstream ss(str);
        string word;
        while (ss >> word) {
            info.push_back(word);
        }

        int val = stoi(info[0]);
        root = new Node(val);

        queue<Node*> Q;
        Q.push(root);

        int i = 1;
        while (!Q.empty() && i < info.size()) {
            Node* curr = Q.front();
            Q.pop();

            // Left child
            if (i < info.size() && info[i] != "N") {
                val = stoi(info[i]);
                curr->left = new Node(val);
                Q.push(curr->left);
            }
            i++;

            // Right child
            if (i < info.size() && info[i] != "N") {
                val = stoi(info[i]);
                curr->right = new Node(val);
                Q.push(curr->right);
            }
            i++;
        }
    }

    // Inorder Traversal (Left, Root, Right)
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Preorder Traversal (Root, Left, Right)
    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Postorder Traversal (Left, Right, Root)
    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    // Public wrappers
    void printInorder() {
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    void printPreorder() {
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    void printPostorder() {
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << endl;
    }
};

int main() {
    Tree t1;
    string str;
    cout << "Enter tree (level order, space separated): ";
    getline(cin, str); // Example: 10 20 30 N 40 N N

    t1.BuildTree(str);

    t1.printInorder();
    t1.printPreorder();
    t1.printPostorder();

    return 0;
}
