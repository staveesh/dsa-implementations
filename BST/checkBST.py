from BST import Node

def inorder(root,arr):
	if root:
		inorder(root.left,arr)
		arr.append(root.key)
		inorder(root.right,arr)

def isBST(root):
	arr = []
	inorder(root,arr)
	return arr == sorted(arr)

root = Node(6)
root.left = Node(9)
root.right = Node(10)
root.left.left = Node(17)
root.left.right = Node(4)
root.right.right = Node(11)

print isBST(root)

root = Node(6)
root.left = Node(4)
root.right = Node(7)

print isBST(root)