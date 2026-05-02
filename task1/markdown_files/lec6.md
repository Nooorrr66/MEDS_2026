# Lecture 6: Timing and Verification II – Summary Notes

## Part 1: Combinational Circuit Timing

### 1.1 The Reality of Delay
- Digital logic abstraction (output changes instantly) is **not physically true**.
- Transistors have finite switching time due to:
  - Capacitance and resistance
  - Finite speed of light (=30 cm/ns – significant on chip scale)

### 1.2 Delay Definitions
- **Contamination delay (`tcd`)** – minimum time until output *starts* changing.
- **Propagation delay (`tpd`)** – maximum time until output *finishes* changing.
- Delays depend on:
  - Rising vs. falling transitions
  - Different input paths
  - Temperature, voltage, aging

### 1.3 Critical Path & Shortest Path
- **Critical (longest) path** = sum of `tpd` along worst-case route -> determines **maximum clock frequency**.
- **Shortest path** = sum of `tcd` -> determines **hold time vulnerability**.
- Example: `tpd = 2*tpd_AND + tpd_OR`, `tcd = tcd_AND`

### 1.4 Glitches
- **Glitch:** one input transition causes multiple output transitions.
- Visible in K-maps when moving between prime implicants.
- **Fixing:** add consensus terms (increases area/power).
- **Often ignored** if only steady-state output matters – designer's choice.

---

## Part 2: Sequential Circuit Timing

### 2.1 Flip-Flop Timing Parameters
- **`tsetup`** – D must be stable *before* clock edge.
- **`thold`** – D must be stable *after* clock edge.
- **Aperture time** = `tsetup + thold`
- **Metastability** – if D changes during aperture time, output can settle unpredictably.

### 2.2 Clock-to-Q Delays
- **`tccq`** (contamination) – earliest Q changes after clock edge.
- **`tpcq`** (propagation) – latest Q stabilizes after clock edge.

### 2.3 System Timing Constraints (Two Flip-Flops with Logic)
- **Setup constraint (max delay):**  
  `Tc > tpcq + tpd + tsetup`  
  -> Determines **minimum clock period** (max frequency).
- **Hold constraint (min delay):**  
  `tccq + tcd > thold`  
  -> If violated, data changes too fast for next flip-flop.

### 2.4 Fixing Violations
- **Setup violation:** reduce logic depth, simplify paths, or lower clock frequency.
- **Hold violation:** add buffers to short paths (increases `tcd`) – **does not affect max frequency**.

### 2.5 Clock Skew
- Clock does **not** arrive at all flip-flops simultaneously.
- **Skew** = time difference between two clock edges.
- Skew **increases effective `tsetup` and `thold`** -> more sequencing overhead.
- Managed by careful clock network design (e.g., clock trees, meshes).

---

## Part 3: Circuit Verification Overview

### 3.1 Two Main Questions
1. Is it **functionally correct**?
2. Does it meet **timing constraints**?

### 3.2 Verification Tools
- **Formal verification** (SAT solvers)
- **HDL simulation** (Vivado, ModelSim)
- **Circuit simulation** (SPICE)

### 3.3 Practical Split-Responsibility Approach
- **High-level (C/HDL):** check only functionality (fast simulation).
- **Low-level (circuit):** check only timing/power, plus functional equivalence to high-level model.

---

## Part 4: Functional Verification

### 4.1 Testbench Concept
- **Testbench** = module that tests a **Device Under Test (DUT)**.
- Provides inputs, checks outputs.
- **Not synthesized** – uses simulation-only constructs (`#10`, `$display`).

### 4.2 Testbench Types

| Type | Input Generation | Error Checking |
|------|----------------|----------------|
| Simple | Manual | Manual (waveforms) |
| Self-Checking | Manual | Automatic |
| Testvector-based | File | Automatic |
| Automatic | Generated | Automatic (vs golden model) |

### 4.3 Simple Testbench
- Hardcoded inputs, wait statements.
- Output checked by looking at waveforms or `$display`.
- **Pros:** easy for corner cases.
- **Cons:** not scalable, manual checking.

### 4.4 Self-Checking Testbench
- Same hardcoded inputs, but with `if (y != expected) $display("error")`.
- **Pros:** prints errors automatically.
- **Cons:** still not scalable, testbench itself can have bugs.

### 4.5 Testvector-Based Testbench
- Read inputs + expected outputs from a file (e.g., `$readmemb`).
- Use a **clock** to sequence through vectors.
- Check on falling edge, apply on rising edge (convention).
- **Pros:** easy to change test cases without recompiling testbench.
- **Cons:** file size limited, still need to generate vectors.

### 4.6 Automatic Testbench with Golden Model
- **Golden model** = high-level, simpler, verified-correct version of DUT.
- Test pattern generator feeds same inputs to DUT and golden model.
- Comparator checks mismatch.
- **Pros:** fully automated, high coverage, good separation of roles.
- **Cons:** golden model may be hard to write; input generation still challenging.

### 4.7 The Verification Wall
- 32-bit adder: 64 inputs -> 2^64 possible combinations.
- Testing 1 input/ns -> **58.5 years** to test all.
- Must use **pruning**, **formal methods**, or **constrained-random** testing.

---

## Part 5: Timing Verification

### 5.1 Two Approaches
- **High-level simulation** with `#delay` statements – fast, but timing is approximate.
- **Circuit-level timing verification** – accurate, but requires synthesized design.

### 5.2 Role of Tools (e.g., Vivado)
- Tools attempt to **meet timing automatically** for given clock constraint.
- Output: timing report with worst-case paths, max frequency, and violations.

### 5.3 Common Failures
- Desired clock frequency too aggressive -> setup violation.
- Excessive clock skew -> hold violation (harder to fix post-fabrication).
- Asynchronous logic issues.

### 5.4 Fixing Timing Errors (Manual Iteration)
- Try different synthesis/place-and-route options (random seeds, hints).
- Manually optimize critical paths:
  - Simplify logic.
  - Split long combinational chains.
  - Add buffers to fix hold violations.

### 5.5 Good Design Principles
- **Critical path design:** minimize maximum logic delay -> maximize performance.
- **Balanced design:** equalize delays across paths -> avoid bottlenecks.
- **Optimize common case** – but ensure corner cases still work.

---

## Key Formulas to Remember

| Constraint | Formula |
|------------|---------|
| Setup (max freq) | `Tc > tpcq + tpd + tsetup` |
| Hold (min delay) | `tccq + tcd > thold` |
| Clock skew effect | Increases effective `tsetup` and `thold` |

---