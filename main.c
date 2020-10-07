#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main() {
  


  list_t *list = list_alloc();

  //ADD TO FRONT
  list_add_to_front(list, 135);
  list_add_to_front(list, 20);
  list_add_to_front(list, 7);
  list_add_to_front(list, 35);

  list_print(list); //check that the add to front function works properly. Shoudld print list 35, 7, 20, 135

  //ADD TO BACK
  list_add_to_back(list, 10);
  list_add_to_back(list, 5);
  list_add_to_back(list, 7);
  list_add_to_back(list, 13);

  list_print(list); //check that the add to back function works properly. Shoudld print list 35, 7, 20, 135, 10, 5, 7, 13

  //ADD AT INDEX
  list_add_at_index(list, 6, 2); 
  list_print(list); //check that the add at index function works properly. Shoudld print list 35, 7, 6, 20, 135, 27, 10, 5, 7, 13

  list_add_at_index(list, 27, 5); 
  list_print(list); //check that the add at index function works properly. Shoudld print list 35, 7, 6, 20, 135, 27, 10, 5, 7, 13

  list_add_at_index(list, 1, 12); //Should say index is out of range
  list_print(list); //check that the add at index function works properly. Shoudld print list 35, 7, 6, 20, 135, 27, 10, 5, 7, 13

  list_add_at_index(list, 1, -1); //Should say index is out of range
  list_print(list); //check that the add at index function works properly. Shoudld print list 35, 7, 6, 20, 135, 27, 10, 5, 7, 13

  
  //REMOVE FROM FRONT
  list_remove_from_front(list);
  list_print(list); //check that the remove from front function works properly. Shoudld print list 7, 6, 20, 135, 27, 10, 5, 7, 13

  list_remove_from_front(list);
  list_print(list); //check that the remove from front function works properly. Shoudld print list 6, 20, 135, 27, 10, 5, 7, 13


  //REMOVE FROM BACK
  list_remove_from_back(list);
  list_print(list); //check that the remove from back function works properly. Shoudld print list 6, 20, 135, 27, 10, 5, 7

  // list_remove_from_back(list);
  // list_print(list); //check that the remove from back function works properly. Shoudld print list 6, 20, 135, 27, 10, 5

  //REMOVE AT INDEX
  list_remove_at_index(list,2);
  list_print(list); //check that the remove at index function works properly. Shoudld print list 6, 20, 27, 10, 5, 7

  list_remove_at_index(list,-1); //Should say that the index is out of range
  list_print(list); //check that the remove at index function works properly. Shoudld print list 6, 20, 27, 10, 5, 7

  list_remove_at_index(list,-1); //Should say that the index is out of range
  list_print(list); //check that the remove at index function works properly. Shoudld print list 6, 20, 27, 10, 5, 7


  //Check if element is in the list *compare against most recently printed list*
  list_is_in(list, 3); //False
  list_is_in(list, 27); //True
  list_is_in(list, 6); //True

  list_print(list);

  //Get element at a given index
  list_get_elem_at(list, 2); //prints 27
  list_get_elem_at(list, -1); //prints error statement
  list_get_elem_at(list, 1002); //prints error statement


  //Get index of a given element
  list_get_index_of(list, 6); //prints 0
  list_get_index_of(list, 100); //prints error statement
  list_get_index_of(list, -4); //prints error statement


  
  // list_print(list);

  
	
  list_free(list);
  printf("Tests for linked list implementation\n");
  return 0;
}