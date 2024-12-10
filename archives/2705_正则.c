// Description
//
// 编写程序，判断用户输入的一个字符串是否是一个合法的用户自定义标识符。假定不可作为用户自定义标识符的关键字有：int、double、float、for、if、while、do、goto、switch、break。
//
// Input
// 输入有多行，每行是一个字符串，长度不超过10个字符。
//
// Output
// 每行输入对应一行输出，如果对应的输入是一个合法的用户自定义标识符，则输出“yes”，否则输出“no”。

// Sample Input
// Init
// int
// 1asdf
// _def
// def def
// double

// Sample Output
// yes
// no
// no
// yes
// no
// no

#include <regex.h>
#include <stdio.h>
#include <string.h>

char *keywords[] = {"int",   "double", "float", "for",    "if",
                    "while", "do",     "goto",  "switch", "break"};

int is_keyword(const char *str) {
  for (int i = 0; i < 10; i++) {
    if (strcmp(str, keywords[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

int is_valid_identifier(const char *str) {
  regex_t regex;
  const char *pattern = "^[a-zA-Z_][a-zA-Z0-9_]*$";

  // qwq, c 里面正则用起来好麻烦
  if (regcomp(&regex, pattern, 0) != 0) {
    fprintf(stderr, "Error compiling regex\n");
    return 0;
  }

  int match = regexec(&regex, str, 0, NULL, 0);

  regfree(&regex);

  return match == 0;
}

int main() {
  char str[11];

  while (gets(str) != NULL) {
    if (is_keyword(str)) {
      printf("no\n");
    } else if (is_valid_identifier(str)) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }

  return 0;
}
