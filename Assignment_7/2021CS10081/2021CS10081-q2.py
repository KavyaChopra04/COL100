def sortings(inpt : str) -> str: # it takes string as input and return string
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

    # return your's string result
    # your's code end here 
    

if __name__=="__main__": # calling main (run automtically)
    inpt = input()       # taking input from user (string type)
    out = sortings(inpt) # calling function sortings in which you have to write code
    print (out)          # printing the output of your's function

    
            
    
            
            