#include <stdio.h>
#include <stdlib.h>
#define INICIAL 5

int main(){
    
    int *p;
    int tamanho = INICIAL;
    int i;
    
    
    p =(int *) malloc(tamanho*sizeof(int));
    
    if(p == NULL){
        printf("Erro: Sem memoria!\n");
        exit(1);
    }
    
    for(i = 0; i<=tamanho; i++){
        printf("Digite p[%d]: ", i);
        scanf("%d", &p[i]);
        if(p[i]==0){
            printf("Numero invalido!\n");
            break;
        }else{
            if(i == tamanho){
                tamanho += INICIAL;
            }
        }
        
    }
    
    for(int j = 0; j < i; j++){
        printf("%d", p[j]);
    }
    
    free(p);

    return 0;
}