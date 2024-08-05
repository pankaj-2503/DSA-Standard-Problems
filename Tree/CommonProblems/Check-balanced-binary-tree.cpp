// Brute force approach
// TC : O(N^2) , SC:O(N)

class Solution {
public:
    int height(TreeNode*root){
        if(root==NULL) return 0;
        int lh=height(root->left);
       
        int rh=height(root->right);
        return max(lh,rh)+1;

    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int lh=height(root->left);
        int rh=height(root->right);
        if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right)) return true;
        return false;
    }
};

// Optimised approach
//  TC: O(N)
class Solution {
public:
    int height(TreeNode*root){
        if(root==NULL) return 0;
        int lh=height(root->left);
        if(lh==-1) return -1;
        int rh=height(root->right);
        if(rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        return max(lh,rh)+1;

    }
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
    }
};