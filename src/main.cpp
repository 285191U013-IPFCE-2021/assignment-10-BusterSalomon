extern "C"{
    // Add the header files required to run your main
    #include "..\include\linked_list.h" 
	#include "..\include\btree.h"
}
#include <stdio.h>


// File for sandboxing and trying out code
int main(int argc, char **argv)
{
	
	// ------- TESTING RECURSIVE MAP
	// Defining node to map
	node *n_to_map = NULL;
    	n_to_map = make_node (1,
			make_node (2,
				   make_node (3,
					      make_node (4,
							  make_node (5,
								    NULL)))));
	
	node * n_mapped = map (n_to_map, square);
	int sum = sum_squares (n_to_map);
	// Print
	printf ("%d\n", sum);
	print_list (n_to_map);
	printf ("\n");
	print_list (n_mapped);

	// ------ NODE TREE FUNCTIONS
	struct tree_node *root = NULL;

	struct tree_node *root1 = Initialize (root);

	// A
	printf ("\n\n");
	printf ("A: %d\n", Empty (root1));

	// B and C
	struct tree_node *root2 = Insert (102, root1);
	printf ("Insert and Contains (C): %d\n", Contains (102, root2));
	struct tree_node *root3 = Remove (102, root2);
	printf ("Same as before (B) ?: %d\n", root1 == root3);

	// D
	struct tree_node *t;
	Initialize (t);
	int x = 10, y = 20;
	t = Insert (x, t);
	t = Insert (y, t);
	t = Remove (x, t);
	int z = Contains (y, t);
	printf ("D: %d\n", z);

	// E
	struct tree_node *tp;
	Initialize (tp);
	x = 10;
	tp = Insert (x, tp);
	tp = Insert (x, tp);
	tp = Remove (x, tp);
	printf ("(E) - y: %d\n", Contains (x, tp));
	tp = Remove (x, tp);
	printf ("(E) - z: %d\n", Contains (x, tp));

    return 0;
}