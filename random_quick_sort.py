import random
import numpy as np

def rightmost_partition(A,p,r):
    pivot=A[r]
    i=p-1
    for j in range(p,r):
        if(A[j]<=pivot):
            i=i+1
            A[i],A[j]=A[j],A[i]
    i=i+1
    A[i],A[r]=A[r],A[i]
    return i

def random_partition(A,p,r):
    rand=random.randint(p,r)
    A[r],A[rand]=A[rand],A[r]
    q=rightmost_partition(A,p,r)
    return q

def random_quicksort(A,p,r):
    if(p<r):
        q=random_partition(A,p,r)
        random_quicksort(A,p,q-1)
        random_quicksort(A,q+1,r)
        return A

lst=list([8,1,6,3,2,4,7,5])
A=np.array(lst)
p=0
r=len(A)-1
array=random_quicksort(A,p,r)
for i in range(0,len(array)):
    print(array[i], end=" ")