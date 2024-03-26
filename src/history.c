#include <stdio.h>
#include <stdlib.h>
#include "history.h"
/* Initialize the linked list to keep the history. */

List* init_history()
{
  List *token_history = (List*)malloc(sizeof(List));
  if(token_history != NULL)
    {
     token_history ->root = NULL;
    }
  return token_history;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
  Item *temp = list->root;
  short id = 1;
  while(temp->next != NULL){
    temp = temp->next;
    id++;
  }
  
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */

char *get_history(List *list, int id){
  Item *temp = list->root;
  while(temp != NULL){
    if(temp->id == id){
      return temp->str;
    }
    temp = temp->next;
  }
  return NULL;
}

/*Print the entire contents of the list. */

void print_history(List *list){
  if(list->root->next == NULL || list == NULL){
    printf("There is no history to print.]\n");
    return;
  }
  Item *temp = list->root;
  while(temp != NULL){
    printf("ID[%d]: %s\n", temp->id,temp->str);
    temp = temp->next;
  }
}

/*Free the history list and the strings it references. */

void free_history(List *list)
{
  Item *curr = list->root;

  while(curr != NULL){
    Item *prev = curr;
    free(curr->str);
    curr = prev->next;
    free(prev);
  }
  free(list);
}
