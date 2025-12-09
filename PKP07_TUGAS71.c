#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_MHS 100
#define MAX_NAMA 50

typedef struct{
    char nama[MAX_NAMA];
    int umur;
    float ipk;
}Mahasiswa;

typedef enum {
    MENU_KELUAR = 0,
    MENU_TAMBAH,
    MENU_TAMPIL,
    MENU_HAPUS
}Menu;

void viewMenu();
void menuInput(Mahasiswa *m);
void tambahKeArray(Mahasiswa arr[], int *jumlah);
void viewTabel(const Mahasiswa arr[], int jumlah);

 

int main() {
    Mahasiswa daftar[MAX_MHS];
    int jumlah_data = 0;

    while (1) {
        int pilih_int;
        viewMenu();
        if (scanf("%d", &pilih_int) != 1) {
            printf("Input tidak valid.\n");
            continue;
        }

        Menu pilih = (Menu)pilih_int;
        switch (pilih) {
            case MENU_TAMBAH:
                tambahKeArray(daftar, &jumlah_data);
                break;
            case MENU_TAMPIL:
                viewTabel(daftar, jumlah_data);
                break;
            case MENU_KELUAR:
                printf("Program selesai.\n");
                return 0;
            default:
                printf("Pilihan tidak tersedia.\n");
        }
    }
}

void viewMenu(){
    printf("\nDaftar menu:\n");
    printf("1. Masukkan data\n");
    printf("2. Tampilkan data\n");
    printf("0. Keluar\n");
    printf("Pilihan: ");
}

void menuInput(Mahasiswa *m) {
    printf("Nama: -> ");
    scanf(" %49[^\n]", m->nama);
    printf("Umur: -> ");
    scanf("%d", &m->umur);
    printf("IPK : -> ");
    scanf("%f", &m->ipk);
}

void tambahKeArray(Mahasiswa arr[], int *jumlah) {
    if (*jumlah >= MAX_MHS) {
        printf("Kapasitas data penuh.\n");
        return;
    }
    Mahasiswa *slot = &arr[*jumlah];
    menuInput(slot);
    (*jumlah)++;
}

void viewTabel(const Mahasiswa arr[], int jumlah) {
    if (jumlah == 0) {
        printf("Belum ada data.\n");
        return;
    }
    printf("No | %-28s | %-4s | %-4s |\n", "Nama", "Umur", "IPK");
    for (int i = 0; i < jumlah; i++) {
        printf("%-2d | %-28s | %-4d | %-4.1f |\n",
            i + 1, arr[i].nama, arr[i].umur, arr[i].ipk);
    }
}  
