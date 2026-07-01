/*
============================================================
Problem: 1480. Running Sum of 1D Array
Difficulty: Easy
Topic: Prefix Sum

Approach:
- Traverse the array from left to right.
- Add the previous running sum to the current element.
- Update the array in-place.

Interview Explanation:
- Each element stores the sum of all previous elements.
- Modify the input array directly.
- No extra array is required.

Time Complexity: O(n)
Space Complexity: O(1)
============================================================
*/


class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }

        return nums;
    }
};
