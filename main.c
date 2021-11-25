#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int num;
    int level;
    struct node* boss;
    struct node* c[2];
}node;

int cmpfunc (const void * a, const void * b) {

    node aa = *(node*)a;
    node bb = *(node*)b;

    return ( aa.level > bb.level );
}

int printTree(node* head){
    if(!head){
        return 0;
    }
    printf("%d\n",head->num);
    printTree(head->c[0]);
    printTree(head->c[1]);
    return 0;
}

int main()
{
    
    int n=0;
    scanf("%d",&n);
    node a[n];
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i].num,&a[i].level);
        a[i].boss = NULL;
        a[i].c[0] = NULL;
        a[i].c[1] = NULL;
    }

    qsort(a,n,sizeof(node),cmpfunc);

    for(int i=1;i<n;i++){
        node* head = &a[0];
        for(int j=2;j<a[i].level;j++){
            head = head->c[a[i].num>head->num];
        }
        head->c[a[i].num>head->num] = &a[i];
        a[i].boss = head;
    }

    int q=0;
    scanf("%d",&q);
    while (q--){
        int a,b;
        scanf("%d%d",&a,&b);
        int f=0;
        node* head = &a[0];
    }
    
    


    return 0;
}