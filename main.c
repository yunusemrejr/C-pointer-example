/*
 * C Pointer Demonstration Tool
 * An interactive educational program for learning pointer concepts in C
 * 
 * Author: YUNUS EMRE VURGUN
 * License: MIT
 * Version: 2.0
 */

#include "pointer_demo.h"

/* ============================================================================
 * UTILITY FUNCTIONS
 * ============================================================================ */

void print_separator(void) {
    printf("%s\n", SEPARATOR);
}

void pause_for_user(void) {
    printf("\nPress Enter to continue...");
    while (getchar() != '\n');
    getchar();
}

void display_header(void) {
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║        C POINTER DEMONSTRATION TOOL v%s                   ║\n", VERSION);
    printf("║        Educational Interactive Pointer Examples            ║\n");
    printf("╚════════════════════════════════════════════════════════════╝\n");
    printf("\n");
}

void display_menu(void) {
    printf("\nSelect a demonstration:\n");
    printf("  1. Basic Pointer Dereferencing\n");
    printf("  2. Pointer Arithmetic\n");
    printf("  3. Array and Pointer Relationship\n");
    printf("  4. Pointer to Pointer (Double Pointer)\n");
    printf("  5. Const Pointers\n");
    printf("  6. Function Pointers\n");
    printf("  7. Void Pointers\n");
    printf("  8. Swap Using Pointers\n");
    printf("  9. All Demonstrations\n");
    printf("  0. Exit\n");
    printf("\nEnter your choice: ");
}

/* ============================================================================
 * HELPER FUNCTIONS FOR DEMONSTRATIONS
 * ============================================================================ */

int modify_value(int *ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Error: NULL pointer received\n");
        return -1;
    }
    
    printf("  → Inside function: received pointer to address %p\n", (void*)ptr);
    printf("  → Dereferencing pointer: current value = %d\n", *ptr);
    printf("  → Doubling the value: %d × 2 = %d\n", *ptr, *ptr * 2);
    
    *ptr = *ptr * 2;
    
    printf("  → New value at address %p: %d\n", (void*)ptr, *ptr);
    
    return 0;
}

void swap_values(int *a, int *b) {
    if (a == NULL || b == NULL) {
        fprintf(stderr, "Error: NULL pointer received\n");
        return;
    }
    
    int temp = *a;
    *a = *b;
    *b = temp;
}

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int execute_operation(operation_func func, int x, int y) {
    if (func == NULL) {
        fprintf(stderr, "Error: NULL function pointer\n");
        return 0;
    }
    return func(x, y);
}

/* ============================================================================
 * DEMONSTRATION 1: Basic Pointer Dereferencing
 * ============================================================================ */

void demo_basic_pointer(void) {
    printf("\n");
    print_separator();
    printf(" DEMONSTRATION 1: Basic Pointer Dereferencing\n");
    print_separator();
    printf("\n");
    
    int a = 101;
    
    printf("Initial value of 'a': %d\n", a);
    printf("Memory address of 'a': %p\n", (void*)&a);
    printf("\nCalling modify_value() with pointer to 'a'...\n");
    
    modify_value(&a);
    
    printf("\nBack in main():\n");
    printf("  → Value of 'a' after function call: %d\n", a);
    printf("  → The original variable was modified through its pointer!\n");
    printf("\n✓ Demonstration complete!\n");
}

/* ============================================================================
 * DEMONSTRATION 2: Pointer Arithmetic
 * ============================================================================ */

void demo_pointer_arithmetic(void) {
    printf("\n");
    print_separator();
    printf(" DEMONSTRATION 2: Pointer Arithmetic\n");
    print_separator();
    printf("\n");
    
    int numbers[] = {10, 20, 30, 40, 50};
    int *ptr = numbers;
    
    printf("Array: [10, 20, 30, 40, 50]\n");
    printf("Base address (ptr): %p\n\n", (void*)ptr);
    
    printf("Pointer arithmetic demonstration:\n");
    for (int i = 0; i < 5; i++) {
        printf("  ptr + %d = %p → value: %d\n", i, (void*)(ptr + i), *(ptr + i));
    }
    
    printf("\nIncrementing pointer:\n");
    printf("  Before: ptr = %p, *ptr = %d\n", (void*)ptr, *ptr);
    ptr++;
    printf("  After:  ptr = %p, *ptr = %d\n", (void*)ptr, *ptr);
    printf("  → Pointer moved to next integer (typically +4 bytes)\n");
    
    printf("\n✓ Demonstration complete!\n");
}

/* ============================================================================
 * DEMONSTRATION 3: Array and Pointer Relationship
 * ============================================================================ */

void demo_array_pointer(void) {
    printf("\n");
    print_separator();
    printf(" DEMONSTRATION 3: Array and Pointer Relationship\n");
    print_separator();
    printf("\n");
    
    int arr[] = {100, 200, 300, 400, 500};
    int *ptr = arr;
    
    printf("Array declaration: int arr[] = {100, 200, 300, 400, 500}\n");
    printf("Pointer declaration: int *ptr = arr\n\n");
    
    printf("Accessing elements using array notation:\n");
    for (int i = 0; i < 5; i++) {
        printf("  arr[%d] = %d (address: %p)\n", i, arr[i], (void*)&arr[i]);
    }
    
    printf("\nAccessing elements using pointer notation:\n");
    for (int i = 0; i < 5; i++) {
        printf("  *(ptr + %d) = %d (address: %p)\n", i, *(ptr + i), (void*)(ptr + i));
    }
    
    printf("\nKey insight: arr[i] is equivalent to *(arr + i)\n");
    printf("✓ Demonstration complete!\n");
}

/* ============================================================================
 * DEMONSTRATION 4: Pointer to Pointer (Double Pointer)
 * ============================================================================ */

void demo_double_pointer(void) {
    printf("\n");
    print_separator();
    printf(" DEMONSTRATION 4: Pointer to Pointer (Double Pointer)\n");
    print_separator();
    printf("\n");
    
    int value = 42;
    int *ptr = &value;
    int **ptr_to_ptr = &ptr;
    
    printf("Variable hierarchy:\n");
    printf("  value = %d (address: %p)\n", value, (void*)&value);
    printf("  ptr = %p (points to value, address of ptr: %p)\n", (void*)ptr, (void*)&ptr);
    printf("  ptr_to_ptr = %p (points to ptr, address: %p)\n", (void*)ptr_to_ptr, (void*)&ptr_to_ptr);
    
    printf("\nDereferencing levels:\n");
    printf("  *ptr = %d (dereference once)\n", *ptr);
    printf("  **ptr_to_ptr = %d (dereference twice)\n", **ptr_to_ptr);
    
    printf("\nModifying value through double pointer:\n");
    printf("  Before: value = %d\n", value);
    **ptr_to_ptr = 84;
    printf("  After:  value = %d\n", value);
    printf("  → Changed original variable through double indirection!\n");
    
    printf("\n✓ Demonstration complete!\n");
}

/* ============================================================================
 * DEMONSTRATION 5: Const Pointers
 * ============================================================================ */

void demo_const_pointer(void) {
    printf("\n");
    print_separator();
    printf(" DEMONSTRATION 5: Const Pointers\n");
    print_separator();
    printf("\n");
    
    int x = 10, y = 20;
    
    printf("Three types of const with pointers:\n\n");
    
    printf("1. Pointer to const (const int *ptr):\n");
    const int *ptr1 = &x;
    printf("   → Can change where pointer points\n");
    printf("   → Cannot change the value it points to\n");
    printf("   ptr1 points to: %d\n", *ptr1);
    ptr1 = &y;
    printf("   After ptr1 = &y: %d\n", *ptr1);
    
    printf("\n2. Const pointer (int *const ptr):\n");
    int *const ptr2 = &x;
    printf("   → Cannot change where pointer points\n");
    printf("   → Can change the value it points to\n");
    printf("   *ptr2 = %d\n", *ptr2);
    *ptr2 = 15;
    printf("   After *ptr2 = 15: %d\n", *ptr2);
    
    printf("\n3. Const pointer to const (const int *const ptr):\n");
    const int *const ptr3 = &y;
    printf("   → Cannot change where pointer points\n");
    printf("   → Cannot change the value it points to\n");
    printf("   *ptr3 = %d (read-only)\n", *ptr3);
    
    printf("\n✓ Demonstration complete!\n");
}

/* ============================================================================
 * DEMONSTRATION 6: Function Pointers
 * ============================================================================ */

void demo_function_pointer(void) {
    printf("\n");
    print_separator();
    printf(" DEMONSTRATION 6: Function Pointers\n");
    print_separator();
    printf("\n");
    
    operation_func op_ptr;
    int a = 15, b = 3;
    
    printf("Function pointers allow storing and calling functions dynamically\n\n");
    
    printf("Available operations:\n");
    printf("  - add(a, b): returns a + b\n");
    printf("  - multiply(a, b): returns a * b\n");
    printf("\nValues: a = %d, b = %d\n\n", a, b);
    
    printf("Setting function pointer to 'add':\n");
    op_ptr = add;
    printf("  Result: %d + %d = %d\n", a, b, execute_operation(op_ptr, a, b));
    
    printf("\nSetting function pointer to 'multiply':\n");
    op_ptr = multiply;
    printf("  Result: %d × %d = %d\n", a, b, execute_operation(op_ptr, a, b));
    
    printf("\nUse cases: callbacks, plugin systems, state machines\n");
    printf("✓ Demonstration complete!\n");
}

/* ============================================================================
 * DEMONSTRATION 7: Void Pointers
 * ============================================================================ */

void demo_void_pointer(void) {
    printf("\n");
    print_separator();
    printf(" DEMONSTRATION 7: Void Pointers\n");
    print_separator();
    printf("\n");
    
    printf("Void pointers (void *) can point to any data type\n");
    printf("Must be cast before dereferencing\n\n");
    
    int int_val = 42;
    float float_val = 3.14f;
    char char_val = 'A';
    
    void *void_ptr;
    
    printf("Pointing to integer:\n");
    void_ptr = &int_val;
    printf("  Address: %p\n", void_ptr);
    printf("  Value (cast to int*): %d\n", *(int*)void_ptr);
    
    printf("\nPointing to float:\n");
    void_ptr = &float_val;
    printf("  Address: %p\n", void_ptr);
    printf("  Value (cast to float*): %.2f\n", *(float*)void_ptr);
    
    printf("\nPointing to char:\n");
    void_ptr = &char_val;
    printf("  Address: %p\n", void_ptr);
    printf("  Value (cast to char*): %c\n", *(char*)void_ptr);
    
    printf("\nUse cases: generic data structures, malloc(), callback data\n");
    printf("✓ Demonstration complete!\n");
}

/* ============================================================================
 * DEMONSTRATION 8: Swap Using Pointers
 * ============================================================================ */

void demo_swap_pointer(void) {
    printf("\n");
    print_separator();
    printf(" DEMONSTRATION 8: Swap Using Pointers\n");
    print_separator();
    printf("\n");
    
    int x = 100, y = 200;
    
    printf("Classic example: swapping two variables\n\n");
    printf("Before swap:\n");
    printf("  x = %d (address: %p)\n", x, (void*)&x);
    printf("  y = %d (address: %p)\n", y, (void*)&y);
    
    printf("\nCalling swap_values(&x, &y)...\n");
    printf("  → Function receives pointers to both variables\n");
    printf("  → Uses temporary variable to swap values\n");
    
    swap_values(&x, &y);
    
    printf("\nAfter swap:\n");
    printf("  x = %d (address: %p)\n", x, (void*)&x);
    printf("  y = %d (address: %p)\n", y, (void*)&y);
    printf("  → Values exchanged, addresses remain the same!\n");
    
    printf("\n✓ Demonstration complete!\n");
}

/* ============================================================================
 * MAIN FUNCTION
 * ============================================================================ */

int main(void) {
    int choice;
    bool running = true;
    
    while (running) {
        display_header();
        display_menu();
        
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("\n⚠ Invalid input! Please enter a number.\n");
            pause_for_user();
            continue;
        }
        
        while (getchar() != '\n');
        
        switch (choice) {
            case 1:
                demo_basic_pointer();
                pause_for_user();
                break;
            case 2:
                demo_pointer_arithmetic();
                pause_for_user();
                break;
            case 3:
                demo_array_pointer();
                pause_for_user();
                break;
            case 4:
                demo_double_pointer();
                pause_for_user();
                break;
            case 5:
                demo_const_pointer();
                pause_for_user();
                break;
            case 6:
                demo_function_pointer();
                pause_for_user();
                break;
            case 7:
                demo_void_pointer();
                pause_for_user();
                break;
            case 8:
                demo_swap_pointer();
                pause_for_user();
                break;
            case 9:
                demo_basic_pointer();
                demo_pointer_arithmetic();
                demo_array_pointer();
                demo_double_pointer();
                demo_const_pointer();
                demo_function_pointer();
                demo_void_pointer();
                demo_swap_pointer();
                pause_for_user();
                break;
            case 0:
                printf("\n");
                print_separator();
                printf("Thank you for using C Pointer Demonstration Tool!\n");
                printf("Keep learning and happy coding! 🚀\n");
                print_separator();
                printf("\n");
                running = false;
                break;
            default:
                printf("\n⚠ Invalid choice! Please select 0-9.\n");
                pause_for_user();
                break;
        }
    }
    
    return 0;
}
