// 请编写程序检查C语言源程序中下列符号是否配对：/*与*/、(与)、[与]、{与}。
// 注意不考虑字符及字符串以及注释中的符号，按正常逻辑处理即可。
//
// 输入为一个C语言源程序。当读到某一行中只有一个句点.和一个回车的时候，标志着输入结束。程序中需要检查配对的符号不超过100个。
//
// 首先，如果所有符号配对正确，则在第一行中输出`YES`，否则输出`NO`。
// 然后在第二行中指出第一个不配对的符号：如果缺少左符号，则输出`?-右符号`；如果缺少右符号，则输出`左符号-?`。

// Sample Input
// void test()
// {
//     int i, A[10];
//     for (i=0; i<10; i++) { /*/
//         A[i] = i;
// }
// .

// Sample Output
// NO
// /*-?

#include <iostream>
#include <stack>

using namespace std;

void error_missing_left(char c);
void error_missing_right(char c);
void error_unexpected_left(char c, char expected);

bool is_pair(char left, char right);
string left_of(char c);
string right_of(char c);

int main() {
  string line;
  string str;

  while (getline(cin, line)) {
    if (line == ".")
      break;

    str += line + '\n';
  }

  stack<char> s;
  for (auto it = str.begin(); it != str.end(); it++) {
    bool is_comment = false;

    switch (*it) {
      case '/': {
        if (it[1] == '*') {
          // NOTE: 这里不直接在里面声明，而是在外面声明，然后在里面赋值，
          //       因为 case 不能跳过对象初始化
          is_comment = true;

          // HACK: 利用 case 其实是 goto 的特性，
          //       当不是注释时直接跳过上面的判断
          case '(':
          case '[':
          case '{': {
            s.push(*it);

            // NOTE: 是注释时跳过下一个字符（即 *），
            //       用来处理 `/*/` 的情况
            if (is_comment)
              it++;

            break;
          }
        }
        break;
      }
      case '*': {
        if (it[1] == '/') {
          is_comment = true;

          case ')':
          case ']':
          case '}': {
            if (s.empty()) {
              error_missing_left(*it);
            } else if (is_pair(s.top(), *it)) {
              s.pop();
            } else {
              error_missing_right(s.top());

              // TODO: 我还是觉得这里用另一种错误会比较好，比如我这里写的括号不匹配，
              //       而不是说缺了右括号
              // error_unexpected_left(s.top(), *it);
            }

            if (is_comment)
              it++;

            break;
          }
        }
        break;
      }
    }
  }

  if (s.empty()) {
    cout << "YES\n";
  } else {
    error_missing_right(s.top());
  }

  return 0;
}

void error_missing_left(char c) {
  cout << "NO\n";
  cout << "?-" << right_of(c) << "\n";
  exit(0);
}

void error_missing_right(char c) {
  cout << "NO\n";
  cout << left_of(c) << "-?\n";
  exit(0);
}

void error_unexpected_left(char c, char expected) {
  cout << "NO\n";
  cout << left_of(c) << "-" << right_of(expected) << "\n";
  exit(0);
}

bool is_pair(char left, char right) {
  return (left == '(' && right == ')') || (left == '[' && right == ']') ||
         (left == '{' && right == '}') || (left == '/' && right == '*');
}

string left_of(char c) {
  switch (c) {
    case ')':
      return "(";
    case ']':
      return "[";
    case '}':
      return "{";
    case '*':
    case '/':
      return "/*";
    default:
      return string(1, c);
  }
}

string right_of(char c) {
  switch (c) {
    case '(':
      return ")";
    case '[':
      return "]";
    case '{':
      return "}";
    case '/':
    case '*':
      return "*/";
    default:
      return string(1, c);
  }
}
