n=int(input())
k=1
for i in range (1,n+1):
	for j in range (0,i):
		print(k,end=" ")
		k+=1
	print()
