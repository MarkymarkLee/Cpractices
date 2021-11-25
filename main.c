#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
 
typedef struct node
{
    char c;
    int count;
    struct node* next;
}node_t;
 
 
int string_to_int(char s[10]){
    int ans=0;
    for(int i=0;i<strlen(s);i++){
        ans*=10;
        ans+=(s[i]-'0');
    }
    return ans;
}
 
node_t* newNode(){
    node_t* s = malloc(sizeof(node_t));
    s->c = 'A';
    s->count = 0;
    s->next = NULL;
    return s;
}
 
int main(){
 
    node_t* head = newNode();
    int n=0;
 
    while(true){
        char command[4][10];
 
        if(scanf("%s",command[0])==EOF){
            break;
        }
        else if(strcmp(command[0],"insert")==0){
 
 
            scanf("%s",command[1]);
            scanf("%s",command[2]);
            scanf("%s",command[3]);
            int k = 0;
            char target = command[2][0];
            int m = string_to_int(command[3]);
 
            if(strcmp(command[1],"left")==0){
                k=1;
            }
            else if(strcmp(command[1],"right")==0){
                k = n+1;
            }
            else{
                k = string_to_int(command[1]);
            }
 
            node_t *cur = head;
            int a=0;
 
            while(cur){
                a+=cur->count;
                if(a>=k-1){
                    break;
                }
                cur = cur->next;
            }
 
            if(k==1){
                node_t* nn = newNode();
                nn->next = head->next;
                head->next = nn;
                nn->c = target;
                nn->count = m;
            }
            else if(k==n+1){
                node_t* nn = newNode();
                cur->next = nn;
                nn->c = target;
                nn->count = m;
            }
            else{
                if(a==k-1){
 
                    node_t* nn = newNode();
                    nn->next = cur->next;
                    cur->next = nn;
                    nn->c = target;
                    nn->count = m;
 
                }
                else{
                    if(cur->c==target){
                        cur->count+=m;
                    }
                    else{
                        node_t* nn[2];
                        nn[0] = newNode();
                        nn[1] = newNode();
                        nn[1]->next = cur->next;
                        cur->next = nn[0];
                        nn[0]->next = nn[1];
 
                        nn[0]->c = target;
                        nn[1]->c = cur->c;
 
                        int temp = cur->count;
                        cur->count = temp-(a-k+1);
                        nn[0]->count = m;
                        nn[1]->count = a-k+1;
                    }
                }
            }
 
            n+=m;
        }
        else if(strcmp(command[0],"print")==0){
            node_t *cur = head;
            char cur_c = ' ';
            int ccount=0;
            while(cur){
                if(cur->count>0){
                    if(cur_c==cur->c){
                        ccount+=cur->count;
                    }
                    else{
                        if(ccount>0){
                            printf("%c %d ",cur_c,ccount);
                        }
                        cur_c = cur->c;
                        ccount = cur->count;
                    }
                }
                cur = cur->next;
            }
            if(ccount>0){
                printf("%c %d ",cur_c,ccount);
            }
            printf("$\n");
        }
        else{
            break;
        }
 
    }
 
 
 
    return 0;
}