class Solution {
public:
    int findMountain(MountainArray &a, int n){
        int s = 0, e = n - 1;
        while(s < e){
            int m = s + (e- s)/2;
            if(a.get(m + 1) < a.get(m)) e = m - 1;  
            else s = m + 1; 
        }
        return s;
    }
    
    int findEle(MountainArray &a, int s, int e, int t, bool rev = false){
        while(s <= e){
            int m = s + (e - s)/2;
            int ele = a.get(m);
            if(ele == t) return m;
            if(rev){
                if(ele < t) e = m - 1;
                else s = m + 1;
            } else {
                if(ele < t) s = m + 1;
                else e = m - 1;
            }
        }
        return -1;
    }
    
    int findInMountainArray(int t, MountainArray &a) {
        int n = a.length();
        int posOfPeak = findMountain(a, n);
        int occ = findEle(a,0, posOfPeak, t);
        if(occ != -1) return occ;
        return findEle(a, posOfPeak+1, n - 1, t, 1);
    }
};