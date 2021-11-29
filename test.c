#include <stdio.h>
#include <assert.h>

int main(void){

    int a[10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            a[i][j] = 10*i+j;
        }
    }

    for(int i=0;i<100;i++){
        printf("%d\n",*(*a+i));
    }

    

    return 0;
}