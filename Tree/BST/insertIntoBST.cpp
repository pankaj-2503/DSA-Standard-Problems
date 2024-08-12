
class Solution {
// recursion -> TC: O(N) same sC
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            root=new TreeNode(val);
            return root;
        }
        if(val>root->val){
            root->right=insertIntoBST(root->right,val);
        }
        else if(val<root->val){
            root->left=insertIntoBST(root->left,val);
        }
        return root;

    }
};


// Iterative -> TC: O(N) , SC:O(1)
 TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);

        TreeNode*cur=root;
        while(true){
            if(cur->val<val){
                if(cur->right) cur=cur->right;
                else{
                    cur->right=new TreeNode(val);
                    break;
                }
            }else{
                if(cur->left) cur=cur->left;
                else{
                    cur->left=new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }