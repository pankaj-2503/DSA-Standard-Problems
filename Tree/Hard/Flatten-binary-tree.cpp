class Solution {
public:
// TC: O(N) , SC: O(N)
    TreeNode*flattenHelper(TreeNode*root){
        if(root==NULL) return NULL;

        TreeNode*leftTail=flattenHelper(root->left);
        TreeNode*rightTail=flattenHelper(root->right);

        if(leftTail!=NULL){
            leftTail->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }

        return rightTail!=NULL?rightTail:leftTail!=NULL?leftTail:root;
    }
    void flatten(TreeNode* root) {
         flattenHelper(root);
    }
};

// REcursive Approach  -> TC: O(N) , SC: O(logN)
TreeNode*prev=NULL;
    void flatten(TreeNode* root) {
       if(root==NULL){
           return;
       }

       // Recursive call to
       // flatten the right subtree
       flatten(root->right);
       
       // Recursive call to
       // flatten the left subtree
       flatten(root->left);
       
       // At this point, both left and right
       // subtrees are flattened, and 'prev'
       // is pointing to the rightmost node
       // in the flattened right subtree.

       // Set the right child of
       // the current node to 'prev'.
       root->right = prev;

       // Set the left child of the
       // current node to NULL.
       root->left = NULL;

       // Update 'prev' to the current
       // node for the next iteration.
       prev = root;
    }


// Another approach using stack -> TC: O(N) , SC: O(logN)

 void flatten(TreeNode* root) {
       if(root == NULL){
            return;
        }
        
        stack<TreeNode*> st;
        st.push(root);  
        
      
        while (!st.empty()) {  
           
            TreeNode* cur = st.top(); 
            st.pop();  

            if (cur->right != NULL) {
                st.push(cur->right); 
            }
            
            if (cur->left != NULL) {
                st.push(cur->left); 
            }

            if (!st.empty()) {
                cur->right = st.top();  
            }
            
            cur->left = NULL;  
        }
    }

// MOrris traversal ( preorder) -> Tc: O(N) , SC:O(1)

void flatten(TreeNode* root) {
         TreeNode* curr = root;
        // preorder morris traversal
        // Iterate until 'curr'
        // becomes NULL
        while (curr) {
            // Check if the current
            // node has a left child
            if (curr->left) {
                // If yes, find the rightmost
                // node in the left subtree
                TreeNode* pre = curr->left;
                while (pre->right) {
                    pre = pre->right;
                }

                // Connect the rightmost node in
                // the left subtree to the current
               //  node's right child
                pre->right = curr->right;

                // Move the entire left subtree to the
                // right child of the current node
                curr->right = curr->left;

                // Set the left child of
                // the current node to NULL
                curr->left = NULL;
            }

            // Move to the next node
            // on the right side
            curr = curr->right;
        }
    }