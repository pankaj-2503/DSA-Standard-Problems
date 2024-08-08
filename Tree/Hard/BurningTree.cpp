// TC: O(2*N) , SC: O(3N)
int findTime(unordered_map<Node*,Node*>&m,Node*target){
        unordered_map<Node*,int>visited;
        queue<Node*>q;
        q.push(target);
        visited[target]=1;
        
        // doing bfs to find time also checking if node is visited or not
        int time=0;
        while(!q.empty()){
            int sz=q.size();
            int flag=0;
            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();
                
                if(node->left && !visited[node->left]){
                    flag=1;
                    visited[node->left]=1;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right]){
                    flag=1;
                    visited[node->right]=1;
                    q.push(node->right);
                }
                if(m[node] && !visited[m[node]]){
                    flag=1;
                    visited[m[node]]=1;
                    q.push(m[node]);
                }
                
            }
            if(flag==1) time++;
        }
        return time;
    }
    Node*bfsToParent(Node*root,unordered_map<Node*,Node*>&m,int target){
        queue<Node*>q;
        q.push(root);
        
        Node*ans;
        while(!q.empty()){
            
            
                Node*front=q.front();
                if(front->data==target) ans=front;
                q.pop();
                if(front->left){
                    m[front->left]=front;
                    q.push(front->left);
                }
                if(front->right){
                    m[front->right]=front;
                    q.push(front->right);
                }
            
        }
        return ans;
    }
    
    int minTime(Node* root, int target) 
    {
        // we need to map parent
        unordered_map<Node*,Node*>m;
        
        Node*startnode=bfsToParent(root,m,target);
        
        // visited for bfs traversal
        int mx=findTime(m,startnode);
        return mx;
        
    }