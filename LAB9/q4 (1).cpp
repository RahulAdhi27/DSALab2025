#include <iostream>
#include <stack>
using namespace std;

class BST {
    // Structure for a tree node
    struct Node {
        char data;
        Node* left;
        Node* right;
    };
    
    Node* root;

    // Private helper functions
    Node* insert(Node* node, char value);
    void preorder(Node* node);
    void inorder(Node* node);
    void postorder(Node* node);
    Node* search(Node* node, char key);
    Node* constructExpressionTree(string postfix);
    
public:
    BST() { root = nullptr; } // Constructor initializes root to null
    void insert(char value) { root = insert(root, value); }
    void preorder() { preorder(root); cout << endl; }
    void inorder() { inorder(root); cout << endl; }
    void postorder() { postorder(root); cout << endl; }
    bool search(char key) { return search(root, key) != nullptr; }
    void constructTree(string postfix) { root = constructExpressionTree(postfix); }
};

int main() {
    BST tree;
    int choice;
    string expression;
    
    while (true) {
        // Display menu
        cout << "\n1. Postfix Expression\n2. Construct Expression Tree\n3. Preorder\n4. Inorder\n5. Postorder\n6. Exit\nEnter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter a valid postfix expression: ";
                cin >> expression;
                break;
            case 2:
                tree.constructTree(expression);
                break;
            case 3:
                tree.preorder();
                break;
            case 4:
                tree.inorder();
                break;
            case 5:
                tree.postorder();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}

// Function to insert a value into the BST
BST::Node* BST::insert(Node* node, char value) {
    if (!node) {
        node = new Node{value, nullptr, nullptr};
        return node;
    }
    if (value < node->data) node->left = insert(node->left, value);
    else if (value > node->data) node->right = insert(node->right, value);
    return node;
}

// Function to construct an expression tree from postfix expression
BST::Node* BST::constructExpressionTree(string postfix) {
    stack<Node*> st;
    for (char ch : postfix) {
        Node* newNode = new Node{ch, nullptr, nullptr};
        if (isalnum(ch)) {
            st.push(newNode);
        } else {
            newNode->right = st.top(); st.pop();
            newNode->left = st.top(); st.pop();
            st.push(newNode);
        }
    }
    return st.top();
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
BST::Node* BST::search(Node* node, char key) {
    if (!node || node->data == key) return node;
    if (key < node->data) return search(node->left, key);
    return search(node->right, key);
}
