#include <stdio.h>
int main(){
    
    double celcius;
    int menu;
    
    while(1){

    printf("\ndengan kalkulator suhu ada yg bisa dibanting\n");
    printf("sila pilih menu konversi\n1. Celcius ke Fahrenheit\n2. Celcius ke Kelvin\n3. Celcius ke Reamur\n");
    printf("0. keluar\n");
    printf("Pilih Nomor: ");
    scanf("%d" ,&menu);

    if (menu == 0){
        break;
    }else if (menu != 1 && menu != 2 && menu != 3){
        printf("\niseng atau memang gaptek?\ngaada menu kok dipilih.. hmmm\n");
        continue;
    }
    
    printf("\nsila Masukkan suhu dalam celcius ex(35.6): ");
    scanf("%lf" ,&celcius);

//noAIAI//iniWM//

    switch (menu)
    {
    case 1:
        printf("\n%.2lf C dalam Fahrenheit = %.2lf\n" ,celcius ,celcius * 9/5 + 32);
        break;
    case 2: 
        printf("\n%.2lf C dalam Kelvin = %.2lf\n" ,celcius ,celcius + 273);
        break;
    case 3:
        printf("\n%.2lf C dalam Reamur = %.2lf\n" ,celcius ,celcius* 4/5);
        break;
    case 0:
        return 0;
        
    default: (printf("\ntidak ada yang bercanda,\nsemua fokus pada 1 titik\nyaitu menu\n"));
       
    }

    
    
    }   
    
     
return 0;


}