package CS_LiuBoRui.lab2;

public class Complex
{
    private double real;
    private  double imag;

    public Complex()
    {
        this.imag=0;
        this.real=0;
    }
    public Complex(double r,double i)
    {
        this.imag=i;
        this.real=r;
    }

    public Complex add(Complex c)
    {
        return new Complex(c.real+this.real,c.imag+this.imag);
    }
    public Complex minus(Complex c)
    {
        return new Complex(c.real-this.real,c.imag-this.imag);
    }
    public Complex times(Complex c)
    {
        return new Complex(this.real*c.real-this.imag*c.imag,this.imag*c.real+c.imag*c.real);
    }

    public static void main(String[] args)
    {
        Complex a=new Complex(18,2);
        Complex b=new Complex(19,3);
        Complex result1=a.add(b);
        Complex result2=a.times(b);

        System.out.println(result1);
        System.out.println(result2);
    }

    @Override
    public String toString()
    {
        if(imag>=0) return real+"+"+imag+"i";
        //else if(imag==0) return real;
        else return real+"-"+Math.abs(imag)+"i";
    }
}


