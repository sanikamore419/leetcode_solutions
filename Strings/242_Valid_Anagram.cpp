# 242. Valid Anagram

## Problem Statement

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, otherwise return `false`.

An **anagram** is a word or phrase formed by rearranging the letters of another word using **all the original letters exactly once**.

---

## Examples

### Example 1

```text
Input: s = "anagram", t = "nagaram"

Output: true
```

### Example 2

```text
Input: s = "rat", t = "car"

Output: false
```

---

# Approach (Frequency Array)

## Idea

Two strings are anagrams if:

- They have the **same length**.
- Every character appears the **same number of times**.

We use a frequency array of size **26** because the strings contain only lowercase English letters.

### Algorithm

1. Check whether both strings have the same length.
2. Create a frequency array of size 26.
3. Count every character of string `s`.
4. Decrease the frequency for every character of string `t`.
5. If every frequency becomes `0`, both strings are anagrams.

---

# C++ Solution

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {

        // Step 1: Check if lengths are equal
        if(s.size() != t.size()) {
            return false;
        }

        // Step 2: Create frequency array
        vector<int> freq(26, 0);

        // Step 3: Count characters of s
        for(char c : s) {
            freq[c - 'a']++;
        }

        // Step 4: Decrease frequency using t
        for(char c : t) {
            freq[c - 'a']--;
        }

        // Step 5: Check frequencies
        for(int count : freq) {
            if(count != 0) {
                return false;
            }
        }

        return true;
    }
};
```

---

# Code Explanation

## Step 1

```cpp
if(s.size() != t.size()) {
    return false;
}
```

If the lengths are different, they can never be anagrams.

Example

```text
s = "cat"
t = "cats"

Length:
3 != 4

Return false
```

---

## Step 2

```cpp
vector<int> freq(26, 0);
```

Creates a frequency array of size **26**.

Initially,

| Character | Frequency |
|-----------|----------:|
| a | 0 |
| b | 0 |
| c | 0 |
| ... | ... |
| z | 0 |

Each index stores the count of one letter.

---

## Step 3

```cpp
for(char c : s) {
    freq[c - 'a']++;
}
```

Count the occurrence of every character in `s`.

### What does `c - 'a'` mean?

It converts a character into an array index.

| Character | Index |
|-----------|------:|
| a | 0 |
| b | 1 |
| c | 2 |
| d | 3 |
| ... | ... |
| z | 25 |

Example

```cpp
c = 'd'

'd' - 'a' = 3
```

So,

```cpp
freq[3]++;
```

increases the count of `'d'`.

---

## Step 4

```cpp
for(char c : t) {
    freq[c - 'a']--;
}
```

Decrease the frequency using the second string.

If both strings contain the same characters, every increase from the first loop is cancelled by a decrease in the second loop.

---

## Step 5

```cpp
for(int count : freq) {
    if(count != 0) {
        return false;
    }
}
```

Check every frequency.

If any value is **not zero**, the strings are **not** anagrams.

Otherwise, return `true`.

---

# Dry Run

## Input

```text
s = "anagram"
t = "nagaram"
```

### Count characters of `s`

```text
a → 3
n → 1
g → 1
r → 1
m → 1
```

### Decrease using `t`

```text
n → 0
a → 2
g → 0
a → 1
r → 0
a → 0
m → 0
```

Final frequencies

```text
a → 0
n → 0
g → 0
r → 0
m → 0
```

All frequencies are `0`.

Return

```text
true
```

---

## Example 2

```text
s = "rat"
t = "car"
```

After counting `s`

```text
a → 1
r → 1
t → 1
```

After decreasing using `t`

```text
a → 0
r → 0
t → 1
c → -1
```

Some frequencies are not zero.

Return

```text
false
```

---

# Complexity Analysis

### Time Complexity

- Count characters of `s` → **O(n)**
- Decrease using `t` → **O(n)**
- Check frequency array → **O(26)** ≈ **O(1)**

Overall:

**O(n)**

---

### Space Complexity

Uses a fixed-size frequency array of 26 elements.

**O(1)**

---

# Follow-up (Unicode Characters)

If the strings contain **Unicode characters**, a frequency array of size 26 is not enough.

Instead, use a hash map:

```cpp
unordered_map<char, int> freq;
```

The approach remains the same:

- Count characters from the first string.
- Decrease counts using the second string.
- Check if all frequencies become zero.

---

# Key Takeaways

- First check whether both strings have the same length.
- Use a frequency array to count characters.
- Increase counts for the first string.
- Decrease counts for the second string.
- If every frequency becomes **0**, the strings are anagrams.
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`
