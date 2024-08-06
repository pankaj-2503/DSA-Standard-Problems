 // TC: O(N) same sc
 int isSumProperty(Node *root)
    {
     // Add your code here
       if(root==NULL || (root->left==NULL && root->right==NULL)) return 1;
       int sum=0;
       if(root->left) sum+=root->left->data;
       if(root->right) sum+=root->right->data;
       
       return (root->data==sum && isSumProperty(root->left) && isSumProperty(root->right));
    }