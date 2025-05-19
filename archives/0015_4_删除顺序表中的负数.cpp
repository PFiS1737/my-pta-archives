// 本题要求实现一个函数，可删除顺序表中的负数元素。
//
// （删除元素的函数已经有了，乐）

// Sample Input
// 21 -54 -56 -78 -94 11 13 53 -64 97 -66 -68 -72 19

// Sample Output
// 21 11 13 53 97 19 

// Prepend Code Start
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef int DataType;
#define LISTSIZE  100 
typedef struct
{
    DataType items[LISTSIZE]; /* 存放顺序表元素的数组 */
    int length;                /* 表示线性表的当前表长 */
}SqList;
/* 【 本题要求函数-删除顺序表L里的负数 】*/
void Del_negative(SqList *L);

int InitSqList(SqList *L)
{ /* L为指向顺序表的指针 */
    L->length = 0;
    return 1;
}
int SqListEmpty( SqList L )
{/* L为顺序表 */
    if( L.length <= 0 )
        return 1;
    else
        return 0;
}
int SqListInsert( SqList *L, int pos, DataType item )
{     
    int j;
    if ( L->length == LISTSIZE )                // "溢出”处理
    {     
        printf("overflow!\n");
        return 0; 
    }
    if ( (pos<=0) || (pos > L->length+1) )    // pos值"超出”处理
    {    
        printf("position is error!/n");
        return 0;  
    }
    for (j = L->length -1; j >=pos-1; j--)
        L-> items[j+1] = L-> items[j];    //后移一个位置
    L-> items[pos-1] = item;              //新的数据元素写入
    L->length++;                          //线性表的长度增加1
    return 1;
}
int SqListDelete ( SqList *L, int pos, DataType *item ) 
{/* L为指向顺序表的指针，pos为删除位置，用于item返回被删元素 */    
    int i;
    if( SqListEmpty(*L) )
    {
        printf("顺序表为空表，无法进行删除操作!");
        return 0;
    }
    if ( ( pos<1 ) || ( pos>L->length ) )  
        // 判断pos值是否超出所允许的范围
    {
        printf("删除位置不合法，其取值范围应该是[1,length]");
        return 0; 
    }
    *item = L->items[pos-1];          // 把第pos个元素赋给*item 
    for ( i=pos ; i<L->length ; i++ )   
        L->items[i-1]= L->items[i]; // 第i个元素后的所有元素依次前移  
    L->length--;                    // 顺序表长度减 1
    return 1;       
}

int TraverseSqList(SqList L)
{    /* L为顺序表 */
    int i;
    for (i=0;i<L.length;i++)
    {
        printf("%d ",L.items[i]);
    }
    printf("\n");
    return 1;
}

int main()
{
    SqList A;
    DataType x;
    char ch;
    int pos = 1;
    InitSqList(&A);
    do
    {  
        scanf("%d",&x);
        SqListInsert( &A , pos++ , x );        
    }while ((ch=getchar())!='\n');
    Del_negative(&A);
    TraverseSqList(A);
    return 0;
}
// Prepend Code End


void Del_negative(SqList *L) {
  for (int i = 0; i < L->length; i++) {
    if (L->items[i] < 0) {
      int _;
      SqListDelete(L, i + 1, &_);
      i--;
    }
  }
}
