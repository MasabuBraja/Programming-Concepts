#include<stdio.h>
#include<stdlib.h>
#include<time.h>//buat random seed
#include<windows.h>// buat efek2(sleep)

typedef struct{
char nama[50];
long long saldo;
int totalMain;
}Akun;

//Prototype
void depo(Akun *p);
void spin(Akun *p);
int logikaSlot(int putaran, long long taruhan);

int  main(){
    srand(time(0));//random seed biar hasil rand beda terus

    Akun user;
    int menu;

    printf("ZEUS 777 | SLOT PALING GACOR | BISA DEPO 10K\n | RUNGKAD UANG KEMBALI\n");
    printf("Masukkan Username : ");
    scanf("%49[^\n]",user.nama);//baca sampe ketemu enter

    user.saldo=0;
    user.totalMain=0;
    do{
        printf("\nHalo %s, Saldo: Rp %lld\n" ,user.nama ,user.saldo);
        printf("1. DEPO\n");
        printf("2. SPIN! BISA UNTUNG 5X LIPAT\n");
        printf("0. Sadar & Berhenti\n");
        printf("Pilih: ");
        scanf("%d",&menu);

        switch(menu){
            case 1:
            depo(&user);
            break;
            case 2:
            if(user.saldo > 0){
            spin(&user);}
            else{
                printf("\nSaldo Kurang! DEPO dulu biar GACOR!!\n");}
            break;
            case 0:
            printf("\nkeputusan bijak. Anda keluar dengan saldo Rp %lld\n",user.saldo);
            break;
            default:printf("INVALID\n");
        }
    }while(menu!=0);

    return 0;
}


void depo(Akun *p){
    long long rp;
    printf("mau depo berapa?: ");
    scanf("%lld" ,&rp);
    p->saldo += rp;
    printf("berhasil DEPO! saldo sekarang : Rp %lld\n", p->saldo);

}

void spin(Akun *p){
    long long taruhan;
    long long hasilMenang;
    printf("saldo anda: %lld",p->saldo);
    printf("\nMasukkan jumlah taruhan: Rp ");
    scanf("%lld",&taruhan);

    if (taruhan > p->saldo){
        printf("saldo tidak cukup, DEPO dulu!\n");
        return;
    }
    if (taruhan <= 0){printf("Invalid");return;}

    p->saldo -= taruhan;
    p->totalMain++;

    printf("Mesin sedang Berputar");
    for (int i=0;i<3;i++){
        printf(".");Sleep(750);
    }
    printf("\n");
    hasilMenang= logikaSlot(p->totalMain,taruhan);

    if (hasilMenang == -1){//JACKPOT palsu bikin nagih
        printf("============================\n");
        printf("!!!   JACKPOT MAXWIN    !!!\n");
        printf("HOKI SETAHUN AKHIRNYA KEPAKE\n");
        printf("   PETIR MENYAMBAR 5000X   \n");
        printf("   MENANG : Rp %lld\n",taruhan*5000);
        printf("==============================\n");
        Sleep(3500);
        //JACKPOT PALSU ISINYA CUMA PRINTF

        printf("[SYSTEM] Verifying Transaction...\n");Sleep(2000);
        printf("FAILED!\n");Sleep(1000);
        printf("BAD GATEWAY 502. KONEKSI SERVER TERPUTUS\n");
        printf("GAGAL MEMPROSES. SILAHKAN HUBUNGI ADMIN\n");
        printf("(dongo. mau kaya ya kerja!)wkwkwk\n");
        printf("\ntekan ENTER untuk lanjut\n");
        getchar();getchar();
    }else{
        p->saldo += hasilMenang;
        if(hasilMenang>0){
            printf("\nSENSANTIONAL! MENANG Rp%lld\n",hasilMenang);
            printf("\nTekan ENTER untuk lanjut");
            getchar();getchar();
        }else{
            printf("RUNGKAD! UANG RP %lld HANGUS\n",taruhan);
            printf("Tekan ENTER untuk lanjut");
            getchar();getchar();
        }
    }
}

int logikaSlot(int putaran, long long taruhan){
    if(putaran<=2){//menang 2 kali pertama spin
        int gacor=(rand()%4)+2;//kasih menang 2-5 x lipat
        return gacor*taruhan;
    }
    else{
        int hoki=rand()%100;
        if (hoki == 99){return -1;}//jackpot 
        else if(hoki<80)return 0;//80% Kalah
        else{
            float balik=((rand()%41)+10)/100.0;// 20% uang kembali receh, kalo pake int hasil selalu 0
            return (long long)(taruhan*balik);
        }
    }
}