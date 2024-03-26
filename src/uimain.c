#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char sen[100];
  char userChoice;
  List *token_history = init_history();
  int i = 1;
  int userPos;
  char *user_token;
  char yesOrNo;
  while(i){
    printf("> Please enter a '1' if you would like to tokenize a string, and '2' to get a history of the tokens,enter a '3'to select a specifc string from the past, enter q to quit.\n");
    scanf(" %c", &userChoice);
    switch(userChoice)
      {
      case '1':
	printf("Enter a string you want to tokenize: ");
	scanf(" %[^\n]", &sen);
	printf("\n");
	char **tokens = tokenize(sen);
	printf("\n");
	add_history(token_history, sen);
	print_tokens(tokens);
	free_tokens(tokens);
	break;
      case '2':
	printf("Here is  your tokenizer history: \n");
	print_history(token_history);
	break;
      case '3':
	printf("Please enter the integer of the string you would like to get: ");
	scanf(" %d", &userPos);
	user_token = get_history(token_history,userPos);
	printf("TOKEN:[ %s\n]",user_token);
	break;
      case 'q':
	i = 0;
	printf("Thank you!\n");
	break;
      default:
	printf("Invalid input please try again.\n");
      }
  }
    return 0;
  }
