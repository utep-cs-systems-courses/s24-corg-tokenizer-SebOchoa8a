
#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
//function to check if a char is space or a tab
int space_char(char c)
{
  if(c == ' ' || c =='\t'){// returns 1 if c is a space or tab 0 if not
    return 1;
  }
  return 0;
}

int non_space_char(char c)//function to check if a char is not a space or tab
{
  if(c == ' ' || c == '\t' || c == '\0'){//returns 1 if not a space or tab return 0 if it is
    return 0;
  }
  return 1;
}
char *token_start(char *str)//function to find the start of a token (the first non-space character in a string
{
  int i=0;
  while (space_char(str[i]))
    i++;//increment i until a non-space char is found
  return str + i;//return a pointer to the first non-space- char
}

//function to find the end of a token
char *token_terminator(char *token)
{

  int i = 0;
  while(*(token + i)){
    if(space_char(*(token + i))){
      break;//breaks when the end of the string is found
    }
    i++;// increment i until end of string
  }
  return token + i;// returns a pointer to the space,tab, or null
}

int count_tokens(char *str)//function to count the number of tokens in a string
{
  int token_count = 0;
  int flagForToken = 0;
  for(int i = 0; str[i] != '\0'; i++){
    if(space_char(str[i])){
      flagForToken = 0;// reset flag if a space or tab is found
    }else if(!flagForToken){
      flagForToken = 1;//se flag id a non-space char is found
      token_count++;// Increment token count for each new token
    }
  }
  return token_count;// return the total num of tokens
}
//function to copy a string of a given length
char *copy_str(char *inStr, short len)
{
  char *str_copy = malloc((len+1) * sizeof(char));
  for(short i = 0; i < len; i++){
    str_copy[i] = inStr[i];//copy each char from inStr to str_copy
  }
  str_copy[len] = '\0';//add null terminator at the end
  return str_copy;//return the copied string
}

//Function to tokenize a string into an array of tokens
char **tokenize(char* str)
{
  int token_count = count_tokens(str);//count the number of tokens in the string
  char **tokens = malloc(sizeof(char *) * (token_count + 1));//allocate memory for the array of tokens
  char *token = str;
  for(int i = 0; i < token_count; i++){
    token = token_start(token);//find the start of the next token
    char* token_end = token_terminator(token);//find the end of the token
    int length = token_end - token;//calculate the length of the token
    tokens[i] = copy_str(token,length);// copy the token into the array
    token = token_terminator(token);// move the token to the next char after the token
  }
  
  tokens[token_count] = '\0';//add a null terminator at the end of the array
  return tokens;// return the array of tokens
}


//function to print the array of tokens
void print_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i] != NULL){
    printf("TOKEN[%d]: %s\n", i,tokens[i]);//this line primts each token of the array
    i++;
  }
  printf("\n");
}

void free_tokens(char **tokens)//Function to free the memory allocated for the tokens
{
  int i = 0;
  while(tokens[i]){
    free(tokens[i]);//free the memory for each token in the array
    i++;
  }
}
