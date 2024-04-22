package CS_LiuBoRui.lab4;

import javax.naming.AuthenticationException;
import java.util.ArrayList;
import java.util.List;

public class UserTest
{
    public static void main(String[] args)
    {
        List<String> blacklist= new ArrayList<>();
        blacklist.add("admin");
        blacklist.add("administrator");
        AuthenticationManager a=new AuthenticationManager(blacklist);

        User user1=new User("jack","123456");
        User user2=new User("Kevin","1234567");
        try
        {
            if(a.verifyUser(user1))
            {
                System.out.println(user1.getUsername()+" authenticated successfully");
            }
        }
        catch (AuthenticationException e)
        {
            System.out.println(user1.getUsername()+" "+e.getMessage());
        }
        try
        {
            if(a.verifyUser(user2))
            {
                System.out.println(user2.getUsername()+" authenticated successfully");
            }
        }
        catch (AuthenticationException e)
        {
            System.out.println(user2.getUsername()+" "+e.getMessage());
        }
    }
}
