#include <stdio.h>
#include <string.h>
int main(){
    
    
    char beo [100];
    printf ("lu mau beo ngomong apa? : ");
    // getchar();
    fgets(beo,sizeof(beo),stdin);
    // beo[strlen(beo)-1] ='\0';
    // scanf ("%[^\n]s" ,&beo);

    printf ("lah bener ngomong : %s", beo);



    return 0;
}
