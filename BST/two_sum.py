from BST import Node

def minval(root):
	temp = root
	while temp.left:
		temp = temp.left
	return temp

def maxval(root):
	temp = root
	while temp.right:
		temp = temp.right
	return temp

def suc(root,node):
	if node.right:
		return minval(node.right)
	while root:
		if root.key > node.key:
			succ = root
			root = root.left
		elif root.key < node.key:
			root = root.right
		else:
			break
	return succ
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

def two_sum(root,k):
	l = minval(root)
	r = maxval(root)
	while True:
		if l.key + r.key > k:
			
k = int(raw_input())

