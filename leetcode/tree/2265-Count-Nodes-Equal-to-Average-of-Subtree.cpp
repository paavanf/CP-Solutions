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
    int ans=0;
    pair<int,int>dfs(TreeNode* root)//sm and ct
    {
        if(root==NULL)
        return {0,0};
        pair<int,int>left=dfs(root->left);
        pair<int,int>right=dfs(root->right);
        int sm=root->val+left.first+right.first;
        int ct=1+left.second+right.second;
        if(sm/ct==root->val)
        ans++;
        return{sm,ct};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};