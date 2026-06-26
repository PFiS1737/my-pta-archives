// 定义IntegerStack接口，用于声明一个存放Integer元素的栈的常见方法:
//
// public Integer push(Integer item);
// //如果item为null，则不入栈直接返回null。如果栈满，也返回null。如果插入成功，返回item。
//
// public Integer pop();   //出栈，如果为空，则返回null。出栈时只移动栈顶指针，相应位置不置为null
// public Integer peek();  //获得栈顶元素，如果为空，则返回null.
// public boolean empty(); //如果为空返回true
// public int size();      //返回栈中元素个数
// 定义IntegerStack的实现类ArrayIntegerStack，内部使用数组实现。创建时，可指定内部数组大小。
//
// main方法说明
// 输入n，建立可包含n个元素的ArrayIntegerStack对象
// 输入m个值，均入栈。每次入栈均打印入栈返回结果。
// 输出栈顶元素，输出是否为空，输出size
// 使用Arrays.toString()输出内部数组中的值。
// 输入x，然后出栈x次，每次出栈均打印。
// 输出栈顶元素，输出是否为空，输出size
// 使用Arrays.toString()输出内部数组中的值。

// Sample Input
// 5
// 3
// 1 2 3
// 2

// Sample Output
// 1
// 2
// 3
// 3,false,3
// [1, 2, 3, null, null]
// 3
// 2
// 1,false,1
// [1, 2, 3, null, null]

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();

        ArrayIntegerStack stack = new ArrayIntegerStack(n);

        int m = in.nextInt();
        while (m-- > 0) {
            System.out.println(stack.push(in.nextInt()));
        }

        System.out.println(
            (stack.peek() == null ? "null" : stack.peek()) + "," + stack.empty() + "," +
            stack.size()
        );
        System.out.println(Arrays.toString(stack.inner));

        int x = in.nextInt();
        while (x-- > 0) {
            System.out.println(stack.pop());
        }

        System.out.println(
            (stack.peek() == null ? "null" : stack.peek()) + "," + stack.empty() + "," +
            stack.size()
        );
        System.out.println(Arrays.toString(stack.inner));

        in.close();
    }
}

interface IntegerStack {
    //如果item为null，则不入栈直接返回null。如果栈满，也返回null。如果插入成功，返回item。
    public Integer push(Integer item);
    //出栈，如果为空，则返回null。出栈时只移动栈顶指针，相应位置不置为null
    public Integer pop();
    public Integer peek();  //获得栈顶元素，如果为空，则返回null.
    public boolean empty(); //如果为空返回true
    public int size();      //返回栈中元素个数
}

class ArrayIntegerStack implements IntegerStack {
    Integer[] inner;
    ArrayIntegerStack(int capacity) {
        inner = new Integer[capacity];
    }

    int top = 0;

    @Override
    public Integer push(Integer item) {
        if (item == null || top == inner.length) {
            return null;
        }
        inner[top++] = item;
        return item;
    }

    @Override
    public Integer pop() {
        if (empty()) {
            return null;
        }
        return inner[--top];
    }

    @Override
    public Integer peek() {
        if (empty()) {
            return null;
        }
        return inner[top - 1];
    }

    @Override
    public boolean empty() {
        return top == 0;
    }

    @Override
    public int size() {
        return top;
    }
}
