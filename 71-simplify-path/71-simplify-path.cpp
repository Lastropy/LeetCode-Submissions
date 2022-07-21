class Solution {
public:
    string simplifyPath(string path) {
        stringstream str(path);
        string s;
        vector<string> ans({"/"});
        while(getline(str,s, '/')){
            if( s == ""  || s == ".") 
                continue;
            if( s == ".." && ans.size() == 1)
                continue;
            else if(s == "..")
                ans.pop_back();
            else
                ans.push_back(s);          
            
        }
        path = "";
        for(int i  = 0; i < ans.size(); i++){
            path += ans[i];
            if(i == 0 || i == ans.size() -1)
                continue;
            path +="/";
        }
        return path;
    }
};