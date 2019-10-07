import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    public static void main(String[] args) {
        MyQueue<Integer> queue = new MyQueue<Integer>();

        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();

        for (int i = 0; i < n; i++) {
            int operation = scan.nextInt();
            if (operation == 1) { // enqueue
              queue.enqueue(scan.nextInt());
            } else if (operation == 2) { // dequeue
              queue.dequeue();
            } else if (operation == 3) { // print/peek
              System.out.println(queue.peek());
            }
        }
        scan.close();
    }
}

class MyQueue<Integer>{
    private Stack<Integer> enStack, deStack;
    
    public MyQueue(){
        enStack = new Stack<Integer>();
        deStack = new Stack<Integer>();
    }

    public void enqueue(Integer n) {
        enStack.push(n);
    }

    public Integer dequeue(){
        // If the dequeue stack is not empty then the top of the dequeue stack is
        // still the front of the queue.
        if(deStack.empty()){
            // If it is empty then transfer the enqueue stack over
            while(!enStack.empty()){
                deStack.push(enStack.pop());
            }
        }
        return deStack.pop();
    }

    public Integer peek(){
        // If the dequeue stack is not empty then the top of the dequeue stack is
        // still the front of the queue.
        if(deStack.empty()){
            // If it is empty then transfer the enqueue stack over
            while(!enStack.empty()){
                deStack.push(enStack.pop());
            }
        }
        return deStack.peek();
    }
}

