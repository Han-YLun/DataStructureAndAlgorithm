import javafx.beans.binding.IntegerExpression;
import jdk.nashorn.internal.ir.debug.JSONWriter;

import java.util.Stack;

public class Que150 {
    public int evalRPN(String[] tokens) {
        //用来保存整数
        Stack<Integer> stack = new Stack();

        for (int i=0;i<tokens.length;i++) {
            String token = tokens[i];
            //如果是数字，就保存在栈中
            if(!isOperate(token)){
                stack.add(Integer.valueOf(token));
            }else{
                //如果是运算符,就判断是什么运算符，并且进行运算,并且把值重新放到栈中
                int t1 = stack.pop();
                int t2 = stack.pop();
                if(token == "+" ){
                    t1 = t1 + t2;
                }else if(token == "-"){
                    t1 = t2 - t1;
                }else if(token == "*"){
                    t1 = t1 * t2;
                }else if(token == "/"){
                    t1 = t2 / t1;
                }
                stack.add(t1);
            }
        }
        return  stack.pop();
    }

    /**
     * 判断s是否为运算符
     * @param s
     * @return
     */
    public boolean isOperate(String s){

        return (s == "+") || (s == "-") || (s == "*") || (s == "/");
    }

    public static void main(String[] args) {
        String[] str = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
        Que150 q= new Que150();
        System.out.println(q.evalRPN(str));
    }
}
