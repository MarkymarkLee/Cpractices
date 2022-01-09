#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "lock.h"

Locks* init(int lockSeq[][3], int n){
    Locks* l = malloc(sizeof(Locks));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            l->num[i][j] = lockSeq[i][j];
        }
    }
    l->count=n;
    return l;
}
 
int numUnlocked(Locks *locks, bool lights[], int m){
    
    int unlocked=0;
    for(int i=0;i<locks->count;i++){
        //printf("ok\n");
        for(int j=0;j<3;j++){
            int k=locks->num[i][j];
            int kk = k>0?k:-k;
            if((k>0&&lights[kk-1])||(k<0&&!lights[kk-1])){
                unlocked++;
                break;
            }
        }
    }
    return unlocked;
}