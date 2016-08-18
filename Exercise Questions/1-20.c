#include <stdio.h>
/// 1-20
#define TABN 8 /// tab increment width

main()
{
  int c, nb, pos;
  nb = 0; /// number of blanks necessary
  pos = 1; /// position of char. in line
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      nb = TABN - (pos - 1) % TABN;
      while (nb > 0) {
        putchar(' ');
        ++pos;
        --nb;
      }
    } else if (c == '\n') {
      putchar(c);
      pos = 1;
    } else {
      putchar(c);
      pos++;
    }
  }
}
