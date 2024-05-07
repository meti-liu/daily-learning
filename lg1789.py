def fun_m(d,x,y,n):
    for i in range(x-2,x+3):
        for j in range(y-2,y+3):
            if i<0 or j<0 or i>=n or j>=n:continue
            if (abs(i-x)+abs(j-y))<=2 :d[i][j]=1
def fun_k(d,x,y,n):
    for i in range(x-2,x+3):
        for j in range(y-2,y+3):
            if i<0 or j<0 or i>=n or j>=n:continue
            else:d[i][j]=1
ans=0
n,m,k=map(int,input().split())#多组数据用map迭代器输入
d=[[0]*n for _ in range(n)]#二位列表初始化
for i in range(0,m):
    mx,my=map(int,input().split())
    fun_m(d,mx-1,my-1,n)
for i in range(0,k):
    kx,ky=map(int,input().split())
    fun_k(d,kx-1,ky-1,n)
for i in range(0,n):
    for j in range(0,n):
        if d[i][j]==0: ans+=1
print(ans)