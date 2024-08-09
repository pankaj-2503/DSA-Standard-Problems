class Solution {
public:
// TC: O(N), SC: O(N)
    TreeNode*build(vector<int>&inorder,int is,int ie,vector<int>&postorder,int ps,int pe,map<int,int>&m){
        if(ps>pe || is>ie) return NULL;

        TreeNode*root=new TreeNode(postorder[pe]);

        int index=m[postorder[pe]];
        int numLeft=index-is;

        root->left=build(inorder,is,index-1,postorder,ps,ps+numLeft-1,m);
        root->right=build(inorder,index+1,ie,postorder,ps+numLeft,pe-1,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return NULL;

        map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }

        return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,m);
    }
};