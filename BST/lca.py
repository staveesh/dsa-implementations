from BST import Node

def lca(root, n1, n2):
	temp = root
	l1 = []
	l2 = []
	while(True):
		if temp:
			if n1 > temp.key:
				l1.append(temp)
				temp = temp.right
			elif n1 < temp.key:
				l1.append(temp)
				temp = temp.left
			else:
				l1.append(temp)
				break
	temp = root
	while(True):
		if temp:
			if n2 > temp.key:
				l2.append(temp)
				temp = temp.right
			elif n2 < temp.key:
				l2.append(temp)
				temp = temp.left
			else:
				l2.append(temp)
				break
	return max(list(set(l1).intersection(l2)))

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

root = Node(20)
root.left = Node(8)
root.right = Node(22)
root.left.left = Node(4)
root.left.right = Node(12)
root.left.right.left = Node(10)
root.left.right.right = Node(14)
 
n1 = 10 ; n2 = 14
t = lca(root, n1, n2)
print "LCA of %d and %d is %d" %(n1, n2, t.key)
 
n1 = 14 ; n2 = 8
t = lca(root, n1, n2)
print "LCA of %d and %d is %d" %(n1, n2 , t.key)
 
n1 = 10 ; n2 = 22
t = lca(root, n1, n2)
print "LCA of %d and %d is %d" %(n1, n2, t.key)
