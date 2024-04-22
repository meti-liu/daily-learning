package CS_LiuBoRui.lab4;
import javax.naming.AuthenticationException;//先提前声明一种全新的异常类型
import java.util.ArrayList;
import java.util.List;

public class AuthenticationManager
{
    private List<String> blacklistedUsernames = new ArrayList<>();

    public AuthenticationManager(List<String> blacklistedUsernames)
    {
        this.blacklistedUsernames = blacklistedUsernames;
    }

    public boolean verifyUser(User user) throws AuthenticationException
    {
        if(user.getUsername()==null||user.getUsername().isEmpty())
        {
            throw new AuthenticationException("Authentication Failed:用户名不能为空");
        }
        if(user.getPassword()==null||user.getPassword().length()<=6)
        {
            throw new AuthenticationException("AuthenticationFailed:密码长度不能小于6");
        }
        if(blacklistedUsernames.contains(user.getUsername()))
        {
            throw new AuthenticationException("Authentication Failed:用户在黑名单中");
        }
        return true;
    }
}
