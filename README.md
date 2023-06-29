# Data-Structures-Assignment-2

A circular linked list contains nodes with binary values.

Write an efficient program that accepts as input a pointer to a list and returns the length of the list (the number of nodes in it). It is forbidden to use an additional pointer that checks whether it reached the top of the list, but it is allowed to change the binary value at each node from 0 to 1 and vice versa.

In order to build the input, you need to build a circular, two-way linked list, which randomly adds a node in each iteration (with a probability of 0.99 it adds a node and with a probability of 0.01 it stops adding nodes. You can define a condition that is usually met, if the condition is met - we add a node. Otherwise, we are done). When creating a node a random binary value must be entered in the key field.

The length of the list must be calculated after the list exists.

Do not use the LIST libraries but implement everything manually Do not use an additional data structure

What is the efficiency of the algorithm?
