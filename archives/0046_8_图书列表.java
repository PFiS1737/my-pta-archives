// 构建一个书类Book，包括名称（字符串），价格（整型），作者（字符串，多个作者当做一个字符串处理），版本号（整型），提供带参数的构造函数Book(String name, int price, String author, int edition)，提供该类的toString()和equals()方法，toString方法返回所有成员属性的值的字符串形式，形如“name: xxx, price: xxx, author: xxx, edition: xxx”，当两个Book对象的名称(不关心大小写，无空格)、作者(不关心大小写，无空格)、版本号相同时，认为两者表示同一本书。 Main函数中，读入两本书，输出他们是否相等，打印两本书的信息。
//
// 构建一个书单类BookList，该类中用一个列表类对象存放书单，提供添加图书（addBook）、查找图书（searchBook）的函数
// main函数从键盘输入多个Book添加到书单中，（添加时，提供书的名称、价格、作者、版本号），而后从键盘读入一本书，查找该列表对象中是否包含该书，若包含，输出”found: 该书在列表中的序号”，若不包含，输出“not found”，查找时，提供书的名称、作者、版本号。
//
// 输入描述：
// 添加书的个数
// 添加的书
// 查找的书
//
// 输出描述：
// 查找结果

// Sample Input
// 2
// ThinkingInJava
// 86
// BruceEckel
// 4
// CoreJava
// 95
// CayS.Horstmann
// 10
// CoreJava
// CayS.Horstmann
// 10

// Sample Output
// found: 1

import java.util.ArrayList;
import java.util.Scanner;

class Book {
    String name;
    int price;
    String author;
    int edition;
    public Book(String name, int price, String author, int edition) {
        this.name = name;
        this.price = price;
        this.author = author;
        this.edition = edition;
    }
    @Override
    public String toString() {
        return String.format(
            "name: %s, price: %d, author: %s, edition: %d", name, price, author, edition
        );
    }
    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Book) {
            Book b = (Book)obj;
            return this.name.equalsIgnoreCase(b.name) &&
                this.author.equalsIgnoreCase(b.author) && this.edition == b.edition;
        }
        return false;
    }
}

class BookList {
    ArrayList<Book> books = new ArrayList<Book>();
    void addBook(Book b) {
        books.add(b);
    }
    void searchBook(Book b) {
        int idx = books.indexOf(b);
        if (idx != -1) {
            System.out.println("found: " + idx);
        } else {
            System.out.println("not found");
        }
    }
}

public class Main {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        BookList bl = new BookList();
        int n = s.nextInt();
        for (int i = 0; i < n; i++) {
            bl.addBook(new Book(s.next(), s.nextInt(), s.next(), s.nextInt()));
        }
        bl.searchBook(new Book(s.next(), 0, s.next(), s.nextInt()));
        s.close();
    }
}
