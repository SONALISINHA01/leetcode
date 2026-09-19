/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr || head->next ==nullptr)return 0;
        ListNode* hare= head;
        ListNode* turtoise = head;
        while(hare != nullptr && turtoise !=nullptr){
            turtoise= turtoise->next;
            hare = hare->next;
            if(hare){
                hare=hare->next;
            }else{
                return 0;
            }
            if(hare==turtoise){
                turtoise = head;
                while(turtoise!=hare){
                    turtoise=turtoise->next;
                    hare=hare->next;
                }
                return hare;
            }
        }
        return 0;
    }
};