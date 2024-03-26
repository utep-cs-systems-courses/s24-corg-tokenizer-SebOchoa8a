#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

int space_char(char c)
{
  if(c == ' ' || c =='\t'){
    return 1;
  }
  return 0;
}

int non_space_char(char c)
{
  if(c == ' ' || c == '\t' || c == '\0'){
    return 0;
  }
  return 1;
}
char *token_start(char *str)
{
  int i = 0;
  while(space_char(str[i])){
    i++;
  }
  return str + i;
}

char *token_terminator(char *token)
{

  int i = 0;
  while(*(token + i)){
    if(space_char(*(token + i))){
      break;
    }
    i++;
  }
  return token + i;
}

int count_tokens(char *str)
{
  int token_count = 0;
  int flagForToken = 0;
  for(int i = 0; str[i] != '\0'; i++){
    if(space_char(str[i])){
      flagForToken = 0;
    }else if(!flagForToken){
      flagForToken = 1;
      token_count++;
    }
  }
  return token_count;
}

char *copy_str(char *inStr, short len)
{
  char *str_copy = malloc((len+1) * sizeof(char));
  for(short i = 0; i < len; i++){
    str_copy[i] = inStr[i];
  }
  str_copy[len] = '\0';
  return str_copy;
}



char **tokenize(char* str)
{

  int token_count = count_tokens(str);
  char **tokens = malloc(sizeof(char *) * (token_count + 1));
  char *token = str;
  for(int i = 0; i < token_count; i++){
    token = token_start(token);
    char* token_end = token_terminator(token);
    int length = token_end - token;
    tokens[i] = copy_str(token,length);
    token = token_terminator(token);
  }
  
  tokens[token_count] = '\0';
  return tokens;
}



void print_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i] != NULL){
    printf("TOKEN[%d]: %s\n", i,tokens[i]);
    i++;
  }
  printf("\n");
}

void free_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i]){
    free(tokens[i]);
    i++;
  }
}
