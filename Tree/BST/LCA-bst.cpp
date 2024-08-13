class Solution {
public:
// TC: O(H) , SC:O(H)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        int cur=root->val;
        if(cur>p->val && cur>q->val) return lowestCommonAncestor(root->left,p,q);
        if(cur<p->val && cur<q->val) return lowestCommonAncestor(root->right,p,q);

        return root;
    }
};


class Solution {
public:
// TC: O(H) , SC:O(1)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int small=min(p->val,q->val);
        int large=max(p->val,q->val);
        
        while(root){
            if(root->val>large) root=root->left;
            else if(root->val<small) root=root->right;
            else return root;
        }
       return NULL;
    }
};