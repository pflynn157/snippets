#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    struct vector_item *next;
    void *data;
} vector_item;

typedef struct {
    vector_item *first;
    size_t size;
} vector;

vector *vector_init() {
    vector *vec = malloc(sizeof(vector));
    vec->first = NULL;
    vec->size = 0;
    return vec;
}

void vector_push_back(vector *vec, void *data, size_t data_size) {
    vector_item *item = malloc(sizeof(vector_item));
    item->next = NULL;
    item->data = malloc(data_size);
    memcpy(item->data, data, data_size);
    
    if (vec->first == NULL) {
        vec->first = item;
        vec->size = 1;
        return;
    }
    
    vector_item *item1 = vec->first;
    while (item1->next != NULL) {
        item1 = (vector_item *)item1->next;
    }
    
    item1->next = (struct vector_item *)item;
    vec->size += 1;
}

void *vector_get_at(vector *vec, size_t pos) {
    if (pos > vec->size) return NULL;
    
    vector_item *item = vec->first;
    for (size_t i = 0; i<pos; i++) {
        item = (vector_item *)item->next;
    }
    
    return item->data;
}

void vector_destroy(vector *vec) {
    vector_item *item = vec->first;
    while (item != NULL) {
        vector_item *item1 = item;
        item = (vector_item *)item->next;
        
        free(item1->data);
        free(item1);
    }
    
    free(vec);
}

//
// Test program
//
int main() {
    vector *numbers = vector_init();
    for (int i = 0; i<10; i++) {
        vector_push_back(numbers, &i, sizeof(int));
    }
    
    printf("Size: %ld\n", numbers->size);
    
    for (int i = 0; i<numbers->size; i++) {
        int x = *((int *)vector_get_at(numbers, i));
        printf("%d\n", x);
    }
    
    vector_destroy(numbers);

    return 0;
}

