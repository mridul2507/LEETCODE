class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            int k = '{'-s[i];
            sum += k*(i+1);
        }

        return sum;
    }
};