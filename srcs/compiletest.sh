#!/bin/sh
name=$@
mv tests/$name.c .
cc *.c ../libft/libft.a -o $name
mv $name.c tests/.
