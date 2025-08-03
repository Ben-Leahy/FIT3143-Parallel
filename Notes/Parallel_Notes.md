# FIT3143 Parallel Notes
## General

### Assessments
Workshops: week 4, week8, week12: quizzes: what to prepare is released a week before hand.
Applieds: even weeks, the questions are released early
Labs: odd weeks, the questions are released early.

AI is allowed, but not in presentations, demonstrations, and oral interviews

### Things to know:
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


## Theory:
### Week 1
<font color="0041C2">Concurrency:</font>
Executing things at the time but not necessarily simultaneously. Ie, oscillate between completing parts of multiple tasks. Both tasks don't need to make progress every nanosecond, but they are both being balanced. 

<font color="0041C2">Parralel:</font>
Splitting a task into multiple subtasks, and completing each in parallel. 

<font color="0041C2">CPU:</font>
Few, powerful cores. Good for sequential tasks.

<font color="0041C2">GPU:</font>
Many simply cores. Good for parallel tasks. 

SMP



One resource for it:
https://ftp.utcluj.ro/pub/users/civan/CPD/3.RESURSE/9.Book_2018_Introduction%20to%20ParallelComputing_Trobek.pdf

Types of Parallelism:
Shared memory systems
Multiple processing units, one memory source. 
Results in the Threads approach
Distributed systems
Multiple processing units with their own memory source. 
Results in Message Passing model
Graphic processor units: 
??Used as co-processors for solving general purpose numerically intensive problems
Results in Stream model

Chapter 2:
Measuring performance:
Parallel execution time
Speedup
Efficiency

General:
Model of computation for a parallel computer: RAM

Multiprocessor model is for shared memory systems. There are 3 sub-models:
Parallel Random Access Machine (PRAM):
Many p, to one unified storage, constant access. 
Issue: what happens when two processors try to access the same position in storage? Unpredictable behaviour
Solution: exclusive write exclusive read PRAM. Or many other more relaxed concurrent versions such as concurrent write concurrent read PRAM. As we relax we gain a little more power, CWCR PRAM is at most log(p) times faster than the fastest algorithm on the EWER PRAM.
Application: Design on CWCR PRAM, then convert to EWER which would be at most log(p) times slower. 

Local Memory Machine (LMM), 


Modular Memory Machine (MMM).