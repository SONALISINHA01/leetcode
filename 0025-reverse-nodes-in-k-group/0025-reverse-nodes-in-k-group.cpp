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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> an;
        while(head!=nullptr){
            an.push_back(head->val);
            head=head->next;
        }
        int n = an.size();
        n = n/k;
        ListNode* ans;
        ListNode* ret =ans;
        for(int i=0;i<n;i++){
            for(int j =i*k+k-1;j>=i*k;j--){
                ListNode* temp= new ListNode(an[j]);
                if(ret == nullptr){
                    ret = ans= temp;
                }else{
                    ans->next=temp;
                    ans=ans->next;
                }
            }
        }
        for(int i=n*k;i<an.size();i++){
            ListNode* temp= new ListNode(an[i]);
            if(ret == nullptr){
                ret = ans= temp;
            }else{
                ans->next=temp;
                ans=ans->next;
            }
        }
        return ret;
    }
};