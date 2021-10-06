#ifndef _HISTORY_
#define _HISTORY_

typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;

/* Initialize the linked list to keep the history. */
List* init_history()
{
  List *history=(List*)malloc(sizeof(List*));
  history->root=NULL;
  return history;
}


/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
  Item *add=(Item*)malloc(sizeof(Item*));
  if(list->root==NULL)
    {
      add->id=1;
      list->root=add;
    }
  else
    { 
      Item *old=list->root;
      while(old->next!=NULL)
	{
	  old=old->next;
	}
      add->id=old->id+1;
      old->next=add;
     
      /*
      while(list->next!=NULL)
	{
	  list=list->next;
	}
      add->id=list->id+1;
      list->next=add;
      */
    }
  add->str=str;
  add->next=NULL;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id)
{
  Item *ptr=list->root;
  while(ptr->id!=id)
    {
      ptr=ptr->next;
    }
  return ptr->str;
}

/*Print the entire contents of the list. */
  void print_history(List *list)
  {
    while(list!=NULL)
      {
	printf("id[%d]: %s\n",list->root->id,list->root->str);
      }
  }

/*Free the history list and the strings it references. */
  void free_history(List *list);

#endif
