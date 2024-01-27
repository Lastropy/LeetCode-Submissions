class Solution {
public:
    int find_rotation_index(vector<int> &a){
        int s = 0, e = a.size() - 1;
        while(s <= e){
            int m = s + (e- s)/2;
            if(a[m] >= a[0]) s = m + 1;
            else e = m - 1;
        }
        return e;
    }
     
    int find_occ(vector<int> &a, int tar, int s, int e){
        while(s <= e){
            int m = s + (e-s)/2;
            if(a[m] == tar) return m;
            else if(a[m] < tar) s = m + 1;
            else e = m - 1;
        }
        return - 1;
    }
    int search(vector<int>& a, int t) {
        int point_of_rot = find_rotation_index(a);
        return max(find_occ(a, t, 0, point_of_rot), find_occ(a, t, point_of_rot + 1, a.size() - 1));
    }
};