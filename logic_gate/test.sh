#!bin/bash

test() {
    gcc -o main main.c value.c logic_gate.c
    ./main
}

test
