class Solution {
public:
    // Morris inorder traversal
    // TC: O(N) , SC: O(1)
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode*cur,*pre;
        vector<int>ans;
        cur=root;
        if(root==NULL) return {};
        while(cur!=NULL){
            if(cur->left==NULL){
                ans.push_back(cur->val);
                cur=cur->right;
            }
            else{
                // find inorder predecessor
                pre=cur->left;
                while(pre->right!=NULL && pre->right!=cur) pre=pre->right;
                // connect to current node and move cur to left
                if(pre->right==NULL){
                    pre->right=cur;
                    cur=cur->left;
                }
                

                // revert change made in if part 
                else{
                    pre->right=NULL;
                    ans.push_back(cur->val);
                    cur=cur->right;

                }
            }
        }

        return ans;
    }
};