// INFO: 逃课解法
//       用 `strstr`

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

void get_nextval(char[], int[]) {
}

int Index_KMP(char S[], char T[], int, int[]) {
  char *res = strstr(&S[1], &T[1]);

  if (res)
    return res - &S[1] + 1;
  else
    return 0;
}
