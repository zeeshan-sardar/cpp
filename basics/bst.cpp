#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data)
{
    Node* newNode;
    newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

int main()
{
    Node* root;
    root = createNode(1);
    root->left = createNode(2);
    root->left->left = createNode(3);
    root->right = createNode(5);

    cout<<root->data<<" "<<root->left->data<<endl;
}