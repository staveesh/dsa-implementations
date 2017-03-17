s = raw_input()
def pal(s):
	tab = [[0 for j in range(len(s))] for i in range(len(s))]
	for i in range(len(s)):
		tab[i][i] = 1
	for sl in range(2,len(s)+1):
		for i in range(len(s)-sl+1):
			j = sl+i-1
			if s[i] == s[j] and sl == 2:
				tab[i][i] = 2
			elif s[i] == s[j]:
				tab[i][j] = 2+tab[i+1][j-1]
			else:
				tab[i][j] = max(tab[i][j-1],tab[i+1][j])
	return tab[0][len(s)-1]
print pal(s)
