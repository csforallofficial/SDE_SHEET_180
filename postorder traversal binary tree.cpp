/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:


Input: root = [1,2]
Output: [2,1]
Example 5:


Input: root = [1,null,2]
Output: [2,1]
 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?
*/


//recursive approach - 

void postorder(Node* root, vector<int>& ans){
    if(root==NULL)
        return;
    postorder(root->left,ans);
    postorder(root->right,ans);
    ans.push_back(root->data);
}
vector <int> postOrder(Node* root)
{
    vector<int> ans;
    postorder(root,ans);
    return ans;
}

//iterative approach - 

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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st1,st2;
        vector<int> ans;
        if(root == NULL)
            return ans;
        st1.push(root);
        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);
            if(root->left != NULL)
                st1.push(root->left);
            if(root->right != NULL)
                st1.push(root->right);
        }
        while(!st2.empty()){
            root = st2.top();
            ans.push_back(root->val);
            st2.pop();
        }
        return ans;
    }
};
