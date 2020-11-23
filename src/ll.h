
#ifndef LL_H
#define LL_H

#include <stdint.h>

typedef struct {
    uint16_t len;
    void * data;
    void * next;
    void * prev;
}list_el_t; 

typedef struct {
    list_el_t * head;
    list_el_t * tail;
    uint16_t len;
}list_t;

/**
    @name list_push
    @brief add data to end of linked list
    @param [in] list - a pointer to a list 
    @param [in] data - a pointer to a data
    @param [in] len - the length of the data  
*/
void list_push(list_t * list, void * data, uint16_t len);

/**
    @name list_pop
    @brief removes data from end of linked list
    @param [in] list - a pointer to a list 
    @param [out] data - a pointer to the removed element's data
    @param [out] len - length of the data  
*/
void list_pop(list_t * list, void * data, uint16_t * len);

/**
    @name list_shift 
    @brief removes data from start of linked list
    @param [in] list - a pointer to a list 
    @param [out] data - a pointer to the removed element's data
    @param [out] len - length of the data  
*/
void list_shift(list_t * list, void * data, uint16_t * len);

/**
    @name list_len 
    @brief removes data from start of linked list
    @param [in] list - a pointer to a list 
    @return length of linked list
*/
uint16_t list_len(list_t * list);


#endif // LL_H