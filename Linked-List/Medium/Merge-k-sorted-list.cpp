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


// Brute force -> tc -> O(nlogn) , sc ->O(n)


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> nodes;
        for (auto l : lists) {
            while (l) {
                nodes.push_back(l->val);
                l = l->next;
            }
        }
        sort(nodes.begin(), nodes.end());

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        for (int x : nodes) {
            curr->next = new ListNode(x);
            curr = curr->next;
        }
        return dummy->next;
    }
};



// Tc -> O(Nlogk + klogk) , Sc -> O(k)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0) return NULL;

        ListNode*dummy= new ListNode(0);
        ListNode*temp=dummy;

        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(auto &head:lists){
            if(head!=NULL) pq.push({head->val,head});
        }

        while(!pq.empty()){
            ListNode*top=pq.top().second;
            pq.pop();

            if(top->next) pq.push({top->next->val,top->next});
            temp->next=top;
            temp=temp->next;
        }
        return dummy->next;


    }
};



// Tc -> O(k*n) , SC -> O(1)
class Solution {
public:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val <= l2->val) {
            l1->next = merge2Lists(l1->next, l2);
            return l1;
        } else {
            l2->next = merge2Lists(l1, l2->next);
            return l2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        ListNode* res = nullptr;
        for (auto l : lists) {
            res = merge2Lists(res, l);
        }
        return res;
    }
};


