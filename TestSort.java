package Java;

import java.util.Arrays;

public class TestSort {
    public static void main(String[] args){
        int[] a={10,30,20,90,80,50,60,70};
        bubbleSort(a);
        int[] b={1,8,7,9,4,3,5,2,6};
        Arrays.sort(b);//先排好序
        System.out.println(Arrays.toString(b));
        System.out.println(binarySearch(b,7));//返回的是排好顺序后的索引

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
}
