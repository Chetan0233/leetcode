# Longest Substring Without Repeating Characters

## Problem Description
Given a string s, find the length of the longest substring without duplicate characters.

 
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.


Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.


Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.


 
Constraints:


	0 <= s.length <= 5 * 104
	s consists of English letters, digits, symbols and spaces.



## My Code
```cpp
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
```

## AI Insights & Optimizations
Failed to generate insights after trying all available models and keys.

## Interview Explanation
Failed to generate explanation.