class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,prod=1,k=n;

        while(k){
            int d=k%10;
            sum+=d;
            prod*=d;
            k/=10;
        }

        return (n%(sum+prod)==0) ? true : false;
    }
};