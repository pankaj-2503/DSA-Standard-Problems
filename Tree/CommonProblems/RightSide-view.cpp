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