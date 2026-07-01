/*
============================================================
Problem: 169. Majority Element
Difficulty: Easy
Topic: Arrays

Approach:
- Use Boyer-Moore Voting Algorithm.
- Maintain a candidate and its vote count.
- Increase count for the same element.
- Decrease count for a different element.
- If count becomes zero, choose a new candidate.

Interview Explanation:
- Different elements cancel each other's votes.
- The majority element appears more than n/2 times.
- It can never be completely canceled.
- The final candidate is the majority element.

Time Complexity: O(n)
Space Complexity: O(1)
============================================================
*/


class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int candidate = 0;
        int count = 0;

        for (int num : nums) {

            if (count == 0)
                candidate = num;

            if (num == candidate)
                count++;
            else
                count--;
        }

        return candidate;
    }
};
