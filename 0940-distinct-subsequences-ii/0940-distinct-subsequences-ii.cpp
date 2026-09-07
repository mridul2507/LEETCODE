class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int i, string &s, vector<int> &dp, vector<int> &prev){
        if(i == 0) return 1;
        if(dp[i] != -1) return dp[i];

        long long ans = (2LL * solve(i - 1, s, dp, prev)) % MOD;
        if(prev[i] != -1) {
            ans = (ans - solve(prev[i] - 1, s, dp, prev) + MOD) % MOD;
        }
        return dp[i] = ans;
    }

    int distinctSubseqII(string s) {
        int n = s.size();

        vector<int> dp(n + 1, -1);
        vector<int> prev(n + 1, -1);
        vector<int> last(26, -1);

        for(int i = 1; i <= n; i++){
            int c = s[i - 1] - 'a';
            prev[i] = last[c];
            last[c] = i;
        }

        return (solve(n, s, dp, prev) - 1 + MOD) % MOD;
    }
};