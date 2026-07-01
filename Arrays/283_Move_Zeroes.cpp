/*
============================================================
Problem: 283. Move Zeroes
Difficulty: Easy
Topic: Arrays, Two Pointers

Approach:
- Use two pointers.
- One pointer scans the array.
- The second pointer keeps track of the position for the next non-zero element.
- Swap non-zero elements to the front.

Interview Explanation:
- Maintain the relative order of non-zero elements.
- Move every non-zero element to the earliest available position.
- Zeros automatically shift to the end.
- Perform the operation in-place.

Time Complexity: O(n)
Space Complexity: O(1)
============================================================
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int j = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
