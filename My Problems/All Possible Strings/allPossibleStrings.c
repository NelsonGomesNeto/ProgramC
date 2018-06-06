#include <stdio.h>

void allPossibleStrings(char s[], int i, int ni, char ns[])
{
  if (!s[i])
  {
    ns[ni] = '\0';
    printf("%s\n", ns);
    return;
  }

  ns[ni] = s[i];
  allPossibleStrings(s, i + 1, ni + 1, ns);
  allPossibleStrings(s, i + 1, ni, ns);
}

int main()
{
  char s[11]; scanf("%s", s);
  char ns[11]; allPossibleStrings(s, 0, 0, ns);
  return(0);
}
