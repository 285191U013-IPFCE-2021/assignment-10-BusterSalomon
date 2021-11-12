#include "..\include\btree.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

/*
PROBLEM SOLVING STEPS

1. Find out if the value to be insertet is greater, smaller or equal to current
1a. greater
    a. If it is greater than the next value
        - Move in to the next one ex: Insert (x, t->right)
    b. If it is smaller than the next value
        - Insert between
        ex: t->right = new_t, new_t
    c. If it is equal to the next value 
        - Move on to the next one ex: Insert (x, t->right)


1b. smaler
1c. equal
    // Should be insertet to the left
    a. Node to inserts left should be set to currents left
    b. Currents left should be set to node to be insertet
     - Note: This is accomplished by making a new tree_node instance

     //               20
     //             /    \
     //            /      \
     //          20       30
     //          /        /\
     //         5        /  \
     //        /  \    25   40
     //       /    \   
     //      1     15 


*/

// Makes tree node
struct tree_node * makeTreeNode (int x) {
    struct tree_node *newTreeNode = malloc (sizeof (struct tree_node));
    
    // Asign data
    newTreeNode->item = x;

    // Always inserts in the bottom
    newTreeNode->left = NULL;
    newTreeNode->right = NULL;

    return newTreeNode;
}

// Insert item x into the tree t
/*
    This function always insert in a bottom - ie. creates leaf
    because the code required to write is much less than if tree_nodes should be inserted
    in between other tree_nodes
*/
struct tree_node * Insert (int x, struct tree_node *t) {
    
    // Base case - reached an end
    if (t == NULL) {
        return makeTreeNode (x);
    }

    // Greater
    if (x > t->item) {
        // If t->right != NULL, then t->right is returned from Insert, ie. NO CHANGE
        t->right = Insert (x, t->right);
    }

    // Smaller or equal
    else { // t->item <= x
        // If t->left != NULL, then t->left is returned from Insert, ie. NO CHANGE
        t->left = Insert (x, t->left);
    }

    // Return t
    return t;
}

// Get min
struct tree_node * get_min (struct tree_node *current) {
    while (current->left != NULL) current = current->left;
    return current; 
}

// Remove one item from the tree t
struct tree_node * Remove (int x, struct tree_node *t) {
    
    
    // Base case 1 - Root == NULL, return root, no value to be removed
    if (t == NULL) return t;

    // Recursivec cases
    // Greater
    if (x > t->item) {
        t->right = Remove (x, t->right);
    }

    // Smaller
    else if (x < t->item) {
        t->left = Remove (x, t->left);
    }

    // Base case 2 - Equal
    else { // (x == t->item)
        // One child or no childs
        // In case of no childs NULL is returned - because t->right = NULL
        if (t->left == NULL) {
            // Swap the right value up and free t
            struct tree_node * r_temp = t->right;
            free (t);
            return r_temp;

        }
        else if (t->right == NULL) {
            // Swap the left value up and free t
            struct tree_node * l_temp = t->left;
            free (t);
            return l_temp;
        }

        // Both childs
        else { // t->left && t->right
            // Get smallest in right sub tree
            struct tree_node * min_tree_node = get_min (t->right);
            
            // Assign item
            t->item = min_tree_node->item;
            
            // Removes tree_node leaf
            t->right = Remove (min_tree_node->item, t->right);

        }
    }
    
    // Always return t if no prior return, ie. no changes to the tree so far
    return t;
}



// Return true if the tree t contains item x. Return false otherwise.
int Contains (int x, struct tree_node *t) {

    // BASE CASES
    // Reached an end without succes
    if (t == NULL) return false;
    // Equal
    if (x == t->item) return true;

    // RECURSIVE CASES
    // Greater
    else if (x > t->item) {
        return Contains (x, t->right);
    }

    // Smaller
    else {
        return Contains (x, t->left);
    }
    
}

// Create an empty tree
struct tree_node * Initialize (struct tree_node *t) {
    t = NULL;
    return t;
}

// Test if empty
int Empty (struct tree_node *t) {
    return t == NULL;
}

// Test if full
int Full (struct tree_node *t) {
    // Unless the program run of out virtual memoray adresses to use, the tree will never be full
    return 0;
}
