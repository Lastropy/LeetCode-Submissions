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
    TreeNode *build(vector<int> &p, vector<int> &i, unordered_map<int, int> &mp, int stp, int enp, int sti, int eni){
        if(sti > eni || stp > enp) return NULL;        
        auto root = new TreeNode(p[stp]);
        int idx = mp[root -> val];
        int numLeft = (idx - sti);
        root -> left = build(p, i, mp, stp + 1, stp + numLeft,sti, idx - 1);
        root -> right = build(p, i, mp, stp + numLeft + 1 , enp,idx + 1, eni);
        return root;
    }
    TreeNode* buildTree(vector<int>& p, vector<int>& i) {
        int stp = 0, enp = p.size() - 1;
        int sti = 0, eni = i.size() - 1;
        unordered_map<int, int> mp;
        for(int idx = 0; idx < i.size(); idx++){
            mp[i[idx]] = idx;
        }
        return build(p, i, mp, stp, enp, sti, eni);
    }
};