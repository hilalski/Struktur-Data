#include <stdio.h>
#include <stdlib.h>
#define MAX 2

struct mahasiswa{
    char nama[30];
    char provinsi[50];
    char kabkota[50];
    int kodepos;
};

int main()
{
    struct mahasiswa mhs[MAX];
    int i;
    for(i=0;i<MAX;i++)
        {
            printf("Input Nama = ");scanf("%s",mhs[i].nama);
            printf("Input Provinsi = ");scanf("%s",mhs[i].provinsi);
            printf("Input Kabupaten/Kota = ");scanf("%s",mhs[i].kabkota);
            printf("Input Kode pos = ");scanf("%d",&mhs[i].kodepos);
            printf("\n");
        }

    system("clear");

            printf("\nDATA MAHASISWA\n");
    for(i=0;i<MAX;i++)
        {
            printf("Nama = %s\n",mhs[i].nama);
            printf("Provinsi = %s\n",mhs[i].provinsi);
            printf("Kabupaten/Kota = %s\n",mhs[i].kabkota);
            printf("Kode pos = %d\n",mhs[i].kodepos);
            printf("\n");
        }
    return 0;
}
