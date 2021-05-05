package Java;

import java.util.Locale;

public class TestString {
    public static void main(String[] args){
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

    }
}
