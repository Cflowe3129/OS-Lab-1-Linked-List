#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main() {
  


  list_t *list = list_alloc();

  //ADD FUNCTIONS
  list_add_to_back(list, 10);
  list_add_to_front(list, 135);
  list_add_to_front(list, 20);
  list_add_to_back(list, 5);
  list_add_to_back(list, 7);
  list_add_to_back(list, 13);
  list_add_at_index(list, 6, 2);
  list_add_to_back(list, 3);


  
  list_length(list);
	list_print(list);

  
  //REMOVE FUNCTIONS
  list_remove_from_front(list);
  list_remove_from_front(list);
  list_remove_from_back(list);
  list_remove_from_back(list);
	list_remove_at_index(list,2);

  
  list_length(list);
	list_print(list);

  
  list_is_in(list, 3);
  list_get_elem_at(list, 2); 
  list_get_index_of(list, 135);

  
  list_print(list);

  
	
	list_free(list);
  printf("Tests for linked list implementation\n");
  return 0;
}