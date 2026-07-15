# RISC-V "C" (Compressed Instruction) Extension Summary

The **C (Compressed Instruction) Extension** adds support for **16-bit instructions** alongside the normal 32-bit RISC-V instructions. Its primary goal is to reduce program size while maintaining compatibility with the standard instruction set. Programs can freely mix 16-bit and 32-bit instructions, and the processor automatically decodes both formats.

The compressed extension introduces shorter versions of frequently used instructions such as arithmetic operations, loads, stores, branches, jumps, and stack pointer operations. These compressed instructions usually operate on commonly used registers or use smaller immediate values, allowing the same operations to be represented with fewer bits.

One of the biggest advantages of the C extension is **improved code density**. Since programs occupy less memory, fewer instruction bytes need to be fetched from memory, reducing memory bandwidth requirements and improving instruction cache utilization. This often leads to better performance and lower power consumption, especially in embedded and battery-powered systems where memory and energy are limited.

Another important feature is that the C extension does **not change the programmer's model**. The same registers, execution model, and software behavior remain unchanged; only the instruction encoding becomes more compact. Existing software and compilers can generate compressed instructions automatically when appropriate, requiring little or no changes from programmers.

Overall, the C extension is valuable because it reduces executable size, improves cache efficiency, lowers power consumption, and enhances performance without sacrificing compatibility with the base RISC-V ISA. For these reasons, it is one of the most widely implemented RISC-V standard extensions.
