package Java;

/**
 * 泛型
 */

public class TestGeneric {
    public static void main(String[] args){
        /*
        MyCollection m=new MyCollection();
        m.set("陈国颖",0);
        m.set(12345,1);
        Integer a=(Integer)m.get(1);//强制转型
        String str=(String)m.get(0);//
        System.out.println(a);
        System.out.println(str);

         */
        MyCollection<String> m=new MyCollection<>();
        m.set("陈",1);
        String str=m.get(1);
        System.out.println(str);

    }
}
/*
class MyCollection{
    Object[] objs=new Object[5];
    public void set(Object obj,int index){
        objs[index]=obj;
    }
    public Object get(int index){
        return objs[index];
    }
}

 */

/**
 * 加标签
 *
 * @param <A>
 */
class MyCollection<A>{
    Object[] Obj=new Object[5];
    public void set(A a,int index){//A类型
        Obj[index]=a;
    }
    public A get(int index){
        return (A) Obj[index];//注意
    }

}


