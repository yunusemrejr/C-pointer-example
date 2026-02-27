#ifndef POINTER_DEMO_H
#define POINTER_DEMO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Version Information */
#define VERSION "2.0"
#define AUTHOR "YUNUS EMRE VURGUN"

/* Display Constants */
#define SEPARATOR "═══════════════════════════════════════════════════════════"
#define LINE_WIDTH 60

/* Function Type Definitions */
typedef int (*operation_func)(int, int);

/* Core Demonstration Functions */
void display_header(void);
void display_menu(void);
void print_separator(void);
void pause_for_user(void);

/* Pointer Demonstrations */
void demo_basic_pointer(void);
void demo_pointer_arithmetic(void);
void demo_array_pointer(void);
void demo_double_pointer(void);
void demo_const_pointer(void);
void demo_function_pointer(void);
void demo_void_pointer(void);
void demo_swap_pointer(void);

/* Helper Functions */
int modify_value(int *ptr);
void swap_values(int *a, int *b);
int add(int a, int b);
int multiply(int a, int b);
int execute_operation(operation_func func, int x, int y);

#endif /* POINTER_DEMO_H */
