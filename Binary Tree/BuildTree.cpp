#include <bits/stdc++.h>
using namespace std;

// A Node consists of: left pointer, value, and right pointer
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

    // Utility function to print inorder traversal (for testing)
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Public method to trigger traversal
    void printInorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    Tree t1;
    string str;
    getline(cin, str);  // e.g., "10 20 30 N 40 N N"

    t1.BuildTree(str);

    cout << "Inorder Traversal: ";
    t1.printInorder();

    return 0;
}
