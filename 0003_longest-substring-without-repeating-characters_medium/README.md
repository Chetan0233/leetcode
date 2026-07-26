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

## Code Explanation
The provided code is a solution to the "Longest Substring Without Repeating Characters" problem. It uses a sliding window approach with the help of an unordered map to keep track of the last seen index of each character. Here's a step-by-step breakdown:

1. **Initialization**: The code starts by initializing an unordered map `last` to store the last seen index of each character, and two integers `l` (left pointer) and `ans` (answer) to 0.
2. **Sliding Window**: The code then enters a loop that iterates over the string `s` using a right pointer `r`.
3. **Check for Repeating Character**: Inside the loop, it checks if the current character `s[r]` is already present in the `last` map. If it is, it updates the left pointer `l` to be the maximum of its current value and the last seen index of the character plus one. This effectively slides the window to the right of the previous occurrence of the character.
4. **Update Last Seen Index**: Regardless of whether the character was previously seen or not, the code updates the last seen index of the character in the `last` map to the current right pointer `r`.
5. **Update Answer**: Finally, the code updates the answer `ans` to be the maximum of its current value and the length of the current window (i.e., `r - l + 1`).
6. **Return Answer**: After iterating over the entire string, the code returns the answer `ans`, which represents the length of the longest substring without repeating characters.

## Complexity Analysis
- **Time Complexity:** The time complexity of this solution is O(n), where n is the length of the input string `s`. This is because the code makes a single pass over the string, and the operations inside the loop (looking up and updating the `last` map, and updating the answer) take constant time.
- **Space Complexity:** The space complexity of this solution is also O(n), as in the worst case, the `last` map will store an entry for each character in the string. However, since the string can contain at most 128 unique characters (for ASCII), the space complexity is effectively O(1) for the map. Nevertheless, considering the possibility of a string with n unique characters, the space complexity is O(n) for the map, and O(1) for the other variables.

## Optimizations
The provided code is already quite efficient and optimal for this problem. However, a few minor suggestions can be made:
- Using a `const` reference to the string `s` in the function parameter can avoid a copy of the string.
- Using a more descriptive variable name instead of `l` and `r` can improve readability.
- Adding comments to explain the logic and purpose of each section of the code can make it easier to understand for others.

## Interview Explanation
Here's a conversational script on how to explain this solution to an interviewer:

"Alright, so this problem is asking us to find the length of the longest substring without repeating characters in a given string. To approach this, I decided to use a sliding window technique, which allows us to efficiently scan the string and keep track of the characters we've seen so far.

"The key data structure I used here is an unordered map, which stores the last seen index of each character. This map is crucial because it allows us to quickly look up whether a character has been seen before and, if so, where it was last seen.

"Now, let's walk through the logic of the code. We start by initializing the left and right pointers of the sliding window, as well as the answer variable. Then, we iterate over the string using the right pointer.

"For each character, we check if it's already present in the map. If it is, we update the left pointer to be the maximum of its current value and the last seen index of the character plus one. This effectively slides the window to the right of the previous occurrence of the character.

"Regardless of whether the character was previously seen or not, we update the last seen index of the character in the map to the current right pointer.

"Finally, we update the answer to be the maximum of its current value and the length of the current window, which is simply the difference between the right and left pointers plus one.

"The time complexity of this solution is O(n), where n is the length of the input string, because we make a single pass over the string. The space complexity is also O(n) in the worst case, although in practice, it's likely to be much smaller due to the limited number of unique characters in the string.

"I hope that helps clarify the solution! Do you have any questions or would you like me to elaborate on any part of the code?"