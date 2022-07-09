# This is the starter code for COL100 Assignment 6 question 1
# There are different functions in this question that you have to fill 


# IMPORTANT NOTE: The code is only to make sure you use functions, you have to do the input/output
# and parsing of the input as well and then use your functions to solve the problem.
# You may do input/output anywhere in the code


# IMPORTANT NOTE: We will ONLY be checking the OUTPUT in this questions and thus we have left the
# design of the code/functions upto you.

# You can only use arrays or lists to store your data and are not allowed to import anything
st=[]
def PickPlate():
    # This is the PickPlate function as mentioned in the pdf
    # It takes no parameters and doesn't need to return anything,
    # you could return a value if it helps your implementaton
    if(len(st)==0):
        print("Invalid")
    else:
        st.pop()
    return

def AddPlate(PlateID: int):
    # This is the AddPlate operation as mentioned in the pdf
    # This takes in one value the PlateID and adds it to the arrangement
    # You will have to parse the input and call this function wherever needed.
    # It doesn't need to return anything,
    # you could return a value if it helps your implementaton
    st.append(PlateID)
    return


def Check():
    # This is the Check function as mentioned in the pdf
    # It takes no parameters and doesn't need to return anything,
    # you could return a value if it helps your implementaton
    if(len(st)==0):
        print("Invalid")
    else:
        print(st[-1])
    return

# A sample testcase is the following it is the Example 1 as in the pdf, you can uncomment to run it
def testcase():
    # The example in the pdf has the following operations
    AddPlate(5) # AddPlate 5
    # Note that you have to parse the input and then send values in the function like done here
    Check() # Check
    AddPlate(4) # AddPlate 4
    Check() # Check
    AddPlate(3) # AddPlate 3
    PickPlate() # PickPlate
    Check() # Check
    # Here we have not called print statements and that is upto you to do
    # You could return values and then print or print in the function itself
    # You can do whatever you like as long as the functions are used in the code
#testcase()
# You can uncomment the above line to check whether your functions work
# Please comment it out before you submit otherwise the output will not match the autograder
def extint(s):
    ans=0;
    for char in s:
        if(char>='0' and char<='9'):
            ans=ans*10 + int(char)
    return ans
q=int(input())
for i in range(q):
    s=input()
    if(s[0]=='C'):
        Check()
    elif(s[0]=='P'):
        PickPlate()
    else:
        n=extint(s)
        AddPlate(n)