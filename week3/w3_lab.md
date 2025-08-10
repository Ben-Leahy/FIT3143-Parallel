# notes from lecture

Pipelining and superscalar processing

Most CPU's are pipelined at the moment

Our basics are:
think about computer arcitecture of a chipa and what the process is (memory, program counter, ALU, register etc)
The issue with this is tha tmuch of hte CPU is idle
With pipelining, for a n phase cycle, we can complete instructions n times faster: starting the next instruction before the previous has finsihed. 

pipeline latency: the time to complete a cycle of processing and executing an instruction. 
Stall: ie if somethign is missed from cache, we have to retrieve from main memory, that takes longer than multiple cycles and so the cpu will sit idle in the meantime
- data hazard: instruction n+1 uses output of instructino n. To resolve this, we can ensure this doesn't occur at compilation, we can stall the cpu until instruction n is finished, we can forward the result (requires extra hardward, forward it directly from the ALU unit to the ALU unit again rather than sending and retireeving from teh register)
- conditional branch: you don't know which branch of your code you are going to follow until the conditional statement has been solved. We can stall the pipeline until the branch is resolved, or stall the first time and store the branch target in cache for the following times. 

Pipelining is only possible when there are no mutual dependencies between operands (data dependencies)