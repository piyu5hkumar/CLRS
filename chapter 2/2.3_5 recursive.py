def bsearch(ls,search,beg,end):
    if beg<=end:
        mid=int((beg+end)/2)
        if int(ls[mid])==search :
            print("found at index ",mid)
            return True
        elif search < int(ls[mid]):
            return bsearch(ls,search,beg,mid-1)
        else:
            return bsearch(ls,search,mid+1,end)
    else:
        return False
def main():
    arr=input("enter your array in ascending order ").split()
    search=int(input("Enter element to be searched "))
    if bsearch(arr,search,0,len(arr)-1)==False:
        print("not found")

main()
