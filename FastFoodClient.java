package CS_LiuBoRui.lab3;
interface Hamburger
{
    void eat();
    String getName();
}
interface Cola
{
    void drink();
    String getName();
}
interface FastFoodFactory
{
    Hamburger createHamburger();
    Cola createCola();
}





class MCHamburger implements Hamburger
{

    @Override
    public void eat()
    {
        System.out.println("eating a hamburger in MC");
    }

    @Override
    public String getName()
    {
        return "麦当劳汉堡";
    }
}
class KFCHamburger implements Hamburger
{

    @Override
    public void eat()
    {
        System.out.println("eating a hamburger in KFC");
    }

    @Override
    public String getName()
    {
        return "肯德基汉堡";
    }
}
class MCCola implements Cola
{

    @Override
    public void drink()
    {
        System.out.println("drinking a cola in MC");
    }

    @Override
    public String getName()
    {
        return "麦当劳可乐";
    }
}
class KFCCola implements Cola
{

    @Override
    public void drink()
    {
        System.out.println("drinking a Cola in KFC");
    }

    @Override
    public String getName()
    {
        return "肯德基可乐";
    }
}


class MCFactory implements FastFoodFactory
{

    @Override
    public Hamburger createHamburger()
    {
        return new MCHamburger();
    }

    @Override
    public Cola createCola() {
        return new MCCola();
    }

}
class KFCFactory implements FastFoodFactory
{
    @Override
    public Hamburger createHamburger()
    {
        return new KFCHamburger();
    }

    @Override
    public Cola createCola() {
        return new KFCCola();
    }
}
public class FastFoodClient
{
    public static void main(String[] args)
    {
        FastFoodFactory factoryA=new MCFactory();
        FastFoodFactory factoryB=new KFCFactory();
        Hamburger a=factoryA.createHamburger();
        Hamburger b=factoryB.createHamburger();
        Cola c=factoryA.createCola();
        Cola d=factoryB.createCola();

        a.eat();
        System.out.println(a.getName());
        b.eat();
        System.out.println(b.getName());
        c.drink();
        System.out.println(c.getName());
        d.drink();
        System.out.println(d.getName());

    }
}
