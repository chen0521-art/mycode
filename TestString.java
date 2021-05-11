package Java;

import java.util.Locale;

public class TestString {
    public static void main(String[] args){
        /*
        String str1="abcde";
        String str5=new String("abcde");
        String str2="How are you!";
        String str3=" How are you! ";
        String str4="how are you!";
        System.out.println(str1.charAt(3));//d 提取下标为3的字符
        System.out.println(str1.length());

        System.out.println(str1==str5);//false前者直接把字符存放在常量池里，而后者时创建了新的对象 地址不一样了
        System.out.println(str5.equals(str1));//true比较字符串用equals方法，比较的时内容
        System.out.println(str4.equalsIgnoreCase(str2));//true 忽略大小写的比较

        System.out.println(str2.indexOf("a"));//4 首字母第一次出现的位置，空格占一个位置，无论是字母还是单词，都用双引号

        String str6=str2.replace("How","how");//替换，但原来的并没有改变
        System.out.println(str6);

        System.out.println(str2.startsWith("How"));//是不是以How开头 无论是字母还是单词，都要用双引号
        System.out.println(str3.endsWith(" "));

        String str7=str1.substring(2);//提取字符串，从下标为2开始到字符串结尾结束
        String str8=str1.substring(2,4);//[2,4)
        System.out.println(str7);
        System.out.println(str8);

        System.out.println(str2.toLowerCase(Locale.ROOT));//转小写
        System.out.println(str2.toUpperCase(Locale.ROOT));//转大写

        System.out.println(str3.trim());//去除字符串首尾的空格，但中间的不行
        */

        /*
        String 类，为不可变字符序列，只能赋值一次
        StringBuilder,StringBuffer 可变字符序列，可对内容进行修改，前一个“线程不安全，但效率高”，后一个
        “线程安全，但效率低”，一般使用前者
         */
        StringBuilder sb=new StringBuilder("chen");
        System.out.println(Integer.toHexString(sb.hashCode()));//打印地址
        sb.append("guo").append("ying");
        System.out.println(sb);
        System.out.println(Integer.toHexString(sb.hashCode()));//地址跟前面一样，没有改变
        sb.setCharAt(0,'C');//替换字符  索引+替换后的字符
        System.out.println(sb);
        /*
        在字符串后面拼接字符（串）
        错误方法：
        String s1="";
        for(int i=0;i<5000;i++){
            s1=s1+i;//整个循环下来需要创建10000个对象，这样会使服务器奔溃的
        }

         */
        StringBuilder s=new StringBuilder("");
        for(int i=0;i<5000;i++){
            s.append(i);//正确的方法
        }
        long num=Runtime.getRuntime().freeMemory();//获取系统剩余内存空间
        long time=System.currentTimeMillis();//获取系统的当前时间  运行前后的时间差那用得上，上同
        System.out.println(num);
        System.out.println(time);
    }
}
