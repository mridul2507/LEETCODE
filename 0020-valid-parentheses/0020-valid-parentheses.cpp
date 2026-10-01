class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='(' || ch=='{' || ch=='[')
                stack.push(ch);
            else{
                if(!stack.empty()){
                    char top=stack.top();
                    if(ch==')' && top=='(' ||
                    ch=='}' && top=='{' ||
                    ch==']' && top=='[') stack.pop();

                    else return false;
                }
                else{
                    return false;
                }
            }
        }
        return (!stack.empty()) ? false:true;
    }
};