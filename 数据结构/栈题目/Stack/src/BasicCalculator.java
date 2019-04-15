import java.util.Stack;

public class BasicCalculator {


    public int calculate(String s) {
        StringBuilder stringBuilder = toSuffix(s);
        String[] strings = stringBuilder.toString().split(" ");
        int result = getValueOfExpression(strings);

        return result;
    }

    /**
     * 获取表达式的值
     * @param strings 每一个string字符串为数字或者运算符
     * @return  返回表达式的结果
     */
    private int getValueOfExpression(String[] strings) {

        //数字栈用来保存运算数字
        Stack<Integer> numStack = new Stack<>();
        for (int i = 0; i < strings.length; i++) {

            //当字符是加号时,从栈中弹出两个数字,进行运算并且把结果放回栈中
            if (strings[i].charAt(0) == '+'){
                int num1 = numStack.pop();
                int num2 = numStack.pop();
                numStack.push(num2+num1);
            }else if(strings[i].charAt(0) == '-'){
                //当字符是减号时,从栈中弹出两个数字,进行运算并且把结果放回栈中
                int num1 = numStack.pop();
                int num2 = numStack.pop();
                numStack.push(num2-num1);
            }else{
                //当字符串是数字时,将数字压入栈中
                numStack.push(Integer.parseInt(strings[i]));
            }
            
        }
        //返回栈中最后的结果
        return numStack.pop();
    }

    /**
     * 将中缀表达式转化为后缀表达式
     * @param s 中缀表达式
     * @return  后缀表达式
     */
    private  StringBuilder toSuffix(String s){
        //用来保存后缀表达式
        StringBuilder sb = new StringBuilder();
        //保存运算符
        Stack<Character> operatorStack = new Stack<>();
        for (int i = 0; i < s.length();) {

            char temp = s.charAt(i);
            //如果是数字,就把数字的连续数字都取出来,并且是空格分隔
            if (isNumber(temp)){
                int[] result = getNumAndEndIndex(s, i);
                sb.append(result[0]);
                sb.append(" ");
                i = result[1];
            }else if(temp == '('){
                //如果是左括号,直接压入栈中
                operatorStack.push(temp);
                i++;
            }else if(temp == '+' || temp == '-'){
                //如果时+或-,并且栈内不为空
                if (!operatorStack.isEmpty()){
                    while (!operatorStack.isEmpty()){
                        char item = operatorStack.pop();
                        //如果是栈顶是左括号，直接推入栈中,并且结束循环
                        if (item == '('){
                            operatorStack.push(item);
                            break;
                        }else{
                            //否则就添加到StringBuilder中
                            sb.append(item);
                            sb.append(" ");
                        }
                    }
                }
                //并且把符号压入栈中
                operatorStack.push(temp);
                i++;
            }else if(temp == ')'){
                //如果是右括号,就一直出栈,直到栈顶为左括号
                char item = operatorStack.pop();
                while(item != '('){
                    sb.append(item);
                    sb.append(" ");
                    item = operatorStack.pop();
                }
                i++;
            }else{
                i++;
            }
        }

        //如果栈内不为空,就一直出栈
        while (!operatorStack.isEmpty()){
            sb.append(operatorStack.pop());
            sb.append(" ");
        }
        return sb;
    }

    /**
     * 获取字符串的数字以及结束的索引
     * @param s 字符串
     * @param i 数字开始的索引
     * @return  数组:下标0代表数字,下标1代表结束的索引
     */
    private int[] getNumAndEndIndex(String s, int i) {

        //保存数字以及结束的索引
        int num = 0;
        int index = i;
        for (; index < s.length(); index++) {
            if (isNumber(s.charAt(index))){
                num = num * 10 + s.charAt(index) - '0';
            }else{
                break;
            }
        }
        int[] result = new int[2];
        result[0] = num;
        result[1] = index;
        return result;
    }

    /**
     * 判断字符是否为数字
     * @param c 字符
     * @return  是否为数字
     */
    private boolean isNumber(char c){
        if(c >= '0' && c <= '9')
            return true;
        return false;
    }



    public static void main(String[] args) {
        BasicCalculator q = new BasicCalculator();
        System.out.println(q.calculate("(1+(4+5+2)-3)+(6+8)"));
    }
}