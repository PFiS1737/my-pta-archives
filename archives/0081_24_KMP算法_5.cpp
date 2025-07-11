// INFO: while-while 写法

// Sample Input
// abdsegdsagddfddfedfgds
// egdsa

// Sample Output
// 5

// Prepend Code Start
#include<cstring>
#include<iostream>
using namespace std;

#define MAXSTRLEN 255 

void get_nextval(char T[], int next[]);
int Index_KMP(char S[], char T[], int pos, int next[]);

int main()
{
char S[MAXSTRLEN+1],T[MAXSTRLEN+1];
char S1[MAXSTRLEN],S2[MAXSTRLEN];
cin >> S1 >> S2;
strcpy(&S[1],S1);
strcpy(&T[1],S2);    
S[0]=strlen(S1);
T[0]=strlen(S2);
int *next = new int[T[0]+1];
get_nextval(T,next);
cout<<Index_KMP(S,T,1,next);
return 0; 
}
// Prepend Code End

void get_nextval(char T[], int next[]) {
  next[1] = 0;

  int i = 1, j = 0;

  while (i < T[0]) {
    while (j && T[j] != T[i]) {
      j = next[j];
    }

    i++;
    j++;

    next[i] = j;

    if (T[i] == T[j]) { // optimize
      next[i] = next[j];
    }
  }
}

int Index_KMP(char S[], char T[], int pos, int next[]) {
  int i = pos, j = 1;

  while (i <= S[0] && j <= T[0]) {
    while (j && S[i] != T[j]) {
      j = next[j];
    }

    i++;
    j++;
  }

  if (j > T[0]) {
    return i - T[0];
  } else {
    return 0;
  }
}
