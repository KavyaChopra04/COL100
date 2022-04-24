import math
a = eval(input())
b = eval(input())
c = eval(input())
pre=-1*b;
qre=-1*b;
pim=0;
qim=0;
if(b*b-4*a*c>=0):
	qre+=math.sqrt(b*b-4*a*c)
	pre-=math.sqrt(b*b-4*a*c)
else:
	qim+=math.sqrt(4*a*c-b*b)
	pim-=math.sqrt(4*a*c-b*b)
qre/=(2*a)
pre/=(2*a)
qim/=(2*a)
pim/=(2*a)
print('%.2f' %(pre), " ",'%.2f' %(pim))
print('%.2f' %(qre), " ",'%.2f' %(qim))
