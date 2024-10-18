class Solution {
public:
    // Brute Force : TC->O(N*M)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headB){
            ListNode*temp=headA;
            while(temp){
                if(temp==headB) return headB;
                temp=temp->next;
            }
            headB=headB->next;
        }
        return NULL;
    }
};

// Using set : TC->O(N+M) as unordered set takes O(1) average time
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*>s;
        while(headA){
            s.insert(headA);
            headA=headA->next;
        }
        while(headB){
            if(s.find(headB)!=s.end()) return headB;
            headB=headB->next;
        }
        return NULL;
    }

    // using 2 pointers : TC->O(N)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode*ptr1=headA;
        ListNode*ptr2=headB;
        while(ptr1!=ptr2){
            ptr1=ptr1==NULL?headB:ptr1->next;
            ptr2=ptr2==NULL?headA:ptr2->next;
        }
        return ptr1;
    }