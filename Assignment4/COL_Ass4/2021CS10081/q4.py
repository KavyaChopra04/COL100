n=int(input())
for i in range(0,n):
	print(' '*(i), chr(65+i)*(n-i),sep="")
