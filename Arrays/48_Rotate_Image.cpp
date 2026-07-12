# Rotate Image (LeetCode 48)

## Problem

Given an `n × n` matrix representing an image, rotate the image by **90°** in-place.

- Do **not** use another 2D matrix.
- Modify the original matrix directly.

---

# 90° Clockwise Rotation

## Approach

The rotation can be done in two steps:

1. Transpose the matrix.
2. Reverse every row.

### Example

#### Input

```text
1 2 3
4 5 6
7 8 9
```

### Step 1: Transpose

```text
1 4 7
2 5 8
3 6 9
```

### Step 2: Reverse Every Row

```text
7 4 1
8 5 2
9 6 3
```

### C++ Code

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // Transpose
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse every row
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```

### Complexity

- **Time:** O(n²)
- **Space:** O(1)

---

# 90° Anticlockwise Rotation

## Approach

The rotation can also be performed in-place.

Steps:

1. Transpose the matrix.
2. Reverse every column.

### Example

#### Input

```text
1 2 3
4 5 6
7 8 9
```

### Step 1: Transpose

```text
1 4 7
2 5 8
3 6 9
```

### Step 2: Reverse Every Column

```text
3 6 9
2 5 8
1 4 7
```

### C++ Code

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        // Transpose
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse every column
        for(int j = 0; j < n; j++) {
            int top = 0;
            int bottom = n - 1;

            while(top < bottom) {
                swap(matrix[top][j], matrix[bottom][j]);
                top++;
                bottom--;
            }
        }
    }
};
```

### Complexity

- **Time:** O(n²)
- **Space:** O(1)

---

# Quick Revision

| Rotation | Steps |
|----------|-------|
| **90° Clockwise** | Transpose → Reverse Rows |
| **90° Anticlockwise** | Transpose → Reverse Columns |

---

## Key Takeaways

- **Transpose:** Swap `matrix[i][j]` with `matrix[j][i]`.
- Start `j` from `i + 1` to avoid swapping the same pair twice.
- No extra matrix is required.
- This is the standard in-place interview solution.
