# Lecture 4: Sequential Logic, FPGAs & Verilog

---

## Lecture 4a: Sequential Logic Design II - Finite State Machines (FSMs)

### Sequential Circuits & Memory
- Output depends on:
  - Current inputs
  - Past inputs (state)
- Use memory elements:
  - Latches
  - Flip-flops

---

### D Flip-Flop
- Edge-triggered state element
- Captures input **D** on the **rising edge** of the clock
- Holds output **Q** for the entire clock cycle

---

### Finite State Machine (FSM) Structure

An FSM consists of three main components:

1. **State Register**
   - Stores the current state
   - Implemented using flip-flops

2. **Next State Logic**
   - Combinational logic
   - Determines next state based on:
     - Current state
     - Inputs

3. **Output Logic**
   - Generates outputs

---

### Moore vs. Mealy FSMs

#### Moore Machine
- Outputs depend **only on current state**

#### Mealy Machine
- Outputs depend on:
  - Current state
  - Inputs

---

### FSM Design Steps

1. Determine states
2. Create a **state transition diagram**
3. Create a **state transition table**
4. Create an **output table**
5. Derive logic equations:
   - Next state
   - Outputs
6. Draw the schematic

---

### State Encoding Schemes

#### Binary (Fully Encoded)
- Uses `log2(number_of_states)` bits
- Pros:
  - Fewer flip-flops
- Cons:
  - More complex logic

#### One-Hot Encoding
- Uses `number_of_states` bits
- Only one bit is `1` at a time
- Pros:
  - Simple logic
- Cons:
  - More flip-flops

#### Output Encoding
- Outputs encoded directly in state bits
- Used in **Moore machines only**
- Minimizes output logic

---

## Lecture 4b: Introduction to FPGAs & Labs

### What is an FPGA?
- **Field-Programmable Gate Array**
- A **reconfigurable hardware device**
- Can be programmed to implement custom circuits

---

### Key Building Blocks
- **Look-Up Tables (LUTs)** -> Implement logic
- **Programmable switches** -> Connect components

---

### Advantages & Disadvantages

#### Advantages
- High performance for specialized tasks
- Energy efficient
- Low development cost
- Fast time-to-market
- Reconfigurable after deployment

#### Disadvantages
- Slower than custom ASICs
- Higher area usage
- Added latency due to flexibility

---

### FPGA Applications
- Deep learning (Microsoft Brainwave)
- Cloud acceleration (AWS F1)
- Genomics (DRAGEN)
- Climate modeling
- Memory research (RowHammer, RowPress)
- Architecture prototyping (PiDRAM, MetaSys)


## Lecture 4c: Hardware Description Languages (HDL) and Verilog

### Purpose of HDLs
- Languages like:
  - Verilog
  - VHDL
- Used to:
  - Describe hardware
  - Simulate designs
  - Synthesize circuits
- Enable management of **billions of transistors**

---

### Verilog Module
- Basic building block
- Includes:
  - Module name
  - Inputs / outputs
  - Internal logic

---

### Hierarchical Design
- Build complex systems using smaller modules
- Improves:
  - Readability
  - Scalability
  - Debugging

---

### Structural vs. Behavioral Modeling

#### Structural (Gate-Level)
- Connects:
  - Gates
  - Lower-level modules

#### Behavioral
- Describes functionality using:
  - `assign`
  - `if`
  - `case`
- Most commonly used approach

---

### Key Verilog Constructs

#### assign
- Continuous assignment
- Used for **combinational logic**

#### always Block
- Executes when signals in sensitivity list change

Examples:
```verilog
always @(posedge clk)
always @(*)