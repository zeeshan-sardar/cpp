#include<iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

Node* createNode(int data)
{
    Node* head = new Node();
    head->data = data;
    head->next = nullptr;
    return head;
}

int main()
{
    createNode(2)
}