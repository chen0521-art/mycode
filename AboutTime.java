package Java;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;

public class AboutTime {
    public static void main(String[] args) throws ParseException {
        Date d1=new Date();//括号里面填具体数字，其对应的是毫秒数，返回的是对应的日期   不填则表示当前系统时间
        System.out.println(d1);//Wed May 12 14:44:56 CST 2021 对应当前时间
        System.out.println(d1.getTime());//将对应日期变成毫秒数 从1970年一月一号零时零分零秒到对应日期
        Date d2=new Date();
        System.out.println(d2.after(d1));// true 比较哪个时间靠前，哪个靠后d2靠前
        /**
         * DateFormat类和SimpleDateFormat类（日期格式化）
         * 前者是抽象类，一般使用它的实现类SimpleDateFormat
         */
        DateFormat df=new SimpleDateFormat("yyyy-MM-dd hh:mm:ss");//不能new抽象类 把时间对象按照“格式字符串指定的格式“转成相应的字符串
        String str1 = df.format(new Date());
        System.out.println(str1);
        //反过来
        Date date=df.parse("2021-05-21 15:15:00");//这里输入的格式要与之前规定的df的格式相同
        System.out.println(date);//Fri May 21 15:15:00 CST 2021

        Calendar k=new GregorianCalendar();
        System.out.println(k);
        /*
        获取元素
         */
        int year=k.get(Calendar.YEAR);
        int month=k.get(Calendar.MONTH);//0——11，0表示一月
        int day=k.get(Calendar.DATE);
        int weekday=k.get(Calendar.DAY_OF_WEEK);//1——7，1对应周日
        System.out.println(weekday);

        /*
        设置日期
         */
        Calendar c2=new GregorianCalendar();
        c2.set(Calendar.YEAR,2030);
        System.out.println(c2);

        Calendar c3=new GregorianCalendar();
        c3.add(Calendar.DATE,100);//往后100天

        Date d4=c3.getTime();//日期对象转化为时间对象
        System.out.println(d4);
        Calendar c4=new GregorianCalendar();
        c4.setTime(new Date());//反过来
        System.out.println(c4);


    }
}
