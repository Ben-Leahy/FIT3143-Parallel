Context for Inter-Process Communications:
- Consider, given the delay in the communication between processes, is it worth parallelising an algorithm into multiple processes. 


Inter-Process Communication types:
- Shared memory
- Interrupts (unix signals and analogues)
- Message passing (connection through internet) the following are types of message passing. 
    - Streams -> BSD sockets but dividing the information into packets. 
    - BSD sockets -> third party storage that both procresses can access
    - Other exampels: multicase support

Internet:
- UDP: low overhead, packets of data may or may not arrive (streaming -. memory)
- TCP: higher overhead, packets will arrive (eventually) in order
- FTP (FIle transfer protocol)

Internet protocols:
For both of these protocols, consider the overhead of transmission times. 
Also consider that if you send a very high number of messages, but each containing a small amount of data, then most of what you have sent is just wrapping. 

OSI Reference model (describes how packets of information travel in the internet)
This has a different set of layers (more) than described below

The TCP(Transmission Control Protocol), IP (internet protocol), IETF (internet engineering task force)
For context, transitioning between these layers is where a lot of latency comes from. 
Application layer:
    For transmitting data over networks (internet) between applications. Ie HTTP (hyper-text transfer protocol), SMTP(simple mail transfer protocol), SSH(secure shell protocol) Each service
Transport layer:
    Helps transmit the data to the right location. Uses port numbers and ICP or UDP
    UDP: low overhead. Unreliable. 
    TCP: Higher overhead, reliably arrive and arrive in order.
Internet layer:
    (barely our consideration)
    IP Internet Protocol, IP addresses. ICMP
Link Layer: 
    (not our consideration)
    Physical transmission, physical storage locations. Ie ethernet


Scribbles:
gigabyte = 1024 bytes
Consider that we need a buffer of memory in the kernel 
Concurrent: in progress at the same time
Parallel: executing at the same time. 

Pre reading for week 4 or something idk
We fork one process, from 1 core to 2 cores. (fork just means copying the code of a process to another location)
Join also means to tell the parent to stop executing until the child comes back

How to create thread, fork and join, access memory stack and shared memory. Okay so OopenMP allows us to do private for stack and public for heap.  


what is a PRAM LMM and MMM???