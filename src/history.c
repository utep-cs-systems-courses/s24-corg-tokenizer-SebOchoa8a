#include <stdio.h>
#include <stdlib.h>
#include "history.h"
/* Initialize the linked list to keep the history. */
List* init_history()
{
  List *token_history = (List*)malloc(sizeof(List));// allocate memeory for the list struct
  if(token_history != NULL)
    {
      token_history ->root = NULL;//set the root pointer to NULL
    }
  return token_history;//return the list
}

/* Add a history item to the end of the list.
*/
void add_history(List *list, char *str)
{
  Item *temp = (Item*)malloc(sizeof(Item));//allocate the memory for the new history item
  int posId = 1;
  int length = 0;
  //find the length of the string
  while(*(str + length) != '\0' && *(str + length) != '\n')
  {
    length++;
  }
  
  temp->str = (char*)malloc((length + 1) * sizeof(char));//allocate memory for the string in the history item
  //put the string into the history item
  for(int i = 0; i < length;i++){
    temp->str[i] = str[i];
  }
  temp->str[length] = '\0';//add null terminator to the string
  temp->next = NULL;// set the next pointer to NULL

  if(list->root == NULL)// if the list is empty
    {
    temp->id = posId;// set the ID of the history item
    list->root = temp;// set the root of the list to the new history item
  }
  else// if list not empty
  {
    Item *copy_list = list->root;//creates a copy of the list root to iterate through the list
    while(copy_list->next != NULL)
      {
	copy_list = copy_list->next;// move to the next item in the list
      }
    temp->id = copy_list->id + 1;// set the ID of tje history item
    copy_list->next = temp;//add the new history item to the end of the list
  }
  posId++;// increment the position ID
}

/* Retrieve the string stored in the node where Item->id == id. */

char *get_history(List *list, int id){
  Item *temp = list->root;//start at the root of the list
  while(temp != NULL){// iterate through the list
    if(temp->id == id){// if the ID matches the user ID
      return temp->str;
    }
    temp = temp->next;//move to the next item in the list
  }
  return NULL;//return Null if the ID is not found
}

/*Print the entire contents of the list. */
void print_history(List *list){
  if(list == NULL || list->root == NULL){// if the list is empty of NULL
    printf("There is no history to print.\n");
    return;
  }
  Item *temp = list->root;// start at the root of the list
  while(temp != NULL){// iterate through the list
    printf("ID[:%d]: %s\n", temp->id, temp->str);//print the ID and the string
    temp = temp->next;//Move to the next item in the list
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list)
{
  Item *curr = list->root;//start at the roor of the list

  while(curr != NULL){//Iterate through the list
    Item *prev = curr;//store a reference to the curr item
    free(curr->str);// free the string in the current item
    curr = prev->next;//Move to the next item in the list
    free(prev);// free the current item
  }
  free(list);//free the list struct
}
