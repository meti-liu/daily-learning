package CS_LiuBoRui.lab4;

public class mistake1 {
    private int a = 1893;

    public static void main(String[] args)
    {
        mistake1 t1 = new mistake1();
        mistake1 t2 = null;
        System.out.println(t1.a);
        System.out.println(t1.hello());
//        if(t2!=null)
//        {
//            System.out.println(t2.a);
//            System.out.println(t2.hello());
//        }
//        else System.out.println("t2 is null,invalid operation");
        try
        {
            System.out.println(t2.a);
            System.out.println(t2.hello());
        }
        catch (NullPointerException e)
        {
            System.out.println("t2 is null,found a nullPointerException");
        }
    }

    public String hello() {
        return "江城多山，珞珈独秀";
    }
}

