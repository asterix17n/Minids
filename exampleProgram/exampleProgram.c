/*
 ============================================================================
 Name        : exampleProgram.c
 Author      : Asterix C [asterix17n@gmail.com]
 Version     :
 Copyright   : Copyright (C) 2013  Asterix C [asterix17n@gmail.com]
 Description : Uses shared library to print greeting
 To run the resulting executable the LD_LIBRARY_PATH must be
 set to ${project_loc}/libminids/.libs
 Alternatively, libtool creates a wrapper shell script in the
 build directory of this program which can be used to run it.
 Here the script will be called exampleProgram.
 ============================================================================
 */

#include "stack_int.h"

int main(void) {
	stack_int_t l_stack = 0;
	int i;

	for (i = 0; i < 51; i++)
		stack_int_push(&l_stack, i);

	stack_int_print(l_stack);

	return 0;
}
