# Lectures 5 & 6: Timing, Verification & Verilog (The Simple Version)

## Part 1: Why Timing Matters (The Real World)

- **Digital logic straight up lies sometimes.** Nothing is instant.
- Gates take time, wires take time… everything has *delay*.
- So yeah, your circuit can be 100% correct on paper and still fail in real life if you push the clock too fast.

## Part 2: The Two Key Delays

- **Propagation Delay (tpd):** When the output is *finally done changing* (max delay).
- **Contamination Delay (tcd):** When the output *starts changing* (min delay).

**Easy way to think about it:**
- tcd -> first movement
- tpd -> everything settled

## Part 3: The Two Timing Rules (YOU NEED THESE)

### Rule 1: Setup Time (don’t be late)

- Flip-flop needs data **before** the clock edge.
- If data comes late -> boom, wrong value.

- Formula:
  `Clock Period > tpcq + tpd + tsetup`

- If it breaks:
  - slow down clock  
  - or simplify your logic (shorten path)

---

### Rule 2: Hold Time (don’t be too fast)

- Data changes *too quickly* and messes up the next flip-flop.

- Formula:
  `tccq + tcd > thold`

- If it breaks:
  - add buffers (literally slow things down)

---

- **Golden rule:**  
    - Setup = max delay issue  
    - Hold = min delay issue  

## Part 4: Glitches & Skew (the annoying stuff)

- **Glitches:**
  - Output randomly flickers before settling
  - Usually harmless -> ignore unless it causes real issues

- **Clock Skew:**
  - Clock doesn’t hit all flip-flops at the same time
  - Makes timing harder to satisfy

## Part 5: Verilog (actual usable version)

### Two ways to write it

1. **Structural**
   - Basically wiring diagram
   - “this connects to that”

2. **Behavioral**
   - More like instructions
   - “if this happens, do that”
   - This is what you’ll mostly use

---

### Blocking vs Non-Blocking (SUPER IMPORTANT)

- **Blocking (`=`):**
  - happens immediately, in order
  - use for combinational logic

- **Non-blocking (`<=`):**
  - everything updates together later
  - use for sequential logic (clocked stuff)

**Just remember:**
- no clock -> `=`
- clock -> `<=`

---
### Output Logic
- `assign` (Moore)
- or combinational logic (Mealy)

---

## Part 6: Testing (don’t skip this)

You can’t “feel” if hardware works. You have to test it.

### Simple Testbench
- just throw inputs and look at waves  
- okay for tiny stuff  

### Self-Checking
- code tells you if something is wrong  
- way better  

### Golden Model
- make a simple correct version  
- compare outputs automatically  

---

### Reality Check
- Testing all inputs for a 32-bit adder = `2⁶⁴` cases  
 That’s basically impossible → test smart, not everything  

---

## Part 7: What actually matters (cheat sheet)

| Problem              | Cause            | Fix                          |
|---------------------|------------------|------------------------------|
| Circuit too slow    | Setup violation  | shorten path / reduce clock  |
| Random wrong data   | Hold violation   | add buffers                  |
| Output flickering   | Glitch           | usually ignore               |
| Clock mismatch      | Skew             | fix clock design             |
---

### FSM (3-block pattern you will see everywhere)


1. **State register**
`   -   ```verilog
    -   always @(posedge clk)
    -       state <= nextstate;
    
2. **Next State Logic**
    -```verilog
    -always @(*) begin
    -    case(state)
---
