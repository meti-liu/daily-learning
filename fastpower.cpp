double fastpower(double x,int n)
{
    if(n==0) return 1;
    double half=fastpower(x,n/2);
    if(n<0) return 1/fastpower(x,-n);
    else if(n%2==0) return half*half;
    else if(n%2==1) return x*half*half;
}