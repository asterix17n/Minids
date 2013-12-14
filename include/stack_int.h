/*
 *  Copyright (C) 2013-2014  Asterix C [asterix17n@gmail.com]
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef STACK_INT_H_
#define STACK_INT_H_

struct stack_int_node {
	int data;
	struct stack_int_node *next;
};

typedef struct stack_int_node stack_int_node_t;

typedef struct stack_int_node *stack_int_node_ptr_t;

typedef struct stack_int_node *stack_int_t;

extern void stack_int_print(stack_int_t);

extern void stack_int_push(stack_int_t *, const int);

extern void stack_int_destroy(stack_int_t *);

extern int stack_int_size(stack_int_t);

extern int stack_int_top(stack_int_t);

extern int stack_int_pop(stack_int_t *);

extern int stack_int_is_empty(stack_int_t);

extern void stack_int_init(stack_int_t *);

#endif /* STACK_INT_H_ */
