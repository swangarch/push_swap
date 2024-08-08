push_swap is a project in the school 42

The goal is to sort a stack with several instructions, and some constraints. 

Use make to make the push_swap program, and make bonus to make checker.

push_swap takes series of numbers as arguments, and print the instruction on stdout which allows to sort the stack.

chekcer takes the same numbers, and take in stdin the instructions to check if these instructions can actually sort the stack, then print "OK\n" or "KO\n"

The program has to handle input errors, if input is not integer, the program should display "Error\n"

Basic rules:
there are two stacks a and b.

pb: push the top element from stack a to b;

pa：push the top element from stack b to a;

ra：rotate stack a;

rb: rotate stack b;

rr: rotate two stacks together;

rra：reverse rotate stack a;

rrb: reverse rotate stack b;

rrr: reverse rotate two stacks together;

sa: swap top two elements from stack a;

sb: swap top two elements from stack b;

The algorithm is inspired by A. Yigit Ogun's turkish algorithm, with some improvement to achieve better performance.

1. If the stack a is already sorted, do nothing.
2. If the stack a contain less than 3 numbers, a independent algorithm will sort it in maximum 2 instructions.
3. If the stack has more than three elements:
     <1> Push elements directly from a to b, only three left, when there is less than 100 numbers.
     <2> Push elements from a to b, with a pre-sorting by divide the numbers into 4 chunks, only three left in a, in descending order, when there is more than 100 numbers.
4. Sort 3 left elements in stack a.
5. Iterate from b to calculate the total cost to push a element form b to a in the right position, then push the one with lowest cost until b is empty.

I have full score 125 with average 570 instructions to sort 100 numbers, and average 4100 instructions to sort 500 numbers, in the best case, 3800 instructions. 
The division into 4 chunks improved significantly the performance, when there are more than 100 numbers.
