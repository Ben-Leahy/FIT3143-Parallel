# Single instruction Multiple data architectures
Most multimedia uses specialised SIMD libraries: multimedia specialised co-processor chips

Typical SIMD architectures:
- each processor has it's Own memory
- is programmable
- and executes the same instruction simultaneously

Space granularity:
How many data elements will each processor have to handle
- complete fine grain -> one data element match to each processing element
- partial fine grain -> a few data elements match to each processing element
- coarse grain -> many data elements match to each processing element

Connectivity:
- hypercube, pyramid,
- tree -> memory
- neighbours -> use a lot. High diameter high bandwidth

processor connectivity:
- single-bit
- integer
- floating-point

local autonomy:
simple vs autonomous

# Vector processing:
**What**For processing vectors, or things which can be vectorised. 
**Why** Because in comparison to regular computation, we can save on n-1 opcode fetches, decodes and operand loads, for a vector of length n.

A vector operand will be a register (or a pointer to an array in memory) 
This can be stall free because we know how long it will take to do. 
Chaining: Have an extra (a 4th -> 2 for current, 1 for result, 1 for next) register, so that we can load on the extra register while we operate on the other two. 
Parallelising loops: when there are no variables updated in each that other loops have to work on. Then each ALU can work on a separate iteration of the loop -> this is what a vectorising compiler can set up.

# MPI functions and stuff
Native to C

Buffering is handled by OS and MPI. 
Start with Blocking, then transition to non-blocking as an improvement. 
For non-blocking: we just request the MPI to send the request. Then there are wait routines to ensure that what needs to change has changed. any function that starts with MPI_I is non-blocking. 

slide 32 if all are sent before blocking what happens or something. 
