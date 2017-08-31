// asdf


#include <stdio.h>
#define MAXLINE 40 /* maximum input line size */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
main()
{
  int len; /* current line length */
  int max; /* maximum length seen so far */
  char line[MAXLINE]; /* current input line */
  char longest[MAXLINE]; /* longest line saved here */
  char tmp[MAXLINE]; /* pass this to getline when line and longest should not be overwritten */

  max = 0;
  while ((len = getline(line, MAXLINE)) > 0) {
    while (len==MAXLINE) /* we didn't get the whole line */
      len += getline(tmp, MAXLINE);
    if (len > max) {
      max = len;
      copy(longest, line);
    }
    printf("%d\n", len);
  }
  if (max > 0) /* there was a line */
    printf("%s", longest);
  return 0;
}

/* getline: read a line into s, return leeeeeeeeeeee            eeeeeeeeeeeeeength */
int getline(char s[], int lim)
{
  int c, i;

  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy (char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
