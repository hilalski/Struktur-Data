#include<stdio.h>

struct
{
    int nosim;
    char *tipesim;
    char *nama;
    char *kabkota;
    char *provinsi;
    char *goldarah;
}warga,*p = &warga;

struct
{
    int day,month,year;
}expired,*pp = &expired;


int main()
{
    expired.day = 17;
    expired.month=8;
    expired.year=2024;
    warga.nosim=42069666;
    warga.tipesim="A";
    warga.nama="Joko Widodo";
    warga.goldarah="O";
    warga.kabkota="Solo";
    warga.provinsi="Jawa Tengah";
    //warga.masaberlaku= &expired;

    printf("\nSurat Izin Mengemudi\n");
    printf("Nomor SIM      : %d\n",p->nosim);
    printf("Tipe SIM       : %s\n",p->tipesim);
    printf("Nama           : %s\n",p->nama);
    printf("Kabupaten/Kota : %s\n",p->kabkota);
    printf("Provinsi       : %s\n",p->provinsi);
    printf("Golongan Darah : %s\n",p->goldarah);
    printf("Masa Berlaku   : %2d-%d-%4d\n",pp->day,pp->month,pp->year);

    return 0;
}
