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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* prev = dummy;
        ListNode* temp = head;
        int a=0;
        while(temp != nullptr){
            temp= temp->next;
            a++;
        }
        if(a%2==0){
            a=a/2;
            a++;
        }else{
            a=a/2;
            a++;
        }int i=1;
        ListNode* temp1 = head;
        while(i!=a){
            temp1 = temp1->next;
            prev = prev->next;
            i++;
        }
        prev->next = temp1->next;
        temp1= temp1->next;
        head = dummy->next;
        delete dummy;
        return head;
    }
};