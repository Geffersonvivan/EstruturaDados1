#include <stdlib.h>
#include <stdio.h>

int *uniao (int *v1, int n1, int *v2, int n2){
    int *uniao, soma;

    soma = n1 + n2;

    uniao = (int *)malloc(soma*sizeof(int));

    for(int i=0; i<n1; i++)
        uniao[i] = v1[i];

    for(int i=0; i<(n2); i++)
        uniao[i+n1] = v2[i];

    return uniao;
};

int main(){

    int *v1;
    int *v2;
    int *v3;
    int n1, n2;
   
        
    printf("Numero de elementos no vetor 1: ");
    scanf("%d", &n1);
    printf("Numero de elementos no vetor 2: ");
    scanf("%d", &n2);   
    
    
        v1 = (int *) malloc(n1*sizeof(int));
        for(int i = 0; i < n1; i++){
            v1[i] = rand()%100;
        }
        
        v2 = (int *) malloc(n2*sizeof(int));
        for(int j = 0; j < n2; j++){
            v2[j] = rand()%100;
        }
        
        v3 = uniao(v1, n1, v2, n2);
        
        for(int i=0; i<(n1+n2); i++){
            printf("%d\t", v3[i]);
        }
        

    return 0;

}

