Here's a **well-organized and cleaned-up version** of your notes on **Binary Trees**, including explanations and examples for each concept:

---

## 🌳 Binary Tree (BT)

A **Binary Tree** is a hierarchical data structure in which each node has at most **two children**:

* **Left Child**
* **Right Child**

### Structure of a Node

Each node contains:

* A **value**
* A **pointer to the left child**
* A **pointer to the right child**

```
--------------------------------------------------
| Left Pointer |   Data Value   | Right Pointer |
--------------------------------------------------
```

---

## 🌿 Tree Representation (Diagram)

```
               [10]                      ← Level 0 (root)
              /     \
          [20]       [70]               ← Level 1
         /    \      /    
      [15]  [62]   -                      ← Level 2
```

### Node Addresses (Example):

```
root (0x1)
      |
    [10]
   /    \
(ax1)   (cx1)
[20]    [70]
 / \
ex1 dx1
[15] [62]
```

---

## ⏳ Time Complexity (for balanced BT)

* **Height (h)** = `log₂(n + 1)`
* **Nodes per level**:

  * Level 0: `2^0 = 1` node
  * Level 1: `2^1 = 2` nodes
  * Level 2: `2^2 = 4` nodes
* `TC = O(log₂(n+1))`

---

## 🌲 Skewed Tree

A tree where all the nodes form a straight line.

### Right Skewed Example:

```
( )
   \
    ( )
       \
        ( )
           \
            ( )
```

### Left Skewed Example:

```
       ( )
      /
    ( )
    /
  ( )
  /
( )
```

### ⏳ TC: O(N) — because every node has only one child.

---

## 🌕 Full Binary Tree

Every node has **0 or 2 children** (no node has exactly 1 child).

✅ Examples:

```
   (1)
   / \
 ( ) ( )

   (3)
   / \
 ( ) ( )
```

❌ Not Full:

```
   (2)
   / \
 ( ) ( )
        \
         ( )  ← has only one child
```

---

## ✅ Complete Binary Tree

All levels are fully filled **except possibly the last**, and all nodes are **as far left as possible**.

### ✅ Valid Complete BT:

```
       (1)
       / \
     ( ) ( )
    / \  / \
  ( )( )( )( )

       (3)
       / \
     ( ) ( )
    / \
  ( )( )
```

### ❌ Not Complete BT:

```
       (2)
       / \
     ( ) ( )
           / \
         ( )( )   ← last level not filled from left
```

---

## 🏆 Perfect Binary Tree

* **All internal nodes** have **2 children**
* **All leaf nodes** are at the **same level**

### ✅ Perfect BT Example:

```
        (1)
        / \
      ( ) ( )
     / \ / \
   ( )( )( )( )
```

---

## ↕️ Balanced Binary Tree

For every node, the **height difference** between left and right subtrees is at most **1**.

```
| abs(height(left) - height(right)) <= 1 |
```

### ✅ Balanced Example:

```
       ( )
       / \
     ( ) ( )
    /     \
  ( )     ( )
```

### ❌ Not Balanced:

```
       ( )
       / \
     ( )  ( )
     /
   ( )
     \
      ( )
```

* At root, `abs(1 - 2) = 1` → ✅
* At deeper levels, imbalance occurs → ❌

---

## Summary Table

| Type         | Key Property                                                 |
| ------------ | ------------------------------------------------------------ |
| **Skewed**   | All nodes on one side (Left or Right)                        |
| **Full**     | Every node has 0 or 2 children                               |
| **Complete** | All levels filled except last; last filled left to right     |
| **Perfect**  | All internal nodes have 2 children; all leaves at same level |
| **Balanced** | For every node: `abs(height(left) - height(right)) <= 1`     |

---


### ✅ **Build Tree (Level Order)**

* A binary tree can be built from a string using **level order traversal**, where each node's value is followed by its left and right child (or `"N"` for null).

* For example:
  `"10 20 30 N 40 N N"` means:

  ```
         10
        /  \
      20    30
        \
         40
  ```

* Process:

  * First value becomes the **root**.
  * Insert left and right children using a queue.
  * If you see `"N"`, it means the corresponding child is `NULL`.

---

### ✅ **Inorder Traversal (Left → Root → Right)**

* Visit left subtree

* Visit root node

* Visit right subtree

* Example:

  ```
        1
       / \
      2   3
     / \
    4   5
  ```

  Inorder: **4 2 5 1 3**

---

### ✅ **Preorder Traversal (Root → Left → Right)**

* Visit root node

* Visit left subtree

* Visit right subtree

* Example:

  ```
        1
       / \
      2   3
     / \
    4   5
  ```

  Preorder: **1 2 4 5 3**

---

### ✅ **Postorder Traversal (Left → Right → Root)**

* Visit left subtree

* Visit right subtree

* Visit root node

* Example:

  ```
        1
       / \
      2   3
     / \
    4   5
  ```

  Postorder: **4 5 2 3 1**

---

To calculate the **left subtree height** and **right subtree height** of a binary tree using **DFS (Depth-First Search)**, you typically use **recursive traversal**.

Here's the step-by-step concept

---

### ✅ **What is Height of a Tree/Subtree?**

* **Height** = number of **edges** on the longest path from a node down to a leaf.
* Alternatively, if counting **nodes**, height = number of nodes on the longest path minus 1.
* Base case: If the node is `NULL`, height is `-1` (or `0` if counting nodes).

---

### ✅ **Steps to Calculate Left and Right Subtree Height Using DFS:**

1. **Start from the root node.**
2. Use a recursive DFS function to:

   * Traverse left child recursively → this gives **left subtree height**.
   * Traverse right child recursively → this gives **right subtree height**.
3. For each subtree:

   * Height = `1 + max(left subtree height, right subtree height)`
4. To get:

   * **Left subtree height** → call DFS on `root->left`
   * **Right subtree height** → call DFS on `root->right`

---

### 📌 **Example Tree:**

```
        10
       /  \
     20    30
       \
        40
```

* DFS on `root->left (20)`:

  * Left: NULL → height = -1
  * Right → 40 → height = 0
  * So, height = `1 + max(-1, 0)` = 1
* DFS on `root->right (30)`:

  * No children → height = 0

✅ Final:

* Left Subtree Height = **1**
* Right Subtree Height = **0**

---

Great notes! You’ve summarized **DFS** and **BFS** tree traversal techniques very well. Here's a polished and structured explanation that might help you retain this better and use it in interviews or exams.

---

## 🌳 Tree Traversal Summary

---

### **DFS (Depth-First Search)**

Traverses *deep down* before moving sideways.

#### ✅ PreOrder Traversal

* **Order**: Root → Left → Right
* **Use-case**: Clone trees, prefix expressions
* **Example**:

  ```
      10
     /  \
   20    30
   /     / \
  4     8   9
  ```

  **PreOrder**: `10 20 4 30 8 9`

#### ✅ InOrder Traversal

* **Order**: Left → Root → Right
* **Use-case**: Binary Search Tree ⇒ *Sorted Output*
* **Example**:
  **InOrder**: `4 20 10 8 30 9`

#### ✅ PostOrder Traversal

* **Order**: Left → Right → Root
* **Use-case**: Deleting tree, postfix expressions
* **Example**:
  **PostOrder**: `4 20 8 9 30 10`

---

### **BFS (Breadth-First Search / Level Order)**

Traverses *level by level* from top to bottom, left to right.

#### ✅ Level Order Traversal

* **Queue is used**
* At each level:

  1. Check `queue size` ⇒ number of nodes at that level
  2. Process those many nodes
  3. Enqueue their children (left → right)

#### Example Tree:

```
        2
      /   \
     3     4
    / \    /
   5   6  7
        \   \
         8   9
```

#### Traversal Steps:

```
Queue: [2]
→ Level 0: [2]

Queue: [3, 4]
→ Level 1: [3, 4]

Queue: [5, 6, 7]
→ Level 2: [5, 6, 7]

Queue: [8, 9]
→ Level 3: [8, 9]
```

**Level Order Output**: `2 3 4 5 6 7 8 9`

---

## 💡 Bonus

### 🤔 Why Queue in BFS?

Because we need **FIFO** behavior: first in → first out, to process nodes level by level.

### 🤔 Why Stack/Recursion in DFS?

Because we go deep before exploring siblings, and **LIFO** (last in → first out) is required.

---

## ✅ **Diameter of a Binary Tree** 

---

#### 📌 **Definition:**

The **diameter** (or width) of a binary tree is the **length of the longest path between any two nodes** in the tree.
This path **may or may not pass through the root**.

* The **length** is measured in terms of **number of edges**, not nodes.
* So, if the longest path has 4 nodes, the diameter is 3.

---

### 🔍 **Key Formula (DFS Approach):**

For any node:

```
diameter = max(diameter, leftHeight + rightHeight)
```

We compute the height of left and right subtrees for each node recursively and update the diameter.


---

### 🧠 **Example Input**

```
1 2 3 4 5 N N
```

```
         1
       /   \
     2      3
   /  \
  4    5
```

### ✅ **Output**

```
Diameter of Binary Tree: 3
```

🧮 Explanation:

* Longest path is: `4 → 2 → 5` or `4 → 2 → 1 → 3` (both have 3 edges)
* So, Diameter = 3

---



