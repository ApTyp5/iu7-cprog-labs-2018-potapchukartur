
#ifndef __DEQUEUE_H__
#define __DEQUEUE_H__


typedef struct node node_t;

struct node 
{
    void *data;
    node_t *next;
};


int add_front(node_t **head, void *data);

void *pop_front(node_t **head);

node_t *find(node_t *head, const void *data,
    int comparator(const void *, const void *));

void *pop_nonfront(node_t *cur, node_t *prev);

void remove_duplicates(node_t **head, 
    int comparator(const void *, const void *));

int llen(node_t *head);

void front_back_split(node_t *head, node_t **back);

node_t *sorted_merge(node_t **head_a, node_t **head_b,
    int comparator(const void *, const void *));

void free_list(node_t *head);


#endif


