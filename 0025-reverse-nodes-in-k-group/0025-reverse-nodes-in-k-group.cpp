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
        ListNode* ptr=head;
        vector<int> arr;
        while(ptr!=nullptr){
            arr.push_back(ptr->val);
            ptr=ptr->next;
        }
        ListNode* ans=nullptr;
        ListNode* he=nullptr;
        int n = arr.size()/k;
        for(int i =0;i<n*k;i+=k){
            for(int j = i+k-1;j>=i;j--){
                ListNode* temp = new ListNode(arr[j]);
                if(he==nullptr){
                    ans=temp;
                    he= ans;
                }else{
                    ans->next=temp;
                    ans= ans->next;
                }
            }
        }
        for(int i =n*k;i<arr.size();i++){
            ListNode* temp = new ListNode(arr[i]);
            if(he==nullptr){
                ans=temp;
                he = ans;
            }else{
                ans->next=temp;
                ans= ans->next;
            }
        }
        return he; 

    }
};