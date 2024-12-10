// Description
// 运输公司替客户运送货物并收取运费。基本运费为每吨每公里价格，总运费按照运输里程分段打折.
// 计算方法如下：500公里以内部分不打折，501～1000公里部分打九五折，1001～2000公里部分打九折，超过2000公里部分打八八折。
// Input
// 输入三个数字，分别是基本运费p、货物重量w吨、总里程m公里。
// Output
// 输出总运费，精确到小数点后2位。

// Sample Input
// 4.7 29 2008

// Sample Output
// 256522.05

#include <stdio.h>

int main() {
  double p, w, m;
  scanf("%lf %lf %lf", &p, &w, &m);

  double sum = w * p;
  if (m <= 500)
    sum *= m;
  else if (m <= 1000)
    sum *= 500 + (m - 500) * 0.95;
  else if (m <= 2000)
    sum *= 500 + 500 * 0.95 + (m - 1000) * 0.9;
  else
    sum *= 500 + 500 * 0.95 + 1000 * 0.9 + (m - 2000) * 0.88;

  printf("%.2lf\n", sum);

  return 0;
}
