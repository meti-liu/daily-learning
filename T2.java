package CS_LiuBoRui.lab2;

abstract class student
{
    String name;
    int age;
    String degree;
    public abstract void show();
    public student(String name,int age,String degree)
    {
        this.name=name;
        this.age=age;
        this.degree=degree;
    }
}


class Graduate extends student
{
    private String direction;
    public Graduate(String name,int age,String degree,String direction)
    {
        super(name, age, degree);
        this.direction=direction;
    }
    @Override
    public void show()
    {
        System.out.println("\""+name+"\""+","+age+","+"\""+degree+"\""+","+"\""+direction+"\"");

    }
}
class Undergraduate extends student
{
    private String specialty;
    public Undergraduate(String name,int age,String degree,String specialty)
    {
        super(name, age, degree);
        this.specialty=specialty;
    }
    @Override
    public void show()
    {
        System.out.println("\""+name+"\""+","+age+","+"\""+degree+"\""+","+"\""+specialty+"\"");
    }

}
public class T2
{
    public static void main(String[] args)
    {
        student a[]=new student[2];
        a[0]=new Undergraduate("张三", 20, "学士", "计算机科学与技术");
        a[1] = new Graduate("王五", 25, "硕士", "软件工程");
        for(student stu:a)
        {
            stu.show();
        }
    }
}
