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
  //output the string for the user
  while(i){
    printf("> Please enter a '1' if you would like to tokenize a string, and '2' to get a history of the tokens,enter a '3'to select a specifc string from the past, enter q to quit.\n");
    scanf(" %c", &userChoice);//takes user choice
    switch(userChoice)
      {
      case '1'://case for the user to tokenize a string
	printf("Enter a string you want to tokenize: ");
	scanf(" %[^\n]", &sen);//takes user sentence
	printf("\n");
	char **tokens = tokenize(sen);// array to take the tokens for the tokenizer functions
	printf("\n");
	add_history(token_history, sen);//add the tokens to the history
	print_tokens(tokens);//prints the total tokens
	free_tokens(tokens);//frees the memory allocated for the tokens
	break;
      case '2':
	printf("Here is  your tokenizer history: \n");
	print_history(token_history);//prints the tokens total history
	break;
      case '3':
	printf("Please enter the integer of the string you would like to get: ");
	scanf(" %d", &userPos);//takes in int for the user to choose what string they want
	user_token = get_history(token_history,userPos);//give user_token the output of get history
	printf("TOKEN:[ %s\n]",user_token);//prints the user token
	break;
      case 'q':
	i = 0;
	printf("Thank you!\n");//quits if user enters q
	break;
      default:
	printf("Invalid input please try again.\n");
      }
  }
    return 0;
  }
