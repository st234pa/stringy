#include <stdio.h>
#include <stdlib.h>

int mystrlen(char a[]) {
  int total = 0;
  while (a[total]) total++;
  return total;
}
char *mystrcpy(char *d, char *s) {
  int i = 0;
  while (s[i] != '\0') {
    d[i] = s[i];
    i++;
  }
  d[i] = '\0';
  return d;
}
char *mystrncat(char *d, char *s, int n) {
  int dl = mystrlen(d);
  int i;
  for (i = 0; i<n && s[i] != '\0'; i++) d[dl + i] = s[i];
  d[dl+i] = '\0';
  return d;
}
int mystrcmp(char *s1, char *s2) {
  while(*s1  && (*s1 == *s2)) {    
    s1++;
    s2++;
  }
  return *s1 - *s2;
}
int mystrchr(char *s1, int s2) {
  int i;
  for (i = 0; i < mystrlen(s1); i++) {
    if (s1[i] == '\0') return 0;
    if (s1[i] == s2) return i;
  }
  return i;
}

int main() {
  char s1[50] = "Hello";
  int ls1 = mystrlen(s1);
  char s2[50] = "doge";
  int ls2 = mystrlen(s2);
  printf("Before applying functions: \n s1 = %s, length = %d \n s2 = %s, length = %d \n", s1, ls1, s2, ls2);
  mystrcpy(s2, s1);
  ls2 = mystrlen(s2);
  printf("Test mystrcpy s1 to s2: %s, length = %d \n", s2, ls2);
  mystrncat(s2, s1, 3);
  ls2 = mystrlen(s2);
  printf("Test mystrncat s1 to s2: %s, length = %d \n", s2, ls2);
  int k = 'l';
  int c = mystrchr(s2, k);
  printf("Test mystrchr finding e in s2: %d \n", c);
  char s3[50] = "Z";
  int d = mystrcmp(s1, s3);
  printf("Test mystrcmp between s1 and s3: %d \n", d);
}
