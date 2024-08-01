// // Types of tree
// 1. Full binary tree - either 0 or 2 child node are possible
// 2. Complete binary tree - all level of tree must be filled and leaf level
//  and 2nd last level must be empty and filled from left to right
// 3. Perfect binary tree - each parent must have 0 or 2 child nodes , each level must be filled completely
// 4. Balanced binary tree - the difference between left and right subtree must be atmost 1
// 5. Degenerate tree -  binary tree where the nodes are arranged in single path leaning to left or right


void create_tree(node* root0, vector<int> &vec){
        //Your code goes here
        queue<node*>q;
        q.push(root0);
        int i=1;
        while(i<vec.size() && !q.empty()){
            node*front=q.front();
            q.pop();
            if(i<vec.size()){
                front->left=newNode(vec[i]);
                q.push(front->left);
                i++;
            }
            if(i<vec.size()){
                front->right=newNode(vec[i]);
                q.push(front->right);
                i++;
            }
        }
        
    }
