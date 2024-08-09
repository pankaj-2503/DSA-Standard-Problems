class Solution {
public:
// TC: O(N) , SC: O(N)
    TreeNode*build(vector<int>&inorder,int inStart,int inEnd,vector<int>&preorder,int preStart,int preEnd,map<int,int>&m){
        // we are using 2 pointers to check if it's part of left subtree or right subtree
        if(inStart>inEnd || preStart>preEnd) return NULL;

        TreeNode*root=new TreeNode(preorder[preStart]);

        //finding index of current preorder in inorder
        int index=m[root->val];
        //finding size of left tree
        int numLeft=index-inStart;
        // recursive build left subtree
        root->left=build(inorder,inStart,index-1,preorder,preStart+1,preStart+numLeft,m);
        // recursive build right subtree
        root->right=build(inorder,index+1,inEnd,preorder,preStart+numLeft+1,preEnd,m);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // map to store indices of inorder
        map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }

        TreeNode*root=build(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1,m);
        return root;

    }
};