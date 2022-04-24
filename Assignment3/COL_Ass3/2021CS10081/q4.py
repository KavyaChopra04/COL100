s=input()
n=len(str)
if(n==1):
	print("YES")
else if(n==2):
	if(s[0]==s[1]):
		print("YES")
	else:
		print("NO")
else if(n==3):
	if(s[0]==s[2]):
		print("YES")
	else:
		print("NO")
else:
	if(s[0]==s[3] and s[1]==s[2]):
		print("YES")
	else:
		print("NO")