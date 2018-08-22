#include <stdio.h>
#include <string.h>

void countLetters(char s[], int letters[])
{
  for (int i = 0; s[i]; i ++) letters[(int) s[i]] ++;
}

int positive(int num)
{
  return(num < 0 ? -num : num);
}

int compare(char a[], char b[])
{
  int lettersA[256], lettersB[256];
  memset(lettersA, 0, sizeof(lettersA)); memset(lettersB, 0, sizeof(lettersB));
  countLetters(a, lettersA); countLetters(b, lettersB);

  int difference = 0;
  for (int i = 0; i < 256; i ++)
    difference += positive(lettersA[i] - lettersB[i]);
  return(difference);
}

int main()
{
  char a[1000000], b[1000000];
  scanf("%s\n%s", a, b);
  int difference = compare(a, b);
  if (!difference)
    printf("String A can be equal to string B\n");
  else
    printf("String A is different by %d characters\n", difference);

  return(0);
}
