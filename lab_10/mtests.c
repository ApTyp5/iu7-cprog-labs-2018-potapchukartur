#include <stdio.h>
#include <assert.h>
#include "mtests.h"
#include "define.h"
#include "listfunc.h"


int main()
{
    add_front_test1();
    add_front_test2();
    add_front_test3();

    pop_front_test1();
    pop_front_test2();
    pop_front_test3();

    front_back_split_test1();
    front_back_split_test2();
    front_back_split_test3();

    return HAPPY_END;
}


// head == NULL
void add_front_test1()
{
    STEST;

    int data = 5;
    node_t **head = NULL;

    int res = add_front(head, &data);
    int exp_res = WRONG_DATA_REC;

    PVERD(%d, res, exp_res);
}

// data == NULL
void add_front_test2()
{
    STEST;

    int *data = NULL;
    node_t *head = NULL;

    int res = add_front(&head, data);
    int exp_res = WRONG_DATA_REC;

    PVERD(%d, res, exp_res);
}

// pos test
void add_front_test3()
{
    STEST;

    int num1 = 5;
    int num2 = 10;

    node_t *head = NULL;

    int exp_res = HAPPY_END;
    int res = (add_front(&head, &num1) ||
               add_front(&head, &num2));

    assert(head->data == &num2);
    assert(head->next->data == &num1);

    PVERD(%d, res, exp_res);

    free_list(head);
}

// head == NULL
void pop_front_test1()
{
    STEST;

    node_t **head = NULL;

    void *res = pop_front(head);
    void *exp_res = NULL;

    PVERD(%p, res, exp_res);
}

// *head == NULL
void pop_front_test2()
{
    STEST;

    node_t *head = NULL;

    void *res = pop_front(&head);
    void *exp_res = NULL;

    PVERD(%p, res, exp_res);
}

// pos test
void pop_front_test3()
{
    STEST;

    int num1 = 1;

    node_t *head = NULL;

    add_front(&head, &num1);

    void *res = pop_front(&head);
    void *exp_res = &num1;

    PVERD(%p, res, exp_res);
}


// head == NULL
void front_back_split_test1()
{
    STEST;

    node_t *head = NULL;
    node_t *back;

    front_back_split(head, &back);

    int res = HAPPY_END;
    int exp_res = HAPPY_END;

    PVERD(%d, res, exp_res);
}

// back == NULL
void front_back_split_test2()
{
        STEST;

        node_t *head = NULL;
        node_t **back = NULL;

        front_back_split(head, back);

        int res = HAPPY_END;
        int exp_res = HAPPY_END;

        PVERD(%d, res, exp_res);
}

// pos test
void front_back_split_test3()
{
    STEST;

    node_t *head = NULL;
    node_t *back = NULL;
    node_t *iterator = NULL;

    int numlen = 11;
    int num[11] = {0};

    for (int i = 0; i < numlen; i++)
    {
        num[i] = i;
        assert(add_front(&head, num + i) == HAPPY_END);
    }

    front_back_split(head, &back);

    assert(head);
    assert(back);

    int frontlen = llen(head);
    int backlen = llen(back);

    assert(frontlen == backlen || frontlen - 1 == backlen);

    iterator = head;

    for (int i = 0; i < frontlen; i++)
    {
        assert(num  + numlen - 1 - i == iterator->data);
        iterator = iterator->next;
    }

    iterator = back;

    for (int i = 0; i < backlen; i++)
    {
        assert(num + numlen -1 - i - frontlen == iterator->data);
        iterator = iterator->next;
    }

    int exp_res = HAPPY_END;
    int res = HAPPY_END;

    PVERD(%d, res, exp_res);
}



    



    








    







