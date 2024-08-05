// Brute Force -> TC: O(N^2) , SC: O(N)
class Solution {
public:
    int diameter=0;
    int calculateHeight(TreeNode*root){
        if(root==NULL) return 0;
        int leftH=calculateHeight(root->left);
        int rightH=calculateHeight(root->right);

        diameter=max(diameter,leftH+rightH);
        return 1+max(leftH,rightH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        calculateHeight(root);
        return diameter;
    }
};