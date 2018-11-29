
#ifndef __DEQUEUE_H__
#define __DEQUEUE_H__


typedef struct node node_t;

struct node 
{
    void *data;
    node_t *next;
};

/**
 * \brief Добавление узла в начало списка
 *
 * Создает новую голову, записывает указатель на
 * неё в *head и инициализирует её указателем *data.
 * Новая голова связывается со старой
 */
int add_front(node_t **head, void *data);

/**
 * \brief Удаление узла из начала списка
 *
 * Освобождает память первого элемента списка и
 * перезаписывает указаетль на голову (*head) = (*head)->next
 */
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

int list_extend(node_t **, node_t **);

void pint_list(node_t *);


#endif


