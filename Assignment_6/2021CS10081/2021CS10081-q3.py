# This is the starter code for COL100 Assignment 6 question 3
# There are different functions in this question that you have to fill 


# IMPORTANT NOTE: The code is only to make sure you use functions, you have to do the input/output
# and parsing of the input as well and then use your functions to solve the problem.
# You may do input/output anywhere in the code


# IMPORTANT NOTE: We will ONLY be checking the OUTPUT in this questions and thus we have left the
# design of the code/functions upto you.


# You can only use arrays or lists to store your data and are not allowed to import anything
pq=[]
def Highest():
    # This is the highest function as mentioned in the pdf
    # It takes no parameters and doesn't need to return anything,
    # you could return a value if it helps your implementaton
    if(len(pq)==0):
        print("Invalid")
    else:
        maxv=-1
        idn = None
        k=len(pq)
        for i in range(k):
            if(pq[i][0]>maxv):
                maxv=pq[i][0]
                idn=pq[i][1]
        print(idn)
    return

def Order(orderID: int, BillValue:int):
    # This is the order operation as mentioned in the pdf
    # This takes in two values orderID and the bill value
    # You will have to parse the input and call this function wherever needed.
    # It doesn't need to return anything,
    # you could return a value if it helps your implementaton
    nt=[BillValue, orderID]
    pq.append(nt)
    return

def Serve():
    # This is the serve function as mentioned in the pdf
    # It takes no parameters and doesn't need to return anything,
    # you could return a value if it helps your implementaton
    if(len(pq)==0):
        print("Invalid")
    else:
        maxv=pq[0][0]
        idn = 0
        k=len(pq)
        for i in range(k):
            if(pq[i][0]>maxv):
                maxv=pq[i][0]
                idn=i;
        pq.pop(idn)
    return

# A sample testcase is the following it is the Example 1 as in the pdf, you can uncomment to run it
def testcase():
    # The example in the pdf has the following operations
    Order(5,20) # Order 5 20
    # Note that you have to parse the input and then send values in the function like done here
    Highest() # Highest
    Order(4,100) # Order 4 100
    Highest() # Highest
    Order(3,100) # Order 3 100
    Highest() # Highest
    Serve() # Serve
    Highest() # Highest
    # Here we have not called print statements and that is upto you to do
    # You could return values and then print or print in the function itself
    # You can do whatever you like as long as the functions are used in the code
def Route(s):
    i=6;
    num1=0;
    while(s[i]!=" "):
        num1=10*num1+int(s[i])
        i+=1
    i+=1
    num2=0;
    n=len(s)
    while(i<n and s[i]>='0' and s[i]<='9'):
        num2=10*num2+int(s[i])
        i+=1
    Order(num1, num2)
    return
# testcase()
# You can uncomment the above line to check whether your functions work
# Please comment it out before you submit otherwise the output will not match the autograder
q=int(input())
for i in range(q):
    s=input()
    if(s[0]=='H'):
        Highest()
    elif(s[0]=='S'):
        Serve()
    else:
        Route(s)