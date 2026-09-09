class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        if (words.empty() || s.empty()) return ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.size() < totalLen) return ans;

        unordered_map<string, int> target;

        for (const string& word : words) {
            target[word]++;
        }

        // There are wordLen possible starting offsets.
        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset;
            int right = offset;
            int count = 0;

            unordered_map<string, int> seen;

            while (right + wordLen <= s.size()) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                // Word isn't in the target list.
                if (!target.count(word)) {
                    seen.clear();
                    count = 0;
                    left = right;
                    continue;
                }

                seen[word]++;
                count++;

                // Too many occurrences of this word.
                while (seen[word] > target[word]) {
                    string leftWord = s.substr(left, wordLen);
                    seen[leftWord]--;
                    left += wordLen;
                    count--;
                }

                // Exactly wordCount words.
                if (count == wordCount) {
                    ans.push_back(left);

                    // Move window forward by one word
                    string leftWord = s.substr(left, wordLen);
                    seen[leftWord]--;
                    left += wordLen;
                    count--;
                }
            }
        }

        return ans;
    }
};