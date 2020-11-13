import sys
import copy

lnb = 0

n = 0
a = []
b = []   

def mergeAndCount(a,b):
    i = 0
    j = 0
    c=[]
    count = 0
    while len(a)>0 and len(b)>0:
        c.append(min(a[0],b[0]))
        if b[0] < a[0]:
            count = count + len(a)
            b.pop(0)
        else:
            a.pop(0)

    if len(a)<=0:
        c.extend(b)
    else:
        c.extend(a)

    return (count,c)

def sortAndCount(l):
    if len(l) <= 1:
        return (0,l)
    else:
        a = l[:len(l)//2]
        b = l[len(l)//2:]
        (ra,a) = sortAndCount(a)
        (rb,b) = sortAndCount(b)
        (r,l) = mergeAndCount(a,b)
    return(ra+rb+r,l)

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

#acc = 0

#print(n)

print(sortAndCount(b)[0])

# for i in range(len(intervals)):
#     for j in range(i,len(intervals)):
#         if (intervals[i][1]>intervals[j][1]) and (i<j):
#             acc = acc + 1

##print(acc)