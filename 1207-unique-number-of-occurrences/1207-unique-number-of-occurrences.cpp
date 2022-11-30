class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> s;
        sort(arr.begin(), arr.end());
        
        int count = 1;
        
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] == arr[i-1])
                count++;
            else{
                if(s.find(count) != s.end())
                    return false;
                s.insert(count);
                count = 1;
            }
        }
        if(s.find(count) != s.end())
            return false;
        return true;
    }
    
};