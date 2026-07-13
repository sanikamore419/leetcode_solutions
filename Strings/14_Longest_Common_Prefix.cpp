/*
==========================================================
LeetCode 14. Longest Common Prefix
Difficulty: Easy

Approach:
- Use the first string as the reference.
- Compare each character of the first string with
  the corresponding character of every other string.
- If a mismatch is found or a string ends,
  return the prefix found so far.
- If all characters match, return the first string.

Time Complexity: O(N × M)
N = Number of strings
M = Length of the first string

Space Complexity: O(1)
==========================================================
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        // If the array is empty
        if (strs.empty()) {
            return "";
        }

        // Traverse each character of the first string
        for (int i = 0; i < strs[0].size(); i++) {

            // Current character
            char ch = strs[0][i];

            // Compare with every other string
            for (int j = 1; j < strs.size(); j++) {

                // If index is out of range or characters don't match
                if (i >= strs[j].size() || strs[j][i] != ch) {

                    // Return common prefix till previous index
                    return strs[0].substr(0, i);
                }
            }
        }

        // Entire first string is the common prefix
        return strs[0];
    }
};

int main() {

    Solution obj;

    vector<string> strs = {"flower", "flow", "flight"};

    cout << "Longest Common Prefix: "
         << obj.longestCommonPrefix(strs) << endl;

    return 0;
}
