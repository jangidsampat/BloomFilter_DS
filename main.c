#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdint.h>
#define MAX 100
bool map[MAX];

uint32_t mapFun(const uint8_t* key, size_t length, int x) {

  
  size_t i = 0;
  uint32_t hash = x;
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
  int a,b,c;
  a=mapFun(x, 1, 0);
  b=mapFun(x, 11, a);
  c=mapFun(x, 111, b);
  map[a]=1;
  map[b]=1;
  map[c]=1;
}

bool find(char *x) {
  int a,b,c;
  a=mapFun(x, 1, 0);
  b=mapFun(x, 11, a);
  c=mapFun(x, 111, b);
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
        scanf("%s", x);
        add(x);
        break;

      case 2:
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