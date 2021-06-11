#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int key;
    int val;
} Element;

typedef struct Node {
    Element* elem;
    void *p;
    void *l;
    void *r;
} Node;

typedef Node* Tree;


/*****************************************************************************/
Tree insert_element_with_parent(void* parent,Tree _tree,Element* _elem) {
    if(_tree == NULL) {
        //printf("insert here\n");
        _tree = malloc(sizeof(Node));
        _tree -> p = parent;
        _tree -> l = NULL;
        _tree -> r = NULL;
        _tree -> elem = _elem;
    }
    else if(_elem -> key < _tree->elem->key) {
        // add to left side
        //printf("insert left\n");
        _tree->l = insert_element_with_parent(_tree,_tree->l,_elem);
    }
    else {
        // add to right side
        //printf("insert right\n");
        _tree->r = insert_element_with_parent(_tree,_tree->r,_elem);
    }
    
    return _tree;
}

/*****************************************************************************/
Tree insert_element(Tree _tree,Element* _elem) {
    return insert_element_with_parent(NULL,_tree,_elem);
}

/*****************************************************************************/
void destroy_tree(Tree _tree) {
    if(_tree) {
        if(_tree->l) {
            destroy_tree(_tree->l);
        }

        if(_tree->r) {
            destroy_tree(_tree->r);
        }

        free(_tree);
    }
}


/*****************************************************************************/
size_t get_tree_height(Tree _tree) {
    if(_tree == NULL) return 0;

    size_t lh = get_tree_height(_tree->l);
    size_t rh = get_tree_height(_tree->r);
    //printf("lh: %d rh: %d \n",lh,rh);
    return 1 + (lh>rh? lh:rh);
}
 

/*****************************************************************************/
int main(int argc, char* argv[]) {
    printf("Hello World!\n");
    Tree _tree = NULL;

    Element first_element;
    first_element.key = 5;
    first_element.val = 10;

    _tree = insert_element(_tree,&first_element);
    
    Element _second_element;
    _second_element.key = 6;
    _second_element.val = 12;

    _tree = insert_element(_tree,&_second_element);


    Element third_elem;
    third_elem.key = 4;
    third_elem.val = 8;

    _tree = insert_element(_tree,&third_elem);


    size_t h = get_tree_height(_tree);
    printf("H: %d\n",h);


    destroy_tree(_tree);
    return 0;
}
