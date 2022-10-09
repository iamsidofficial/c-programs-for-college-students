// In C, there are many ways to print "Hello World" without a Semicolon....

/* 
  Logic : 'printf' method actually returns an integer which is the count of total number of characters that are required to be printed.
           Using this knowledge about the printf method we can print ‘Hello World’ without using a semicolon by using the print statement
           inside the condition of a conditional statement, which will execute an empty block of code. 
           Also, we can use macros,while loop,switch case,command-line arguments for completing this task.
*/


// Using 'If' Condition

#include<stdio.h>
void main()
{
    if(printf("Hello World")){
    }
}


// Using 'While' loop

#include<stdio.h>
void main()
{
    while(!printf("Hello World")){
    }
}


// Using 'Switch' Case

#include<stdio.h>
void main()
{
    switch(printf("Hello World")){
    }
}


// Using 'MACROS' 

#include<stdio.h>
#define PRINT_HELLOWORLD printf("Hello World")
void main()
{
  if(PRINT_HELLOWORLD){
  }
}


// Using 'command-line arguments'

#include<stdio.h>
int main(char *argv[printf("Hello World")]){}