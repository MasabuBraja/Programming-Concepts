#include <stdio.h>
// prototipe function
void viewMenu();
void gameEasy();
int cekTebakan();
void gameHard();

int main()
{
    int pilih;

    char ulang;
    do
    {
        viewMenu();
        printf("pilih menu: ");
        scanf("%d", &pilih);

        switch (pilih)

        {
        case 1:
            gameEasy();
            break;
        case 2:
            gameHard();
            break;
        case 0:
            printf("\nmakasih udah main :)\n");
            return 0;
        default:
            printf("pilih nomor yang ada\n");
        }
        printf("mau ke menu utama?(y/n): ");
        scanf(" %c", &ulang);
    } while (ulang == 'y'); // biar bisa main tanpa run lagi

    printf("\nmakasih udah main :)");
    return 0;
}

void viewMenu()
{
    printf("===GAME TEBAK ANGKA===\n");
    printf("1. Mau yang gampang aja\n");
    printf("2. Mau yang susah!\n");
    printf("0. Keluar\n");
}
//inti game
void gameEasy()
{
    int target = 44;
    int tebakan;
    int coba = 0;
    int history[100];

    do
    {
        printf("tebak angka 1-100 !: ");
        scanf("%d", &tebakan);
        history[coba] = tebakan;
        coba++;
    } while (cekTebakan(tebakan, target) != 1); // ulangi terus sampe benar

    printf("anda benar setelah menebak %d percobaan", coba);
    printf("\nriwayat tebakan: ");
    for (int i = 0; i < coba; i++)
    {
        printf("%d ", history[i]);
    }
    printf("\n");
}

void gameHard()
{
    int target = 789;
    int tebakan;
    int coba = 0;
    int history[100];

    do
    {
        printf("tebak angka 1-1000 !: ");
        scanf("%d", &tebakan);
        history[coba] = tebakan;
        coba++;
    } while (cekTebakan(tebakan, target) != 1);

    printf("anda benar setelah menebak %d percobaan", coba);
    printf("\nriwayat tebakan: ");
    for (int i = 0; i < coba; i++)
    {
        printf("%d ", history[i]);
    }
    printf("\n");
}
//logika gamenya
int cekTebakan(int tebakan, int target)
{
    if (tebakan < target)
    {
        printf("terlalu Kecil!\n");
    }
    else if (tebakan > target)
    {
        printf("terlalu besar!\n");
    }
    else
    {
        return 1;
    }
}