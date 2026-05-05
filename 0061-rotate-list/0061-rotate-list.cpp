/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int linklistSize(ListNode* h){
        int  i=0;
        while(h){
            h=h->next;
            i++;
        }
        return i;
    }
    ListNode* reverse(ListNode* h){
        ListNode* t=h;
        ListNode* prev=nullptr;
        while(t->next) {prev=t;t=t->next;}
        prev->next=nullptr;
        t->next=h;
        return t;
    }

    

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr) return head;
        int size=linklistSize(head);
        k=k%size;
        for(int i=0;i<k;i++){
            head=reverse(head);
        }
        return head;

    }
};