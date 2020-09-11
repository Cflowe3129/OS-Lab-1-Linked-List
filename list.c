// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list_t *list_alloc() { 
  
  list_t *list = (list_t*) malloc(sizeof(list_t*)); //allocate space for a list to hold a node(s)
  node_t *node = (node_t*) malloc(sizeof(node_t*)); //allocate space for a note to hold a value
  node->value = -1;
  list->head = node;
  
  return list; 
}


void list_free(list_t *l) {
	
  if(!l) {
    
     printf("%s\n\n", "The list does not exist.");

  } else {
    
     int i;
      for(i = 0; i <= list_length(l); i++) {
        list_remove_from_back(l);
      }
      list_remove_from_front(l);
      free(l);
      printf("%s\n\n", "List memory has been freed.");
    
  }
	
  
}

void list_print(list_t *l) {
  
  node_t *current = (node_t*) malloc(sizeof(node_t*)); //allocate space for a note to hold a value
  current = l->head;

  printf("%s\n", "LIST:");
  while(current->next != NULL) {
    printf("%i\n", current->value);
    current = current->next;
  }
  printf("%i\n\n", current->value);
  
}


int list_length(list_t *l) { 
	
	node_t *current = (node_t*) malloc(sizeof(node_t*)); //allocate space for a note to hold a value
  current = l->head;
	
	int i = 0;
//   printf("%s", "List Length: ");
  while(current->next != NULL) {
    i++;
    current = current->next;
  }
//   printf("%i\n\n", i + 1);
	return i + 1; 
  
}


void list_add_to_back(list_t *l, elem value) {
  
  node_t *node = (node_t*) malloc(sizeof(node_t*)); //allocate space for a note to hold a value
  node_t *current = (node_t*) malloc(sizeof(node_t*)); //allocate space for a note to hold a value
  node->value = value;
  



  if(l->head->next == NULL) {
    
    node->value = value; //stores desired value in the new node
    l->head = node; //sets new node as the head of the list
    
  } else {
    
      current = l->head;
      while(current->next != NULL) {
        
        current = current->next;

      }
      current->next = node;
      current = current->next;

  }
}


void list_add_to_front(list_t *l, elem value) {
  
  node_t *node = (node_t*) malloc(sizeof(node_t*)); //allocate space for a note to hold a value

  node->value = value; //stores desired value in the new node
  node->next = l->head; //points new node's next pointer to the head
  l->head = node; //sets new node as the head of the list
  
}


void list_add_at_index(list_t *l, elem value, int index) {
  
  node_t *node = (node_t*) malloc(sizeof(node_t*)); //allocate space for a note to hold a value
  node_t *temp = (node_t*) malloc(sizeof(node_t*)); //allocate space for a note to hold a value
  node_t *current = (node_t*) malloc(sizeof(node_t*)); //allocate space for a note to hold a value
  node->value = value;
  temp->value = 0;
  



  if(index > list_length(l)) {
    
    printf("%s\n", "The chosen index for addition is larger than the size of the list");
    
  } else if (index < 0) {
		
      printf("%s\n", "Please choose an index greater than or equal to 0.");
		
	} else if (index == list_length(l)) {
		
		list_add_to_back(l, value);
		
	} else if (index == 0) {
		
      list_add_to_front(l, value);
		
	} else {
    
      current = l->head;
    
      int i;
      for(i = 0; i < index - 1; i++) {
        
        current = current->next;
      }
      
      temp = current->next;
      current->next = node;
      node->next = temp;  

  }
}


elem list_remove_from_back(list_t *l) { 
  
	node_t *current = (node_t*) malloc(sizeof(node_t*)); //allocate space for a note to hold a value
	node_t *temp = (node_t*) malloc(sizeof(node_t*)); //allocate space for a note to hold a value
  node_t *removed = (node_t*) malloc(sizeof(node_t*)); //allocate space for a note to hold a value



  if(l->head->value == -1) {
    
    printf("%s\n", "The list is empty");
    
  } else {
		
      current = l->head;
      while(current->next != NULL) {
        temp = current;
        current = current->next;
        removed = current;

      }
		  
			current = temp;
		  current->next = NULL;

  }
  printf("%s", "Removed:");
  printf("%i\n\n", removed->value);

  return removed->value; 
  
}


elem list_remove_from_front(list_t *l) { 
  	node_t *removed = (node_t*) malloc(sizeof(node_t*)); //allocate space for a note to hold a value

  
  
  if(l->head->value == -1) {
    
    printf("%s\n", "The list is empty");
    
  } else {

      removed = l->head;
      l->head = l->head->next;

  }
  printf("%s", "Removed: ");
  printf("%i\n\n", removed->value);
  return removed->value; 

}


elem list_remove_at_index(list_t *l, int index) { 
	node_t *node = (node_t*) malloc(sizeof(node_t*)); //allocate space for a note to hold a value
  node_t *temp = (node_t*) malloc(sizeof(node_t*)); //allocate space for a note to hold a value
  node_t *current = (node_t*) malloc(sizeof(node_t*)); //allocate space for a note to hold a value
  node_t *removed = (node_t*) malloc(sizeof(node_t*)); //allocate space for a note to hold a value
  temp->value = 0;
	
	if(index > list_length(l)) {
    
    printf("%s\n\n", "The chosen index for removal is larger than the size of the list");
    
  } else if (index < 0) {
		
		printf("%s\n\n", "Please choose an index greater than or equal to 0.");

	} else if (index == 0) {
    
		list_remove_from_front(l);
		
	} else if (index == list_length(l)) {
		
		list_remove_from_back(l);
			
	} else {
      
      current = l->head;
    
      int i = 0;
      while(i < index ) {
        
				i++;
				temp = current;
        current = current->next;
      }
    
      temp->next = current->next;

  }
  
	printf("%s", "Removed:");
  printf("%i\n\n", current->value);
	return current->value; 

}

bool list_is_in(list_t *l, elem value) { 
  
  node_t *current = (node_t*) malloc(sizeof(node_t*)); //allocate space for a note to hold a value
  current = l->head;

  while(current->next != NULL) {
    if(current->value == value) {
      
      printf("%i", value);
      printf("%s\n", " is in the list.");
      return true;
    } 
    current = current->next;
  }
  
  if(current->value == value) {
      
      printf("%i", value);
      printf("%s\n", " is in the list.");
      return true;
    } 
  printf("%i", value);      
  printf("%s\n\n", " is not in the list.");


  return false;

}
elem list_get_elem_at(list_t *l, int index) { 
  
  node_t *current = (node_t*) malloc(sizeof(node_t*)); //allocate space for a note to hold a value
  
  
  if(index >= list_length(l)) {
    
    printf("%s\n\n", "The chosen index is larger than the size of the list");

    return -1;
    
  } else if (index < 0) {
		
		  printf("%s\n\n", "Please choose an index greater than or equal to 0.");
      return -1;

		
	} else if (index == 0) {
		
    printf("%s", "Returned: ");
    printf("%i\n\n", l->head->value);
		return l->head->value;
		
	} else {
    
      current = l->head;
    
      int i;
      for(i = 0; i <= index - 1; i++) {
        
        current = current->next;
      }
      
      


  }
  printf("%s", "Returned: ");
  printf("%i\n\n", current->value);
  return current->value; 
}
int list_get_index_of(list_t *l, elem value) { 
  
  node_t *current = (node_t*) malloc(sizeof(node_t*)); //allocate space for a note to hold a value
  current = l->head;
  
  int i = 0;
  while(current->next != NULL) {

    if(current->value == value) {
            printf("%s\n", "good");


      printf("%i", value);
      printf("%s", " is in the list at index ");
      printf("%i\n\n", i);

      return i;
    }
    current = current->next;
    i++;
  }

  if (current->next == NULL) {

          printf("%i", value);
          printf("%s\n\n", " is not in the list.");
        return -1;
  }
  
  printf("%s\n", "There was an error checking the list.");
  return -1; 
}