#!/bin/bash

make

cp push_swap push_swap_visualizer/

#ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
ARGS="98 99 31 28 5 88 37 81 21 30 91 100 16 18 58 87 35 63 43 41 64 61 57 13 47 82 3 9 71 6 96 80 14 59 62 25 48 38 90 73 56 84 78 26 42 44 50 49 75 55 79 67 89 8 4 24 17 52 94 66 40 86 70 33 95 10 68 93 27 65 69 77 97 34 83 12 32 76 23 1 20 46 36 11 53 51 54 45 29 2 7 39 85 74 19 92 15 60 22 72"

#./push_swap $ARGS

#ARGS="5 18 4 2 14 8 7 12 10 0 3 16 1 9 6 11 15 19 17 13"
#./push_swap $ARGS

#ARGS="6 8 11 5 7"
#ARGS="5 18 4 2 14 8 7 12 10 0 3 16 1 9 6 11 15 19 17 13"
./push_swap $ARGS | grep -oE 'sorted: Yes'

echo "1 Finished"

./push_swap "98 99 31 28 5 88 37 81 21 30 91 100 16 18 58 87 35 63 43 41 64 61 57 13 47 82 3 9 71 6 96 80 14 59 62 25 48 38 90 73 56 84 78 26 42 44 50 49 75 55 79 67 89 8 4 24 17 52 94 66 40 86 70 33 95 10 68 93 27 65 69 77 97 34 83 12 32 76 23 1 20 46 36 11 53 51 54 45 29 2 7 39 85 74 19 92 15 60 22 72" | grep -oE 'sorted: Yes'
echo "2 Finished"
