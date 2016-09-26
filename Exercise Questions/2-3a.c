#include<stdio.h>
#define YES 1
#define NO  0
//2-3, standard solution.
int htoi(char s[])
{
  int hexdigit, i, inhex, n;

  i = 0;
  if (s[i] == '0') { //wanna skip optional 0x or 0X
    ++i;
    if (s[i] == 'x' || s[i] == 'X')
      ++i;
  }
  n = 0;
  inhex = YES;
  for (; inhex == YES; ++i) {
    if (s[i] >= '0' && s[i] <= '9')
      hexdigit = s[i] - '0';
    else if (s[i] >= 'a' && s[i] <= 'f')
      hexdigit = s[i] - 'a' + 10;
    else if (s[i] >= 'A' && s[i] <= 'F')
      hexdigit = s[i] - 'A' + 10;
    else
      inhex = NO; // not a valid hex digit now
    if (inhex == YES)
      n = 16 * n + hexdigit;
  }
  return n;
}
