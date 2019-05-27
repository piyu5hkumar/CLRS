ls=input("Enter your array ").split();
search=int(input("Enter the element to be searched"))
found=False
for i in range(0,len(ls)):
    if(int(ls[i])==search):
        found=True
        pos=i
if(found):
    print("element found at ",pos)
else:
    print("element not found")

