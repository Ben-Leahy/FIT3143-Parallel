# FIT3143 Parallel Notes
## General

### Assessments
Workshops: week 4, week8, week12: quizzes: what to prepare is released a week before hand.
Applieds: even weeks, the questions are released early
Labs: odd weeks, the questions are released early.
ASSESSED APPLIEDS AND LABS START WEEK 3!!

AI is allowed, but not in presentations, demonstrations, and oral interviews

### Things to know c++:
- data types, variables, operations, controls structures, functions, loops, arrays, I/O and most importantly pointers etc. would be helpful.

### General unit information:
Lectures, workshops/applied/labs, quiz sessions
The first applied and lab is not marked

## Using tools
### Using Docker:
Click on the button top of the mac screen (it looks like a whale) and click "Go to the dashboard"

From the terminal (not inside Docker):
To stop docker:
docker stop ee88b4633823f432b8fae30dd11828f14bb4f80ab066365b7d044ac737b733dd
To start docker:
docker start ee88b4633823f432b8fae30dd11828f14bb4f80ab066365b7d044ac737b733dd

Then run:
docker exec -it ee88b4 bash

### Shortcuts

Chrome: option, command, arrows.
See preview of notes: command, shift, v

### C++
To compile the code: gcc file_name.c -o desired_executable_name
To execute the code: ./desired_executable_name

Always include a main function. 
Import libraries where necessary. 
Example:
/*Headers*/
#include <stdio.h>

/*forward declaration*/
float area_of_square(float);

/*main function*/
int main() {return 0;}

/*subroutine*/
float area_of_square(float side){ return pow(side,2);}

Pointers:
int x = 43;
int *pX = &x; (or int *pX = &x)  //pX is a variable of type: pointer to integer. It points to the location/address of x.
int y = *pX     //y is a variable of type: integer. It stores the value pointed to by the pointer pX


More general things:
%d for int, %s for string. 
Basic variables can be redefined, but not strings nor constants..
An array automatically decays, in most cases, into a pointer to the first element. 

