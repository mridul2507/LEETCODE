class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        string ans="";

        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]!=')') st.push(s[i]);
            else{
                string res="";
                while(st.top()!='('){
                    res+=st.top();
                    st.pop();
                }
                st.pop();

                for(int j=0;j<res.size();j++){
                    st.push(res[j]);
                }
            }
        }

        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }

        return ans;
    }
};