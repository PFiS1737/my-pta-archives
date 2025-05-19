// 双端队列（deque，即double-ended queue的缩写）是一种具有队列和栈性质的数据结构，即可以（也只能）在线性表的两端进行插入和删除。
// 若以顺序存储方式实现双端队列，请编写例程实现下列操作：
// - EnQueue(deque, x)：将元素 x 插入到双端队列 deque 的**头**；
// - DeQueue(deque)：删除双端队列 deque 的**头**元素，并返回其值；
// - Inject(deque, x)：将元素 x 插入到双端队列 deque 的**尾**部；
// - Eject(deque)：删除双端队列 deque 的**尾**部元素，并返回其值。
// 注意：EnQueue 和 Inject 应该在正常执行完操作后返回 true，或者在出现非正常情况时返回 false。
// 当 front 和 rear 相等时队列为空，DeQueue 和 Eject 必须返回由裁判程序定义的 ERROR。

// Sample Input
// 3
// Pop
// Inject 1
// Pop
// Eject
// Push 2
// Push 3
// Eject
// Inject 4
// Inject 5
// Inject 6
// Push 7
// Pop
// End

// Sample Output
// Deque is Empty!
// 1 is out
// Deque is Empty!
// 2 is out
// Deque is Full!
// Deque is Full!
// 3 is out
// Inside Deque: 4 5

// Append Code Start
#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int QElemSet; /* 队列元素类型定义为整型 */
typedef enum { enqueue, dequeue, inject, eject, end } Operation; /* 操作类型 */
typedef int Position; /* 整型下标，表示元素的位置 */
typedef struct DequeNode *Deque;
struct DequeNode {
    int capacity;     /* 双端队列的容量 */
    Position front;   /* 双端队列的队首指针，初始化为0 */
    Position rear;    /* 双端队列的队尾指针，初始化为0 */
    QElemSet *data;   /* 存储数据的数组 */
};

void InitDeque(Deque deque, int n)
{   /* 注意：为区分空队列和满队列，需要多开辟一个空间 */
    deque->data = (QElemSet *)malloc(sizeof(QElemSet) * (n+1));
    deque->front = deque->rear = 0;
    deque->capacity = n+1;
}

bool EnQueue(Deque deque, QElemSet x);
QElemSet DeQueue(Deque deque);
bool Inject(Deque deque, QElemSet x);
QElemSet Eject(Deque deque);

Operation GetOp ()
{ /* 判断输入的操作类型 */
    char op[7]; /* 操作最长6个字符 */
    Operation ret; 
    
    scanf(" %s ", op);
    switch (op[2]) { /* 用第3个字母区分操作 */
        case 's': ret = enqueue; break;
        case 'p': ret = dequeue; break;
        case 'j': ret = inject; break;
        case 'e': ret = eject; break;
        case 'd': ret = end; break;
        default: break;
    }

    return ret;
}

void PrintDeque( Deque deque )
{
    Position p;
    
    printf("Inside Deque:");
    p = deque->front;
    while (p != deque->rear) {
        printf(" %d", deque->data[p]);
        p = (p+1)%deque->capacity;
    }
    printf("\n");
}

int main(void)
{
    Deque deque;
    QElemSet x;
    int n;
    bool done;

    deque = (Deque)malloc(sizeof(struct DequeNode));
    scanf("%d", &n);
    InitDeque(deque, n); /* 初始化队列空间 */
    done = false; /* 初始化结束标识 */
    while (done == false) {
        switch( GetOp() ) {
            case enqueue: /* 执行EnQueue */
                scanf("%d", &x);
                if (EnQueue(deque, x) == false) {
                    printf("Deque is Full!\n");
                }
                break;
            case dequeue: /* 执行DeQueue */
                x = DeQueue(deque);
                if (x == ERROR) {
                    printf("Deque is Empty!\n");
                }
                else {
                    printf("%d is out\n", x);
                }
                break;
            case inject: /* 执行Inject */
                scanf("%d", &x);
                if (Inject(deque, x) == false) {
                    printf("Deque is Full!\n");
                }
                break;
            case eject: /* 执行Eject */
                x = Eject(deque);
                if (x == ERROR) {
                    printf("Deque is Empty!\n");
                }
                else {
                    printf("%d is out\n", x);
                }
                break;
            case end: /* 输入结束，打印队列元素 */
                PrintDeque(deque);
                done = true;
                break;
            default: break;
        }
    }
    return 0;
}
// Append Code End


bool EnQueue(Deque deque, QElemSet x) {
  int front = (deque->front - 1 + deque->capacity) % deque->capacity;
  if (front != deque->rear) {
    deque->front = front;
    deque->data[deque->front] = x;
    return true;
  }
  return false;
}

QElemSet DeQueue(Deque deque) {
  if (deque->front == deque->rear)
    return ERROR;

  QElemSet ret = deque->data[deque->front];
  deque->front = (deque->front + 1) % deque->capacity;
  return ret;
}

bool Inject(Deque deque, QElemSet x) {
  deque->data[deque->rear] = x;
  int rear = (deque->rear + 1) % deque->capacity;
  return rear != deque->front && (deque->rear = rear, true);
}

QElemSet Eject(Deque deque) {
  if (deque->front == deque->rear)
    return ERROR;

  deque->rear = (deque->rear - 1 + deque->capacity) % deque->capacity;
  return deque->data[deque->rear];
}
