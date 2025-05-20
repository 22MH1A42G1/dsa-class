from collections import deque

class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

class Tree:
    def __init__(self):
        self.root = None

    def build_tree(self, s):
        """Builds a binary tree from a space-separated level-order string,
        where 'N' denotes a null."""
        if not s or s[0] == 'N':
            return

        vals = s.split()
        self.root = Node(int(vals[0]))
        queue = deque([self.root])
        i = 1

        while queue and i < len(vals):
            curr = queue.popleft()

            # left child
            if vals[i] != 'N':
                curr.left = Node(int(vals[i]))
                queue.append(curr.left)
            i += 1

            # right child
            if i < len(vals) and vals[i] != 'N':
                curr.right = Node(int(vals[i]))
                queue.append(curr.right)
            i += 1

    def bfs(self):
        """Prints the tree in level-order."""
        if not self.root:
            print("Tree is empty.")
            return

        queue = deque([self.root])
        print("Level-order Traversal:", end=" ")

        while queue:
            node = queue.popleft()
            print(node.data, end=" ")
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

        print()

# Example usage
if __name__ == "__main__":
    tree = Tree()
    s = input("Enter tree (level order, space separated): ")  
    # e.g. "2 3 4 5 6 7 N N 8 N N 9"
    tree.build_tree(s)
    tree.bfs()
