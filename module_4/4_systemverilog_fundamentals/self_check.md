1. What is the difference in behaviour between == and === when one operand contains an X?
== is logical equality and treats X (unknown) as an unknown value. If either operand contains X, the result is usually X (unknown).
=== is case equality and compares every bit exactly, including X and Z.

Example:

4'b10X1 == 4'b10X1   // Result: X (unknown)
4'b10X1 === 4'b10X1  // Result: 1 (true)

Exam answer:
== does not reliably compare values containing X or Z, while === treats X and Z as actual values and compares them exactly.

2. Why does logic replace both reg and wire in most modern RTL, and when would you still need wire?
logic is the preferred data type because it combines the functionality of reg and wire for single-driver signals, making code simpler and easier to read.
wire is still required for multi-driver nets, such as tri-state buses or signals driven by multiple sources.

Exam answer:
logic is the default type for most RTL because it supports both procedural and continuous assignments with a single driver. wire is only needed when a signal has multiple drivers.

3. If a flop's D input changes 0.2 ns before the clock edge and t
su
	​

=0.5 ns, what happens?

The data changes inside the setup time window.

Since:

Required setup = 0.5 ns
Actual setup = 0.2 ns

0.2 ns < 0.5 ns

Therefore, the setup time is violated.

Result:

The flip-flop may capture the old value or the new value.
It may even become metastable, producing an unpredictable output.

Exam answer:
A setup time violation occurs because the data changed too close to the clock edge. The flip-flop may capture an incorrect value or become metastable.

4. What does the reduction operator ^data compute, and what physical circuit does it correspond to?

^data performs a reduction XOR.

It XORs all bits of the vector together to produce one output bit.

Example:

data = 4'b1101

1 ^ 1 ^ 0 ^ 1 = 1

Since there are 3 ones (odd parity), the result is 1.

Physically, it corresponds to a tree of XOR gates.

Exam answer:
^data computes the XOR of all bits in the vector and produces a single-bit result. It corresponds to a reduction XOR circuit built from multiple XOR gates.

5. What is the fundamental difference between combinational and sequential timing, in your own words?

Combinational logic

No clock.
Output changes whenever the inputs change.
Has no memory.

Sequential logic

Controlled by a clock.
Output changes only on a clock edge.
Can store previous values (has memory).

Exam answer:
Combinational logic updates its output immediately when inputs change, while sequential logic updates only on clock edges and can store data using flip-flops.

6. In the my_and_gate / two_gates example, why is named port connection (.a(a), .b(b)) safer than positional connection (a, b, ab_and)?

Named connections explicitly specify which signal connects to which port.

Example:

my_and_gate gate1(
    .a(a),
    .b(b),
    .y(out)
);

Even if the port order changes in the module definition, the connections remain correct.

With positional connections:

my_and_gate gate1(a, b, out);

If you accidentally swap the order, the design compiles but behaves incorrectly, making bugs difficult to find.
