/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // TC:O(N) , SC:O(N)
    // Preorder Traversal
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return {};
        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode*top=s.top();
            s.pop();

            ans.push_back(top->val);
            if(top->right) s.push(top->right);
            if(top->left) s.push(top->left);
        }
        return ans;
    }
};


// Iterative Inorder traversal

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return {};

        stack<TreeNode*>s;
        TreeNode*temp=root;
        while(temp!=NULL || !s.empty()){
            // Moving to left most leaf node
            while(temp!=NULL){
                s.push(temp);
                temp=temp->left;
            }
            // push leftmost node to ans
            temp=s.top();
            s.pop();
            ans.push_back(temp->val);
            // move to right part
            temp=temp->right;
        }
        return ans;
    }
};

// all traversal in one as string
// Time Complexity: O(3N) , SC: O(4N)

vector<vector<int>> preInPostTraversal(Node* root) {
    // Vectors to store traversals
    vector<int> pre, in, post;

    // If the tree is empty,
    // return empty traversals
    if (root == NULL) {
        return {};
    }

    // Stack to maintain nodes
    // and their traversal state
    stack<pair<Node*, int>> st;

    // Start with the root node
    // and state 1 (preorder)
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        // this is part of pre
        if (it.second == 1) {
            // Store the node's data
            // in the preorder traversal
            pre.push_back(it.first->data);
            // Move to state 2
            // (inorder) for this node
            it.second = 2;
            // Push the updated state
            // back onto the stack
            st.push(it); 

            // Push left child onto
            // the stack for processing
            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        }

        // this is a part of in
        else if (it.second == 2) {
            // Store the node's data
            // in the inorder traversal
            in.push_back(it.first->data);
            // Move to state 3
            // (postorder) for this node
            it.second = 3;
            // Push the updated state
            // back onto the stack
            st.push(it); 

            // Push right child onto
            // the stack for processing
            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        }

        // this is part of post
        else {
            // Store the node's data
            // in the postorder traversal
            post.push_back(it.first->data);
        }
    }

    // Returning the traversals
    vector<vector<int>> result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);
    return result;
}