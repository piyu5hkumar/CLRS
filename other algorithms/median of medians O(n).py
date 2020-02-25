import random


def partition(all, pivot):
    left = []
    right = []
    for x in all:
        if x < pivot:
            left.append(x)
        if x > pivot:
            right.append(x)
    return left, right


def findele(all, k, process =False):
    # process = True for debugging purposes
    # if process:print('k',k)
    # if process:
    #     print('all', all)
    if len(all) <= 5:
        all.sort()
        # if process:
        #     print('about to return from',all)
        #     print('returned median', all[k])
        return all[k]
    medians = []
    i = 0
    while(i < len(all)):
        temp = all[i:i+5]
        medians.append(sorted(temp)[len(temp)//2])
        i = i+5
    if process:
        print('medians', medians)
    arb_median = findele(medians, len(medians)//2, process)
    left, right = partition(all, arb_median)
    if process:
        print('left', left)
    if process:
        print('right', right)
    if len(left) == k:
        return arb_median
    elif len(left) > k:
        # if process:
        #     print('recurred left array')
        return findele(left, k, process)
    elif len(left) < k:
        k = k - len(left) - 1
        # if process:
        #     print('recurred right array')
        return findele(right, k, process)


all = [i for i in range(1, 14)]
k = len(all)//2  #index to be searched, it can be median or something else
print(findele(all,k))
