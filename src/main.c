#include <stdio.h>
#include <string.h>
#include "ll.h"

#define ARR_LEN 5

// Proto 
void print_list(list_t * list);

int main()
{
    void * data;
    uint16_t len; 
    int i = 0;
    
    // Create list, must be set to null initially 
    list_t my_list = { .head= NULL, .tail=NULL};

    // String example but can be arbitrary data type & len 
    char * truth[ARR_LEN] ={ "The ","cake ","is ","a ","lie!"};

    for(i = 0; i < ARR_LEN; i++){ // Fill list: 
        list_push(&my_list, truth[i], strlen(truth[i]));
    }
    printf("Print list: \r\n");
    print_list(&my_list); // "The cake is a lie!"
    
    printf("Pop & Print: \r\n");
    list_pop(&my_list, NULL); 
    print_list(&my_list); // "The cake is a "

    printf("Shift & Print: \r\n");
    list_shift(&my_list, NULL);
    print_list(&my_list); // "cake is a "
    
    printf("List length is: %d\r\n",list_len(&my_list)); // 3

    printf("Grab data from end and put at start: \r\n");
    data = list_pop(&my_list, &len); 
    list_shift_in(&my_list, data, len); 
    print_list(&my_list); // "a cake is "

    // Additional tests /////////////////////////////////
    
    printf("Test overpop: \r\n");
    for(i = 0; i < ARR_LEN; i++)
    {
        list_pop(&my_list, &len); 
        printf("%d :",list_len(&my_list));
        print_list(&my_list);
    }

    printf("Reverse load\r\n");
    for(i = 0; i < ARR_LEN; i++){ // Fill list: 
        list_shift_in(&my_list, truth[i], strlen(truth[i]));
    }
    print_list(&my_list);

    printf("Test overshift: \r\n");
    for(i = 0; i < ARR_LEN+2; i++)
    {
        list_shift(&my_list, &len); 
        printf("%d :",list_len(&my_list));
        print_list(&my_list);
    }

    printf("Reverse load\r\n");
    for(i = 0; i < ARR_LEN; i++){ // Fill list: 
        list_shift_in(&my_list, truth[i], strlen(truth[i]));
    }
    print_list(&my_list);
    printf("List length is: %d\r\n",list_len(&my_list));
}

void print_list(list_t * list)
{
    list_el_t * list_el;
    list_el = list->tail;
    while(1)
    {
        if(list_el == NULL)
        {
            break;
        }else
        {
            printf("%s",(char *)list_el->data);
            list_el = (list_el_t *)list_el->next;
        }
    }
    printf("\r\n");
}
