# 344. Reverse String

## Problem Statement

Write a function that reverses a string.

- The input is given as an array of characters `vector<char>`.
- Reverse the array **in-place**.
- Use only **O(1)** extra memory.

### Example 1

```text
Input:  s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
```

### Example 2

```text
Input:  s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
```

---

# Approach (Two Pointers)

## Idea

Use two pointers:

- One pointer (`st`) starts from the beginning.
- Another pointer (`end`) starts from the end.

Swap both characters and move the pointers towards the center until they meet.

This reverses the string **in-place**, so no extra array is required.

---

# C++ Solution

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {

        int st = 0;
        int end = s.size() - 1;

        while(st < end) {
            swap(s[st++], s[end--]);
        }
    }
};
```

---

# Line-by-Line Explanation

## Function Definition

```cpp
void reverseString(vector<char>& s)
```

- Takes the character array as input.
- `&` means the vector is passed **by reference**, so changes are made to the original array.

---

## Initialize Two Pointers

```cpp
int st = 0;
int end = s.size() - 1;
```

- `st` points to the first character.
- `end` points to the last character.

Example:

```text
h  e  l  l  o
^           ^
st         end
```

---

## Loop Until Both Pointers Meet

```cpp
while(st < end)
```

Keep swapping until both pointers cross.

---

## Swap the Characters

```cpp
swap(s[st++], s[end--]);
```

This line performs three operations:

### Step 1

```cpp
swap(s[st], s[end]);
```

Swap the first and last characters.

### Step 2

```cpp
st++;
```

Move the left pointer one step to the right.

### Step 3

```cpp
end--;
```

Move the right pointer one step to the left.

Because of **post-increment (`st++`)** and **post-decrement (`end--`)**, the swap happens first, then the pointers move.

---

# Dry Run

## Input

```text
["h","e","l","l","o"]
```

Initial:

```text
h  e  l  l  o
^           ^
st         end
```

### Iteration 1

Swap

```text
h ↔ o
```

Result

```text
o  e  l  l  h
   ^     ^
  st    end
```

---

### Iteration 2

Swap

```text
e ↔ l
```

Result

```text
o  l  l  e  h
      ^
   st=end
```

Loop stops because `st` is no longer less than `end`.

Final Answer

```text
["o","l","l","e","h"]
```

---

# Example 2

Input

```text
["H","a","n","n","a","h"]
```

### Initial

```text
H  a  n  n  a  h
^              ^
st            end
```

### Swap 1

```text
h  a  n  n  a  H
```

### Swap 2

```text
h  a  n  n  a  H
```

(The second swap exchanges the two `'a'` characters, so the array looks the same.)

### Swap 3

```text
h  a  n  n  a  H
```

(The third swap exchanges the two `'n'` characters.)

Output

```text
["h","a","n","n","a","H"]
```

---

# Why Two Pointers?

Instead of creating another array, we simply swap elements from both ends.

This saves memory and is the optimal solution.

---

# Complexity Analysis

### Time Complexity

Each character is visited at most once.

**O(n)**

### Space Complexity

No extra array is used.

**O(1)**

---

# Key Takeaways

- Use **Two Pointers**.
- Start one pointer from the beginning and the other from the end.
- Swap both characters.
- Move both pointers towards the center.
- Continue until the pointers meet.
- In-place solution with **O(n)** time and **O(1)** space.
