class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int j=nums2.size();
        vector<int> ans;

        for(int i=0;i<nums1.size();i++){
            int res=-1;
            int k=j-1;

            while(nums1[i]!=nums2[k]){
                if(nums1[i]<nums2[k]){
                    res=nums2[k];
                }
                k--;
            }

            ans.push_back(res);
        }

        return ans; 
    }
};