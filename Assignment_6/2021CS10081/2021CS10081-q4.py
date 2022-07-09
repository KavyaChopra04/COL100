# This is the starter code for COL100 Assignment 6 question 4
# There are different functions in this question that you have to fill 


# These are some example matrices that you can use to check your code
matrixA = [[1.00,2.00,3.00],[2.00,3.00,4.00],[4.00,5.00,6.00]]
matrixB = [[1.00,0.00,2.00],[9.00,8.00,5.00],[5.00,8.00,0.00]]
matrixC = [["Hello"]]
matrixD = [[1.00,2.00],[5.00,7.00],[3.00,8.00]]

# This is a print matrix function that could help you debug your code, it prints the whole matrix
def PrintMatrix(A:list ):
	# Print function that can help you debug your solutions
	if A == None:
		print(A)
		return
	# It will print None if the input is None
	rows = len(A)
	cols = len(A[0])
	for i in range(rows):
		for j in range(cols):
			print(A[i][j], end = " ")
		print()

# The argument type is a list and the return type is a boolean
def CheckMatrix(A: list)->bool:
	# Check whether the list of list is a matrix
	# WRITE YOUR CODE HERE
	if(len(A)==0):
		return False
	elif(len(A[0])==0):
		return False
	n=len(A[0])
	for sublist in A:
		if(len(sublist)!=n):
			return False
		for el in sublist:
			if(isinstance(el, float)==False):
				return False

	return True

# IMPORTANT NOTE: Please make sure to use CheckMatrix in the further questions

# The argument type is a list and the return type is a list as well
def Transpose(A:list) -> list:
	# Find the transpose of the matrix given please make sure the dimensions of the list of list
	# the transpose of the matrix
	# WRITE YOUR CODE HERE
	if (CheckMatrix(A)==False):
		return None
	m=len(A)
	n=len(A[0])
	B=[]
	for i in range(n):
		l=[]
		for j in range(m):
			l.append(A[j][i])
		B.append(l)
	return B

# There are two arguments whose type is list, it returns a list as output
def Multiplication(A:list,B:list) -> list:
	# Return the multiplication of matrices A and B if it exists
	if (CheckMatrix(A)==False or CheckMatrix(B)==False):
		return None
	if(len(A[0])!=len(B)):
		return None
	m=len(A)
	n=len(A[0])
	r=len(B[0])
	C=[]
	for i in range(m):
		l=[]
		for j in range(r):
			l.append(0)
		C.append(l)
	for i in range(m):
		for j in range(r):
			for k in range(n):
				C[i][j]+=A[i][k]*B[k][j]
	return C

# There are two arguments whose type is list, it returns a list as output
def Addition(A:list,B:list) -> list:
	# Return the addition of matrices A and B if it exists
	if (CheckMatrix(A)==False or CheckMatrix(B)==False):
		return None
	if(len(A)!=len(B) or len(A[0])!=len(B[0])):
		return None
	m=len(A)
	n=len(A[0])
	C=[]
	for i in range(m):
		l=[]
		for j in range(n):
			l.append(A[i][j] + B[i][j])
		C.append(l)
	return C

# The argument type is a list and the return type is a boolean
def Symmetric(A: list)->bool:
	# Write code to check whether matrix is symmetric or not return True if it is
	# Return False in all the other cases 
	# WRITE YOUR CODE HERE
	if(CheckMatrix(A)==False or len(A)!=len(A[0])):
		return False
	m=len(A)
	n=len(A[0])
	for i in range(m):
		for j in range(n):
			if(A[i][j]!=A[j][i]):
				return False
	return True

# THESE ARE SOME SAMPLE TESTCASES THAT YOU CAN USE TO EVALUATE YOUR CODE
# WE WILL NOT BE CHECKING THE OUTPUT OF THE FOLLOWING AND WILL CHECK THE RETURNED VALUE USING OUR TESTCASES

# Printing Matrix A
#PrintMatrix(matrixA)

# Checking whether matrixC is a valid Matrix
#print(CheckMatrix([["Hello",5.00],[]]))

# Printing the multiplication of matrixA and matrixB
#print("now multiplying A and B")
#PrintMatrix(Multiplication([[1.00]],[[2.00]]))

# Printing the addition of matrixA and matrixB
#print("now adding A and B")
#PrintMatrix(Addition([[1.00,2.00],[3.00,4.00]],[[7.00,8.00],[4.00,1.00]]))

# Is matrixA a symmetric matrix
#print("checking if A is symmetric")
print(Symmetric([[1.00]]))

# Printing the transpose of matrixA
#print("printing transpose")
#PrintMatrix(Transpose([[1.00,4.00]]))

# THE ABOVE ARE ONLY FOR YOUR REFERENCE AND WILL NOT BE INCLUDED IN EVALUATION