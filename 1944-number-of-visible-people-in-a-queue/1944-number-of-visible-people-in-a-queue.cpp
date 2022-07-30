class Solution {
public:
    void findngr(vector<int>& heights, vector<int> &ans){
        stack<int> st;
        for(int i = heights.size() - 1; i >= 0; i--){
            int curr_size = 0 ; 
            while(!st.empty() && heights[st.top()] < heights[i])
            {
                st.pop();
                curr_size++;
            }
            if(i != heights.size() -1) ans[i] = curr_size + (st.size() == 0 ? 0 : 1);
            else ans[i] = 0;
            st.push(i);
        }
    }
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> ans(heights.size(), 0 );
        findngr(heights, ans);
        return ans;
    }
};