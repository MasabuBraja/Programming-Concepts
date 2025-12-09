#include<stdio.h>
int main(){

    int a, b;
    printf("masukkan angka (bebek teman)dipisah spasi: ");
    scanf("%d %d", &a, &b);

    int A= a/b;
    int B= a%b;
    printf("\nmasing2 teman mendapat %d bebek\n", A);
    printf("sisa bebeknya %d\n", B);







    return 0;
}