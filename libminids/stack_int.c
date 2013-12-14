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

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack_int.h"

static stack_int_node_ptr_t stack_int_new_node(const int);
static void stack_int_free_node(stack_int_node_ptr_t *);

/**
 * Function: stack_int_new_node
 * ----------------------------
 * Dynamically allocates an integer stack node
 * and return the pointer.
 */

static stack_int_node_ptr_t stack_int_new_node(const int data) {

	stack_int_node_ptr_t l_node = (stack_int_node_ptr_t) malloc(
			sizeof(stack_int_node_t));

	assert(l_node != 0);

	l_node->data = data;
	l_node->next = 0;

	return l_node;
}

/**
 * Function: stack_int_free_node
 * -----------------------------
 * Frees a dynamically allocated integer stack
 * node and initialized the pointer to NULL.
 */
static void stack_int_free_node(stack_int_node_ptr_t *p_node) {

	stack_int_node_ptr_t l_node;

	if (!p_node)
		return;

	l_node = *p_node;
	*p_node = 0;

	if (l_node)
		free(l_node);
}

/**
 * Function: stack_int_print
 * -------------------------
 * Prints all the contents of the stack.
 * Blank-space is used as delimiter
 */
void stack_int_print(stack_int_t p_stack) {

	int i;

	if (!p_stack)
		return;

	while (p_stack) {
		printf("%d ", p_stack->data);
		p_stack = p_stack->next;
	}
	printf("\n");
}

/**
 * Function: stack_int_push
 * ------------------------
 * Pushes integer data on the top of
 * stack.
 */
void stack_int_push(stack_int_t *p_stack, const int data) {

	stack_int_node_ptr_t l_node = 0;

	assert(p_stack != 0);

	l_node = stack_int_new_node(data);

	assert(l_node != 0);

	l_node->next = *p_stack;

	*p_stack = l_node;

}

/**
 * Function: stack_int_destroy
 * ---------------------------
 * Deletes all the nodes from the integer
 * stack.
 */
void stack_int_destroy(stack_int_t *p_stack) {
	stack_int_node_ptr_t l_node = 0;
	stack_int_node_ptr_t l_temp = 0;

	if (!p_stack)
		return;

	l_node = *p_stack;

	*p_stack = 0;

	if (!l_node)
		return;

	while (l_node) {
		l_temp = l_node;
		l_node = l_node->next;

		stack_int_free_node(&l_temp);
	}
}

/**
 * Function: stack_int_size
 * ------------------------
 * Returns the total number of nodes
 * in the stack.
 */
int stack_int_size(stack_int_t p_stack) {
	int l_size = 0;

	while (p_stack) {
		p_stack = p_stack->next;
		l_size++;
	}
	return l_size;
}

/**
 * Function: stack_int_top
 * -----------------------
 * Returns top element from the integer
 * stack. It crashes if stack is empty.
 */
int stack_int_top(stack_int_t p_stack) {

	assert(p_stack != 0);

	return p_stack->data;
}

/**
 * Function: stack_int_pop
 * -----------------------
 * Returns the top most element from the
 * integer stack and deletes the node.
 */
int stack_int_pop(stack_int_t *p_stack) {

	stack_int_node_ptr_t l_node = 0;
	int data;

	assert(p_stack != 0);

	l_node = *p_stack;
	assert(l_node != 0);

	*p_stack = l_node->next;
	data = l_node->data;

	stack_int_free_node(&l_node);

	return data;
}

/**
 * Function: stack_int_is_empty
 * ----------------------------
 * Returns 1 if stack has zero nodes,
 * otherwise 0.
 */
int stack_int_is_empty(stack_int_t p_stack) {
	int empty = p_stack == 0 ? 1 : 0;
	return empty;
}

/**
 * Function: stack_int_init
 * ------------------------
 * Stack should be initialized before using.
 * Causes memory leak if called on a stack which
 * contains node.
 */
void stack_int_init(stack_int_t *p_stack) {
	assert(p_stack != 0);
	*p_stack = 0;
}
