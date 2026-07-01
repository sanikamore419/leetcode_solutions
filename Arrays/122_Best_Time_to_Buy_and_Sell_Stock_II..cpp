/*
============================================================
Problem: 122. Best Time to Buy and Sell Stock II
Difficulty: Medium
Topic: Greedy

Approach:
- Traverse the array once.
- Whenever today's price is greater than yesterday's,
  add the profit.
- Sum all positive differences.

Interview Explanation:
- Since multiple transactions are allowed,
  every increasing price contributes to profit.
- Capture every upward movement.
- One pass is sufficient.

Time Complexity: O(n)
Space Complexity: O(1)
============================================================
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int profit = 0;

        for (int i = 1; i < prices.size(); i++) {

            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};
