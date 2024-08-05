// TC: O(N) , SC: O(N/2+N/2)
vector<int> topView(Node *root)
    {
       
      vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        // Map to store the top view nodes
        // based on their vertical positions
        map<int, int> mpp;
        
        // Queue for BFS traversal, each element
        // is a pair containing node 
        // and its vertical position
        queue<pair<Node*, int>> q;
        
        
        q.push({root, 0});
        
        // BFS traversal
        while(!q.empty()){
           
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            
         
            if(mpp.find(line) == mpp.end()){
                mpp[line] = node->data;
            }
            
            // Process left child
            if(node->left != NULL){
               q.push({node->left, line - 1});
            }
            
            // Process right child
            if(node->right != NULL){
                q.push({node->right, line + 1});
            }
        }
        
      
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        
        return ans;
    }