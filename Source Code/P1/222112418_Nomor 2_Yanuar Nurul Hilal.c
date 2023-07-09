#include <stdio.h>
#include <stdlib.h>

int PANJANG,LEBAR;

int luas(int p, int l) {
  return p * l;
}

int keliling(int p, int l) {
  return 2*(p + l );
}

int main() {

  system("clear");
  printf("Input Panjang = ");scanf("%i",&PANJANG);
  printf("Input Lebar = ");scanf("%i",&LEBAR);
  printf("\nLuas Persegi Panjang = %i\n", luas(PANJANG, LEBAR));
  printf("Keliling Persegi Panjang = %i\n", keliling(PANJANG, LEBAR));

  return 0;
}