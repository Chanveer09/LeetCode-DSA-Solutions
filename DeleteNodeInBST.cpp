class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr){
            return nullptr;
        }
        if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else{
            
            if(root->left==nullptr){
                return root->right;
            }
            if(root->right==nullptr){
                return root->left;
            }
            TreeNode* successor= root->right;
            while(successor->left!=nullptr){
                successor=successor->left;

            }
            root->val=successor->val;
            root->right=deleteNode(root->right,successor->val);
        }
        return root;
    }
};
