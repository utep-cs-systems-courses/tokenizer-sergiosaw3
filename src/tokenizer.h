#ifndef _TOKENIZER_
#define _TOKENIZER_
#include <stdlib.h>

/* Return true (non-zero) if c is a whitespace characer
   (' ', '\t', or '\n').
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  if(c==' ' || c=='\t' ||c=='\n')
    {
      return 1;
  }
  return 0;
}


/* Return true (non-zero) if c is a non-whitespace
   character (not space, tab, or newline).
   Zero terminators are not printable (therefore false) */
int non_space_char(char c)
{
  if(c==' '|| c=='\t'|| c=='\n')
    {
      return 0;
    }
  return 1;
}

/* Returns a pointer to the first character of the next
   space-separated word in zero-terminated str.  Return a zero pointer if
   str does not contain any words.
   str is assumed to be pointing to a space character */
char *word_start(char *str)
{
  int i;
  char *char_ptr=(char *)malloc(sizeof(char*));
  char_ptr=str;
  for(i=0;i<sizeof(str);i++)
    {
      printf("t= %c\n",*char_ptr);
      if(non_space_char(str[i])==1)
	{
	  //printf("this is non-space char\n");
	  return char_ptr;
	}
      char_ptr++;
    }
  return char_ptr;
 }

/* Returns a pointer terminator to the first space character or string-terminator
   following str in a zero terminated string.
   str is assumed to be pointing to a non-space character*/
 char *word_end(char *str)
{
  int i;
  char *char_ptr=(char *)malloc(sizeof(char*));
  char_ptr=str;
  for(i=0;i<sizeof(str);i++)
    {
      //printf("char_ptr = %c\n",*char_ptr);
      if(space_char(str[i])==1)
	{
	  //printf("this is space char\n");
	  return char_ptr;
	}
      
      char_ptr++;
    }
  return char_ptr;
}

/* Counts the number of space seperated words in the string argument. */
int count_words(char *str)
{
  int i=0;
  int counter=0;
  char *char_ptr=(char *)malloc(sizeof(char*));
  char_ptr=str;
  while(*char_ptr!='\0')
    {
      printf("while loop\n");
      if(space_char(str[i])==1){
	counter++;
      }
      i++;
      char_ptr++;
    }
  free char_ptr;
  return counter;
  /*
  for(i=0;i<sizeof(str);i++)
    {
      if(space_char(str[i])==1){
	printf("word found\n");
	counter++;
      }
      printf("anything\n");
    }
    return counter;*/
}  

/* Returns a newly allocated zero-terminated string
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len);

/* Returns a newly allocated zero-terminated vector of freshly allocated
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string"
     tokens[3] = 0
*/
char **tokenize(char* str);

/* Prints all tokens. */
void print_tokens(char **tokens);

/* Returns a point to the id'th token in the array.
   For exmple if toks contained:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string"
     tokens[3] = 0

  And get_token(tokens, 2) is called a pointer to
  "string" is returned.
*/
char *get_token(char **tokens, int id);

/* Frees all tokens and the vector containing them. */
void free_tokens(char **tokens);

#endif
