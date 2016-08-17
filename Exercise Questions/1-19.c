#include <stdio.h>

/// 1-19

#define MAXLINELEN 1000 /// maximum input line length
#define LONGCHECK    80

int getline(char line[], int maxline);
void copy(char to[], char from[]);
int remover(char s[]);
void reverser(char s[]);

main()
{
  int len, max;
  char line[MAXLINELEN], longest[MAXLINELEN];

  max = 0;
  while ((len = getline(line, MAXLINELEN)) > 0) {
      reverser(line);
      printf("%s", line);
  }
  return 0;
}
//read a line into s and return length
int getline(char s[], int lim)
{
  int c, i ,j;
  j = 0;
  for (i = 0; (c =getchar()) != EOF && c != '\n'; ++i)
    if (i < lim - 2) {
      s[j] = c;
      ++j;
    }
    if (c == '\n') {
      s[j] = c;
      ++j;
      ++i;
    }
  s[j] = '\0';
  return i;
}

//copy from into to and assume to is big enough
void copy(char to[], char from[])
{
  int i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}

void reverser(char s[])
{
  int i, j;
  char can;

  i = 0;
  while (s[i] != '\0') {
    i++;
  }
  i--; /// now we come to the end of this string
  if (s[i] == '\n') {
    i--; /// just leave the newline mark alone
  }
  j = 0;
  while (j < i) {
    can = s[i];
    s[i] = s[j];
    s[j] = can;
    --i;
    ++j;
  }
}

