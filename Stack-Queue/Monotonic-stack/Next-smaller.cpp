vector<int> Solution::prevSmaller(vector<int> &A) {
    // TC:O(N) , same SC
    int n=A.size();
    vector<int> sol(n, -1);
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= A[i]) {
            st.pop();
        }
        sol[i] = st.empty() ? -1 : st.top();
        st.push(A[i]);
    }
    
    return sol;
}
