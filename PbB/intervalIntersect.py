import sys
import copy

def sortAndCount(inputArray):
    if len(inputArray) == 1:
        return inputArray, 0
    else:
        
        a = inputArray[:len(inputArray)//2]
        b = inputArray[len(inputArray)//2:]
        a, ai = sortAndCount(a)
        b, bi = sortAndCount(b)
        c = []
        i = 0
        j = 0
        inversions = 0 + ai + bi
    while i < len(a) and j < len(b):
        if a[i] <= b[j]:
            c.append(a[i])
            i += 1
        else:
            c.append(b[j])
            j += 1
            inversions += (len(a)-i)
    c += a[i:]
    c += b[j:]
    return c, inversions

lnb = 0

n = 0
a = []
b = []   


for line in sys.stdin:
    buffer = line.split()
    if lnb == 0:
        lnb = lnb + 1
        n = int(buffer[0])
    elif lnb == 1:
        for i in range(n):
            a.append(int(buffer[i]))
        lnb = lnb + 1
    else:
        for i in range(n):
            b.append(int(buffer[i]))


#welcome to the dumbfuck zone
intervals = [(a[i],b[i]) for i in range(len(a))]
intervals.sort(key=(lambda x : x[0]))

b = [el[1] for el in intervals]

print(sortAndCount(b)[1])
