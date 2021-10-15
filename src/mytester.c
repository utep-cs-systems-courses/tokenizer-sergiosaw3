#include <stdio.h>
#include "tokenizer.h"
//#include <stdlib.h>
#include "history.h"

void main(void){
  
  char letter = 'g';
  int answer = space_char(letter);
  printf("answer: %d\n",answer);
  char *words=" just words ";
  char *start=word_start(words);
  printf("start: %c\n",*start);
  char *wordss="more words\n";
  char *end=word_end(wordss);
  printf("end: %c\n",*end);

  char *wordsss="there are a lot of words";
  int count=count_words(wordss);
  printf("count: %d\n",count);

  char *copy=copy_str(words, 4);
  printf("words: %s\n",words);
  printf("copy 4: %s\n",copy);

  char **tokenized=tokenize(wordsss);
  //printf("tokenize 1: %s\n",tokenized[5]);

  print_tokens(tokenized);
  char *token=get_token(tokenized,5);
  printf("token 5: %s\n",token);
  
  free_tokens(tokenized);
  

  
  //Item *item1;
  //item1->id=1;
  //item1->str="item111";
  //item1->next=NULL;
  //printf("item 1 id: %d\n",item1->id);

  List *list1=init_history();
  //list1->root=NULL;
  //list1->root=item1;
  char *str1="just\n";
  
  add_history(list1,str1);
  add_history(list1,"some\n");
  print_history(list1);
  char *got=get_history(list1, 1);
  printf("Id 1: %s",got);
  free_history(list1);
}
