class Calculator:
    def __init__(self,n,p,h,w):
        self.name=n
        self.price=p
        self.height=h
        self.weight=w

    def add(self,x,y):
        print(self.name)
        result=x+y
        return(result)
    def minus(self,x,y):
        result=x-y
        return(result)
    def times(self,x,y):
        return(x*y)
    def divide(self,x,y):
        return(x/y)
a=Calculator('God',100,10,20)
#print(a.height)
print(a.height)
print(a.add(2,3))