#include<stdio.h>
/// 1-9
#define NONBLANK 'c'
int main() {
    int c, lastchar;

    while ((c = getchar())!= EOF) {
      if (c != ' ')
        putchar(c);
      else if (lastchar != ' ')
        putchar(c);
      lastchar = c;
    }
}
