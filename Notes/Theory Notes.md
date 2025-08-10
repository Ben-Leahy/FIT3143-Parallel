## Key nomenclature:
**Parallel v distributed**    
Parallel: 

**CPU v GPU**

## Flynn's Taxonomy
**Key:**   
**SI** = single function.  
**MD** = multiple instances of a single function with different inputs (data stream)

**SISD:** single function, single input parameters, single output, single core.  
    **Examples:** single core cpu.    

**SIMD:** single function, mutliple instance of function with different inputs, multipl outputs, multple cores.  
    **Example:** matrix multiplication, GPUs on graphic processing

**MISD:** multiple functions, single input, multiple outputs, multiple cores. 
    **Example:** decrypting something by running multiple independent decryption algorithms

**MIMD:** multiple functions, multiple instances of function with different inputs, multiple outputs multiple cores.  
    **Example:** most things; multiple core cpu, super computer, networked computers. 


## Memory Architecture:  
**Shared memory architecture**  

**Distributed memory architecture**
**Hybrid memory architecture**

## Parallel Pramming models 
A. Shared Memory
B. Threads
C. Message Passing
D. Data Parallel
E. Hybrid 

SPMD
MPMD

## Network and internet
Internet architecture, latency

## Inter process communications
**Context**   
Consider the delay when communicating between processors, is it worth parallelising a task between them?   

**Shared Memory**   
**Unix Signals and analogues (interrupts)**   
**Message Passing**    
- BSD sockets -> third party storage that multiple processors can access
- Streams -> third party storage that multiple processors can access, and that information streams in; it's divided into a series of packets. 
- etc




### Process

### Internet

###