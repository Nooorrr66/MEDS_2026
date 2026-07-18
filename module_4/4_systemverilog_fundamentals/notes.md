SystemVerilog describes HARDWARE, not software.

Everything happens concurrently.

Basic structure

module
    input logic
    output logic
    assign
endmodule

logic
0 1 X Z

bit
0 1 only

wire
multiple drivers

assign
continuous hardware connection

Instantiation
module_name instance(
    .a(sig1),
    .b(sig2)
);

Operators

&  bitwise AND
&a reduction AND
|  bitwise OR
|a reduction OR
^ XOR
~ NOT
&& logical AND
|| logical OR

{x,y}
Concatenation

{4{x}}
Replication

Combinational
No clock
Immediate output

Sequential
Clock
Stores state

Setup
Data stable BEFORE clock

Hold
Data stable AFTER clock

Violation
Metastability

==   normal equality
===  compares X and Z too
