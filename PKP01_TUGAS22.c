#include <stdio.h>
int main(){
    int n;
    printf("sebut aja berapa: ");
    scanf("%d", &n);
    for(int i=0; i<=n*2; i++){
        
        //iniWM

        if(i%2==1){
            printf("%d\n", i);
        }else{
            continue;
        }
    }











    return 0;
}