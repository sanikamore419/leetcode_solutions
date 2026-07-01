class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {

            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else {
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
        }

        return maxProfit;
    }
};


/*
------------------------------------------------------------
Interview Explanation:

- Keep track of the minimum stock price seen so far.
- For each day, calculate the profit if the stock is sold today.
- Update the maximum profit whenever a larger profit is found.
- The entire array is traversed only once.

Time Complexity: O(n)
Space Complexity: O(1)
------------------------------------------------------------
*/
