package Java;

import java.util.*;

public class TestSort {
    public static void main(String[] args){
        int[] a={10,30,20,90,80,50,60,70};
        bubbleSort(a);
        int[] b={1,8,7,9,4,3,5,2,6};
        Arrays.sort(b);//先排好序
        System.out.println(Arrays.toString(b));
        System.out.println(binarySearch(b,7));//返回的是排好顺序后的索引
        System.out.println("------------------");
        test1();
        System.out.println("------------------");
        test2();

    }
    public static void bubbleSort(int[] a){
        for(int j=0;j<a.length-1;j++){
            boolean flag=true;//优化，不进行没必要的循环
            for(int i=0;i<a.length-1-j;i++){
                int temp;
                if(a[i]>a[i+1]){
                    temp=a[i];
                    a[i]=a[i+1];
                    a[i+1]=temp;
                    flag=false;
                }
            }
            if(flag){
                break;
            }
        }
        System.out.println(Arrays.toString(a));
    }
    public static int binarySearch(int[] a,int target){//二分法查找，前提条件是已经排好顺序了，不断缩小查找的范围，减少查找时间
        int start=0;//开始查找处
        int end=a.length-1;//尾巴
        while(start<=end){
            int mid=(start+end)/2;//中间
            if(target==a[mid]){
                return mid;
            }
            if(target>a[mid]){
                start=mid+1;
            }
            if(target<a[mid]){
                end=mid-1;
            }
        }
        return -1;
    }
    public static void test1(){//每一行数据用Map储存，整个表格用list链接
        Map<String,String> row1=new TreeMap<>();
        row1.put("id","1001");
        row1.put("name","张三");
        row1.put("salary","10000");
        Map<String,String> row2=new HashMap<>();
        row2.put("id","1002");
        row2.put("name","李四");
        row2.put("salary","20000");
        Map<String,String> row3=new HashMap<>();
        row3.put("id","1003");
        row3.put("name","赵武");
        row3.put("salary","2020");
        List<Map> list=new ArrayList<>();
        list.add(row1);
        list.add(row2);
        list.add(row3);
        for(Map m:list){
            System.out.println("id:"+m.get("id")+",name:"+m.get("name")+",salary:"+m.get("salary"));
        }
    }
    public static void test2(){//行数据使用javabean（提供相应set，get方法等等的类）储存，表格用Map或者List来连接
        Worker w1=new Worker("1001","张三",10000);
        Worker w2=new Worker("1002","里斯",20000);
        Worker w3=new Worker("1003","赵武",5000);
        List<Worker> list=new ArrayList<>();
        list.add(w1);
        list.add(w2);
        list.add(w3);
        for(Worker m:list){
            //System.out.println(m);这样输出可以重写toString
            System.out.println("id:"+m.getId()+",name:"+m.getName()+",salary:"+m.getSalary());
        }
    }

}
class Worker{
    private String id;
    private String name;
    private int salary;

    public Worker(String id, String name, int salary) {
        this.id = id;
        this.name = name;
        this.salary = salary;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
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


}
