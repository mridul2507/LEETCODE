class Solution {
public:
    void solve(vector<int>& candidates, int index, int target, vector<vector<int>>& res,vector<int>& curr){
        if(target==0){
            res.push_back(curr);
            return;
        }
        if(target<0) return;

        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            curr.push_back(candidates[i]);
            solve(candidates,i+1,target-candidates[i],res,curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        solve(candidates,0,target,res,curr);
        return res;
    }
};