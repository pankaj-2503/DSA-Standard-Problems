// TC: O(N)-> best case O(log2N) , SC:O(1)
int findCeil(Node* root, int input) {
    int ans=-1;
    while(root){
        if(root->data==input) return input;
        if(input>root->data) root=root->right;
        else{
            ans=root->data;
            root=root->left;
        }
    }
    return ans;
}

  int floor(Node* root, int x) {
        // Code here
        int ans=-1;
        while(root){
            if(root->data==x) return x;
            else if(root->data<x){
                ans=root->data;
                root=root->right;
            }else{
                root=root->left;
            }
        }
        return ans;
    }