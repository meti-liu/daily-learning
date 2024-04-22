package CS_LiuBoRui.lab4;

public class mistake2
{
    public static void main(String[] args)
    {
        int result = test();
        System.out.println(result);
    }

    public static int test()
    {
        int i = 1;
        try {
            i++;
            System.out.println("try block, i = " + i);
            return i;
        } catch (Exception e) {
            i++;
            System.out.println("catch block i = " + i);
            return i;
        } finally {
            i++;
            System.out.println("finally block i = " + i);
            return i;
        }
    }

}
