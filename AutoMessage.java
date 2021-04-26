package cn.sxt;
import java.util.Scanner;
import java.awt.*;
import java.awt.datatransfer.Clipboard;
import java.awt.datatransfer.StringSelection;
import java.awt.datatransfer.Transferable;
import java.awt.event.KeyEvent;
public class AutoMessage {
    public static void main(String[] args) throws InterruptedException{
        String name;
        Scanner user=new Scanner(System.in);
        System.out.println("输入好友昵称");
        name=user.nextLine();
        //AutoMessage a=new AutoMessage();
        SendMessage(name);
    }
    public  static void SendMessage(String name) throws InterruptedException{
        Robot robot=null;
        try{
          robot=new Robot();
        } catch(AWTException e){
            e.printStackTrace();
        }
        assert robot!=null;
        robot.keyPress(KeyEvent.VK_CONTROL);
        robot.keyPress(KeyEvent.VK_ALT);
        robot.keyPress(KeyEvent.VK_W);

        robot.keyRelease(KeyEvent.VK_CONTROL);
        robot.keyRelease(KeyEvent.VK_ALT);
        robot.delay(1000);

        robot.keyPress(KeyEvent.VK_CONTROL);
        robot.keyPress(KeyEvent.VK_F);
        robot.keyRelease(KeyEvent.VK_CONTROL);

        Clipboard clip=Toolkit.getDefaultToolkit().getSystemClipboard();
        Transferable tText=new StringSelection(name);
        clip.setContents(tText,null);

        robot.keyPress(KeyEvent.VK_CONTROL);
        robot.keyPress(KeyEvent.VK_V);
        robot.keyRelease(KeyEvent.VK_CONTROL);
        robot.delay(1000);
        robot.keyPress(KeyEvent.VK_ENTER);

        SendM();


    }
    public static void SendM() throws InterruptedException{
        String[] messages={
                "你好，我是微信机器人小V",
                "渣辉我有事跟你说！",
                "其实，我是你爹",
                "真的，我没有骗你",
                "我要是骗你的话，渣辉就踏马是狗来的",
                "哈哈哈哈哈",
        };

        for(String message :messages){
            sendOneMessage(message);
        }
        Thread.sleep(2000);
        //sendOneMessage("自动发信息，屌不屌！");


    }

    public static void sendOneMessage(String msg){
        Clipboard clip=Toolkit.getDefaultToolkit().getSystemClipboard();
        Transferable tText;
        Robot robot=null;
        try{
            robot=new Robot();
        }catch(AWTException e){
            e.printStackTrace();
        }
        assert robot !=null;
        robot.delay(500);
        tText=new StringSelection(msg);
        clip.setContents(tText,null);
        robot.keyPress(KeyEvent.VK_CONTROL);
        robot.keyPress(KeyEvent.VK_V);
        robot.keyRelease(KeyEvent.VK_CONTROL);
        robot.delay(500);
        robot.keyPress(KeyEvent.VK_ENTER);
        robot.delay(500);

    }


}
