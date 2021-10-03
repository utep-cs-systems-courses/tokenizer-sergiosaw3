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
  char *t=(char *)malloc(sizeof(char*));
  *t=str;
  for(i=0;i<sizeof(t);i++)
    {
      printf("for loop works %p okay\n",t);
      printf("inside: %c\n",t);
      printf("at 1: %c\n",t[1]);
      t++;
      //printf("for loop\n");
      ///if(non_space_char(str[i])==1)
      //if(none_space_char(t)==1)
      ///{
	  // printf("word start found");
	  ///printf("we got here\n");
	  ///return str[i];
	  //return t;
      ///}
    }
  //free t;
  return t;
 }

/* Returns a pointer terminator to the first space character or string-terminator
   following str in a zero terminated string.
   str is assumed to be pointing to a non-space character*/
 char *word_end(char *str);/*
{
  for(i=0;i<*str;i++)
    {
      if(space_char(*str[i])==1)
	{
	  return *str[i];
	}
    }
}
/*
/* Counts the number of space seperated words in the string argument. */
int count_words(char *str);

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
