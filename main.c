#include <stdio.h>

int main(){

    while(1){
        static int  i = 10;
        i++;
        printf("%d\n",i);
        if(i>20){
            break;
        }
    }
    printf("%d\n",i);
    
    return 0;
}