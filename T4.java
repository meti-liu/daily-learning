package CS_LiuBoRui.lab2;
import java.util.Scanner;
interface Soundable
{
    public void increaseVolume( );
    public void decreaseVolume( );
    public void stopSound( );
    public void playSound( );
}
class Radio implements Soundable
{
    private int volume=5;
    @Override
    public void increaseVolume()
    {
        volume++;
        System.out.println("Radio音量提高至: "+volume);
    }

    @Override
    public void decreaseVolume()
    {
        volume--;
        System.out.println("Radio音量降低至: "+volume);
    }

    @Override
    public void stopSound()
    {
        System.out.println("Radio停止播放");
    }

    @Override
    public void playSound()
    {
        System.out.println("Radio开始播放，音量是"+volume);
    }
}
class Walkman implements Soundable
{
    private int volume=10;
    @Override
    public void increaseVolume()
    {
        volume++;
        System.out.println("Walkman音量提高至: "+volume);
    }

    @Override
    public void decreaseVolume()
    {
        volume--;
        System.out.println("Walkman音量降低至: "+volume);
    }

    @Override
    public void stopSound()
    {
        System.out.println("Walkman停止播放");
    }

    @Override
    public void playSound()
    {
        System.out.println("Walkman开始播放，音量是"+volume);
    }
}
class MobilePhone implements Soundable
{
    private int volume=15;
    @Override
    public void increaseVolume()
    {
        volume++;
        System.out.println("MobilePhone volume is increased to: "+volume);
    }

    @Override
    public void decreaseVolume()
    {
        volume--;
        System.out.println("MobilePhone volume is decreased to: "+volume);
    }

    @Override
    public void stopSound()
    {
        System.out.println("MobilePhone stopped");
    }

    @Override
    public void playSound()
    {
        System.out.println("MobilePhone is playing at volume"+volume);
    }
}

public class T4
{
    public static void main(String[] args)
    {
        System.out.println("你想听哪个设备 1.radio 2.walkman 3.mobilephone ");
        Soundable device;
        Scanner a=new Scanner(System.in);
        int choice=a.nextInt();
        a.nextLine();
        switch (choice)
        {
            case 1:
                System.out.println("Radio启动");
                device=new Radio();
                break;
            case 2:
                System.out.println("Walkman启动");
                device=new Walkman();
                break;
            case 3:
                System.out.println("MobilePhone启动");
                device=new MobilePhone();
                break;
            default:
                System.out.println("无效输入，请输入1或2或3");
                a.close();
                return;
        }
        device.playSound();
        System.out.println("提高音量吗？yes or not");
        if(a.nextLine().equals("yes")) device.increaseVolume();
        System.out.println("降低音量吗？yes or not");
        if(a.nextLine().equals("yes")) device.decreaseVolume();
        System.out.println("停止播放吗？yes or not");
        if(a.nextLine().equals("yes")) device.stopSound();

        a.close();
    }
}
