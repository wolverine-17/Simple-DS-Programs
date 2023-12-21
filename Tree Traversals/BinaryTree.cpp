#include <iostream>

using namespace std;

// Node class for a binary tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

// Binary Tree class
class BinaryTree
{
private:
    Node *root;

public:
    BinaryTree()
    {
        root = nullptr;
    }

    // Function to perform Inorder Traversal
    void inorderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    // Function to perform Preorder Traversal
    void preorderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            cout << node->data << " ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);
        }
    }

    // Function to perform Postorder Traversal
    void postorderTraversal(Node *node)
    {
        if (node != nullptr)
        {
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout << node->data << " ";
        }
    }

    // Public functions to call traversals
    void inorder()
    {
        cout << "Inorder Traversal: ";
        inorderTraversal(root);
        cout << endl;
    }

    void preorder()
    {
        cout << "Preorder Traversal: ";
        preorderTraversal(root);
        cout << endl;
    }

    void postorder()
    {
        cout << "Postorder Traversal: ";
        postorderTraversal(root);
        cout << endl;
    }

    // Function to insert a node into the binary tree
    Node *insert(Node *node, int value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }

        if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insert(node->right, value);
        }

        return node;
    }

    // Public function to insert a value into the binary tree
    void insert(int value)
    {
        root = insert(root, value);
    }
};

int main()
{
    BinaryTree myTree;

    // Insert nodes into the binary tree
    myTree.insert(50);
    myTree.insert(30);
    myTree.insert(70);
    myTree.insert(20);
    myTree.insert(40);
    myTree.insert(60);
    myTree.insert(80);

    // Perform tree traversals
    myTree.inorder();
    myTree.preorder();
    myTree.postorder();

    return 0;
}
