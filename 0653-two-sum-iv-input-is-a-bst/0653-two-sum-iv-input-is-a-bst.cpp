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
    void func(TreeNode* root, int k, vector<int> &res){
        if(!root) return;
        func(root->left,k,res);
        res.push_back(root->val);
        func(root->right,k,res);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>res;
        func(root,k,res);
        int i=0;
        int j=res.size()-1;
        
        while(i<j){
            if(res[i]+res[j]==k)
                return true;
            else if(res[i]+res[j]>k)
                j--;
            else
                i++;
        }
        return false;
    }
};