#include "linked_list.h"

void ll_init(list *l){
    l -> parent = NULL;
    l -> sz = 0;
}

void ll_append(list *l, int val){
    if(l -> parent == NULL){
        l -> parent = malloc(sizeof(node));
        if (!(l -> parent)) exit(0);
        l -> parent -> child = NULL;
        l -> parent -> value = val;
        l -> sz = 1;
        return;
    }
    
    node *tmp = l -> parent;
    while (tmp -> child != NULL)
        tmp = tmp -> child;

    tmp -> child = malloc(sizeof(node));
    if (!(tmp -> child)) exit(0);
    tmp -> child -> child = NULL;
    tmp -> child -> value = val;
    ++(l -> sz);
}

void ll_push_start(list *l, int val){
    node *tmp = l -> parent;
    l -> parent = malloc(sizeof(node));
    l -> parent -> child = tmp;
    l -> parent -> value = val;
    ++(l -> sz);
}

void ll_pop(list *l){
    if(l -> sz == 1){
        free(l -> parent);
        l -> sz = 0;
        return;
    }
    node *tmp = l -> parent;
    for (int i = 0; i < l -> sz - 2; i++)
        tmp = tmp -> child;
    free(tmp -> child); 
    --(l -> sz);
}

void ll_set(list *l, int index, int val){
    if(index > l -> sz - 1){
        printf("Out-of-Range error\n");
        exit(0);
    }
    node *tmp = l -> parent;
    for (int i = 0; i < index; ++i){
        tmp = tmp -> child;
    }
    tmp -> value = val;
}

void ll_dispose(list* l){
    if (l -> sz == 0 || l -> sz == 1){
        free(l -> parent);  // if parent is NULL, free does nothing
        return;
    }
    node *tmp1 = l -> parent;
    node *tmp2;// = l -> parent;
    while(tmp1 -> child != NULL){
        tmp2 = tmp1 -> child;
        free(tmp1 -> child);
        tmp1 = tmp2;
    }
    l -> sz = 0;
    l -> parent = NULL;
}

void ll_rm(list *l, int index){
    node *tmp1 = l -> parent;
    node *tmp2;
    if (l -> sz == 1 || l -> sz == 0){
        free(l -> parent);
        l -> sz = 0;
        l -> parent = NULL;
        return;
    } else if(index == 0){
        tmp2 = l -> parent -> child;
        free(l -> parent);
        l -> parent = tmp2; 
        --(l -> sz);
        return;
    }
    for (int i = 0; i < index - 1; ++i){
        tmp1 = tmp1 -> child;
    }
    tmp2 = tmp1 -> child -> child;
    free(tmp1 -> child);
    tmp1 -> child = tmp2;
    --(l -> sz);
}

void ll_insert(list *l, int index, int val){
    if (index == 0){
        ll_push_start(l, val);
        return;
    }
    node *tmp1 = l -> parent;
    node *tmp2;
    for (int i = 0; i < index - 1; ++i){
        tmp1 = tmp1 -> child;
    }
    tmp2 = tmp1 -> child;
    tmp1 -> child = malloc(sizeof(node));
    tmp1 -> child -> child = tmp2;
    tmp1 -> child -> value = val;
    ++(l -> sz);
}

void ll_print(list *l){
    node *tmp = l -> parent;
    printf("[ ");
    for (int i = 0; i < l -> sz; i++){
        printf("%d ", tmp -> value);
        tmp = tmp -> child;
    }
    printf("]\n");
}

int ll_get(list *l, int index){
    node *tmp = l -> parent;
    for (int i = 0; i < index; ++i)
        tmp = tmp -> child;
    return tmp -> value;
}

int ll_peek(list *l){
    node *tmp = l -> parent;
    while (tmp -> child != NULL)
        tmp = tmp -> child;
    return tmp -> value;
}

int ll_size(list *l){
    return l -> sz;
}

/* Returns the address of the last node */
static node* get_last(list *l){
    node *tmp = l -> parent;
    while (tmp -> child != NULL)
        tmp = tmp -> child;
    return tmp;
}



