#include "ll.h"
#include <stdlib.h>
#include <string.h>

/**
    @name list_push
    @brief add data to end of linked list
    @param [in] list - a pointer to a list 
    @param [in] data - a pointer to a data
    @param [in] len - the length of the data  
*/
void list_push(list_t * list, void * data, uint16_t len){
    list_el_t * el = malloc(sizeof(list_el_t));
    memset(el,0,sizeof(list_el_t)); // Memory may not all be 0 
    if(list->tail == NULL){ // Handle first element case 
       list->tail = el;
    }
    if(list->head != NULL){
        el->prev = list->head; // Update previous 
        list->head->next = el; // Update next 
    }
    list->head = el; // New head
    // Handle data elements 
    el->data = data;
    el->len = len;
    list->len++;
}

/**
    @name list_pop
    @brief removes data from end of linked list
    @param [in] list - a pointer to a list 
    @param [out] data - a pointer to the removed element's data
    @param [out] len - length of the data  
*/
void list_pop(list_t * list, void * data, uint16_t * len){
    list_el_t * el = NULL;
    
    if(list->head == NULL){ // List was empty, nothing to pop
        data = NULL;
        *len = 0;
        return; 
    }
    el = list->head; // Get end element of list 
    // Handle data elements
    if(&data != NULL)
    {
        data = el->data;
    }
    if(&len != NULL)
    {
        *len = el->len;
    }
    if(el->prev != NULL){ // if not the last element 
        ((list_el_t *)el->prev)->next = NULL; // Remove 'next' entry
        list->head = el->prev; // Update list head         
    }else{ // end of list 
        list->head = NULL;
        list->tail = NULL;
    }
    free(el);
    list->len--;
}

/**
    @name list_shift 
    @brief removes data from start of linked list
    @param [in] list - a pointer to a list 
    @param [out] data - a pointer to the removed element's data
    @param [out] len - length of the data  
*/
void list_shift(list_t * list, void * data, uint16_t * len){
    list_el_t * el = NULL;
    if(list->tail == NULL) // List was empty, nothing to shift
    {
        data = NULL;
        *len = 0;
        return;         
    }
    el = list->tail; // Get start element of list 
    // Handle data elements
    if(&data != NULL)
    {
        data = el->data;
    }
    if(&len != NULL)
    {
        *len = el->len;
    }
    if(el->next != NULL){ // if not the last element 
        ((list_el_t *)el->next)->prev = NULL; // Remove 'prev' entry
        list->tail = el->next; // Update list tail         
    }else{ // end of list 
        list->head = NULL;
        list->tail = NULL;        
    }
    free(el);
    list->len--;
}

/**
    @name list_len 
    @brief removes data from start of linked list
    @param [in] list - a pointer to a list 
    @return length of linked list
*/
uint16_t list_len(list_t * list){
    return list->len;
}