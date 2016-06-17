#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _contato{
    int info;
    struct _contato *ant;
    struct _contato *prox;
} TpContato;

TpContato *lst_inicia(void){
    return NULL;
}

TpContato *lst_insere(TpContato *Lista, int valor){
    
    TpContato *novo = (TpContato*)malloc(sizeof(TpContato));
    
    novo->info = valor;
    novo->prox = Lista;
    novo->ant = NULL;
    
    if (Lista != NULL) {
        Lista->ant = novo;
    }
    
    return novo;
}

TpContato *lst_preenche(TpContato *Lista, int tam_lista){
    
    for (int i = 0; i < tam_lista; i++) {
        Lista = lst_insere(Lista, rand()%tam_lista);
    }
    return Lista;
}

void imprime(TpContato *Lista){
    TpContato *aux;
    
    for (aux = Lista; aux != NULL; aux = aux->prox) {
        printf("%d\t", aux->info);
    }
    printf("\n\n");
}

TpContato *lst_deleta(TpContato *Lista){

    TpContato *p;
    
    if (Lista == NULL) {
        return 0;
    }
    
    for (p = Lista; p != NULL; p = p->prox) {
        Lista = p->prox;
        if (p->prox != NULL) {
            p->prox->ant = NULL;
        }
        free(p);
    }
    return Lista;
}

TpContato *radixSortLista(TpContato *Lista){
    
    int vetor[10]= {0};
    int vet[10]= {0};
    int i, j;
    
    TpContato *aux;
    
    for (aux = Lista; aux != NULL; aux = aux->prox) {
        vetor[aux->info]++;
    }
    
    for (j = 0; j < 9; j++) {
        vetor[j+1] += vetor[j];
    }
    
    for (aux = Lista; aux != NULL; aux = aux->prox) {
        vet[vetor[aux->info]-1] = aux->info;
        vetor[aux->info] --;
    }

    Lista = lst_deleta(Lista);
    
    Lista = lst_inicia();
    
    for (i = 9; i >= 0; i--) {
        
        Lista = lst_insere(Lista, vet[i]);
    }
    return Lista;
}

TpContato *radixSortLista_02(TpContato *Lista, int tamanho){
    
    int vetor[10] = {0};
    int vet[20] = {0};
    int i = 0;
    
    TpContato *aux = Lista;
    
    while (i < tamanho && aux!= NULL) {
        vet[i] = aux->info;
        i++;
        aux = aux->prox;
    }
    
    for (i = 0; i < 20; i++) {
        vetor[(vet[i]%10)/1]++;
    }
    
    return Lista;
}


int main() {
    
    TpContato *Lista;
    Lista = lst_inicia();
    

    Lista = lst_preenche(Lista, 10);
    imprime(Lista);
    

    
    Lista = radixSortLista(Lista);

    imprime(Lista);
    
    
    Lista = lst_deleta(Lista);
    
//    Lista = lst_preenche(Lista, 20);
//    imprime(Lista);
//    
//    Lista = radixSortLista_02(Lista, 20);
//    imprime(Lista);


    return 0;
}

