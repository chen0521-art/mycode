package Java;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.Scanner;

public class PrintCalendar {
    public static void main(String[] args) throws ParseException {
        System.out.println("输入日期（格式如2021-05-21）：");
        Scanner user=new Scanner(System.in);
        String str1=user.nextLine();

        DateFormat df=new SimpleDateFormat("yyyy-MM-dd");
        Date date1=df.parse(str1);
        Calendar c1=new GregorianCalendar();
        c1.setTime(date1);//时间对象转化为日期对象 这四行很重要

        System.out.print("日\t一\t二\t三\t四\t五\t六");
        System.out.println();

        int target=c1.get(Calendar.DAY_OF_MONTH);//定位目标日期

        c1.set(Calendar.DAY_OF_MONTH,1);//其他元素也会随着该元素的改变而改变

        int weekday=c1.get(Calendar.DAY_OF_WEEK);//寻找打印1号的位置
        for(int i=1;i<weekday;i++){
            System.out.print("\t");
        }
        int max=c1.getActualMaximum(Calendar.DAY_OF_MONTH);//该月份的最大天数
        for(int i=1;i<=max;i++){
            if((i-8+weekday)%7==0){
                if(i==target){
                    System.out.println(i+"*");//标志目标日期
                }
                else{
                    System.out.println(i);
                }
            }
            else{
                if(i==target){
                    System.out.print(i+"*"+"\t");
                }
                else{
                    System.out.print(i+"\t");
                }
            }

        }
    }
}
