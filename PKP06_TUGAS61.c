#include<stdio.h>
#include<stdlib.h>

void sequentialSearch(int *arr, int n, int x, int *index){
for(int i=0;i<n;i++){
    if (arr[i]==x){
        *index=i;
        return;
    }
}
}

int main(){
    int n,x;
    int index= -1;

    scanf("%d",&n);
    int *arr=malloc(n*sizeof(int));
    
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    scanf("%d",&x);
    sequentialSearch(arr,n,x,&index);
    printf("%d\n",index);
    free(arr);

    return 0;
}