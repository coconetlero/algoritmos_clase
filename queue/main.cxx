#include <stdio.h>
#include <assert.h>
#include <queue.h>


int main(int argc, char **argv)
{
    Queue *queue = create_queue(5);
    print_queue(queue);

    int d = dequeue(queue);
    enqueue(queue, 20);
    enqueue(queue, 10);
    enqueue(queue, 23);
    print_queue(queue);

    d = dequeue(queue);
    printf("%d\n", d);
    d = dequeue(queue);
    printf("%d\n", d);
    print_queue(queue);

    enqueue(queue, 15);
    enqueue(queue, 7);
    enqueue(queue, 19);
    print_queue(queue);

    d = dequeue(queue);
    printf("%d\n", d);
    d = dequeue(queue);
    printf("%d\n", d);
    print_queue(queue);

    enqueue(queue, 31);
    print_queue(queue);

    enqueue(queue, 27);
    enqueue(queue, 1);
    enqueue(queue, 9);

    clear_queue(queue);
}
