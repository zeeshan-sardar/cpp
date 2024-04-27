#include<iostream>
#include<vector>
using namespace std;

int recursive_sum(int m,int n)
{
    if(m==n)
        return m;
    return m+recursive_sum(m+1,n);
}

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        data = x;
        left = right = NULL;
    }
    
};

class TreePathSum{
    public:
    static bool hasPath(TreeNode* p, int sum)
    {
        if(p==NULL)
            return false;

        if(p->left == NULL && p->right == NULL && p->data == sum)
        {
            return true;
        }
            
        return hasPath(p->left, sum - p->data) || hasPath(p->right, sum - p->data);
    }
};

class TreeAllPathSum{

    TreeAllPathSum()
    {
        count = 0;
    }
    public:
    static vector<int> path;
    static int count;
    
    static int hasPath(TreeNode* p, int sum)
    {
        path.push_back(p->data);
        if(p==NULL)
            return 0;

        if(p->left == NULL && p->right == NULL && p->data == sum)
        {
            return 1;
        }
        
        path.pop_back();
        return hasPath(p->left, sum - p->data) + hasPath(p->right, sum - p->data);
    }
};
int TreeAllPathSum::count = 0;
vector<int> TreeAllPathSum::path ;

int main()
{
    int m = 4, n = 6;
    cout<<recursive_sum(m,n)<<endl;

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(7);

    cout<<"Has Path: "<<TreeAllPathSum::hasPath(root, 12)<<endl;

    TreeAllPathSum* tree_paths;

    for(auto p:tree_paths->path)
    {
        cout<<p<<"->";
    }

}