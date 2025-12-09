#include <stdio.h>

int main()
{
    int panjang[] = {250, 200, 275, 190, 300, 240};
    int lebar[] = {310, 420, 260, 410, 290, 330};
    int jumlah = 0;
    int n = sizeof(panjang)/sizeof(panjang[0]);
    for (int i = 0; i < n; i++)
    {
        int luas = panjang[i] * lebar[i];
        // printf("akuarium %d, luas = %d\n" ,i+1 ,luas);
        if (luas >= 85000)
        {
            jumlah++;
        }
    }

    printf("Jumlah akuarium yang memenuhi syarat adalah sebanyak %d akuarium", jumlah);

    return 0;
}
