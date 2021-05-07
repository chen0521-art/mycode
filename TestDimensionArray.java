package Java;
import java.util.Arrays;
public class TestDimensionArray {
    public static void main(String[] args){
        int[][] a=new int[3][];//原理（与类数组相同）：先建立一个数组，长度为3，用来存放其它数组的地址  故【3】【】，不规定后面数组的长度
        a[0]=new int[]{10,20,30};
        a[1]=new int[]{40,50};
        a[2] = new int[]{10};
        System.out.println(Arrays.toString(a));//打印的是第一个数组里的东西，即“地址”
        System.out.println(a[1][0]);//40 a[1]指向后面的地二个数组，【0】就是该数组的第一个元素
        for(int[] m:a){
            System.out.println(Arrays.toString(m));//正确的打印内容
        }

        /*
        数组存储表格数据
         */
        Object[] b1={"1001","你好","100"};//1001本质上不是对象，但这里的基本数据类型会被“自动装箱”成包装类对象
        Object[] b2={"1001","你好","100"};
        Object[] b3={"1001","你好","100"};
        Object[][] c=new Object[3][];
        c[0]=b1;
        c[1]=b2;
        c[2]=b3;
        for(Object[] m:c){
            System.out.println(Arrays.toString(m));
        }
    }
}
