# 206. Reverse Linked List

## Problem Statement
Given the `head` of a singly linked list, reverse the list and return the new head.

### Example

**Input:**
```
1 -> 2 -> 3 -> 4 -> 5
```

**Output:**
```
5 -> 4 -> 3 -> 2 -> 1
```

---

## Approach (Iterative)

We use three pointers:

- **prev** → Points to the previous node.
- **curr** → Points to the current node.
- **next** → Temporarily stores the next node before changing links.

### Algorithm

1. Initialize:
   - `prev = NULL`
   - `curr = head`
2. Traverse the linked list until `curr` becomes `NULL`.
3. Store the next node.
4. Reverse the current node's link.
5. Move `prev` and `curr` one step forward.
6. Return `prev`, which becomes the new head of the reversed list.

---

## Code

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }
};
```

---

## Dry Run

Initial List:

```
1 -> 2 -> 3 -> NULL
```

### Iteration 1

```
prev = NULL
curr = 1

next = 2
1 -> NULL

prev = 1
curr = 2
```

Current List:

```
1 -> NULL

2 -> 3
```

---

### Iteration 2

```
next = 3

2 -> 1 -> NULL

prev = 2
curr = 3
```

Current List:

```
2 -> 1 -> NULL

3
```

---

### Iteration 3

```
next = NULL

3 -> 2 -> 1 -> NULL

prev = 3
curr = NULL
```

Loop ends.

Return:

```
3 -> 2 -> 1 -> NULL
```

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## Key Learning

The order of operations is very important:

```cpp
next = curr->next;   // Save next node
curr->next = prev;   // Reverse the link
prev = curr;         // Move prev forward
curr = next;         // Move curr forward
```

Remember it as:

**Save → Reverse → Move Prev → Move Curr**
