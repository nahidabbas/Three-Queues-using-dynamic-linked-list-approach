#include <stdio.h>
#include <stdlib.h>

/* Student Name:Nahid Abbas
*  Student Number:8957997
*  
The program below should do the following:
- Creates three queues using dynamic linked list approach. 
- Enqueues 5 integers into each queue at initialization.
- After initialization, these queues will have some sort of ranking in terms of priority: high priority, medium priority, and low priority.
- The program will enqueue one item to all queues on every iteration, however, the dequeuing will happen based on the priority as follows:
Dequeue from high priority queue happens first. If the high priority queue is empty, medium priority queue is dequeued.
If both high and medium priority queues are empty, low priority queue is dequeued.
- For every iteration, the program prints out the contents of all queues.
- An additional queue is implemented to keep track of the dequeued items.
- At the end of the program, the contents of the tracker is printed out.

Requirements:
- Complete writing the functions as described in the function documentation comments.
- Function signature must be not be changed. (Do not add/remove/modify any function parameter nor its return type)
- main() function must not be modified.
- Queue and queue node structures must not be modified.
- The output should look like this:

High Priority Queue: 11 12 13 14 15 
Medium Priority Queue: 21 22 23 24 25 
Low Priority Queue: 31 32 33 34 35 

Iteration 1:
High Priority Queue: 13 14 15 101 
Medium Priority Queue: 21 22 23 24 25 111 
Low Priority Queue: 31 32 33 34 35 121 

Iteration 2:
High Priority Queue: 15 101 102 
Medium Priority Queue: 21 22 23 24 25 111 112 
Low Priority Queue: 31 32 33 34 35 121 122 

Iteration 3:
High Priority Queue: 102 103 
Medium Priority Queue: 21 22 23 24 25 111 112 113 
Low Priority Queue: 31 32 33 34 35 121 122 123 

Iteration 4:
High Priority Queue: 104 
Medium Priority Queue: 21 22 23 24 25 111 112 113 114 
Low Priority Queue: 31 32 33 34 35 121 122 123 124 

Iteration 5:
High Priority Queue: 105 
Medium Priority Queue: 22 23 24 25 111 112 113 114 115 
Low Priority Queue: 31 32 33 34 35 121 122 123 124 125 

Iteration 6:
High Priority Queue: 106 
Medium Priority Queue: 23 24 25 111 112 113 114 115 116 
Low Priority Queue: 31 32 33 34 35 121 122 123 124 125 126 

Iteration 7:
High Priority Queue: 107 
Medium Priority Queue: 24 25 111 112 113 114 115 116 117 
Low Priority Queue: 31 32 33 34 35 121 122 123 124 125 126 127 

Iteration 8:
High Priority Queue: 108 
Medium Priority Queue: 25 111 112 113 114 115 116 117 118 
Low Priority Queue: 31 32 33 34 35 121 122 123 124 125 126 127 128 

Iteration 9:
High Priority Queue: 109 
Medium Priority Queue: 111 112 113 114 115 116 117 118 119 
Low Priority Queue: 31 32 33 34 35 121 122 123 124 125 126 127 128 129 

Iteration 10:
High Priority Queue: 110 
Medium Priority Queue: 112 113 114 115 116 117 118 119 120 
Low Priority Queue: 31 32 33 34 35 121 122 123 124 125 126 127 128 129 130 

Contents of Tracker Queue:
Tracker Queue: 11 12 13 14 15 101 102 103 104 21 105 22 106 23 107 24 108 25 109 111 

*/

// Structure for the queue node
typedef struct QueueNode
{
    int data;
    struct QueueNode* next;
} QueueNode;

// Structure for the queue
typedef struct Queue
{
    QueueNode* front;
    QueueNode* rear;
} Queue;

/** 
 * @brief This function initializes a queue.
 * 
 * @param [out] queue - Pointer to queue structure.
 **/
void initializeQueue(Queue* queue)
{
    queue = (Queue*) malloc (sizeof(Queue));
    queue->front == NULL;
    queue->rear == NULL;
}

/** 
 * @brief This function checks if a queue is empty
 * @param [in] queue - Pointer to queue structure.
 * @return True if queue is empty.
 **/
int isQueueEmpty(Queue* queue)
{
    return queue->front == NULL && queue->rear == NULL;
    
}

/**
 * @brief This function enqueues data into a queue.
 * 
 * @param [in/out] queue - Pointer to queue structure.
 * @param [in] data - Data to be enqueued.
 **/
void enqueue(Queue* queue, int data)
{
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear==NULL)
    {
        queue->front = queue->rear = newNode;
        return;
    }
    else 
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

/**
 * @brief This function dequeues data from a queue.
 * 
 * @param [in/out] queue - Pointer to queue structure.
 * @return Dequed data, returns -1 if queue is empty
 **/
int dequeue(Queue* queue)
{
    if (queue->front == NULL) 
    {
        return -1;
    }
    else 
    {
        QueueNode* temp = queue->front;
        int data = temp->data;
        queue->front = temp->next; //  update front then free the node.
        free(temp);
        if (queue->front == NULL)
        {
            queue->rear = NULL;
        }
        return data;
    }
}

/**
 * @brief This function prints the contents of a queue
 * 
 * @param [in] queue - Pointer to queue structure.
 * @param [in] queueName - Pointer to a string that represents the queue name.
 **/
void printQueue(Queue* queue, const char* queueName)
{
     printf(" %s Queue : ", queueName);
     QueueNode* current = queue->front;

     while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
       printf("\n");
}

/**
 * @brief This function dequeues one item based on priority.
 * Dequeue from high priority queue first. If the high priority queue is empty, try medium priority.
 * If both high and medium priority queues are empty, try low priority.
 *
 * @param [in/out] highPriorityQueue - Pointer to high priority queue.
 * @param [in/out] highPriorityQueue - Pointer to medium priority queue.
 * @param [in/out] highPriorityQueue - Pointer to low priority queue.
 * @param [out] trackerQueue - Pointer to the tracker queue
 **/
void dequeueBasedOnPriority(Queue* highPriorityQueue, Queue* mediumPriorityQueue, Queue* lowPriorityQueue, Queue* trackerQueue)
{
    int dequeuedItem = -1;

    //  high priority queue if not empty dequeue high priority
    if (!isQueueEmpty(highPriorityQueue)) 
    {
        dequeuedItem = dequeue(highPriorityQueue);
    }
    // If high priority queue is empty,  dequeue medium priority
    else if (!isQueueEmpty(mediumPriorityQueue))
    {
        dequeuedItem = dequeue(mediumPriorityQueue);
    }
    // If  high and medium priority queues are both empty, dequeue low priority
    else if (!isQueueEmpty(lowPriorityQueue)) 
    {
        dequeuedItem = dequeue(lowPriorityQueue);
    }

    if (dequeuedItem != -1) 
    {
        enqueue(trackerQueue, dequeuedItem);
    }
}



int main()
{
    Queue highPriorityQueue, mediumPriorityQueue, lowPriorityQueue, trackerQueue;
    initializeQueue(&highPriorityQueue);
    initializeQueue(&mediumPriorityQueue);
    initializeQueue(&lowPriorityQueue);
    initializeQueue(&trackerQueue);

    // Enqueue some initial data
    for (int i = 1; i <= 5; i++) {
        enqueue(&highPriorityQueue, i + 10);
        enqueue(&mediumPriorityQueue, i + 20);
        enqueue(&lowPriorityQueue, i + 30);
    }

    printQueue(&highPriorityQueue, "High Priority");
    printQueue(&mediumPriorityQueue, "Medium Priority");
    printQueue(&lowPriorityQueue, "Low Priority");
    printf("\n");
    
    for (int iteration = 1; iteration <= 10; iteration++) {
        int dequeuedItem = -1;

        dequeueBasedOnPriority(&highPriorityQueue, &mediumPriorityQueue, &lowPriorityQueue, &trackerQueue);
        dequeueBasedOnPriority(&highPriorityQueue, &mediumPriorityQueue, &lowPriorityQueue, &trackerQueue);


        // Enqueue a new item in all queues for each iteration
        enqueue(&highPriorityQueue, 100 + iteration);
        enqueue(&mediumPriorityQueue, 110 + iteration);
        enqueue(&lowPriorityQueue, 120 + iteration);

        // Print the contents of all queues
        printf("Iteration %d:\n", iteration);
        printQueue(&highPriorityQueue, "High Priority");
        printQueue(&mediumPriorityQueue, "Medium Priority");
        printQueue(&lowPriorityQueue, "Low Priority");
        printf("\n");
    }

    // Print the contents of the tracker queue and all other queues at the end
    printf("Contents of Tracker Queue:\n");
    printQueue(&trackerQueue, "Tracker");
    printf("\n");

    // Free allocated memory for all queues
    QueueNode* current = trackerQueue.front;
    while (current != NULL) {
        QueueNode* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}
