from BST import Node

def minValue(root):
	current = root

	while current.left:
		current = current.left
	return current

def Delete(root,key):
	if root is None:
		return root

	if key < root.key:
		root.left = Delete(root.left,key)

	elif key > root.key:
		root.right = Delete(root.right,key)

	else:
		if root.left is None:
			temp = root.right
			root = None
			return temp
		if root.right is None:
			temp = root.left
			root = None
			return temp

		temp = minValue(root.right)
		root.key = temp.key
		root.right = Delete(root.right,temp.key)
	return root

def inorder(root):
	if root:
		inorder(root.left)
		print root.key,
		inorder(root.right)

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

root = Node(50)
n1 = Node(30)
n2 = Node(70)
n3 = Node(60)
n4 = Node(80)
n5 = Node(20)
n6 = Node(40)
Insert_rec(root,n1)
Insert_rec(root,n2)
Insert_rec(root,n3)
Insert_rec(root,n4)
Insert_rec(root,n5)
Insert_rec(root,n6)
inorder(root)
print ''
Delete(root,20)
inorder(root)
print ''
Delete(root,30)
inorder(root)
print ''
Delete(root,50)
inorder(root)