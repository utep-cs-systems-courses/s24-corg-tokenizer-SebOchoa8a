#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char sen[100];
  char userChoice;
  List *token_history = init_history();
  printf("> Please enter a '1' if you would like to tokenize a string, and '2' to get a history of the tokens, enter q to quit.\n");
  scanf(" %c", &userChoice);
  switch(userChoice)
    {
    case '1':
      printf("Enter a string you want to tokenize: ");
      scanf(" %[^\n]", &sen);
      printf("\n");
      char **tokens = tokenize(sen);
      printf("\n");
      add_history(token_history, &sen);
      print_tokens(tokens);
      free_tokens(tokens);
      break;
    case '2':
      printf("Here is  your tokenizer history: \n");
      print_history(token_history);
      break;
    case 'q':
    printf("Thank you!\n");
      break;

    default:
      printf("Invalid input please try again.\n");
      
    }
  
  return 0;
}
