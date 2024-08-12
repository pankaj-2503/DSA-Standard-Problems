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
// tc: O(H)
class Solution {
public:
    bool isleaf(TreeNode*root){
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        return false;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return NULL;
        TreeNode* parent = NULL;                 // Find the node to be deleted and its parent
        TreeNode* current = root;
        while (current != NULL && current->val != key) {
            parent = current;
            if (key < current->val) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        if (current == NULL) return root;       // If the key is not found in the tree

        if (isleaf(current)) {        // If the node to be deleted is a leaf node
            if (current == root) {    // If the node to be deleted is the root itself
                return NULL;
            } else {                  // Disconnect the leaf node from its parent
                if (parent->left == current) {
                    parent->left = NULL;
                } else {
                    parent->right = NULL;
                }
            }
        } else if (current->left == NULL || current->right == NULL) {     // If the node to be deleted has one child
            TreeNode* child = (current->left != NULL) ? current->left : current->right;
            if (current == root) {       // If the node to be deleted is the root
                return child;
            } else {
                if (parent->left == current) {
                    parent->left = child;
                } else {
                    parent->right = child;
                }
            }
        } else {                                   // If the node to be deleted has two children
            TreeNode* successorParent = current;
            TreeNode* successor = current->right;  // Finding the in-order successor
            while (successor->left != NULL) {
                successorParent = successor;
                successor = successor->left;
            }
            current->val = successor->val;         // Replace current node's value with successor's value

            if (successorParent->left == successor) {   // Delete the in-order successor
                successorParent->left = successor->right;
            } else {
                successorParent->right = successor->right;
            }
        }
        return root;
    }
};