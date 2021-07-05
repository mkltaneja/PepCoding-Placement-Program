import java.io.*;
import java.util.*;

public class Main {

    public static class CustomQueue {
        int[] data;
        int front;
        int size;

        public CustomQueue(int cap) {
            data = new int[cap];
            front = 0;
            size = 0;
        }

        int size() {
            return size;
            // write ur code here
        }

        void display() {
            for(int i = front, cnt = 0; cnt < size; i=(++i)%data.length, cnt++)
                System.out.print(data[i]+" ");
                System.out.println();
            // write ur code here
        }

        void add(int val) {
            if(size == data.length)
            {
                System.out.println("Queue overflow");
                return;
            }
            data[(front + size++)%data.length] = val;
            // write ur code here
        }

        int remove() {
            if(size == 0)
            {
                System.out.println("Queue underflow");
                return -1;
            }
            size--;
            int idx = front;
            front = ++front % data.length;
            return data[idx];
            // write ur code here
        }

        int peek() {
            if(size == 0)
            {
                System.out.println("Queue underflow");
                return -1;
            }
            return data[front];
            // write ur code here
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        CustomQueue qu = new CustomQueue(n);

        String str = br.readLine();
        while (str.equals("quit") == false) {
            if (str.startsWith("add")) {
                int val = Integer.parseInt(str.split(" ")[1]);
                qu.add(val);
            } else if (str.startsWith("remove")) {
                int val = qu.remove();
                if (val != -1) {
                    System.out.println(val);
                }
            } else if (str.startsWith("peek")) {
                int val = qu.peek();
                if (val != -1) {
                    System.out.println(val);
                }
            } else if (str.startsWith("size")) {
                System.out.println(qu.size());
            } else if (str.startsWith("display")) {
                qu.display();
            }
            str = br.readLine();
        }
    }
}