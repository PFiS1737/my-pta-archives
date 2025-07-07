// How would you implement mergesort without using recursion?
// 如何在不使用递归的情况下实现归并排序？
//
// The idea of iterative mergesort is to start from N sorted sublists of length 1, and each time to merge a pair of adjacent sublists until one sorted list is obtained.  
// You are supposed to implement the key function of merging.
// 迭代归并排序的思想是从 N 个长度为 1 的有序子列表开始，每次合并一对相邻的子列表，直到得到一个有序列表。
// 你需要实现合并的关键函数。

// Sample Input
// 10
// 8 7 9 2 3 5 1 6 4 0

// Sample Output
// 7 8 2 9 3 5 1 6 0 4 
// 2 7 8 9 1 3 5 6 0 4 
// 1 2 3 5 6 7 8 9 0 4 
// 0 1 2 3 4 5 6 7 8 9 
// 0 1 2 3 4 5 6 7 8 9 

// Prepend Code Start
#include <stdio.h>

#define ElementType int
#define MAXN 100

void merge_pass( ElementType list[], ElementType sorted[], int N, int length );

void output( ElementType list[], int N )
{
    int i;
    for (i=0; i<N; i++) printf("%d ", list[i]);
    printf("\n");
}

void  merge_sort( ElementType list[],  int N )
{
    ElementType extra[MAXN];  /* the extra space required */
    int  length = 1;  /* current length of sublist being merged */
    while( length < N ) { 
        merge_pass( list, extra, N, length ); /* merge list into extra */
        output( extra, N );
        length *= 2;
        merge_pass( extra, list, N, length ); /* merge extra back to list */
        output( list, N );
        length *= 2;
    }
} 


int main()
{
    int N, i;
    ElementType A[MAXN];

    scanf("%d", &N);
    for (i=0; i<N; i++) scanf("%d", &A[i]);
    merge_sort(A, N);
    output(A, N);

    return 0;
}
// Prepend Code End

#include <algorithm>
using namespace std;

void merge_pass(ElementType list[], ElementType sorted[], int N, int length) {
  for (int k = 0; k < N; k += 2 * length) {
    int left = k;
    int mid = k + length < N ? k + length : N;
    int right = k + 2 * length < N ? k + 2 * length : N;

    merge(list + left, list + mid, list + mid, list + right, sorted + left);
  }
}
