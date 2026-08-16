class Solution {
public:
// TC : O(N) , SC: O(N)
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;

        // we are doing levelOrder traversal and storing result then pushing each level right most element to ans
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>levelOrder;
        while(!q.empty()){
            int sz=q.size();
            vector<int>temp;
            for(int i=0;i<sz;i++){
                TreeNode*node=q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            levelOrder.push_back(temp);
        }
        for(auto i:levelOrder){
            ans.push_back(i.back());
        }
        return ans;
    }
};


// Optimised approach using Bfs
vector<int> rightSideView(TreeNode* root) {
    if (!root) return {};
    vector<int> ans;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            TreeNode* node = q.front();
            q.pop();

            // If it's the last element of the current level, add it to ans
            if (i == sz - 1) ans.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return ans;
}


// Using DFS

class Solution {
public:
    void solve(TreeNode* root, int level, vector<int>& ans) {
        if (!root) return;

        // If this is the first time we've reached this level,
        // the current node is the rightmost one.
        if (level == ans.size()) {
            ans.push_back(root->val);
        }

        // Prioritize Right child first!
        solve(root->right, level + 1, ans);
        solve(root->left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, 0, ans);
        return ans;
    }
};