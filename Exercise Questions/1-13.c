#include <stdio.h>
/// 1-13
#define IN  1
#define OUT 0
#define MAXHIST 20 ///max length of histogram
#define MAXWORD 15 ///max length of a word

main()
{
  int c, i, j,  nc, state;
  int len; /// length of each bar
  int maxvalue; /// max value for wl[]
  int ovflow; /// num of overflow words
  int wl[MAXWORD]; /// word length counters

  state = OUT;
  nc = 0; /// num of chars in a word
  ovflow = 0; /// num of words >= MAXWORD
  for (i = 0; i < MAXWORD; i++) {
    wl[i] = 0;
  }
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      if (nc > 0) {
        if (nc < MAXWORD) {
          ++wl[nc];
        } else {
          ++ovflow;
        }
      }
      nc = 0;
    } else if (state = OUT) {
      state = IN;
      nc = 1; /// beginning of a new word
    } else {
      ++nc;
    }
  }

  maxvalue = 0;

  for (i = 1; i < MAXWORD; ++i) {
    if (wl[i] > maxvalue)
      maxvalue = wl[i]; /// find out the max one in wl[]
  }
//      printf("lengs - nums : \n");
//    for (i = 1; i < MAXWORD; ++i) {
//      printf("%5d - %5d : ",i , wl[i]);
//      if (wl[i] > 0) {
//        if ((len = wl[i] * MAXHIST/maxvalue) <= 0) /// 所谓的缩放设置
//          len = 1;
//      } else /// wl[i] <= 0
//        len = 0;
//      while (len > 0) {
//        putchar('*');
//        --len;
//      }
//      putchar('\n');
//    }
//  if (ovflow > 0)
//    printf("There are %d words >= %d\n", ovflow, MAXWORD);
  for ( i = MAXHIST; i > 0; i--) {
    printf("         ");
    for (j = 1; j < MAXWORD; ++j)
      if(wl[j] * MAXHIST/maxvalue >= i)
        printf(" * ");
      else
        printf("   ");
    /// then this line is finished
    putchar('\n');
  }
  printf("  length:");
  for (i = 1; i < MAXWORD; ++i)
    printf("%2d ",i);
  putchar('\n');
  printf("  number:");
  for ( i = 1; i < MAXWORD;++i )
    printf("%2d ",wl[i]);
  putchar('\n');
  if (ovflow > 0 )
    printf("There are %d words >= %d\n", ovflow, MAXWORD);

  return 0;
}
