class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int mini=INT_MAX, maxi=INT_MIN;
        int n=nums.size();
        vector<int> mini_nums(n);

        for(int i=n-1;i>=0;i--){
            mini=min(mini,nums[i]);
            mini_nums[i]=mini;
        }

        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            mini=mini_nums[i];

            if(maxi-mini <= k) return i;
        }

        return -1;
    }
};