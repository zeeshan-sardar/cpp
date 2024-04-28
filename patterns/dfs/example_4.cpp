// Given a binary tree and a number sequence, 
// find if the sequence is present as a root-to-leaf path in the given tree.

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
class PathSeq{
    public:
    bool path_seq(Node* head, vector<int> seq)
    {
        return find_path_with_seq(head, seq, 0);
    }
    private:
    bool find_path_with_seq(Node* head, vector<int> seq, int seq_idx)
    {
        if(head == nullptr || seq[seq_idx] != head->data)
            return false;
        if(head->left == nullptr && head->right == nullptr && seq[seq_idx] == head->data)
        {
            return true;
        }
        return find_path_with_seq(head->left, seq, seq_idx+1) || find_path_with_seq(head->right, seq, seq_idx+1);
    }
};
int main()
{
    Node* head = create_node(1);
    head->left = create_node(7);
    head->right = create_node(9);
    head->right->left = create_node(6);
    head->right->right = create_node(9);

    PathSeq ps;
    vector<int> seq = {1,9,9};
    cout<<"Result: "<<ps.path_seq(head, seq)<<endl;
}