#include<stdio.h>
#include<math.h>
//2-3, my solution
int atoi(char s[])
{
  int i, n;
  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
    n = 10 * n + (s[i] - '0');
  }
  return n;
}
int htoi(char s[])
{
  //in char s[]:{0-9,a-f,A-F with optional prefix 0x or 0X}
  int i,j,n;
  n = 0;

  for (j = 0; s[j] != '\0'; j++) {
    if (s[j] >= 'A' && s[j] <= 'F')
      s[j] += 32;
  }

  if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
      for (i = 2; s[i] != '\0'; ++i){
        if (s[i] >= '0' && s[i] <= '9')
          n = 16 * n + (s[i] - '0');
        else if (s[i] >= 'a' && s[i] <= 'f')
          n = 16 * n + (s[i] - 'a' + 10);
      }
  } else {
    for (i = 0; s[i] != '\0'; ++i) {
        if (s[i] >= '0' && s[i] <= '9')
          n = 16 * n + (s[i] - '0');
        else if (s[i] >= 'a' && s[i] <= 'f')
          n = 16 * n + (s[i] - 'a' + 10);
      }
  }

  return n;
}

