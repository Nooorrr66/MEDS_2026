# Lecture 1 - Core Subjects

## Core Topics
- Course introduction and logistics (teaching, grading, labs, exam)
- Why study computer architecture
- What a computer is (computation, communication, storage)
- Abstraction layers (algorithms to electrons)
- Transistors as switches (nMOS, pMOS)
- CMOS logic gates (NOT, NAND, AND, etc.)
- General CMOS gate structure (pull-up / pull-down networks)
- Moore's Law

---

## High-Level Summary
A computer solves problems by orchestrating electrons.  
We begin from the lowest layer:
- Transistors -> Logic Gates -> Combinational Logic -> Processors -> Memory

---

## Course Logistics
- Professors: Onur Mutlu, Mohammad Sadrosadati
- Teaching style:
  - Lectures
  - Readings
  - Labs
  - Homework (optional but recommended)
  - Exam

### Labs
- Build a microprocessor on an FPGA (group work)

### Exam
- 180-minute written exam
- Past exams available online

### Extra Credit
- Analyze RowHammer/RowPress talk (1%)
- Review Moore’s 1965 paper (0.5%)

### Textbooks
- Harris & Harris – Digital Design and Computer Architecture
- Patterson & Hennessy – Computer Organization and Design

---

## Transformation Hierarchy (Abstraction Stack)

| Layer      | Example |
|------------|--------|
| Problem    | Sort an array |
| Algorithm  | Quicksort |
| Program    | C code |
| Runtime    | OS, VM |
| ISA        | MIPS, x86, ARM |
| Microarchitecture | Pipeline, OoO execution |
| Logic      | Gates, adders, muxes |
| Devices    | Transistors |
| Electrons  | Physics |

---

## What is a Computer?

### Three Core Components (von Neumann Model)
- Computation (CPU, ALU)
- Communication (buses, wires)
- Storage (registers, cache, DRAM, disk)

---

## Transistors as Switches

### Types of MOS Transistors

| Type | Function | Passes Well | Gate = 1 | Gate = 0 |
|------|---------|------------|----------|----------|
| nMOS | Pulls down to 0 | 0 | ON | OFF |
| pMOS | Pulls up to 1 | 1 | OFF | ON |

### Key Idea
- nMOS: "normally off" (turns ON with 1)
- pMOS: "normally on" (turns ON with 0)

---

## CMOS Logic Gates

CMOS = Complementary MOS (nMOS + pMOS)

### Why both are needed
- nMOS passes 0 well, 1 poorly
- pMOS passes 1 well, 0 poorly
- Combined:
  - Clean outputs
  - No short circuits
  - No floating nodes

---

## CMOS Gate Structure

- Pull-Up Network (PUN): pMOS -> connects to Vdd (1)
- Pull-Down Network (PDN): nMOS -> connects to GND (0)

Only one network is ON at a time.

---

## Common CMOS Gates

### 1. NOT Gate (Inverter)
- 1 nMOS + 1 pMOS  
- Y = ~A  

### 2. NAND Gate
- pMOS in parallel, nMOS in series  
- Y = ~(A . B)

### 3. AND Gate
- NAND + NOT  

### 4. NOR Gate
- pMOS in series, nMOS in parallel  
- Y = ~(A + B)

### Logical Completeness
- NAND alone is complete  
- NOR alone is complete  

---

## Truth Table

| A | B | A.B (AND) | A+B (OR) | NAND | NOR | ~A |
|--|--|-----------|----------|------|-----|----|
| 0 | 0 | 0 | 0 | 1 | 1 | 1 |
| 0 | 1 | 0 | 1 | 1 | 0 | - |
| 1 | 0 | 0 | 1 | 1 | 0 | - |
| 1 | 1 | 1 | 1 | 0 | 0 | 0 |

---

## Moore’s Law
- Proposed by Gordon Moore (1965)
- Transistor count doubles every ~2 years

### Enabled by
- Smaller transistors
- New materials (Cu, HfO2)
- EUV lithography
- FinFET, GAA

### Note
- Not a physical law
- Slowing down over time

---

## General vs Special Purpose Systems

| Feature | General Purpose (CPU) | Special Purpose (ASIC, TPU) |
|--------|----------------------|-----------------------------|
| Flexibility | High | Low |
| Ease of Programming | High | Low |
| Performance | Moderate | Very High |

### Examples
- CPU: Intel Core, Apple Mx
- Specialized: TPU, Cerebras, Bitcoin miners

