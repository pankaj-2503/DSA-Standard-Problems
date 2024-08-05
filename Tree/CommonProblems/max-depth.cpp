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
class Solution {
public:
// TC: O(n) , SC:O(n)
    int maxDepth(TreeNode* root) {
        int curlevel=0;
        if(root==NULL) return curlevel;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){f
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode*node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            curlevel++;
        }
        return curlevel;
    }
};

// using recursion
int maxDepth(TreeNode* root) {
        
        if(root==NULL) return 0;
        int lh=maxDepth(root->left);
        int rh=maxDepth(root->right);
        return 1+max(lh,rh);
    }