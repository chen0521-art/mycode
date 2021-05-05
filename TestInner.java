package Java;

public class TestInner {
    public static void test(AA a){
        a.aa();
        a.say();
    }
    public static void main(String[] args){
        B.A ba=new B().new A();//创建非静态内部对象时的语法
        C.D cd=new C.D();//创建静态内部类对象语法
        ba.show();
        cd.deploy();
        TestInner.test(new AA() {   //匿名内部类，适合只用一次的类（如键盘听键类）
            @Override
            public void aa() {
                System.out.println("哈哈哈哈哈哈");
            }

            @Override
            public void say() {
                System.out.println("Say hallo");
            }
        });

    }


}
class B{
    private final int money=10000;
    private final String name="陈国颖";
    class A{
        int age=18;
        public void show(){
            int age=17;
            System.out.println(B.this.name+"the rest of your counter is:"+B.this.money);//非静态内部类访问外部类时的格式，但下面一行也可以
            System.out.println(name+"rest is:"+money);
            System.out.println(this.age);//访问内部类成员变量
            System.out.println(age);//访问局部变量
        }
    }
}
class C{
    private static final int H=100;
    private static final String num="123456";
    static class D{
        int W=99;
        void deploy(){
            System.out.println(C.H);//只能访问外部类中的静态成员变量，静态就不能用this
            System.out.println(W);
            System.out.println(num);
        }
    }
}
interface AA{
    void aa();
    void say();
}
