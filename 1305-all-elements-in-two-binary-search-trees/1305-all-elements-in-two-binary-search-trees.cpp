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
    void inorder(TreeNode* root, vector<int>& r){
        if(root == NULL) return;

        inorder(root->left,r);
        r.push_back(root->val);
        inorder(root->right,r);
        return;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> R1;
        vector<int> R2;
        inorder(root1,R1);
        inorder(root2, R2);
        int i=0, j=0;
        int n1 = R1.size();
        int n2 = R2.size();
        vector<int> ans;
        while(i < n1 && j < n2){
            if(R1[i] > R2[j]){
                ans.push_back(R2[j]);
                j++;
            }
            else{
                ans.push_back(R1[i]);
                i++;
            }
        }
        
        while( i < n1){
            ans.push_back(R1[i]);
            i++;
            
        }
        while( j < n2){
            ans.push_back(R2[j]);
            j++;
            
        }
        return ans;
    }
};