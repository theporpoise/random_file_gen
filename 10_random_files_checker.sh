#!/bin/bash
echo Generating 10 random files based on parameters in main.c function
echo expecting your executable to be named ./a.out
make ; ./test.out 10;
echo toutA
make ; ./a.out toutA | cat | diff toutA -
echo toutB
make ; ./a.out toutB | cat | diff toutB -
echo toutC
make ; ./a.out toutC | cat | diff toutC -
echo toutD
make ; ./a.out toutD | cat | diff toutD -
echo toutE
make ; ./a.out toutE | cat | diff toutE -
echo toutF
make ; ./a.out toutF | cat | diff toutF -
echo toutG
make ; ./a.out toutG | cat | diff toutG -
echo toutH
make ; ./a.out toutH | cat | diff toutH -
