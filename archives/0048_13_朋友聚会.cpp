// Today is Ignatius' birthday. He invites a lot of friends. Now it's dinner time. Ignatius wants to know how many tables he needs at least. You have to notice that not all the friends know each other, and all the friends do not want to stay with strangers.
// 今天是伊格纳修斯的生日。他邀请了很多朋友。现在是晚餐时间。伊格纳修斯想知道他至少需要多少张桌子。你要注意，并不是所有的朋友都互相认识，而且所有的朋友都不想和陌生人待在一起。
//
// One important rule for this problem is that if I tell you A knows B, and B knows C, that means A, B, C know each other, so they can stay in one table.
// 这个问题的一个重要规则是，如果我告诉你 A 认识 B，B 认识 C，那就意味着 A、B、C 彼此认识，所以他们可以待在一张桌子上。
//
// For example: If I tell you A knows B, B knows C, and D knows E, so A, B, C can stay in one table, and D, E have to stay in the other one. So Ignatius needs 2 tables at least.
// 例如：如果我告诉你 A 认识 B，B 认识 C，D 认识 E，那么 A、B、C 可以留在一张桌子上，而 D、E 必须留在另一张桌子上。所以 Ignatius 至少需要两张桌子。
//
// Input
//
// The input starts with an integer T(1<=T<=25) which indicate the number of test cases. Then T test cases follow. Each test case starts with two integers N and M(1<=N,M<=1000). N indicates the number of friends, the friends are marked from 1 to N. Then M lines follow. Each line consists of two integers A and B(A!=B), that means friend A and friend B know each other. There will be a blank line between two cases.
// 输入以一个整数 T(1<=T<=25) 开头，表示测试用例的数量。接下来是 T 行测试用例。每个测试用例以两个整数 N 和 M(1<=N,M<=1000) 开头。N 表示好友数量，好友编号从 1 到 N。接下来是 M 行，每行包含两个整数 A 和 B(A!=B)，表示好友 A 和好友 B 彼此认识。两个用例之间会有一个空行。
//
// Output
//
// For each test case, just output how many tables Ignatius needs at least. Do NOT print any blanks.
// 对于每个测试用例，只需输出 Ignatius 至少需要多少个表。不要打印任何空白。

// Sample Input
// 2
// 5 3
// 1 2
// 2 3
// 4 5
// 
// 5 1
// 2 5

// Sample Output
// 2
// 4

// Prepend Code Start
#include <stdio.h>

int pre[1010];
int find(int x);

int main()
{
    int t;
    scanf("%d",&t);
    
    while(t--){
        int n ,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            pre[i]=i;
        
        for(int i=0;i<m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            
            int fx=find(x);
            int fy=find(y);
            
            if(fx!=fy) pre[fx]=fy;
        }
        
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(pre[i]==i) cnt++;
        printf("%d\n",cnt);
    }
    
    return 0;
}
// Prepend Code End

int find(int x) {
  if (pre[x] != x) {
    pre[x] = find(pre[x]);
  }
  return pre[x];
}
