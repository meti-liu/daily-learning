def bitwiseComplement(n):
    if n==0:
        return 1
    else:
        a=[0]*50
        i=0
        while n>0:
            temp=n//2
            a[i]=n-2*temp
            n=temp
            i+=1# python中没有i++

        for j in range(i):
            if a[j]==0:
                a[j]=1
            else:
                a[j]=0

        sum=0
        for j in range(i):
            sum+=a[j]*(2**j)

        return sum
