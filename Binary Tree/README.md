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

If you'd like, I can provide diagrams or animations to visualize these traversals.

