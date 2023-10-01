#include <stdio.h>



int change_a(int *x){ //this is the change_a function responsible for changing the value of "a". it takes one argument, it is an integer, and
//the integer is dereferenced. this means, when we put &a into here, which is the memory address of "a", "*"" will derefence it. Dereferencing is
//when you get the value the pointer is pointing to in the memory. So as a result, *x is actually equal to value of a, which is 101!

*x = *x * 2; //here we assign the value of "a", which we got from its memory location, a new value, which is *x *2 (value of "a" times 2). Now it should
//be equal to "202".

printf("here we doubled the value of a and this is the output within the change_a function: %d\n", *x); //print out the new value within the function.

return 0; //return an integer value, commonly a zero, and because of the same reason as before.
}

 int main(){

 int a = 101; //we assign a default value of "101" to variable a


 printf("Hi, this is a formatted print statement in main, default value of 'a': %d\n", a); //we print it as it is

 change_a(&a); //we call the change_a function and pass &a as an argument which means we passed the memory address of the variable into the function

 printf("Hi, this is a formatted print statement in main, so here is the NEW value of 'a': %d\n", a); //here we printed the result after the function  modified it

 
return 0; //returned an integer because this function is "int" and must return an "int"
}
