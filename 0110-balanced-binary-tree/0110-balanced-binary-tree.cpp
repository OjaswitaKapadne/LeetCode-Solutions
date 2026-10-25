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

    bool isTreeBalanced=true;
    bool isBalanced(TreeNode* root) {
        height(root);
        return isTreeBalanced;
    }

    int height(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }

        int hl=0, hr=0;
        hl = height(root->left);
        hr = height(root->right);

        int diff = hl-hr;
        if(diff!=-1 && diff!=0 && diff!=1) {
            isTreeBalanced=false;
        }

        return max(hl,hr) + 1;
    }
};