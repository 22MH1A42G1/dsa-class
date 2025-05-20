from collections import deque

# Define a Node class
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None

# Tree class to build tree and perform inorder traversal
class Tree:
    def __init__(self):
        self.root = None

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

    def inorder(self, node):
        if not node:
            return
        self.inorder(node.left)
        print(node.data, end=" ")
        self.inorder(node.right)

    def print_inorder(self):
        self.inorder(self.root)
        print()

# Main code
if __name__ == "__main__":
    tree = Tree()
    s = input("Enter tree in level order (e.g., '10 20 30 N 40 N N'): ")
    tree.build_tree(s)

    print("Inorder Traversal:", end=" ")
    tree.print_inorder()
