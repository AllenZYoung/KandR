#include <stdio.h>
/// 1-22
#define N 20

#define MAXCOL  10
#define TABINC   8

char line[MAXCOL];

int exptab(int pos);
int findblnk(int pos);
int newpos(int pos);
void printl(int pos);

main()
{
  int c, pos;

  pos = 0;
  while ((c = getchar()) != EOF) {
    line[pos] = c;
    if (c == '\t')
      pos = exptab(pos);
    else if (c == '\n') { /// have to turn to a new line...
      printl(pos);
      pos = 0; /// reset the position
    } else if ( ++pos >= MAXCOL) {
      pos = findblnk(pos);
      printl(pos);
      pos = newpos(pos);
    }
  }
}

int exptab(int pos) /// expand tab into blanks, return new position
{
  line[pos++] = ' '; /// evidently, tab is at least ONE blank
  for (pos; pos < MAXCOL && pos % TABINC != 0; ++pos)
    line[pos] = ' ';
  if (pos < MAXCOL) /// room left in current line
    return pos;
  else { /// current line is full
    printl(pos);
    return 0; /// reset the position
  }
}

int findblnk(int pos) /// find blank's position
{
  while (pos > 0 && line[pos] != ' ')
    --pos; /// rollback the position index
  if (pos == 0)
    return MAXCOL;
  else
    return pos + 1;
}

int newpos(int pos) /// rearrange line in new position
{
  int i,j;
  if (pos <= 0 || pos >= MAXCOL)
    return 0;
  else {
    i = 0;
    for (j = pos; j < MAXCOL; ++j) {
      line[i] = line[j]; /// move chars "farther" to "closer"...
      ++i;
    }
    return i;
  }
}
void printl(int pos) /// print a line until the pos column
{
  int i;
  for (i = 0; i < pos; ++i)
    putchar(line[i]);
  if (pos > 0)
    putchar('\n');
}
