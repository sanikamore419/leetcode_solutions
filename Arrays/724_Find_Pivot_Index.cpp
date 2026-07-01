/*
============================================================
Problem: 724. Find Pivot Index
Difficulty: Easy
Topic: Prefix Sum

Approach:
- Calculate the total sum of the array.
- Maintain a running left sum.
- Right sum = Total Sum - Left Sum - Current Element.
- Compare left and right sums.

Interview Explanation:
- Compute the total sum once.
- Update the left sum while traversing.
- Calculate the right sum in O(1).
- Return the first index where both sums are equal.

Time Complexity: O(n)
Space Complexity: O(1)
============================================================
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int totalSum = 0;

        for (int num : nums)
            totalSum += num;

        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (leftSum == totalSum - leftSum - nums[i])
                return i;

            leftSum += nums[i];
        }

        return -1;
    }
};
