import java.util.Stack;

public class ImplementQueueUsingStacks {

    class MyQueue {

        Stack<Integer> stack = new Stack();
        /** Initialize your data structure here. */
        public MyQueue() {

        }

        /** Push element x to the back of queue. */
        public void push(int x) {
            stack.push(x);
        }

        /** Removes the element from in front of queue and returns that element. */
        public int pop() {
            if(!stack.isEmpty()){
                return stack.remove(0);
            }
            return -1;
        }

        /** Get the front element. */
        public int peek() {
            if(!stack.isEmpty()){
                return stack.get(0);
            }
            return -1;
        }

        /** Returns whether the queue is empty. */
        public boolean empty() {
            return stack.isEmpty();
        }
}

}
