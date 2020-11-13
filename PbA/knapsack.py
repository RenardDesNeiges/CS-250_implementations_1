import sys

stdin = sys.stdin

first = True

n = 0
m = 0
k = 0

cat = 0

w = []
h = []
c = []
indices = []

iacc = 0

def dumKnapsack(maxMem,w,h,c,i,m,n):
    if(n < 0):
        return 0
    elif w[n]>m:
        if n<1:
            return 0
        if maxMem[m][n-1] == -1:
            maxMem[m][n-1] = dumKnapsack(maxMem,w,h,c,i,m,n-1)
        return maxMem[m][n-1]
    else:
        take = 0
        if c[n] < 1:
            take = h[n]
        else:
            if maxMem[m-w[n]][i[c[n]-1]] == -1:
                maxMem[m-w[n]][i[c[n]-1]] = dumKnapsack(maxMem,w,h,c,i,m-w[n],i[c[n]-1])
            take = h[n]+ maxMem[m-w[n]][i[c[n]-1]] 
        if n<1:
            leave = 0
        else:
            if maxMem[m][n-1] == -1:
                maxMem[m][n-1] = dumKnapsack(maxMem,w,h,c,i,m,n-1)
            leave = maxMem[m][n-1]
        if leave > take:
            return leave
        else:
            return take 

for line in sys.stdin:
    buffer = line.split()
    if first:
        first = False
        n = int(buffer[0])
        m = int(buffer[1])
        k = int(buffer[2])
    else:
        kn = int(buffer[0])
        for i in range(kn):
            w.append(int(buffer[1+2*i]))
            h.append(int(buffer[2+2*i]))
            c.append(int(cat))
            iacc = iacc + 1
        indices.append(iacc-1)
        cat = cat + 1

#print("m = " + str(m) + " n = " + str(n))

maxMem = [[-1 for x in range(n)] for y in range(m+1)] 

#print(maxMem)

if k>0:
    print(dumKnapsack(maxMem,w,h,c,indices,m,n-1))
else:
    print(0)