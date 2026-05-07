#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gc/gc.h"

//pondo a prova

int proccess_user(const char* input){
    gc_scope_begin();

    char* buffer = (char*)gc_malloc(100);
    char* name = (char*)gc_malloc(50);

    strcpy(buffer, input);

    //teste: erro1 input vazio
    if(strlen(buffer) == 0){
        printf("ERROR: input vazio\n");
        return 0; // saiu sem gc_scope_end() e sem free()
    }

    //teste: erro2 input maior que o permitido
    if(strlen(buffer) > 20){
        printf("ERROR: input maior que o tamanho limite (50)\n");
        return 0; //mais um return antecipado
    }

    strcpy(name, buffer);

    printf("Usuario %s processado", name);

    gc_scope_end();
    return 1;
}

int main() {
    gc_init();

    printf("Teste 1: \n");
    proccess_user(""); //erro 1

    printf("\nTeste 2:\n");
    proccess_user("nome_enooorme_haaaan_kkkkkkkkkkkkkkkkk"); //erro 2

    printf("\nTeste 3:\n");
    proccess_user("Pedro"); // sucesso

    return 0;
}
