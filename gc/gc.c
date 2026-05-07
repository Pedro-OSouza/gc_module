#include "gc.h"
#include <stdio.h>
#include <stdlib.h>

//==============DEF======================
typedef struct GCNode{
    void* ptr;
    struct GCNode* next;
} GCNode;

typedef struct GCScope{
    void* list;
    struct GCScope* prev;
} GCScope;

static GCScope* current_scope = NULL;

//==============INIT======================
void gc_init(){
    current_scope = (GCScope*)malloc(sizeof(GCScope));

    current_scope->list = NULL;
    current_scope->prev = NULL;

    atexit(gc_free_all);
}

//==============MALLOC======================
void* gc_malloc(size_t size){
    if(!current_scope){
        fprintf(stderr, "GC não inicializado\n");
        exit(1);
    }

    void* ptr = malloc(size);
    if(!ptr){
        fprintf(stderr, "Erro ao alocar memória\n");
    }

    GCNode* node = (GCNode*)malloc(sizeof(GCNode));
    node->ptr = ptr;
    node->next = current_scope->list;
    current_scope->list = node;

    return ptr;
}

//==============SCOPE======================
void gc_scope_begin(){
    GCScope* scope = (GCScope*)malloc(sizeof(GCScope));

    scope->list = NULL;
    scope->prev = current_scope;
    current_scope->list = scope;
}

void gc_scope_end(){
    if(!current_scope) return;

    GCNode* node = current_scope->list;

    while(node){
        free(node->ptr);

        GCNode* temp = node;
        node = node->next;
        free(temp);
    }

    // voltar para o escopo anterior
    GCScope* prev = current_scope->prev;
    free(current_scope);
    current_scope = prev;
}

//==============CLEANUP======================
void gc_free_all(){
    while(current_scope){
        gc_scope_end();
    }
}


























