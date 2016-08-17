#include <stdio.h>

/// 1-18

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
    if(remover(line) > 0)
      printf("%s", line);


//    printf("%d  %s\n", len, line);
//    if (len > max) {
//      max = len;
//      copy(longest, line);
//    }
//  if (max > 0)
//    printf("%s\n", longest);
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

int remover(char s[])
{
  int i;

  i = 0;
  while (s[i] != '\n') {
    i++;
  }
  i--;/// now s[i] is '\n'
  while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
    i--;
  if (i >= 0) {/// not a blank line
    s[++i] = '\n';
    s[++i] = '\0'; /// now we finish this line
  }
  return i;
}
