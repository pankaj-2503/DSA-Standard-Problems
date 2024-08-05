class Solution {
public:
// TC: O(N) , SC: O(N)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};

        vector<vector<int>>ans;

        queue<TreeNode*>q;
        q.push(root);
        bool leftToRight=true;

        while(!q.empty()){
            int size=q.size();
            vector<int>row(size);

            for(int i=0;i<size;i++){
                TreeNode*temp=q.front();
                q.pop();
                int index=leftToRight?i:size-i-1;
                row[index]=temp->val;

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            leftToRight=!leftToRight;
            ans.push_back(row);
        }
        return ans;
    }
};