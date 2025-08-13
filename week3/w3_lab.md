## Question 5
### Question 5 a
See notebook

### Question 5 b
Anti-dependency exists when two instructions both write to the same location/ for the same value, or one instruction reads while the other wants to write. We need to ensure these operations happen in the correct order, as it changes the output. 
These are examples of instructions then that can't be completed in parallel, and instead need to be completed sequentially. 

For an example:    
1. `int a = 1, b, total;`   
2. `b = a + 2;` # reading a, should occur before 3 when a is redefined. 
3. `a = 4;` # re-defining a
4. `total = a + b` # summing a and b, should happen after b is defined and a is redefined.

Clearly, even if we had 4 integer cores, we couldn't complete all of these operations in parallel. 