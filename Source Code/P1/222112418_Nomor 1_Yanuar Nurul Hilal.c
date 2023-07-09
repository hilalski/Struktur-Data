#include <stdio.h>
#include <stdlib.h>

int main(){

char NAMA[25];
char NIM[10];

float NILAIUTS, NILAIUAS, NILAIKUIS, NILAIAKHIR;


printf("Input Nama = ");
fgets(NAMA,25,stdin);
printf("Input NIM = ");
fgets(NIM,10,stdin);
printf("Input Nilai UTS = ");scanf("%f",&NILAIUTS);
printf("Input Nilai UAS = ");scanf("%f",&NILAIUAS);
printf("Input Nilai Kuis = ");scanf("%f",&NILAIKUIS);

NILAIAKHIR=0.2*NILAIKUIS+0.3*NILAIUTS+0.5*NILAIUAS;
printf("\n");

system("clear");
printf("Nilai Akhir Mahasiswa\n");
printf("Nama = %s\n",NAMA);
printf("NIM = %s\n",NIM);
printf("Nilai Kuis = %.2f\n",NILAIKUIS);
printf("Nilai UTS = %.2f\n",NILAIUTS);
printf("Nilai UAS = %.2f\n",NILAIUAS);
printf("Nilai Akhir = %.2f",NILAIAKHIR);
printf("\n");
    return 0;
}