/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 #define ll long long
class Solution {
    // TC: O(N) , SC: O(N)
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
       
       // we are storing index as 0,1,2,...n-1 to left and right child while level order traversal
       //then calculating width as last index-first index+1
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});
        ll mx=0;
        while(!q.empty()){
            int sz=q.size();
            int mn=q.front().second;
            ll first,last;
            for(int i=0;i<sz;i++){
               ll cur=q.front().second-mn;
               TreeNode*node=q.front().first;
               q.pop();

               if(i==0){
                first=cur;
               }
               if(i==sz-1){
                last=cur;
               }
               if(node->left) q.push({node->left,2*cur+1});
               if(node->right) q.push({node->right,2*cur+2});
            mx=max(mx,last-first+1);
            }
        }
        return mx;
    }
};