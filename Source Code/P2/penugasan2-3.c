#include <stdio.h>
#include <stdlib.h>

int main(void) {
    system("clear");
    int matriks[3][4];
    int baris,kolom;

    for (baris=0;baris<3;baris++){
        for (kolom=0;kolom<4;kolom++){
            printf("Masukkan angka[%d][%d] :\n",baris+1,kolom+1);scanf("%d",&matriks[baris][kolom]);
        }
    }
    printf("\n");

    for (baris=0;baris<3;baris++){
        for (kolom=0;kolom<4;kolom++){
            printf("%d ",matriks[baris][kolom]);
        }
        printf("\n");
    }
    return 0;
}