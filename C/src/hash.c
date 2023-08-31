#include <stdlib.h>
#include <string.h> 

#include "../include/hash.h"

// creating and destructing items and tables 

static HTItem *constructHTItem(const char *key, void *value){
    HTItem *ht_item = malloc(sizeof(HTItem));
    ht_item->key = strdup(key);
    ht_item->value = value;
    return ht_item;
}

HTHashTable *constructHTTable(size_t capacity){
    HTHashTable *ht = malloc(sizeof(HTHashTable));
    ht->capacity = capacity;
    ht->size = 0;
    ht->items = malloc(capacity*sizeof(HTItem*));
    return ht;
}

static void destructHTItem(HTItem *ht_item){
    free(ht_item->key);
    free(ht_item->value);
    free(ht_item);
}

void destructHTTable(HTHashTable *ht){
    for (int i=0; i<ht->capacity; i++){
        HTItem *ht_item = ht->items[i];
        if (!ht_item){ destructHTItem(ht_item); }
    }
    free(ht->items);
    free(ht);
}

// hash functions


