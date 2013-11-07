#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"

extern int mytz(uint32_t data);

int zeroes(uint32_t data)
{
  int zeroes= 0;
  for (int i=0;i<33;i++) {
    if ( (0x1 & (data >> i))== 0){
      zeroes++;
    }else{
      break;
    }
  }
  return zeroes;
}

void printBinary(uint32_t data)
{
  for (int i=0;i<33;i++) {
    printf("%d", (0x1 & (data >> (32 - i))));
  }
  printf("\n");
}

int main()
{
  for (uint32_t i = 0; i<20; i++) {
    printf("number: %d had %d trailing zeroes, asm gave %d\n", i, zeroes(i), mytz(i));
    //printBinary(i);
  }
  return 1;
}
