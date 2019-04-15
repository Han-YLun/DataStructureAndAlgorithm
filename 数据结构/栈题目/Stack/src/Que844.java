import java.util.Stack;

public class Que844 {


    public boolean backspaceCompare(String S, String T) {

        Stack<Character> sStack = new Stack();
        Stack<Character> tStack = new Stack();

        for (int i=0;i< S.length();i++){
            if(S.charAt(i) == '#'){
                if(!sStack.isEmpty()){
                    sStack.pop();
                }
            }else{
                sStack.push(S.charAt(i));
            }
        }

        for (int i=0;i< T.length();i++){
            if(T.charAt(i) == '#'){
                if(!tStack.isEmpty()){
                    tStack.pop();
                }
            }else{
                tStack.push(S.charAt(i));
            }
        }

        S = "";
        T = "";
        while(!sStack.isEmpty()){
            S += sStack.pop();
        }

        while(!tStack.isEmpty()){
            T += tStack.pop();
        }

        if(S.equals(T))
            return true;
        return false;


    }
}
