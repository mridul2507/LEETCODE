class Solution {
public:
    int M = 1e9+7;
    
    long long modPow(long long base, long long exp) {
        long long res = 1;
        while(exp > 0) {
            if(exp % 2 == 1) res = (res * base) % M;
            base = (base * base) % M;
            exp /= 2;
        }
        return res;
    }
    
    int countGoodNumbers(long long n) {
        int ans = (modPow(5,((n+1)/2))*modPow(4,(n/2))) % M;

        return ans;
    }
};