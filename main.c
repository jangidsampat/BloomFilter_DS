#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 100
#define lli unsigned long long int
bool map[MAX];

lli mapFun(const char* key, int length, int x) {
  int i = 0;
  lli hash = x;
  while (i != length) {
    hash += key[i++];
    hash += hash << 10;
    hash ^= hash >> 6;
  }
  hash += hash << 3;
  hash ^= hash >> 11;
  hash += hash << 15;
  return hash%MAX;
}

void add(char *x) {
  lli a,b,c;
  int len=strlen(x);
  a=mapFun(x, len, 0);
  b=mapFun(x, len, a);
  c=mapFun(x, len, b);
  map[a]=1;
  map[b]=1;
  map[c]=1;
}

bool find(char *x) {
  lli a,b,c;
  int len=strlen(x);
  a=mapFun(x, len, 0);
  b=mapFun(x, len, a);
  c=mapFun(x, len, b);
  if (map[a]+map[b]+map[c]==3) return 1;
  return 0;
}

int main(void) {
  bool ret;
  char *x;
  int ch;
  memset(map, 0, sizeof(short)*MAX);
  printf("1 : Add\n");
  printf("2 : Find\n");
  while(1) {
    printf("Enter ch : ");
    scanf("%d", &ch);
    switch (ch) {
      case 1:
        printf("Add What? : ");
        scanf("%s", x);
        add(x);
        break;

      case 2:
        printf("Find What? : ");
        scanf("%s", x);
        if (find(x)) {
          printf("%s : Might be in the Array\n", x);
        } else {
          printf("%s : Not in the Array - Sure!!!\n", x);
        }
        break;

      default:
        return 0;
    }
  }
  return 0;
}