import java.util.Stack;

public class BaseballGame {

    public int calPoints(String[] ops) {

        Stack<Integer> stack = new Stack();
        int sum = 0;

        for (String op : ops) {
            switch (op){

                case "+":
                    int c1 = stack.peek();
                    int c2 = stack.get(stack.size()-2);
                    stack.push(c1+c2);
                    break;
                case "D":
                    stack.push(stack.peek()*2);
                    break;
                case "C":
                    stack.pop();
                    break;
                default:
                    stack.add(Integer.parseInt(op));
                    break;
            }

        }

        while(!stack.isEmpty()){
            sum += stack.pop();
        }
        return sum;

    }
}
