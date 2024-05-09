#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
};

ListNode* createNode(int val)
{
    ListNode* head = new ListNode();
    head->val = val;
    head->next = nullptr;

    return head;
}

void printList(ListNode* head)
{
    while(head!=nullptr)
    {
        cout<<head->val<<endl;
        head=head->next;
    }
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(!list1)
            return list2;
        if(!list2)
            return list1;

        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                curr->next = list1;
                list1 = list1->next;
            }
            else
            {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        if(list1)
            curr->next = list1;
        if(list2)
            curr->next = list2;
        return dummy->next;
    }
};

int main()
{
    ListNode * list1;
    list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(4);
    // printList(list1);

    ListNode * list2;
    list2 = createNode(1);
    list2->next = createNode(3);
    list2->next->next = createNode(4);
    // printList(list2);

    Solution sol;

    printList(sol.mergeTwoLists(list1, list2));


}