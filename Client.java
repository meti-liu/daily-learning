package CS_LiuBoRui.lab3;
interface laptop
{
    void assemble();
}
interface LaptopFactory
{
    laptop createLaptop();
}
class ThinkpadLaptop implements laptop
{
    @Override
    public void assemble() {
        System.out.println("assembling ThinkPad");
    }
}
class LenovoLaptop implements laptop
{
    @Override
    public void assemble() {
        System.out.println("assembling Lenovo");
    }
}
class DellLaptop implements laptop
{
    @Override
    public void assemble() {
        System.out.println("assembling Dell");
    }
}
class XiaomiLaptop implements laptop
{
    @Override
    public void assemble() {
        System.out.println("assembling Xiaomi");
    }
}
class ThinkPadFactory implements LaptopFactory
{
    public laptop createLaptop()
    {
        return new ThinkpadLaptop();
    }
}
class LenovoFactory implements LaptopFactory
{
    public laptop createLaptop()
    {
        return new LenovoLaptop();
    }
}
class DellFactory implements LaptopFactory
{
    public laptop createLaptop()
    {
        return new DellLaptop();
    }
}
class XiaomiFactory implements LaptopFactory
{
    public laptop createLaptop()
    {
        return new XiaomiLaptop();
    }
}
public class Client
{
    public void orderLaptop(LaptopFactory f)
    {
        laptop a=f.createLaptop();
        a.assemble();
    }

    public static void main(String[] args)
    {
        Client c=new Client();
        c.orderLaptop(new ThinkPadFactory());
        c.orderLaptop(new LenovoFactory());
        c.orderLaptop(new DellFactory());
        c.orderLaptop(new XiaomiFactory());

    }
}
