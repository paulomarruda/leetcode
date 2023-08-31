#pragma once 

#ifndef HASH_H
#define HASH_H 

typedef struct{
    char *key;
    void *value;
} HTItem;

typedef struct{
    size_t capacity;
    size_t size;
    HTItem **items;
} HTHashTable;

HTHashTable *constructHTTable(size_t capacity);

void destructHTTable(HTHashTable *ht);

#endif 

