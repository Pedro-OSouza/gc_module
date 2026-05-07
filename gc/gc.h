#ifndef GC_H
#define GC_H
#include <stddef.h>
    void gc_init();
    void* gc_malloc(size_t size);

    void gc_scope_begin();
    void gc_scope_end();

    void gc_free_all();
#endif
