
def check(x):
    if (x==3) :
        print(3)
    elif (x==2) :
        print(2)
    elif((x%2)==0) and (x!=2) :
        print(0)
    elif((x%2)!=0) and (x!=3):
        print(1)
    else:
        print("donno")

k= int(input(""))
check(k)
    