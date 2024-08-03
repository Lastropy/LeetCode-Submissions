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
    TreeNode *build(vector<int>& p, vector<int>& i, int stp, int enp, int sti, int eni){
        // cout << format("stp = {} enp = {} sti = {} eni = {} ", stp, enp, sti, eni) << endl;
        if(sti > eni || stp > enp) return NULL;        
        auto root = new TreeNode(p[stp]);
        int idx;
        for(idx = sti; idx <= eni; idx++){
            if(i[idx] == p[stp]){
                break;
            }
        }
        // cout << p[stp] << " | "<< idx << endl;
        root -> left = build(p, i, stp + 1, stp + (idx - sti) ,sti, idx -1);
        root -> right = build(p, i,stp + (idx - sti) + 1 , enp,idx + 1, eni);
        return root;
    }
    TreeNode* buildTree(vector<int>& p, vector<int>& i) {
        int stp = 0, enp = p.size() - 1;
        int sti = 0, eni = i.size() - 1;
        
        return build(p, i, stp, enp, sti, eni);
    }
};