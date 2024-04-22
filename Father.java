package CS_LiuBoRui.lab3;

public class Father
{
    private int i=test();
    private static int j=method();
    static//静态代码块
    {
        System.out.println("(1)");
    }
    Father()//构造函数
    {
        System.out.println("(2)");
    }
    {//非静态代码块
        System.out.println("(3)");
    }
    public int test()//非静态变量调用
    {
        System.out.println("(4)");
        return 1;
    }
    public static int method()//静态变量调用
    {
        System.out.println("(5)");
        return 1;
    }


}
