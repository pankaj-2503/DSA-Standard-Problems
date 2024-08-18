class Solution {
public:
// TC-> O(N*M*logK + K*logK) , space complexity - O(K+K+k)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int>pq;
        int n=lists.size();
        for(int i=0;i<n;i++){
            ListNode*cur=lists[i];
            while(cur!=NULL){
                pq.push(cur->val);
                cur=cur->next;
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        // for(auto i:ans){
        //     cout<<i<<' ';
        // }
        int i=0;
        ListNode*dummy=new ListNode(-1);
        
        ListNode*temp=dummy;
        while(i<ans.size()){
            temp->next=new ListNode(ans[i]);
            temp=temp->next;
            i++;
        }
        return dummy->next;

        
    }
};