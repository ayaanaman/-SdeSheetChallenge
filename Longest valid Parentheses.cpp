int longestValidParentheses(string A) {
    stack<int>st;
    st.push(-1);
    int ans=0;
    for(int i=0;i<A.size();i++){
        if(A[i]=='('){
            st.push(i);
        }
        else{
            if(st.size())st.pop();
            if(st.size()){
                ans=max(ans,i-st.top());
            }
            else{
                st.push(i);
            }
        }
    }
    return ans;
}
