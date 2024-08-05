// TC: O(N) , SC: O(N/2+N/2)-> maximum width stored in map + max width traversal in bfs
vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int>ans;
        if(root==NULL) return ans;
        map<int,int>m;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            
            Node*temp=top.first;
            int x=top.second;
            
            m[x]=temp->data;
            if(temp->left){
                q.push({temp->left,x-1});
            }
            if(temp->right){
                q.push({temp->right,x+1});
            }
        }
        
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
        
    }