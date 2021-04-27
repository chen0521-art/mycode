package cn.sxt.game;

import javax.swing.JFrame;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class MyGameFrame extends JFrame {
    /*
    窗口的初始化
     */
    public void launchFrame(){
        this.setTitle("我的小游戏");
        this.setVisible(true);
        this.setSize(500,500);//窗口的大小
        this.setLocation(300,300);//窗口出现的位置
        /*
        设置关闭动作，没有以下代码的话，关闭窗口后还要stop
         */
        this.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
                System.exit(0);
            }
        });
    }
    public static void main(String[] args){
        MyGameFrame f=new MyGameFrame();
        f.launchFrame();
    }
}
