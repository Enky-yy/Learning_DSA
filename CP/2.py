# def check(s,k,m,t):
#     if (m%s)==0:
#         if (t>k):
#             print(s)
#         else:
#             print(abs(s-k)+abs(m-k))
#     elif (t>k):
#         print(0)
#     elif (k>m):
#         print(0)
#     elif(t<k):
#         if(s<t):
#             print(max(0,t-k))
#         elif(s>t):
#             print(max(0,k-t))
    

s,k,m = int(input('')),int(input('')),int(input(''))

t=m-k

# check(s,k,m,t)
if (m%k)==0:
    if (t>k):
        print(s)
    else:
        print(min(s,(abs(s-k)+abs(m-k))))
elif (t>k):
    print(0)
elif (k>m):
    print(0)
elif(t<k):
    if(s<t):
        print(max(0,t-k))
    elif(s>t):
        if(s<k):
            print(max(0,s-t))
        else:
            print(max(0,k-t))
    