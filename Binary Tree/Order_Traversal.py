from collections import deque

# Node structure
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

# Tree class
class Tree:
    def __init__(self):
        self.root = None

    # Build Tree from space-separated level order string
    def build_tree(self, s):
        if not s or s[0] == 'N':
            return

        info = s.split()
        self.root = Node(int(info[0]))

        queue = deque([self.root])
        i = 1

        while queue and i < len(info):
            curr = queue.popleft()

            # Left child
            if i < len(info) and info[i] != 'N':
                curr.left = Node(int(info[i]))
                queue.append(curr.left)
            i += 1

            # Right child
            if i < len(info) and info[i] != 'N':
                curr.right = Node(int(info[i]))
                queue.append(curr.right)
            i += 1

    # Inorder Traversal (Left, Root, Right)
    def inorder(self, node):
        if not node:
            return
        self.inorder(node.left)
        print(node.data, end=" ")
        self.inorder(node.right)

    # Preorder Traversal (Root, Left, Right)
    def preorder(self, node):
        if not node:
            return
        print(node.data, end=" ")
        self.preorder(node.left)
        self.preorder(node.right)

    # Postorder Traversal (Left, Right, Root)
    def postorder(self, node):
        if not node:
            return
        self.postorder(node.left)
        self.postorder(node.right)
        print(node.data, end=" ")

    # Public wrappers
    def print_inorder(self):
        print("Inorder Traversal: ", end="")
        self.inorder(self.root)
        print()

    def print_preorder(self):
        print("Preorder Traversal: ", end="")
        self.preorder(self.root)
        print()

    def print_postorder(self):
        print("Postorder Traversal: ", end="")
        self.postorder(self.root)
        print()

# Driver code
if __name__ == "__main__":
    tree = Tree()
    s = input("Enter tree (level order, space separated): ")  # Example: 10 20 30 N 40 N N
    tree.build_tree(s)

    tree.print_inorder()
    tree.print_preorder()
    tree.print_postorder()
