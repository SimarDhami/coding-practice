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
  TreeNode* inorderPre(TreeNode*root){
    /*    if(root->right==NULL)
            return root;
       return  inorderPre(root->right);*/
     while(root->right)
         root=root->right;
      return root;
        //return root->val;
   }
            
    TreeNode* deleteNode(TreeNode* root, int key) {
 if(root==NULL)return root;
 if(root->val==key){
  if(!root->left&&!root->right){ 
         delete root;
         return NULL;}
  else if(root->left==NULL&&root->right!=NULL){
      TreeNode*x= root->right;
      delete root;
      return x;}
  else if(root->left!=NULL&&root->right==NULL){
      TreeNode*x= root->left;
      delete root;
      return x;}
  else{
 TreeNode* x=inorderPre(root->left);
      root->val= x->val;
  root->left= deleteNode(root->left, x->val);
   
   }  
 }
     if(root->val>key) 
  root->left = deleteNode(root->left, key);
     if(root->val<key)
  root->right= deleteNode(root->right, key);
     return root;
     }
    
};