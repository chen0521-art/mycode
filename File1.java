package cn.sxt;

import java.io.File;
import java.io.IOException;

public class TestFile {
    public static void main(String[] args) throws IOException {
        File f=new File("D:/IDEA相关/src/zha.png");
        System.out.println(f.length());//length是文件的长度，单位为k，如果f是文件夹，返回值为0
        f=new File("D:/IDEA相关/src","zha.png");
        System.out.println(f.length());
        f=new File(new File("D:/IDEA相关/src"),"zha.png");
        System.out.println(f.length());
        //常用的创建file对象的3种方法
        test1();
        test2();

    }
    public static void test1(){
        File f=new File("D:/IDEA相关/src/zha.png");
        System.out.println(f.getName());//返回名称
        System.out.println(f.getAbsolutePath());//绝对路径（含有盘符）
        System.out.println(f.getParent());//上路径，没有就返回null
        System.out.println(f.getPath());//返回你创建的路径

    }
    public static void test2() throws IOException {
        File src=new File("D:/IDEA相关/src/aa.txt");
        System.out.println(src.exists());//是否存在
        System.out.println(src.isFile());//是否为文件
        System.out.println(src.isDirectory());//是否为目录
        boolean flag1=src.createNewFile();//不存在才创建，创建成功返回true，否则返回false    要抛出异常，不知道文件是否存在
        boolean flag2=src.delete();//删除已存在的文件，成功true，否则false
        System.out.println(flag1);
        System.out.println(flag2);
    }
}
