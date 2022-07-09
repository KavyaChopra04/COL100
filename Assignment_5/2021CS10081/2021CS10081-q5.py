def pattern(n):
	s=""
	if(n==0):
		return s
	else:
		s+=str(n)
		s+=pattern(n-1)
		s+=str(n)
		s+=pattern(n-1)
		s+=str(n)
		return s
n=int(input())
print(pattern(n))
