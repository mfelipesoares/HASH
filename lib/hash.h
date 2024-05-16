#ifndef __HASH__
#define __HASH__

typedef struct{
    char * key;
    char * value;
    struct Node *next;
}Node;

typedef struct{
    Node *vetor;
    int size;
}Dicionario;

void new_node(char *key, char *value, Dicionario *dici);
Dicionario * new_dici();
void print_dici(Dicionario * dici);
void inserir(Dicionario * dici);
void remover(Dicionario *dici, char *key);
void menu(Dicionario * dici);
void libera(Dicionario *dici);

#endif // !__HASH.H__