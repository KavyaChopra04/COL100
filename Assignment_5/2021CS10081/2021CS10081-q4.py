def valid(c):
	if((c>='a' and c<='z') or (c>='A' and c<='Z')):
		return True
	else:
		return False
def numwords(l):
	minwords=len(l[0]);
	for s in l:
		n=len(s)
		i=0
		wor=0
		while(i<n):
			fv=False;
			while(i<n and valid(s[i])):
				fv=True			
				i+=1
			if(fv):
				wor+=1
			else:
				i+=1
		minwords=min(minwords, wor)
	return minwords

n=int(input())
if(n<=0):
	print('%.2f' %(0))
else:
	l=[]
	for i in range(n):
		s=input()
		l.append(s)
	print('%.2f' %(numwords(l)))
