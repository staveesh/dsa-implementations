def lcs(a,b):
	if a == '' or b == '':
		return 0
	if a[-1:] == b[-1:]:
		return 1+lcs(a[:-1],b[:-1])
	else:
		return max(lcs(a,b[:-1]),lcs(a[:-1],b))

def dp_lcs(a,b):
	m = len(a)
	n = len(b)
	A = [x for x in a]
	B = [y for y in b]
	L = [[None]*(n+1) for i in range(m+1)] # L[i][j] stores L of a[0..i-1] b[0..j-1]
	for i in range(m+1):
		for j in range(n+1):
			if i == 0 or j == 0:
				L[i][j] = 0
			elif a[i-1] == b[j-1]:
				L[i][j] = L[i-1][j-1]+1
			else:
				L[i][j] = max(L[i-1][j],L[i][j-1])
	return L[m][n]
a = raw_input()
b = raw_input()
print lcs(a,b)
print dp_lcs(a,b)