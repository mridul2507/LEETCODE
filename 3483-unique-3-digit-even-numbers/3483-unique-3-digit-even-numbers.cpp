class Solution {
public:
    bool present(int num, unordered_map<int,int>& mp){
        unordered_map<int,int> temp=mp;

        while(num){
            int digit=num%10;
            if(temp[digit]==0) return false;
            temp[digit]--;
            num/=10;
        }

        return true;
    }

    int totalNumbers(vector<int>& digits) {
        int n=digits.size(),ans=0,count=0;
        unordered_map<int,int> mp;

        for(int x:digits){
            mp[x]++;
            if(x%2!=0) count++;
        }

        if(count==n) return ans;

        for(int i=100; i<1000; i+=2){
            if(present(i, mp)) ans++;
        }

        return ans;
    }
};