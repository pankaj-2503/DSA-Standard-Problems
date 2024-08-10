// Tc: O(logn) , SC:O(1)
TreeNode* searchBST(TreeNode* root, int val) {
      while(root != NULL && root->val != val){
            root = val < root->val ? root->left : root->right;
        }
        
        return root;
    }