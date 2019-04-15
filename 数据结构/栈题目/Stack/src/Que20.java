import java.util.Stack;

public class Que20 {


    public boolean isValid(String s) {

        Stack<Character> stack = new Stack<Character>();

        char[] chars = s.toCharArray();

        for (char aChar : chars) {
            if(stack.isEmpty()){
                stack.push(aChar);
            }else if(isMatch(stack.peek(),aChar)){
                stack.pop();
            }else{
                stack.push(aChar);
            }
        }

        return stack.isEmpty();
    }

    private boolean isMatch(Character peek, char aChar) {
        return (peek == '(' && aChar == ')') || (peek == '[' && aChar == ']') ||
             (peek == '{' && aChar == '}');
    }
}
