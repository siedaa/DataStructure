#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Tree {
public:
    Node* buildCompleteTree(int arr[], int n) {
        if (n == 0) return NULL;

        Node* root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);

        int i = 1;
        while (i < n) {
            Node* curr = q.front();
            q.pop();

            // Left child
            if (i < n) {
                curr->left = new Node(arr[i++]);
                q.push(curr->left);
            }

            // Right child
            if (i < n) {
                curr->right = new Node(arr[i++]);
                q.push(curr->right);
            }
        }
        return root;
    }

    // Display Preorder traversal
    void displayPreorder(Node* root) {
        if (root == NULL) return;
        cout << root->data << " ";
        displayPreorder(root->left);
        displayPreorder(root->right);
    }

    // Helper to compute subtree sums
    int findSubtree(Node* root, int target, Node*& foundRoot, bool &found) {
        if (root == NULL) return 0;

        int leftSum = findSubtree(root->left, target, foundRoot, found);
        int rightSum = findSubtree(root->right, target, foundRoot, found);

        int total = root->data + leftSum + rightSum;

        if (total == target && !found) {
            found = true;
            foundRoot = root;
        }

        return total;
    }

    // Wrapper to search and display
    void findAndDisplaySubtree(Node* root, int target) {
        Node* foundRoot = NULL;
        bool found = false;
        findSubtree(root, target, foundRoot, found);

        if (found) {
            cout << " Subtree found with sum = " << target << endl;
            cout << "Subtree (Preorder): ";
            displayPreorder(foundRoot);
            cout << endl;
        } else {
            cout << " No subtree found with sum = " << target << endl;
        }
    }
};

int main() {
    Tree t;
    int n;
    cout << "Enter number of sections (nodes): ";
    cin >> n;

    int arr[100];
    cout << "Enter quantities for each section: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Node* root = t.buildCompleteTree(arr, n);

    cout << "\nWarehouse Tree (Preorder): ";
    t.displayPreorder(root);
    cout << endl;

    int target;
    cout << "\nEnter target quantity sum: ";
    cin >> target;

    t.findAndDisplaySubtree(root, target);

    return 0;
}
