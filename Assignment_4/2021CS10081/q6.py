x=int(input())
n=int(input())
for i in range(1, n+1):
	term=(-1)**i;
	term/=x**(2*i)
	print('%.2f' %(term))
