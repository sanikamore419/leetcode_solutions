# LeetCode #1 - Two Sum

## Problem

Given an array `nums` and an integer `target`, return the indices of the
two numbers such that they add up to `target`.

## Optimal Approach: Hash Map

### Idea

Store each number and its index in a hash map. For every element: 1.
Compute `complement = target - nums[i]`. 2. If the complement already
exists in the map, return its index and the current index. 3. Otherwise,
store the current number and its index.

## C++ Code

``` cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {

            int complement = target - nums[i];

            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};
```

## Dry Run

Input:

    nums = [2,7,11,15]
    target = 9

  i   nums\[i\]   Complement   Hash Map Before   Action
  --- ----------- ------------ ----------------- -----------------------
  0   2           7            {}                Store 2→0
  1   7           2            {2→0}             Found 2, return {0,1}

## Complexity

-   **Time:** O(n)
-   **Space:** O(n)

## Interview Explanation

"I'll use a hash map to store numbers I've already visited along with
their indices. For each element, I calculate the complement
(`target - nums[i]`). If the complement is already in the hash map, I've
found the required pair and return the stored index along with the
current index. Otherwise, I insert the current number into the map and
continue. This solution traverses the array only once, giving O(n) time
complexity and O(n) extra space."

## Common Interview Questions

### Why `unordered_map`?

Average O(1) insertion and lookup.

### Why check before inserting?

For input `[3,3]`, checking first prevents matching an element with
itself and preserves the first index.

### Pattern

This problem teaches the **Hash Map + Complement** pattern, commonly
used in Pair Sum, Two Sum variants, 3Sum, and Subarray Sum problems.
