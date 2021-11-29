#include <stdio.h>
#include "node.h"

void print(struct node *n,int count,int ans[]){

    if(!n->left&&!n->right){
        for(int i=0;i<count;i++){
            printf("%d ",ans[i]);
        }
        printf("%d\n",n->data);
        return ;
    }

    ans[count] = n->data;
    if(n->left){
        print(n->left,count+1,ans);
    }
    if(n->right){
        print(n->right,count+1,ans);
    }
    
    return;
}

void print_all_paths(struct node *root){
    int ans[1000];
    print(root,0,ans);
}