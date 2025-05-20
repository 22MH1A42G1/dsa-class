#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Tree {
private:
    Node* root;

public:
    Tree() : root(nullptr) {}

    // Build tree from space-separated level-order string ("N" = null)
    void buildTree(const string& s) {
        if (s.empty() || s[0] == 'N') return;

        vector<string> vals;
        stringstream ss(s);
        string word;
        while (ss >> word) vals.push_back(word);

        root = new Node(stoi(vals[0]));
        queue<Node*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < (int)vals.size()) {
            Node* curr = q.front(); q.pop();

            // left child
            if (vals[i] != "N") {
                curr->left = new Node(stoi(vals[i]));
                q.push(curr->left);
            }
            i++;

            // right child
            if (i < (int)vals.size() && vals[i] != "N") {
                curr->right = new Node(stoi(vals[i]));
                q.push(curr->right);
            }
            i++;
        }
    }

    // BFS / Level-order traversal
    void bfs() const {
        if (!root) {
            cout << "Tree is empty.\n";
            return;
        }

        queue<Node*> q;
        q.push(root);
        cout << "Level-order Traversal: ";

        while (!q.empty()) {
            Node* curr = q.front(); q.pop();
            cout << curr->data << " ";
            if (curr->left)  q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << "\n";
    }
};

int main() {
    Tree tree;
    cout << "Enter tree (level order, space-separated; use 'N' for null):\n";
    string input;
    getline(cin, input);

    tree.buildTree(input);
    tree.bfs();

    return 0;
}
