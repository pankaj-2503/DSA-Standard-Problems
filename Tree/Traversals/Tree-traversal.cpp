
// Traversal of of 2 types 

// i) BFS : ->Preorder,Postorder,Inorder
// ii) DFS : ->Level Order Traversal


struct TreeNode{
      int data;
      TreeNode*left;
      TreeNode*right;

      TreeNode(int val){
        data=val;
        left=null;
        right=null;
      }
}

// Preorder Traversal
//  TC: O(N), SC: O(N)
class Solution {
public:
    void solve(TreeNode*root,vector<int>&ans){
        if(root==NULL) return ;

        ans.push_back(root->val);
        solve(root->left,ans);
        solve(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        solve(root,ans);
        return ans;
    }
};

// Inorder Traversal
//  TC: O(N), SC: O(N)

class Solution {
public:
    void solve(TreeNode*root,vector<int>&ans){
        if(root==NULL) return;
        solve(root->left,ans);
        ans.push_back(root->val);
        solve(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        solve(root,ans);
        return ans;
    }
};


// Post Order Traversal
//  TC: O(N), SC: O(N)
class Solution {
public:
    void solve(TreeNode*root,vector<int>&ans){
        if(root==NULL) return;
        solve(root->left,ans);
        solve(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        solve(root,ans);
        return ans;
    }
};

// Level Order Traversal
// TC : O(N) , SC:O(N)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return {};

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<int>level;
            
            for(int i=0;i<sz;i++){
                TreeNode*node=q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};


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