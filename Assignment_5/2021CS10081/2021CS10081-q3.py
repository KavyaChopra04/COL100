def padovan(a):
	if(a==0 or a==1 or a==2):
		return 1
	else:
		return padovan(a-2)+padovan(a-3)
def negpadovan(a):
	if(a==0 or a==1 or a==2):
		return 1
	else:
		return negpadovan(a+3)-negpadovan(a+1)
n =int(input())
if(n>=0):
	print('%.2f' %(padovan(n)))
else:
	print('%.2f' %(negpadovan(n)))
