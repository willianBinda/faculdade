#include <iostream>
#include <iomanip>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    void insert(int data) {
        Node* newNode = new Node(data);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* current = root;
        while (true) {
            if (data < current->data) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == nullptr) {
                    current->right = newNode;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }

    bool search(int data) {
        Node* current = root;
        while (current != nullptr) {
            if (current->data == data) {
                return true;
            } else if (data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }

    void inorderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        inorderTraversal(node->left);
        cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void preorderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        cout << node->data << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void postorderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->data << " ";
    }

    
};


int main() {
    BinaryTree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(7);
    tree.insert(3);

    cout << "Inorder traversal: ";
    tree.inorderTraversal(tree.root);
    cout << endl;

    cout << "Preorder traversal: ";
    tree.preorderTraversal(tree.root);
    cout << endl;

    cout << "Postorder traversal: ";
    tree.postorderTraversal(tree.root);
    cout << endl;

    if (tree.search(15)) {
        cout << "15 is found in the tree." << endl;
    } else {
        cout << "15 is not found in the tree." << endl;
    }

    if (tree.search(8)) {
        cout << "8 is found in the tree." << endl;
    } else {
        cout << "8 is not found in the tree." << endl;
    }
    // printTree(tree.root);

    return 0;
}