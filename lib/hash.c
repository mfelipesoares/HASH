#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"


void new_node(char *key, char *value, Dicionario *dici){
    int key_len = strlen(key);
    int value_len = strlen(value);

    Node * temp = NULL;
    temp = (Node *)malloc(sizeof(Node));
    temp->key = (char*)malloc((key_len + 1) * sizeof(char));
    temp->value = (char*)malloc((value_len + 1) * sizeof(char));
    temp->next = NULL;
    strcpy(temp->key, key);
    strcpy(temp->value, value);
    dici->size++;

    Node * aux = (Node *) dici->vetor;

    if(dici->vetor == NULL){
        dici->vetor = temp;
    }else{
        while(aux->next != NULL){
            aux = (Node *)aux->next;
        }
        aux->next =(struct Node *) temp;
    }
}


Dicionario * new_dici(){
    Dicionario * temp = NULL;
    temp = (Dicionario *)malloc(sizeof(Dicionario));
    temp->vetor = NULL;
    temp->size = 0;
    return temp;
}

void print_dici(Dicionario * dici){
    Node * aux = dici->vetor;
    printf("HASH {\n");
    while(aux!= NULL){
        printf("\t\"%s\" : \"%s\";\n", aux->key, aux->value);
        aux =(Node *) aux->next;
    }
    printf("}\nSIZE: %d\n", dici->size);

}
void inserir(Dicionario * dici){
    char key[257];
    char value[257];
    printf("Digite a chave: ");
    scanf(" %256[^\n]", &key);
    printf("Digite o valor: ");
    scanf(" %256[^\n]", &value);
    new_node(key, value, dici);
}
void remover(Dicionario *dici, char *key) {
    Node *prev = NULL;
    Node *current = dici->vetor;

    // Procurar o nó com a chave fornecida
    while (current != NULL && strcmp(current->key, key) != 0) {
        prev = current;
        current = (Node*)current->next;
    }

    // Se a chave não foi encontrada, retornar
    if (current == NULL) {
        printf("Chave '%s' não encontrada.\n", key);
        return;
    }

    // Remover o nó encontrado
    if (prev == NULL) {
        // Se o nó a ser removido for o primeiro da lista
        dici->vetor = (Node*)current->next;
    } else {
        // Se o nó a ser removido estiver no meio ou no final da lista
        prev->next = (struct Node*)current->next;
    }

    // Liberar a memória alocada para a chave, o valor e o próprio nó
    free(current->key);
    free(current->value);
    free(current);
    dici->size--;
    printf("Elemento com chave '%s' removido com sucesso.\n", key);
}
void menu(Dicionario * dici){
    int choice = 0;
    while(1){
        printf("\nTABELA HASH\n"
            "1 - Inserir\n"
            "2 - Remover\n"
            "3 - Buscar\n"
            "4 - Imprimir\n"
            "5 - Sair\n"
            "Digite a opção desejada: "
        );
        scanf("%d", &choice);
        system("clear");
        getchar();
        switch(choice){
            case 1 : inserir(dici); break;
            case 2:
                char key_to_remove[257];
                printf("Digite a chave do elemento a ser removido: ");
                scanf(" %256[^\n]", key_to_remove);
                remover(dici, key_to_remove);
                break;
            case 3 : break;
            case 4 : print_dici(dici); break;
            case 5 : printf("Tchau :)\n"); exit(0);
            default: printf("Opção inválida\n"); break;

        }
    }
}

void libera(Dicionario *dici){
    Node *aux = dici->vetor;
    while(aux != NULL){
        Node *temp = aux;
        aux =(Node *) aux->next;
        free(temp->key);
        free(temp->value);
        free(temp);
    }
    free(dici);
}
