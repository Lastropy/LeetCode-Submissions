class StockSpanner {
public:
    // {price, ans}
    stack<vector<int>> st;   
    int next(int price) {
        int res = 1;
        while(!st.empty() && st.top()[0] <= price)
            res += st.top()[1], st.pop();
        st.push({price, res});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */