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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>cp;
        ListNode*prev=head;
        ListNode*curr=head->next;
        int idx=2;
        while(curr->next!=NULL)
        {
            if((curr->val>prev->val && curr->val>curr->next->val)|| (curr->val<prev->val && curr->val<curr->next->val))
            cp.push_back(idx);
            prev=curr;
            curr=curr->next;
            idx++;
        }
        if(cp.size()<2)
        return {-1,-1};
        sort(cp.begin(),cp.end());
        int n=cp.size();
        //int miniD=cp[n-1]-cp[n-2];
        int miniD=INT_MAX;
        for(int i=1;i<n;i++)
        miniD=min(miniD,cp[i]-cp[i-1]);
        int maxiD=cp[n-1]-cp[0];
        return {miniD,maxiD};
    }
};