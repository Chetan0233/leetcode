class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> last;
        int l = 0, ans = 0;

        for (int r = 0; r < s.size(); r++) {
            if (last.count(s[r])) {
                l = max(l, last[s[r]] + 1);
            }
        last[s[r]] = r;
        ans = max(ans, r - l + 1);
    }
    return ans;
    }
};