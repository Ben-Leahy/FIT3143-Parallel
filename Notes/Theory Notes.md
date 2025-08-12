## Key nomenclature:

**Parallel v distributed**  
Parallel:

**CPU v GPU**

**CPU v ALU v core**
CPU: that's your computer, may contain 1 to many cores
Core (CPU core): that's like our chip diagram, may contain 1 to many ALUs.
ALU: basic execution unit (ie, integer/logical/address/floating point).

**Latency v efficiency v throughput v time phase**  
Time phase: the time taken for the computer architecture to do one thing (think 5 steps from computer architecture)
Throughput: the number of instructions per time phase.
Latency: the length of time for a single instruction to complete its execution cycle (ie 5 x len(time phase))
Efficiency: throughput.

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

## Computer Architecture

The TLB maps between addresses and virtual addresses.
See diagram of architecture

### Process

1. Increment program counter (PC), fetch next instruction in Opcode (ie ADD)
2. Decode Opcode
3. Route operands to ALU
4. ALU operation
5. Store ALU output in register

### Process

### Internet

## Pipelining

**Definition:** A type of parallel processing, where each instruction is offset by one time period. Single ALU.
**Context:** With standard architecture, if we wait for the previous instruction to be loaded, the components are inactive most of the time.

### Issues

**Data hazard/ data dependency:** instruction n+1 uses output of instruction n. To resolve this, we can:

- ensure this doesn't occur at compilation,
- we can stall the cpu until instruction n is finished,
- we can forward the result.(requires extra hardward, forward it directly from the ALU unit to the ALU unit again rather than sending and retireeving from teh register).

**Conditional branch** you don't know which branch of your code you are going to follow until the conditional statement has been solved.

- We can stall the pipeline until the branch is resolved,
- or stall the first time and store the branch target in cache for the following times.
- or we can start computing both at the same time.
- speculative execution (see details below)

### Pipeline stalls

**Defintion:** for it to be a stall, nothing is coming out (finishing, being printed to memory). This means that the throughput is 0 during a stall. When something is outputted, the stall is over. So if instruction A is executing, then it requires output of instruction B, we are stalled. We wipe it, we start doing instruction B, and when instruction B finishes and is printed to memory then the stall is over.

This is why in general, it generally takes one latency period to start computing again. There are advanced mecagnisms to reduce this.
Causes: data is missed from cache, data dependency is picked up in runtime

Stalls and resolution:

- So we have data forwarding as a technique.
- If we don't ahve hte hardware then we need to know how to deal with latency period. So remember time is on our y axis. So we can only read the time period after we have stored. This requires some optimisation still.
- Then if we have no optimisation, then we have to reset it all and to instruction A first then instruction B

## Superscalar Processing

### General

**Definition** A type of parallel processing, where multiple ALUs are contained with a single core, allowing multiple instructions to be calculated in parallel. The only reason this is better than than multiple cores is because we can share the cache and stuff, so it's a bit cheaper in terms of hardware for the same performance.
**Use** Everything uses this now. It takes advantage of ILP.  
**N-way superscalar processor** N-way superscalar processor means N pipelines/ALU (Arithmetic Logic Unit)/EU (Execution Unit). Up to N times faster.  
**Instruction Level Parallelism (ILP):** is possible if instructions are not mutually dependent.

### Issues

- **Data dependence:** Type of ILP. Think Data Hazard/ data dependency. Resolution: we can't forward because they are happening at the same time. Stall. They can't necessarily be avoided. Changing the compilation.
- **Procedural dependence:** Type of ILP. Think conditional branch; what is the next instruction I should execute? Resolution: speculative execution; you can start executing both potential branches and store the outputs in cache until we pick a path. An issue with this is that we write the two possible paths in cache, but if we fill up cache then we need to write the result of the conditional in cache, we might run into a problem (shoul dbe low occuring instance because cache should have enough storage to wait out conditional calculation)
- **Anti-dependency:** Type of ILP. This is when both instructions write (or one writes and one reads) to the same location, and so the order in which they write to memory matters.
- **Resource Dependency:** If there are no other restrictions as described above, then we can execute more instructions than we have ALUs/EUs and so we are restricted by hardward.

## Question techniqes

- Processing unit means it's higher level we assume that things are already loaded and stuff
- We assume that there are no extra headers unless specified.

# TODO / to ask
