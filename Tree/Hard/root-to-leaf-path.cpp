 // TC: O(N) , SC: O(N)
   void helper(Node*root,vector<vector<int>>&ans,vector<int>&temp){
       if(root==NULL) return ;
       temp.push_back(root->data);
       if(!root->left && !root->right){
           ans.push_back(temp);
       }
       
       //move left and right recursively
       helper(root->left,ans,temp);
       helper(root->right,ans,temp);
       
       // backtrack if all call are done
       temp.pop_back();
   }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>ans;
        vector<int>temp;
        helper(root,ans,temp);
        return ans;
    }