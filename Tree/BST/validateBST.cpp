class Solution {
public:
// tC: O(N) , SC:O(N)
    bool helper(TreeNode*root,long long minval,long long maxval){
        if(root==NULL) return true;
        if(root->val<=minval || root->val>=maxval) return false;

        return helper(root->left,minval,root->val) && helper(root->right,root->val,maxval);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,LONG_MIN,LONG_MAX);
    }
};