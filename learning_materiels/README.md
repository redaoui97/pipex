This is a little summary of the principles and mechanisms that Linux uses, it's a bunch of random informations that I read about the Kernel and its components.
<h3>Hardware basics</h3>
<h4>The CPU</h4>
<p>
The CPU is the heart of the computer system, it calculates, performs logical operations and manages data flows by reading instructions from memory and then executing them. It operates on binary data (ones and zeros). These ones and zeros correspond to electrical switches being either on or off.<br>
The processor's execution is governed by an external clock (the system clock) that generates regular clock pulses to the cpu and at each clock pulse, the processor does some work. (100Mhz cpu receives 100M clock ticks every second). <br>
The instructions have to fetched from the memory as they are executed.<br>
Some special purpose, dedicated, registers: Porgram counter (register that contains the address of the nxti nstruction ot be executed),
Stack Pointer (A way of easily saving and restoring temporary values in external memory.), Processor status (yields results, other informations about the current state of the cpu...) <br>
<h4>Memory</h4>
Cache (temporarily holds content of the main memory. Very fast. types (I-Cache, B-Cache, D-Cache...) <br>
Main memory (very slow compared to the cache, stores the data send it to the cpu to process it)
<h4>Address Spaces</h4>

</p>
