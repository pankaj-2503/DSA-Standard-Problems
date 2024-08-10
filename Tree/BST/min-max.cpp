// TC: O(log(N))
int minValue(Node* root) {
        // for finding min, similarly for max go to right side
        while(root->left){
            root=root->left;
        }
        return root->data;
}

int maxValue(Node*root){
    while(root->right){
        root=root->right;
    }
    return root->data;
}