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
    TreeNode* build(vector<int>& p, vector<int>& in, unordered_map<int, int> &mp,int sti, int eni, int stp, int enp){
        if(stp > enp || sti > eni) return NULL;
        auto root = new TreeNode(p[enp]);
        int idx = mp[root -> val];
        int numLeft = idx - sti - 1;
        root -> left = build(p, in, mp, sti, idx - 1, stp, stp+ numLeft);
        root -> right = build(p, in, mp, idx + 1, eni, stp + numLeft + 1, enp - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& p) {
        int sti = 0, eni = in.size() - 1;
        int stp = 0, enp = p.size() - 1;
        unordered_map<int, int> mp;
        for(int i = 0; i < in.size(); i++){
            mp[in[i]] = i;
        }
        return build(p, in, mp, sti, eni, stp, enp);
    }
};