// 该程序包含：
//
// Person类:
//
// 属性：int id, String name, String phoneNumber，String address。
//
// 方法：
//
// 无参构造方法，有参构造方法（id, name, phoneNumber，addres）, 
//
// 各个参数的getter/setter方法，
//
// toString()方法。
//
// Utils类:
//
// 用于生成通讯录(具体代码下面已给出)
//
// Main类的main方法:
//
// 使用Utils类创建一个通讯录personList，使用Map将personList中的person对象按name分类存储。即，key为person的name值，value为对应的person对象的List列表（说明：就是将相同name值的person对象放在一起List列表中）。
//
//  接下来就可以在该Map中根据姓名与电话号码查询联系人。查询方法如下：
//
// 输入n
// 输入n行的name以及phoneNumber值，以空格分开。然后根据name查找map，如果找到且在列表中的存在某个person对象的电话号码也相同，则输该person对象。如果找不到（即找不到name与电话号码均匹配的Person对象）则输出提示信息。
// 最后一行输出map的数量，即map.size()(该行输出在输出样例中未显示)
//
// 输入格式:
// 一个正整数n
//
// 接下去的n行：
//
// 输入name以及phoneNumber
//
// 输出格式:
// 如果找到对象则输出该对象
//
// 未找到对象则输出"Not found!"。

// Sample Input
// 5
// Vern 15678785276
// Paul 13369862612
// Todd 15094198414
// Mike 15079239680
// Tony 13739215033

// Sample Output
// Not found!
// Person [id=162538, name=Paul, phoneNumber=13369862612, address=Room 8-446-6866, ShiGu Road]
// Person [id=139814, name=Todd, phoneNumber=15094198414, address=Room 8-856-5546, JiYuan Road]
// Not found!
// Person [id=184950, name=Tony, phoneNumber=13739215033, address=Room 71-896-9345, SongBai Road]
// 161999

import java.util.*;
import java.util.stream.Collectors;

class Main {
    public static void main(String[] args) {
        List<Person> persons = Utils.getPersonList();
        Map<String, List<Person>> map =
            persons.stream().collect(Collectors.groupingBy(Person::getName));

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        while (n-- > 0) {
            String name = sc.next();
            String phoneNumber = sc.next();
            if (map.containsKey(name)) {
                Person person = map.get(name)
                                    .stream()
                                    .filter(p -> p.getPhoneNumber().equals(phoneNumber))
                                    .findFirst()
                                    .orElse(null);
                System.out.println(person != null ? person.toString() : "Not found!");
            } else {
                System.out.println("Not found!");
            }
        }
        System.out.println(map.size());

        sc.close();
    }
}

class Person {
    int id;
    String name;
    String phoneNumber;
    String address;
    Person() {
    }
    public Person(int id, String name, String phoneNumber, String address) {
        this.id = id;
        this.name = name;
        this.phoneNumber = phoneNumber;
        this.address = address;
    }
    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getPhoneNumber() {
        return phoneNumber;
    }
    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }
    public String getAddress() {
        return address;
    }
    public void setAddress(String address) {
        this.address = address;
    }
    @Override
    public String toString() {
        return "Person [id=" + id + ", name=" + name + ", phoneNumber=" + phoneNumber +
            ", address=" + address + "]";
    }
}

class Utils {
    private static final Random rd = new Random(3);
    private static final int number = 200000;
    private static List<String> getPersonName() {
        StringBuilder sb = new StringBuilder();
        List<String> names = new ArrayList<String>();
        for (int i = 0; i < Utils.number; i++) {
            sb.delete(0, sb.length());
            for (int j = 0; j < 4; j++) {
                if (j == 0) {
                    sb.append((char)('A' + rd.nextInt(26)));
                } else {
                    sb.append((char)('a' + rd.nextInt(26)));
                }
            }
            names.add(sb.toString());
        }
        return names;
    }
    private static List<String> getPhoneNumber() {

        String[] telFirst = ("134,135,136,137,138,139,150,151,152,157,158,159,130,131,"
                             + "132,155,156,133,153")
                                .split(",");
        StringBuilder sb = new StringBuilder();
        List<String> phoneNumbers = new ArrayList<String>();
        for (int i = 0; i < Utils.number; i++) {
            sb.delete(0, sb.length());
            for (int j = 0; j < 9; j++) {
                if (j == 0) {
                    sb.append(telFirst[rd.nextInt(telFirst.length)]);
                } else {
                    sb.append(rd.nextInt(10));
                }
            }
            phoneNumbers.add(sb.toString());
        }
        return phoneNumbers;
    }

    private static List<String> getPersonAddress() {
        List<String> addresses = new ArrayList<String>();
        String[] roads = {"HuanDao Road", "WenZeng Road", "ZhongShang Road", "KaiHe Road",
                          "NanHua Road",  "SongBai Road", "BinShui Road",    "ShiGu Road",
                          "JiYuan Road",  "YinJiang Road"};
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < Utils.number; i++) {
            sb.delete(0, sb.length());
            for (int j = 0; j < 2; j++) {
                if (j == 1) {
                    sb.append(roads[rd.nextInt(roads.length)]);
                } else {
                    sb.append("Room " + rd.nextInt(100) + "-" + rd.nextInt(1000) + "-" +
                              rd.nextInt(10000) + ", ");
                }
            }
            addresses.add(sb.toString());
        }
        return addresses;
    }

    public static List<Person> getPersonList() {
        List<String> names = Utils.getPersonName();
        List<String> phones = Utils.getPhoneNumber();
        List<String> addresses = Utils.getPersonAddress();
        List<Person> persons = new ArrayList<Person>();

        for (int i = 0; i < Utils.number; i++) {
            Person person = new Person();
            person.setId(i);
            person.setName(names.get(i));
            person.setPhoneNumber(phones.get(i));
            person.setAddress(addresses.get(i));
            persons.add(person);
        }
        return persons;
    }
}
