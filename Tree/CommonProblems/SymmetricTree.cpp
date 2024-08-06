// TC: O(N) , SC: O(1)
class Solution {
public:
    bool checkSymmetry(TreeNode*root1,TreeNode*root2){
        if(root1==NULL || root2==NULL){
            return root1==root2;
        }
        return root1->val==root2->val && checkSymmetry(root1->left,root2->right) && checkSymmetry(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return checkSymmetry(root->left,root->right);
    }
};