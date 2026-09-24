class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            int sum=0,x=nums[i];
            while(x){
                int d=x%10;
                sum+=d;
                x/=10;
            }

            if(sum==i) return i;
        }

        return -1;
    }
};