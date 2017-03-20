from BST import Node

def Search(root,key):
	if root is None or root.key == key:
		return root
	if root.key < key:
		return Search(root.right,key)

	return Search(root.left,key)

def Insert_iter(root,node):
	cur_node = root
	if not node:
		root = node
	else:
		while(True):
			if key < cur_node.key and cur_node.left:
				cur_node = cur_node.left
			elif key > cur_node.key and cur_node.right:
				cur_node = cur_node.right

			if not cur_node.right and key > cur_node.key:
				cur_node.right = node
				break
			elif not cur_node.left and key < cur_node.key:
				cur_node.left = node
				break
	return root

def Insert_rec(root,node):
	if not root:
		root = new_node
	else:
		if node.key > root.key:
			if root.right is None:
				root.right = node
			else:
				Insert_rec(root.right,node)
		else:
			if root.left is None:
				root.left = node
			else:
				Insert_rec(root.left,node)

def inorder(root):
	if root:
		inorder(root.left)
		print root.key,
		inorder(root.right)

root = Node(15)
n1 = Node(3)
n2 = Node(17)
n3 = Node(14)
n4 = Node(23)
n5 = Node(6)
Insert_rec(root,n1)
Insert_rec(root,n2)
Insert_rec(root,n3)
Insert_rec(root,n4)
Insert_rec(root,n5)
inorder(root)