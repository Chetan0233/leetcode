# Container With Most Water

## Problem Description
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 
Example 1:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.


Example 2:

Input: height = [1,1]
Output: 1


 
Constraints:


	n == height.length
	2 <= n <= 105
	0 <= height[i] <= 104



## My Code
```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int maxarea=0;
        int r = height.size()-1;
        while(l<r){
            int area = min(height[l],height[r])*(r-l);
            maxarea=max(maxarea,area);
            if(height[l]<=height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxarea;
    }
};
```

## Code Explanation
The given code is a solution to the "Container With Most Water" problem on LeetCode. Here's a step-by-step breakdown of how it works:
- The code initializes two pointers, `l` and `r`, to the start and end of the `height` array, respectively. 
- It then enters a while loop that continues until `l` is no longer less than `r`.
- Inside the loop, it calculates the area of water that can be trapped between the two lines at indices `l` and `r`. The area is calculated as the minimum height of the two lines multiplied by the distance between them (`min(height[l], height[r]) * (r - l)`).
- The code then updates the `maxarea` variable to store the maximum area found so far.
- The code checks if the height of the line at index `l` is less than or equal to the height of the line at index `r`. If it is, the code increments `l` to move the left pointer to the right. This is because moving the left pointer has the potential to increase the area, whereas moving the right pointer would not increase the area due to the smaller height.
- If the height of the line at index `l` is greater than the height of the line at index `r`, the code decrements `r` to move the right pointer to the left. This is because moving the right pointer has the potential to increase the area, whereas moving the left pointer would not increase the area due to the smaller height.
- Once the while loop exits, the code returns the `maxarea` variable, which stores the maximum area of water that can be trapped between any two lines.

## Complexity Analysis
- **Time Complexity:** The time complexity of this solution is O(n), where n is the number of elements in the `height` array. This is because the code only needs to iterate through the array once, using the two-pointer technique to compare each pair of lines.
- **Space Complexity:** The space complexity of this solution is O(1), which means the space required does not change with the size of the input array. This is because the code only uses a constant amount of space to store the `l`, `r`, and `maxarea` variables, regardless of the size of the input array.

## Optimizations
The given code is already optimal for this problem, with a time complexity of O(n) and a space complexity of O(1). However, there are a few edge cases to consider:
- If the input array is empty or contains only one element, the function should return 0 because there are no pairs of lines to form a container.
- If the input array contains duplicate heights, the function should still work correctly because it uses the minimum height of the two lines to calculate the area.
- If the input array contains a large number of elements, the function may take a significant amount of time to run due to its O(n) time complexity. However, this is still the most efficient solution for this problem.

## Interview Explanation
Here's how a candidate should verbally explain this solution to an interviewer:
"Okay, so the problem asks us to find the maximum area of water that can be trapped between two lines in a given array of heights. To solve this, we can use a two-pointer technique, where we start with two pointers, one at the beginning of the array and one at the end.
"We calculate the area of water that can be trapped between the two lines at the current pointers, and then we move the pointer that corresponds to the shorter line towards the other pointer. This is because moving the pointer that corresponds to the taller line wouldn't increase the area, since the area is limited by the height of the shorter line.
"We continue this process until the two pointers meet, at which point we've checked all possible pairs of lines and can return the maximum area found.
"The time complexity of this solution is O(n), where n is the number of elements in the array, because we only need to iterate through the array once. The space complexity is O(1) because we only use a constant amount of space to store the pointers and the maximum area found.
"In terms of edge cases, we need to consider what happens if the input array is empty or contains only one element. In these cases, we should return 0 because there are no pairs of lines to form a container.
"Overall, this solution is efficient and effective, and it takes into account all possible pairs of lines to find the maximum area of water that can be trapped.
"One thing to note is that this solution assumes that the input array is valid, i.e., it contains only non-negative integers. If the input array can contain negative integers or other invalid values, we would need to add some error checking code to handle these cases.
"Also, it's worth noting that this solution has a time complexity of O(n), which means it can handle large input arrays. However, if the input array is extremely large, we may need to consider using a more efficient algorithm or data structure to improve performance.
"I hope that helps clarify the solution! Do you have any questions or would you like me to explain anything further?"