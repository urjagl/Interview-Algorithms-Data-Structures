import java.util.ListIterator;
import java.util.Stack;


// In place stack sort
static void sortedInsert(Stack<Integer> s, int x){
	if(s.isEmpty() || x > s.peek()){
		s.push(x);
		return;
	}
	int temp = s.pop();
	sortedInsert(s,x);
	s.push(temp);
}

static void sortStack(Stack<Integer> s){
if(!s.isEmpty()){
	int temp = s.pop();
	sortStack(s);
	sortedInsert(s,x);
	}
}

// Remove duplicates from a string
public static String unique(String s){
	String str = new String();
	int len = s.length();
	for (int i = 0; i < len; i++){
		char c = s.charAt(i);
		if(s.indexOf(c) < 0){
			str += c;
		}
	}
	return str;
}


/* Java Program to implement a queue using two stacks */
// Note that Stack class is used for Stack implementation
 
import java.util.Stack;
 
public class GFG
{
    /* class of queue having two stacks */
    static class Queue
    {
        Stack<Integer> stack1 ;
        Stack<Integer> stack2 ;
    }
     
    /* Function to push an item to stack*/
    static void push(Stack<Integer> top_ref, int new_data)
    {
        //Push the data onto the stack
        top_ref.push(new_data);
    }
     
    /* Function to pop an item from stack*/
    static int pop(Stack<Integer> top_ref)
    {
        /*If stack is empty then error */
        if(top_ref.isEmpty())
        {
            System.out.println("Stack Underflow");
            System.exit(0);    
        }
        //pop the data from the stack
        return top_ref.pop(); 
    }
    //Function to enqueue an item to the queue
    static void enQueue(Queue q, int x)
    {
        push(q.stack1, x);
    }

    
    /* Function to dequeue an item from queue */
    static int deQueue(Queue q)
    {
        int x;
        /* If both stacks are empty then error */
        if(q.stack1.isEmpty() && q.stack2.isEmpty() )
        {
            System.out.println("Q is empty");
            System.exit(0);
        }
      
        /* Move elements from stack1 to stack 2 only if
        stack2 is empty */
        if(q.stack2.isEmpty())
        {
            while(!q.stack1.isEmpty())
            {
            x = pop(q.stack1);
            push(q.stack2, x);
              
            }
        }
        x = pop(q.stack2);
        return x;
    }

String countChars(String s){
	String result;
	int len = s.lengt();
	int j = 0;
	while(i < length){
		int num = 1;
		while(s[i] == s[j]){
			j++;
			num++;
		}
		i = j+1;
		result += s[i]+num.toString();
	}
}





}