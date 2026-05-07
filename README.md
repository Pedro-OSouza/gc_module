# gc_module

🇧🇷 PT-BR | 🇺🇸 EN

---

# 🇧🇷 Português

`gc_module` é um pequeno módulo experimental escrito em C com o objetivo de tornar o gerenciamento de memória menos manual e mais automatizado.

A proposta do projeto é permitir que o desenvolvedor utilize `gc_malloc()` no lugar de `malloc()` e reduza a necessidade de chamadas manuais de `free()`, utilizando um sistema simples baseado em escopos.

O módulo foi pensado principalmente para estudos, testes de conceitos e experimentação com gerenciamento de memória em C.

---

## Objetivo

Em C, o gerenciamento manual de memória pode facilmente gerar:

- memory leaks
- double free
- ponteiros inválidos
- esquecimentos de `free()`
- problemas em retornos antecipados

O `gc_module` tenta reduzir esses problemas utilizando:

- rastreamento de ponteiros alocados
- limpeza automática por escopo
- limpeza global automática ao encerrar o programa

---

## Como funciona

O módulo cria escopos de memória utilizando:

```c
gc_scope_begin();
gc_scope_end();
```

Toda memória alocada com:

```c
gc_malloc();
```

fica registrada dentro do escopo atual.

Quando o escopo termina, toda memória associada é liberada automaticamente.

Também existe um cleanup global automático com:

```c
atexit(gc_free_all);
```

---

## Estrutura principal

### Inicialização

```c
gc_init();
```

Inicializa o sistema de gerenciamento.

---

### Alocação de memória

```c
char* buffer = (char*)gc_malloc(100);
```

Funciona de forma semelhante ao `malloc()`, mas registra automaticamente o ponteiro no escopo atual.

---

### Escopos

```c
gc_scope_begin();

/* código */

gc_scope_end();
```

Toda memória criada dentro do escopo será liberada automaticamente ao final dele.

---

## Estado atual do projeto

O projeto ainda é simples e experimental.

Atualmente possui:

- gerenciamento básico de ponteiros
- sistema de escopo
- cleanup automático
- integração simples em projetos C

---

## Possíveis melhorias futuras

- detecção de double free
- suporte a realloc
- suporte a threads
- debug de memória
- métricas de uso
- integração mais segura com escopos aninhados
- macros para automação

---

## Aviso

Este projeto é experimental e educacional.

Não é recomendado para produção sem melhorias adicionais, testes extensivos e validações de segurança.

---

# 🇺🇸 English

`gc_module` is a small experimental module written in C designed to make memory management less manual and more automated.

The project's goal is to allow developers to use `gc_malloc()` instead of `malloc()` and reduce the need for manual `free()` calls by using a simple scope-based system.

This module was mainly created for study purposes, concept testing, and experimentation with memory management in C.

---

## Goal

In C, manual memory management can easily lead to:

- memory leaks
- double free
- invalid pointers
- forgotten `free()` calls
- issues caused by early returns

`gc_module` attempts to reduce these problems by using:

- allocated pointer tracking
- automatic scope cleanup
- automatic global cleanup when the program exits

---

## How it works

The module creates memory scopes using:

```c
gc_scope_begin();
gc_scope_end();
```

Every allocation made with:

```c
gc_malloc();
```

is automatically registered inside the current scope.

When the scope ends, all associated memory is automatically released.

There is also a global automatic cleanup using:

```c
atexit(gc_free_all);
```

---

## Main structure

### Initialization

```c
gc_init();
```

Initializes the memory management system.

---

### Memory allocation

```c
char* buffer = (char*)gc_malloc(100);
```

Works similarly to `malloc()`, but automatically tracks the allocated pointer inside the current scope.

---

### Scopes

```c
gc_scope_begin();

/* code */

gc_scope_end();
```

All memory allocated inside the scope is automatically released when the scope ends.

---

## Current project state

The project is still simple and experimental.

Current features:

- basic pointer tracking
- scope system
- automatic cleanup
- simple integration with C projects

---

## Possible future improvements

- double free detection
- realloc support
- thread support
- memory debugging
- usage metrics
- safer nested scope integration
- automation macros

---

## Warning

This project is experimental and educational.

It is not recommended for production use without additional improvements, extensive testing, and security validations.

---

# License

MIT License