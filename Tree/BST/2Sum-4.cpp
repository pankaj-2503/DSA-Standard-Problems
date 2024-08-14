class Solution {
public:
// TC: O(N) , SC:O(n)
    unordered_map<int,int>m;
    bool ans=false;
    void inorder(TreeNode*root,int k){
        if(root==NULL) return;
        inorder(root->left,k);
        if(m.find(k-root->val)!=m.end()){
            ans=true;
        }
        m[root->val]++;
        inorder(root->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return NULL;
        inorder(root,k);
        return ans;
    }
};