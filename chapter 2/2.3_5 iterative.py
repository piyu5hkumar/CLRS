arr=input("enter your array in ascending order ").split()
search=int(input("Enter element to be searched "))
start=0
end=len(arr)-1
check=False
while start <= end :
    mid=int((start+end)/2)
    if int(arr[mid])==search:
        print("element found at index ",mid)
        check = True
        break
    elif search < int(arr[mid]):
        end=mid-1
    else:
        start=mid+1

if check==False:
    print("not found")
