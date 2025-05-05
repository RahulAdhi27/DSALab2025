#include <iostream>
using namespace std;

class BST {
    // Structure for a tree node
    struct Node {
        int data;
        Node* left;
        Node* right;
    };
    
    Node* root;

    // Private helper functions
    Node* insert(Node* node, int value);
    void preorder(Node* node);
    void inorder(Node* node);
    void postorder(Node* node);
    Node* search(Node* node, int key);
    
public:
    BST() { root = nullptr; } // Constructor initializes root to null
    void insert(int value) { root = insert(root, value); }
    void preorder() { preorder(root); cout << endl; }
    void inorder() { inorder(root); cout << endl; }
    void postorder() { postorder(root); cout << endl; }
    bool search(int key) { return search(root, key) != nullptr; }
};

int main() {
    BST tree;
    int choice, value;
    
    while (true) {
        // Display menu
        cout << "\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Exit\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                tree.preorder();
                break;
            case 3:
                tree.inorder();
                break;
            case 4:
                tree.postorder();
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                cout << (tree.search(value) ? "Found" : "Not Found") << endl;
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}

// Function to insert a value into the BST
BST::Node* BST::insert(Node* node, int value) {
    if (!node) {
        node = new Node{value, nullptr, nullptr};
        return node;
    }
    if (value < node->data) node->left = insert(node->left, value);
    else if (value > node->data) node->right = insert(node->right, value);
    return node;
}

// Function to perform preorder traversal
void BST::preorder(Node* node) {
    if (node) {
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

// Function to perform inorder traversal
void BST::inorder(Node* node) {
    if (node) {
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
}

// Function to perform postorder traversal
void BST::postorder(Node* node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
}

// Function to search for a value in the BST
BST::Node* BST::search(Node* node, int key) {
    if (!node || node->data == key) return node;
    if (key < node->data) return search(node->left, key);
    return search(node->right, key);
}
