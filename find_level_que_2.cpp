#include<bits/stdc++.h>
#include <queue>
#include <map>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void findLevels(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    map<Node*, int> levelMap;
    q.push(root);
    levelMap[root] = 0;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        int level = levelMap[curr];
        cout << "Node " << curr->data << " is at level " << level << endl;

        if (curr->left != NULL) {
            q.push(curr->left);
            levelMap[curr->left] = level + 1;
        }

        if (curr->right != NULL) {
            q.push(curr->right);
            levelMap[curr->right] = level + 1;
        }
    }
}
Node* createTree() {
    int data;
    cout << "Enter root node data: ";
    cin >> data;
    Node* root = new Node(data);
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        int leftData, rightData;
        cout << "Enter left child of " << curr->data << " (-1 if none): ";
        cin >> leftData;
        if (leftData != -1) {
            curr->left = new Node(leftData);
            q.push(curr->left);
        }
        cout << "Enter right child of " << curr->data << " (-1 if none): ";
        cin >> rightData;
        if (rightData != -1) {
            curr->right = new Node(rightData);
            q.push(curr->right);
        }
    }
    return root;
}
int main() {
    Node* root = createTree();
    findLevels(root);
    return 0;
}
