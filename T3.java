package CS_LiuBoRui.lab2;

import java.util.Objects;

class GeometricObject
{
    protected String color="white";
    protected double weight=1.0;
    protected GeometricObject(){}
    protected GeometricObject(String color,double weight)
    {
        this.color=color;
        this.weight=weight;
    }

    public String getColor()
    {
        return color;
    }

    public void setColor(String color)
    {
        this.color = color;
    }

    public double getWeight()
    {
        return weight;
    }

    public void setWeight(double weight)
    {
        this.weight = weight;
    }
}
class Circle extends GeometricObject
{
    private double radius;
    public Circle(){}
    public Circle(double radius)
    {
        this.radius=radius;
    }
    public Circle(double radius,String color,double weight)
    {
        this.radius=radius;
        this.color=color;
        this.weight=weight;
    }

    public double getRadius()
    {
        return radius;
    }

    public void setRadius(double radius)
    {
        this.radius = radius;
    }
    public double findArea()
    {
        return Math.PI*radius*radius;
    }
    public boolean equals(Circle c)
    {
        if(c.radius==this.radius) return true;
        else return false;
    }
    @Override
   public String toString()
    {
        return "圆的半径为"+radius;
    }
}

public class T3
{
    public static void main(String[] args)
    {
        Circle a=new Circle(4,"blue",3);
        Circle b=new Circle(3,"blue",5);
        boolean R_equal=a.equals(b);
        boolean C_equal= Objects.equals(a.getColor(), b.getColor());
        System.out.println(R_equal);
        System.out.println(C_equal);
        System.out.println(a);
        System.out.println(b);
    }

}
