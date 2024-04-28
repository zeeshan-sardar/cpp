// Given a binary tree where each node can only have a digit (0-9) value, 
// each root-to-leaf path will represent a number. 
// Find the total sum of all the numbers represented by all paths.

#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
};

Node* create_node(int data)
{
    Node* p = new Node();
    p->data = data;
    p->left = p->right = nullptr;
    return p;
}
class PathSum{
    public:
    int sum_of_paths(Node* head)
    {
        find_path_sum(head, 0);
    }
    private:
    int find_path_sum(Node* head, int path_sum)
    {
        if(head == nullptr)
            return 0;
        if(head->left == nullptr && head->right == nullptr)
        {
            path_sum = 10*path_sum + head->data;
            return path_sum;
        }
        else
            path_sum = 10*path_sum + head->data;

        return find_path_sum(head->left, path_sum)+find_path_sum(head->right, path_sum);
        // return stoi(num)+find_path_sum(head->right);


    }
};
int main()
{
    Node* head = create_node(1);
    head->left = create_node(0);
    head->left->left = create_node(1);
    head->right = create_node(1);
    head->right->left = create_node(6);
    head->right->right = create_node(5);

    PathSum ps;
    int result = ps.sum_of_paths(head);
    cout<<"Result: "<<result<<endl;
}