package CS_LiuBoRui.lab4;
import java.util.ArrayList;
import java.util.Comparator;
class BirthDate
{
    private int month;
    private  int day;
    private  int year;
    public BirthDate(int y,int m,int d)
    {
        this.year=y;
        this.month=m;
        this.day=d;
    }
    public int getMonth() {
        return month;
    }

    public void setMonth(int month) {
        this.month = month;
    }

    public int getDay() {
        return day;
    }

    public void setDay(int day) {
        this.day = day;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }
    public String toString()
    {
        return year+"年,"+month+"月,"+day+"日.";
    }
}
class Employee
{
    private String name;
    private int salary;
    private BirthDate birthdate;

    public Employee(String n,int s,BirthDate b)
    {
        this.name=n;
        this.salary=s;
        this.birthdate=b;
    }
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getSalary() {
        return salary;
    }

    public void setSalary(int salary) {
        this.salary = salary;
    }

    public BirthDate getBirthdate() {
        return birthdate;
    }

    public void setBirthdate(BirthDate birthdate) {
        this.birthdate = birthdate;
    }

    @Override
    public String toString()
    {
        return name+","+salary+","+birthdate;
    }
}
class myComparator implements Comparator<Employee>
{

    @Override
    public int compare(Employee o1, Employee o2)
    {
        // 首先按名字比较
        int nameComp = o1.getName().compareTo(o2.getName());
        if (nameComp != 0) {
            return nameComp;
        }

        // 如果名字相同，接着按生日的年比较
        int yearComp = Integer.compare(o1.getBirthdate().getYear(), o2.getBirthdate().getYear());
        if (yearComp != 0) {
            return yearComp;
        }

        // 如果年也相同，按月比较
        int monthComp = Integer.compare(o1.getBirthdate().getMonth(), o2.getBirthdate().getMonth());
        if (monthComp != 0) {
            return monthComp;
        }

        // 如果月也相同，按日比较
        return Integer.compare(o1.getBirthdate().getDay(), o2.getBirthdate().getDay());
    }
}
public class EmployeeTest
{
    public static void main(String[] args)
    {
        ArrayList<Employee> a=new ArrayList<>();
        a.add(new Employee("吕布", 20000, new BirthDate(160, 6, 12)));
        a.add(new Employee("许褚", 16000, new BirthDate(169, 6, 22)));
        a.add(new Employee("张辽", 15000, new BirthDate(169, 7, 18)));
        a.add(new Employee("赵云", 12600, new BirthDate(168, 5, 26)));
        a.add(new Employee("赵云", 12000, new BirthDate(172, 5, 26)));

        System.out.println("排序前");
        for(Employee emp:a)
        {
            System.out.println(emp);
        }
        Comparator<Employee> comp=new myComparator();
        a.sort(comp);
        System.out.println("排序后");
        for(Employee emp:a)
        {
            System.out.println(emp);
        }
    }

}