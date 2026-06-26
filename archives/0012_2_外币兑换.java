// 银行通过买入和卖出外币，为客户提供服务将人民币兑换为外汇或将外汇兑换为人民币。按要求完成下面题目，接受键盘输入外币名称、现汇买入价、现汇卖出价，将人民币和外币相互兑换。
//
// 类定义：
// 创建 Java 类CurrencyExchange
//
// 类中包含3个私有静态成员变量：
//
// 1）currencyName： 外币名称，String型
//
// 2）pricePurchase： 现汇买入价 ，100人民币兑换外币数，double型
//
// 3）priceSale： 现汇卖出价 ，100人民币兑换外币数，double型
//
// 类中包含4个公有静态成员方法：
//
// 1） void setPrice(String currencyN,double priceP, double priceS)
//
// 方法的3个参数分别为类3个私有静态成员变量赋值
// 2） String getCurrencyName()
//
// 返回currencyName的值
// 3）double purchaseForeignMoney(double fmoney)
//
// 返回买入数量为fmoney的外币所需人民币金额。
// 公式：人民币=外币*现汇买入价/100
// 4）double saleForeignMoney(double rmb)
//
// 返回银行接受客户数量为rmb的人民币，可卖出给客户多少金额的外币。
// 公式：外币=人民币*100/现汇卖出价

// Sample Input
// 美元 635.4 638.1
// 1000 1000

// Sample Output
// 1000.00人民币兑换156.72美元
// 1000.00美元兑换6354.00人民币

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        //输入外币名称、现汇买入价、现汇卖出价
        CurrencyExchange.setPrice(sc.next(), sc.nextDouble(), sc.nextDouble());
        //输入人民币金额
        double money = sc.nextDouble();
        //输出上述金额人民币可兑换外币金额
        System.out.printf(
            "%.2f人民币兑换%.2f%s\n", money, CurrencyExchange.saleForeignMoney(money),
            CurrencyExchange.getCurrencyName()
        );
        //输入外币金额
        money = sc.nextDouble();
        //输出上述金额外币可兑换人民币金额
        System.out.printf(
            "%.2f%s兑换%.2f人民币", money, CurrencyExchange.getCurrencyName(),
            CurrencyExchange.purchaseForeignMoney(money)
        );
        sc.close();
    }
}

class CurrencyExchange {
    static String currencyName;
    static double pricePurchase;
    static double priceSale;

    static void setPrice(String currencyN, double priceP, double priceS) {
        currencyName = currencyN;
        pricePurchase = priceP;
        priceSale = priceS;
    }

    static String getCurrencyName() {
        return currencyName;
    }

    static double purchaseForeignMoney(double fmoney) {
        return fmoney * pricePurchase / 100;
    }

    static double saleForeignMoney(double rmb) {
        return rmb * 100 / priceSale;
    }
}
