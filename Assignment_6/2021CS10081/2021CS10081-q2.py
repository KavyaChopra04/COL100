# This is the starter code for COL100 Assignment 6 question 2
# There are different functions in this question that you have to fill 

# IMPORTANT NOTE: The code is only to make sure you use functions, you have to do the input/output
# and parsing of the input as well and then use your functions to solve the problem.
# You may do input/output anywhere in the code


# IMPORTANT NOTE: We will ONLY be checking the OUTPUT in this questions and thus we have left the
# design of the code/functions upto you.

# You can only use arrays or lists to store your data and are not allowed to import anything
q=[]
def Issue():
    # This is the Issue function as mentioned in the pdf
    # It takes no parameters and doesn't need to return anything,
    # you could return a value if it helps your implementaton
    if(len(q)==0):
        print("Invalid")
    else:
        q.pop(0)
    return

def Join(AadharID: int):
    # This is the Join operation as mentioned in the pdf
    # This takes in one value the AadharID and adds the person to the line
    # You will have to parse the input and call this function wherever needed.
    # It doesn't need to return anything,
    # you could return a value if it helps your implementaton
    q.append(AadharID)
    return


def Check():
    # This is the Check function as mentioned in the pdf
    # It takes no parameters and doesn't need to return anything,
    # you could return a value if it helps your implementaton
    if(len(q)==0):
        print("Invalid")
    else:
        print(q[0])
    return

def GetLine():
    # This is the GetLine function as mentioned in the pdf
    # It takes no parameters and doesn't need to return anything,
    # you could return a value if it helps your implementaton
    if(len(q)==0):
        print("Invalid")
    else:
        for el in q:
            print(el, end=" ")
        print()
    return

# A sample testcase is the following it is the Example 1 as in the pdf, you can uncomment to run it
def testcase():
    # The example in the pdf has the following operations
    Join(5) # Join 5
    # Note that you have to parse the input and then send values in the function like done here
    Check() # Check
    Join(4) # Join 4
    Check() # Check
    GetLine() # GetLine
    Join(3) # Join 3
    GetLine() # GetLine
    Issue() # Issue
    Check() # Check
    GetLine() # GetLine
    # Here we have not called print statements and that is upto you to do
    # You could return values and then print or print in the function itself
    # You can do whatever you like as long as the functions are used in the code
def extint(s):
    ans=0;
    for char in s:
        if(char>='0' and char<='9'):
            ans=ans*10 + int(char)
    return ans
# testcase()
# You can uncomment the above line to check whether your functions work
# Please comment it out before you submit otherwise the output will not match the autograder
n=int(input())
for i in range(n):
    s=input()
    if(s[0]=='J'):
        k=extint(s)
        Join(k)
    elif(s[0]=='C'):
        Check()
    elif(s[0]=='I'):
        Issue()
    else:
        GetLine()

