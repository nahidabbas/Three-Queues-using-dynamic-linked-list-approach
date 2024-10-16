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
