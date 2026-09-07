class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        vector<long long> last(26, 0);

        for (char c : s) {
            long long sum = 0;
            for (int i = 0; i < 26; i++) {
                sum = (sum + last[i]) % MOD;
            }
            last[c - 'a'] = (sum + 1) % MOD;
        }

        long long ans = 0;
        for (int i = 0; i < 26; i++) {
            ans = (ans + last[i]) % MOD;
        }

        return ans;
    }
};