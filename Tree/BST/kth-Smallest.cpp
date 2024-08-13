class Solution {
public:
    // TC:O(N) , SC:O(N)
    void inorder(TreeNode*root,vector<int>&v){
        if(root==NULL) return ;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return -1;
        vector<int>v;
        inorder(root,v);
        sort(v.begin(),v.end());
        --k;
        return v[k];
    }
};

class Solution {
public:
    // TC:O(N) , SC:O(1)
    void solve(TreeNode*root,int &cnt,int &ans,int k){
        if(root==NULL) return ;
        solve(root->left,cnt,ans,k);
        cnt++;
        if(cnt==k){
            ans=root->val;
            return;
        }
        solve(root->right,cnt,ans,k);
    }
    int kthSmallest(TreeNode* root, int k) {
       int cnt=0,ans;
       solve(root,cnt,ans,k);
       return ans;
    }
};