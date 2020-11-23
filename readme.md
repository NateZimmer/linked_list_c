# linked_list_c

Basic linked list library for C

## Example:

Snippet from [main.c](./src/main.c)

```c
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
```

Source files are [ll.c](./src/ll.c) & [ll.h](./src/ll.h)

## License: MIT

https://opensource.org/licenses/MIT