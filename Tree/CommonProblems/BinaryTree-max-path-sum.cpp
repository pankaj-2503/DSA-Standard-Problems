class Solution {
public:
// TC: O(N) , SC:O(N)
    int findsum(TreeNode*root,int &mx){
        if(root==NULL) return 0;

        int leftsum=max(0,findsum(root->left,mx));
        int rightsum=max(0,findsum(root->right,mx));
        mx=max(mx,leftsum+rightsum+root->val);
        return max(leftsum,rightsum)+root->val;

    }
    int maxPathSum(TreeNode* root) {
        int mx=INT_MIN;
        findsum(root,mx);
        return mx;
    }
};