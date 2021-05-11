package Java;
import java.util.Arrays;
public class TestArrays {
    public static void main(String[] args){
        copyArr();
        System.out.println();
        delElement(2);
        System.out.println();
        addElement(9,3);

        String[] str1={"11","22","33","44","55"};
        int[] str2={1,3,2,5,6,4};
        System.out.println(Arrays.toString(str1));//打印数组内容
        Arrays.sort(str2);//排序，由小到大，数组str2已经改变 void
        System.out.println(Arrays.toString(str2));
        System.out.println(Arrays.binarySearch(str1,"33"));//查找元素所在的索引并返回（下标），如果没有就返回-1

    }
    public static void copyArr(){
        String[] str1={"aa","bb","cc","dd","ee","ff"};
        String[] str2=new String[10];
        System.arraycopy(str1,2,str2,0,str1.length-2);//只是实现了数组的拷贝
        for(String a:str2){
            System.out.println(a);
        }
    }
    public static void delElement(int index){
        String[] str1={"aa","bb","cc","dd","ee","ff"};
        System.arraycopy(str1,index,str1,index-1,str1.length-index);//拷贝到原来的数组，覆盖
        str1[str1.length-1]=null;//删除一个元素，要出现目标元素后的元素往前移动一个位置的视觉效应，得把最后一个元素置空，否则最后一个元素为ee
        for(String a:str1){
            System.out.println(a);
        }
    }
    public static void addElement(int element,int index){//扩容
        int[] str1={1,2,3,4,5};
        int[] str2=new int[str1.length+10];
        System.arraycopy(str1,0,str2,0,str1.length);
        System.arraycopy(str2,index-1,str2,index,str1.length-index-1);
        str2[index-1]=element;
        for(int a:str2){
            System.out.println(a);
        }

    }
}

