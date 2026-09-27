class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int n:nums) mp[n]++;
        vector<int> ans;

        while(ans.size()!=nums.size()){
            vector<int> curr;
            for(auto &x:mp){
                if(x.second>=1){
                    curr.push_back(x.first);
                    x.second--;
                }
            }
            sort(curr.begin(),curr.end());
            for(int x:curr){
                ans.push_back(x);
            }
        }

        return ans;
    }
};