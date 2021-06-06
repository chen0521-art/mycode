package mycollection;

import java.util.*;

/**
 * 测试迭代器遍历set,map,list
 */
public class TestIterator {
    public static void main(String[] args){
        test1();
        test2();
        test3();
        test4();
    }
    public static void test1(){//链表的迭代器
        List<String> l=new ArrayList<>();
        l.add("chen");
        l.add("guo");
        l.add("ying");
        for(Iterator<String> it=l.iterator();it.hasNext();){//hasNext作为判断条件，是否有下一个记得有分号
            String temp=it.next();//next,即指向对象，又向后移动
            System.out.println(temp);
        }
    }
    public static void test2(){//set的迭代器
        Set<Integer> s=new HashSet<>();
        s.add(77);
        s.add(11);
        s.add(88);
        for(Iterator<Integer> it=s.iterator();it.hasNext();){
            Integer temp=it.next();
            System.out.println(temp);
        }
    }
    public static void test3(){//转成set的迭代器
        Map<Integer,String> m=new HashMap<>();
        m.put(1,"chen");
        m.put(2,"guo");
        m.put(3,"ying");
        Set<Map.Entry<Integer,String>> ss=m.entrySet();
        for(Iterator<Map.Entry<Integer, String>> it = ss.iterator(); it.hasNext();){
            Map.Entry<Integer,String> temp=it.next();
            System.out.println(temp.getKey()+"————"+temp.getValue());
        }
    }
    public static void test4(){//转成key的迭代器
        Map<Integer,Integer> m1=new TreeMap<>();//treemap按key递增的方向打印
        m1.put(12,99);
        m1.put(10,77);
        m1.put(1,100);
        Set<Integer> sss=m1.keySet();//把键都拿出来
        for(Iterator<Integer> it=sss.iterator();it.hasNext();){
            Integer temp=it.next();
            System.out.println(temp+"————"+m1.get(temp));
        }

    }
}
