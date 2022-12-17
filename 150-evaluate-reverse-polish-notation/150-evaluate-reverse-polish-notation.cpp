class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;

        for(auto el: tokens){
            if(el.length() == 1 && !isdigit(el[0])){
                int secondOperand = st.top();
                st.pop();
                int firstOperand = st.top();

                st.pop();
                switch(el[0]){
                    case '+' : st.push(firstOperand + secondOperand);
                               break;
                    case '-' : st.push(firstOperand - secondOperand);
                               break;
                    case '*': st.push((long) firstOperand * secondOperand);
                              break;
                    default: st.push(firstOperand / secondOperand);
                }
            }else{
                st.push(stoi(el));
            }
        }
        return st.top();
        
    }
};