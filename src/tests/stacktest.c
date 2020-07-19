/*
 * Concoct - An imperative, dynamically-typed, interpreted, general-purpose programming language
 * Copyright (c) 2020 BlakeTheBlock and Lloyd Dilley
 * http://concoct.dev/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include "debug.h"
#include "memory.h"
#include "types.h"
#include "vm/stack.h"

int main()
{
	debug_mode = true;
	init_stack();
	init_store();

	Object* object = new_object("null");
	push(object);
	printf("Data type: %s\n", get_data_type(peek()));
	print_object_value(peek());

	object = new_object("true");
	push(object);
	printf("Data type: %s\n", get_data_type(peek()));
	print_object_value(peek());

	object = new_object("100");
	push(object);
	printf("Data type: %s\n", get_data_type(peek()));
	print_object_value(peek());

	object = new_object("5721452096347253");
	push(object);
	printf("Data type: %s\n", get_data_type(peek()));
	print_object_value(peek());

	object = new_object("77.715");
	push(object);
	printf("Data type: %s\n", get_data_type(peek()));
	print_object_value(peek());

	object = new_object("Greetings, Concocter!");
	push(object);
	printf("Data type: %s\n", get_data_type(peek()));
	print_object_value(peek());

	puts("\nValue of each stack item after pop():");
	for(size_t i = stack.count; i > 0; i--)
		print_object_value(pop());

	free_store();

	return 0;
}