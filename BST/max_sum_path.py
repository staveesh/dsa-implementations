from BST import Node

def max_sum(root):
	if root is None:
		return 0

	l = max_sum(root.left)
	r = max_sum(root.right)
	max_single = max(max(l,r)+root.key,root.key)
	max_top = max(max_single,l+r+root.key)
	max_sum.res = max(max_sum.res,max_top)
	return max_single

def max_util(root):
	max_sum.res = float("-inf")
	max_sum(root)
	return max_sum.res

root = Node(10)
root.left = Node(2)
root.right   = Node(10)
root.left.left  = Node(20)
root.left.right = Node(1)
root.right.right = Node(-25)
root.right.right.left   = Node(3)
root.right.right.right  = Node(4)

print max_util(root)