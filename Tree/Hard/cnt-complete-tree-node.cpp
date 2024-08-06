class Solution {
public:
    int cnt=0;
    void helper(TreeNode*root){
        if(root==NULL) return;
        cnt++;
        helper(root->left);
        helper(root->right);
    }

    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
       
        helper(root);
        return cnt;
    }
};