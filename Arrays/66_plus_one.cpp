/*
============================================================
Problem: 66. Plus One
Difficulty: Easy
Topic: Arrays

Approach:
- Traverse the digits from right to left.
- If the current digit is less than 9, increment it and return.
- Otherwise, set it to 0 and carry the increment.
- If all digits are 9, insert 1 at the beginning.

Interview Explanation:
- Simulate manual addition from the last digit.
- Handle carry propagation efficiently.
- Return immediately once no carry is generated.

Time Complexity: O(n)
Space Complexity: O(1)
============================================================
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        for (int i = digits.size() - 1; i >= 0; i--) {

            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);

        return digits;
    }
};
