from typing import List
def ind(inpt : str) -> str: # it takes string as input and return string
    # write your code in this function only
    # your's code start here 
    l=[]
    for i in range(10):
        l.append(0)
    for c in inpt:
        if(c>='0' and c<='9'):
            l[int(c)]+=1;
    nstr=""
    for i in range(10):
        if(l[i]%2==1):
            for j in range (l[i]):
                nstr=nstr+str(i)
    for c in inpt:
        if(c>='0' and c<='9'):
            if(l[int(c)]%2==0):
                nstr=nstr+c
        else:
            nstr=nstr+c
    return nstr

def sortings(lst : List[str]) -> List[str]: 
    l=[]
    n=len(lst)
    for i in range(n):
        lst[i]=ind(lst[i])
    for i in range(n):
        ans=None
        if(len(lst[i])==0):
            l.append([ans,i])
        elif(lst[i][0]>'9' or lst[i][0]<'0'):
            l.append([ans,i])
        else:
            ans=0
            j=0
            k=len(lst[i])
            while(j<k and lst[i][j]<='9' and lst[i][j]>='0'):
                ans=10*ans+int(lst[i][j])
                j+=1
            l.append([ans,i])
    for i in range(0,n):
        minv=l[i][0]
        minin=i
        for j in range(i+1,n):
            if(isinstance(l[j][0],type(None))):
                continue
            elif(isinstance(minv,type(None)) and isinstance(l[j][0],int)):
                minv=l[j][0]
                minin=j
            else:
                if(minv>l[j][0]):
                    minv=l[j][0]
                    minin=j
        if(minv!=l[i][0]):
            k=l[minin][0]
            q=l[minin][1]
            l[minin][0]=l[i][0]
            l[minin][1]=l[i][1]
            l[i][0]=k
            l[i][1]=q
    newlst=[]
    for el in l:
        newlst.append(lst[el[1]])
    return newlst 
    
    # return your's result (list of string) 
    # your's code end here 
    

if __name__=="__main__": # calling main (run automtically)
    lst = []             # list that stores the input strings
    num = int(input())   # taking input from user of number of strings of list
    for i in range(num): # take input of all strings of list
        inpt = input()
        lst.append(inpt) # append each string into the list
    lst = sortings(lst)  # calling function in which you have to write the code
    print (lst)          # printing the output (list of strings) of your's function
