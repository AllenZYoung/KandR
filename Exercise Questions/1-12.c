#include <stdio.h>
/// 1-12
#define IN  1
#define OUT 0

main()
{
  int c, state;
  state = OUT;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') { // outside a word
      if (state == IN) {
        state = OUT;
        putchar('\n');
      }
    } else if (state == OUT) { // at the beginning of a word
      state = IN;
      putchar(c);
    } else // inside a word
      putchar(c);
  }
}
