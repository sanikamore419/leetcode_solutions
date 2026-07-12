# 387. First Unique Character in a String

## Problem Statement

Given a string `s`, return the **index of the first non-repeating (unique) character**. If no such character exists, return `-1`.

### Examples

**Example 1**

```text
Input: s = "leetcode"
Output: 0
```

**Example 2**

```text
Input: s = "loveleetcode"
Output: 2
```

**Example 3**

```text
Input: s = "aabb"
Output: -1
```

---

# Approach (Frequency Array)

### Idea

1. Count how many times each character appears.
2. Traverse the string again.
3. Return the index of the first character whose frequency is `1`.

Since the string contains only lowercase English letters (`a-z`), we use a frequency array of size **26**.

---

# C++ Solution

```cpp
class Solution {
public:
    int firstUniqChar(string s) {

        // Frequency array to store count of each character
        vector<int> freq(26, 0);

        // Step 1: Count the frequency of each character
        for(char ch : s) {
            freq[ch - 'a']++;
        }

        // Step 2: Find the first unique character
        for(int i = 0; i < s.size(); i++) {
            if(freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        // Step 3: No unique character found
        return -1;
    }
};
```

---

# Line-by-Line Explanation

## 1. Create a Frequency Array

```cpp
vector<int> freq(26, 0);
```

Creates an array of size **26** (for letters `a` to `z`).

Initially:

| Character | Frequency |
| --------- | --------: |
| a         |         0 |
| b         |         0 |
| c         |         0 |
| ...       |       ... |
| z         |         0 |

---

## 2. Count Character Frequencies

```cpp
for(char ch : s) {
    freq[ch - 'a']++;
}
```

### What does `ch - 'a'` mean?

Every lowercase letter is converted into an array index.

| Character | Index |
| --------- | ----: |
| a         |     0 |
| b         |     1 |
| c         |     2 |
| d         |     3 |
| ...       |   ... |
| z         |    25 |

Example:

```cpp
ch = 'c';

'ch' - 'a'
= 99 - 97
= 2
```

So,

```cpp
freq[ch - 'a']++;
```

becomes

```cpp
freq[2]++;
```

which increases the frequency of `'c'`.

---

## Example

Input:

```text
abbac
```

Initially:

```text
a b c

0 0 0
```

Read `'a'`

```cpp
freq[0]++;
```

```text
1 0 0
```

Read `'b'`

```cpp
freq[1]++;
```

```text
1 1 0
```

Read second `'b'`

```cpp
freq[1]++;
```

```text
1 2 0
```

Read second `'a'`

```cpp
freq[0]++;
```

```text
2 2 0
```

Read `'c'`

```cpp
freq[2]++;
```

```text
2 2 1
```

Final frequencies:

```text
a → 2
b → 2
c → 1
```

---

## 3. Find the First Unique Character

```cpp
for(int i = 0; i < s.size(); i++) {
```

Traverse the string from left to right.

---

## 4. Check Frequency

```cpp
if(freq[s[i] - 'a'] == 1)
```

This checks whether the current character appears exactly **once**.

Example:

```text
s = "loveleetcode"
```

Frequency table:

```text
l → 2
o → 2
v → 1
e → 4
t → 1
c → 1
d → 1
```

Traversal:

| Index | Character | Frequency | Action   |
| ----: | --------- | --------: | -------- |
|     0 | l         |         2 | Skip     |
|     1 | o         |         2 | Skip     |
|     2 | v         |         1 | Return 2 |

Output:

```text
2
```

---

## 5. Return the Index

```cpp
return i;
```

As soon as the first unique character is found, return its index.

---

## 6. No Unique Character

```cpp
return -1;
```

If every character appears more than once, return `-1`.

Example:

```text
Input: "aabb"

a → 2
b → 2

Output: -1
```

---

# Dry Run

Input:

```text
loveleetcode
```

### Frequency Count

```text
l → 2
o → 2
v → 1
e → 4
t → 1
c → 1
d → 1
```

### Find First Unique

| Index | Character | Frequency |
| ----: | --------- | --------: |
|     0 | l         |         2 |
|     1 | o         |         2 |
|     2 | v         |       1 ✅ |

Return:

```text
2
```

---

# Complexity Analysis

**Time Complexity:** `O(n)`

* One traversal to count frequencies.
* One traversal to find the first unique character.

**Overall:** `O(n)`

**Space Complexity:** `O(1)`

* Uses a fixed-size frequency array of 26 elements.

---

# Key Takeaways

* Use a frequency array because only lowercase letters are present.
* `ch - 'a'` converts a character into an array index.
* First pass counts frequencies.
* Second pass finds the first character whose frequency is `1`.
* This is the optimal solution with **O(n)** time and **O(1)** space.
