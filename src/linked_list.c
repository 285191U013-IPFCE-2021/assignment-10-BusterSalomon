#include "..\include\linked_list.h" 
/*
 * Linked list
 */

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* malloc, free */
#include <assert.h>		/* assert */



/* functions to create lists */
node *make_node (int v, node * q)
{
  node *p = malloc (sizeof (node));
  p->value = v;

  if (q == NULL)
    p->next = NULL;
  else
    p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list (node * p)
{
  node *q = p;
  while (q != NULL)
    {
      node *t = q->next;
      free (q);
      q = t;
    }
}


/* print list to console */
void print_list (node * p) {
    if (p != NULL) {
        printf ("%d, ", p->value);
        print_list (p->next);
    }
}

int sum_squares (node * p) {

    // Simple case
    if (p == NULL) return 0;

    // Recursive case
    else return square (p->value) + sum_squares (p->next);
    
}

// Recursive map function
// Returns an adress to linked list (containing nodes), with the mapped values
node *map (node * p, int (*f) (int)) {
    // Recursive case
    if (p != NULL) {
        int result = (*f) (p->value);
        return make_node (result, map (p->next, f));
    } 
    // Simple case
    else return NULL;
}


int square (int x)
{
  return x * x;
}
