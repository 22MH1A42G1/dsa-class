Here's your **refined, structured, and cleaned-up version** of your **Binary Tree Notes**, complete with examples, visual diagrams, traversal methods, and detailed explanations:

---

# 🌳 Binary Trees — Complete Guide

A **Binary Tree (BT)** is a **hierarchical data structure** where each node has at most **two children**:

* **Left Child**
* **Right Child**

---

## 🧩 Structure of a Node

Each node contains:

* A **value**
* A **left pointer** (to its left child)
* A **right pointer** (to its right child)

```
--------------------------------------------------
| Left Pointer |   Data Value   | Right Pointer |
--------------------------------------------------
```

---

## 🌿 Tree Representation (Example Diagram)

```
               [10]                      ← Level 0 (root)
              /     \
          [20]       [70]               ← Level 1
         /    \      /    
      [15]  [62]   -                      ← Level 2
```

### Node Memory Addresses (Illustrative)

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

## ⏱️ Time Complexity (Balanced Binary Tree)

* **Height (h)** = `log₂(n + 1)`  where `n` = number of nodes
* **Nodes per level**:

  * Level 0 → 2⁰ = 1 node
  * Level 1 → 2¹ = 2 nodes
  * Level 2 → 2² = 4 nodes
* **Operations** like search, insert, delete (on a balanced BT):
  🔁 `O(log n)`

---

## 🌲 Skewed Binary Trees

A tree where each node has only one child.

### 🔹 Right Skewed

```
(1)
   \
   (2)
      \
      (3)
         \
         (4)
```

### 🔹 Left Skewed

```
       (4)
      /
    (3)
   /
 (2)
 /
(1)
```

### ⏳ Time Complexity: `O(n)` — equivalent to a linked list.

---

## 🌕 Full Binary Tree

A Binary Tree in which **every node has 0 or 2 children**.

✅ Valid Full BT:

```
     (1)
    /   \
  (2)   (3)
```

❌ Invalid Full BT:

```
     (1)
    /   \
  (2)   (3)
         \
         (4) ← only one child → violates "full" condition
```

---

## ✅ Complete Binary Tree

* All levels are completely filled **except possibly the last**.
* The last level's nodes are filled **from left to right**.

✅ Valid Example:

```
       (1)
      /   \
    (2)   (3)
   / \   / 
 (4)(5)(6)
```

❌ Invalid Example:

```
       (1)
      /   \
    (2)   (3)
         /   \
       (6)  (7)  ← Not filled from left → violates "complete" rule
```

---

## 🏆 Perfect Binary Tree

* **All internal nodes** have **2 children**
* **All leaves are at the same level**

✅ Example:

```
        (1)
       /   \
     (2)   (3)
    / \   / \
  (4)(5)(6)(7)
```

---

## ↕️ Balanced Binary Tree

For every node:

```
| height(left) - height(right) | ≤ 1
```

### ✅ Balanced Example:

```
       (1)
      /   \
    (2)   (3)
   /         \
 (4)         (5)
```

### ❌ Not Balanced:

```
       (1)
      /   \
    (2)   (3)
   /       
 (4)
    \
    (5)
```

---

## 🧮 Summary Table

| Tree Type    | Key Property                                                 |                            |       |
| ------------ | ------------------------------------------------------------ | -------------------------- | ----- |
| **Skewed**   | All nodes on one side (Left or Right)                        |                            |       |
| **Full**     | Every node has either 0 or 2 children                        |                            |       |
| **Complete** | All levels filled except last; last filled left to right     |                            |       |
| **Perfect**  | All internal nodes have 2 children; all leaves at same level |                            |       |
| **Balanced** | For each node: \`                                            | left height - right height | ≤ 1\` |

---

## 🔁 Tree Traversals (DFS)

### Depth-First Search (DFS)

* **PreOrder**: `root → left → right`
* **InOrder**: `left → root → right`
* **PostOrder**: `left → right → root`

#### Example Tree:

```
        (10)
        /    \
     (20)   (30)
     /        /  \
   (4)     (8) (9)
```

* **PreOrder**: `10 → 20 → 4 → 30 → 8 → 9`
* **InOrder**: `4 → 20 → 10 → 8 → 30 → 9`
* **PostOrder**: `4 → 20 → 8 → 9 → 30 → 10`

---

## 📊 Breadth-First Search (BFS / Level Order)

```
        (2)
       /   \
     (3)   (4)
     / \    /
   (5)(6)(7)
         /    \
       (8)   (9)
```

### Level Order Traversal (Queue Approach)

* Use a queue to track nodes per level
* Enqueue root → while queue not empty:

  * Dequeue current node
  * Enqueue left, then right child (if present)

#### Step-by-Step Queue Levels:

| Step | Queue Contents | Level |
| ---- | -------------- | ----- |
| 1    | \[2]           | 0     |
| 2    | \[3, 4]        | 1     |
| 3    | \[5, 6, 7]     | 2     |
| 4    | \[8, 9]        | 3     |

---

## 🧮 Height of Binary Tree

### Recursive Formula:

```
height(node) = 1 + max(height(left), height(right))
```

### Example:

```
       (1)
      /   \
    (2)   (3)
   /
 (4)
```

* Height of node(4) = 0
* Height of node(2) = 1 + max(0, -1) = 1
* Height of root(1) = 1 + max(1, 0) = 2

---

## 📏 Diameter of a Binary Tree

The **diameter** is the **length of the longest path** between any two nodes (measured in edges).

### Example Tree:

```
       (1)
      /   \
    (2)   (3)
   / \
 (4) (5)
```

* Longest paths:

  * 4 → 2 → 5
  * 4 → 2 → 1 → 3

→ Both have **3 edges**

✅ **Diameter = 3**

---

Let me know if you'd like this turned into **flashcards**, a **PDF**, or code examples in a particular language (like Python or Java).
