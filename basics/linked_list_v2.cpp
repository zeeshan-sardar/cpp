#include<iostream>

using namespace std;


class Node
{
    public:
    int data;
    Node* next;
    // Node(int x)
    // {
    //     data = x;
    //     next = nullptr;
    // }
};

Node* createNode(int data)
{
    Node* node = new Node();
    node->data = data;
    node->next = nullptr;
    return node;
}
void insertAtStart(Node** head, int val)
{
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node** head, int val)
{
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = nullptr;
    // Node* temp = new Node();
    Node* temp = *head;    
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    // *head = temp;
}

void insertAtPosition(Node** head, int val, int pos)
{
    Node* temp = *head;
    Node* newNode = createNode(val);
    for(int i=1; i<pos-1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    
}

void deleteAtStart(Node** head)
{
    (*head) = (*head)->next;
}
void deleteAtEnd(Node** head)
{
    Node* temp = new Node();
    temp = *head;
    while(temp->next->next!=nullptr)
    {
        temp = temp->next;
    }
    temp->next = nullptr;
}
void deleteAtPosition(Node** head, int pos)
{
    Node* temp = new Node();
    temp = *head;
    for(int i=1; i<pos-1; i++)
    {
        temp = temp->next;
    }
    temp->next = temp->next->next;
}

Node* mergeTwo(Node* list1, Node* list2) {
        
    Node* temp = list1;

    while(list1->next != nullptr)
    {
        list1 = list1->next;
    }
    list1->next = list2;
    list1 = temp;
    return list1;
}

void sortNode(Node** head)
{
    Node* temp = *head;
    while(temp->next->next != nullptr)
    {
        if(temp->data > temp->next->data)
        {
            int t = temp->data;
            temp->data = temp->next->data;
            temp->next->data = t;
        }
        temp = temp->next;

    }
    // head = temp;
}
void printList(Node* p)
{
    while(p != nullptr)
    {
        cout<<p->data<<endl;
        p = p->next;
    }
}

Node* sortList(Node* p)
{
    while(p!= nullptr)
    {
        
    }
    return p;
}
int main()
{
    Node* head = createNode(2);
    Node* second = createNode(3);
    Node* third = createNode(4);
    Node* fourth = createNode(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;

    // printList(head);
    // insertAtStart(&head, 1);
    // printList(head);

    // cout<<"Deleteing..."<<endl<<endl;
    // deleteAtStart(&head);
    // printList(head);
    // deleteAtEnd(&head);
    // printList(head);
    // deleteAtPosition(&head, 2);
    // printList(head);

    cout<<"Merging..."<<endl<<endl;

    Node* head2 = createNode(2);
    Node* second2 = createNode(3);
    Node* third2 = createNode(4);
    Node* fourth2 = createNode(5);    
    head2->next = second2;
    second2->next = third2;
    third2->next = fourth2;
    fourth2->next = nullptr;
    printList(head);
    cout<<"Sorting..."<<endl<<endl;
    head = mergeTwo(head, head2);
    sortNode(& head);
    printList(head);




}