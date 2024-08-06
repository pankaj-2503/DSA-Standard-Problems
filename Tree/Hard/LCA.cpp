class Solution {
public:
    // TC,SC-> O(N)
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p==root || q==root || root==NULL) return root;

        TreeNode* left=lowestCommonAncestor(root->left,p,q);
        TreeNode* right=lowestCommonAncestor(root->right,p,q);
        if(left==NULL) return right;
        else if(right==NULL) return left;
        return root;

    }
};