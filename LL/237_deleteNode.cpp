# 237. Delete Node in a Linked List

## Problem Statement

Write a function to delete a node in a **singly linked list**, given only access to that node.

> **Note:** You are **not given the head** of the linked list. The node to be deleted is **not the last node** in the list.

### Example

**Input:**
```
4 -> 5 -> 1 -> 9
```

Delete node:
```
5
```

**Output:**
```
4 -> 1 -> 9
```

---

## Approach

Since we do **not have the head** of the linked list, we cannot reach the previous node to remove the current node.

Instead, we:

1. Copy the value of the next node into the current node.
2. Store the next node in a temporary pointer.
3. Skip the next node by updating the current node's `next` pointer.
4. Delete the temporary node.

This makes it appear as if the given node has been deleted.

---

## Code

```cpp
class Solution {
public:
    void deleteNode(ListNode* node) {

        node->val = node->next->val;

        ListNode* temp = node->next;

        node->next = node->next->next;

        delete temp;
    }
};
```

---

## Dry Run

Given the linked list:

```
4 -> 5 -> 1 -> 9
```

Suppose `node` points to **5**.

### Step 1

Copy the next node's value.

```cpp
node->val = node->next->val;
```

Now the list becomes:

```
4 -> 1 -> 1 -> 9
```

---

### Step 2

Store the next node.

```cpp
ListNode* temp = node->next;
```

```
temp
 ↓
1
```

---

### Step 3

Skip the next node.

```cpp
node->next = node->next->next;
```

Now:

```
4 -> 1 -> 9
```

The duplicate node is no longer part of the linked list.

---

### Step 4

Delete the unused node.

```cpp
delete temp;
```

Memory is freed.

Final linked list:

```
4 -> 1 -> 9
```

---

## Complexity Analysis

- **Time Complexity:** `O(1)`
- **Space Complexity:** `O(1)`

---

## Key Learning

Normally, deleting a node in a singly linked list requires access to the **previous node**.

Since the previous node is unavailable, we use a trick:

```cpp
node->val = node->next->val;      // Copy next node's value
ListNode* temp = node->next;      // Store next node
node->next = node->next->next;    // Skip next node
delete temp;                      // Free memory
```

Instead of deleting the current node, we **copy the next node's data** into it and remove the next node.

This works because the given node is **guaranteed not to be the last node**.
