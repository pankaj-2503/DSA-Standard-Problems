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
// TC: O(N*log(2N)*log(2N)*log(2N))-> bfs+multiset operation+map accessing x and y , SC: O(N+N/2)-> map+maximum level in bfs 
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>m; // map to stores node based on vertical and horizontal level

        queue<pair<TreeNode*,pair<int,int>>>q; // bfs traversal for each node with vertical and level
        q.push({root,{0,0}});
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            TreeNode*temp=front.first;
            int x=front.second.first;
            int y=front.second.second;
            // insert node value to corresponding horizontal and vertical level
            m[x][y].insert(temp->val);

            if(temp->left){
                q.push({temp->left,{x-1,y+1}});
            }
            if(temp->right){
                q.push({temp->right,{x+1,y+1}});

            }
        }
        vector<vector<int>>ans;
        for(auto i:m){
            vector<int>col;
            for(auto j:i.second){
                col.insert(col.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};