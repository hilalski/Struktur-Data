#include    <stdio.h>
#include    <stdlib.h>
struct matakuliah
{
    char namamatkul[30];
    char dosenmatkul[30];
    char kodematkul[7];
    int sksmatkul;
};

int main()
{
    system("clear");

    struct matakuliah matkul;
    strcpy(matkul.namamatkul,"Struktur Data");
    strcpy(matkul.dosenmatkul,"Dwy Bagus Cahyono");
    strcpy(matkul.kodematkul,"K203312");
    matkul.sksmatkul=3;

    struct matakuliah *mk = &matkul;

    printf("Mata Kuliah = %s\n",mk->namamatkul);
    printf("Dosen = %s\n",mk->dosenmatkul);
    printf("Kode Mata Kuliah = %s\n",mk->kodematkul);
    printf("Jumlah SKS Mata Kuliah = %d\n",mk->sksmatkul);

    return 0;
}
