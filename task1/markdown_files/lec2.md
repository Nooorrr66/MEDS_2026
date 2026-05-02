# Combinational Logic – Lecture Notes

##Core Topic
Combinational Logic – how to build and simplify digital circuits using transistors, logic gates, Boolean algebra, and standard building blocks.

---

## 1. Building Blocks of Computers
- All computers are built from:
  - Transistors → Logic Gates → Combinational Circuits
- Two main transistor types:
  - **nMOS** (good at pulling down to 0)
  - **pMOS** (good at pulling up to 1)
- CMOS gates use:
  - Pull-up network (pMOS)
  - Pull-down network (nMOS)

---

## 2. Logic Gates & Boolean Algebra
### Basic Gates:
- NOT, AND, OR, NAND, NOR, XOR

### Boolean Laws:
- Identity
- Commutative
- Associative
- Distributive
- Complement
- Involution
- DeMorgan’s Laws

### DeMorgan’s Laws:
- (X + Y)' = X' · Y'
- (X · Y)' = X' + Y'

---

## 3. Combinational vs Sequential Logic
- **Combinational Logic:**
  - Output depends only on current inputs
  - No memory
- **Sequential Logic:**
  - Output depends on current inputs + past state
  - Has memory

---

## 4. Standard Functional Forms (Canonical)
- **Sum of Products (SOP):**
  - OR of AND terms (minterms)
- **Product of Sums (POS):**
  - AND of OR terms (maxterms)

- **Minterm:**
  - Product including all input variables
- **Maxterm:**
  - Sum including all input variables

---

## 5. Logic Minimization
- Multiple Boolean expressions can represent the same function
- Trade-offs:
  - Cost
  - Speed
  - Power
- Methods:
  - Boolean algebra
  - Karnaugh Maps (K-maps)

---

## 6. Important Combinational Building Blocks

| Block | Function |
|------|--------|
| Decoder | n inputs -> 2^n outputs, one HIGH at a time |
| Multiplexer (MUX) | Selects 1 of N inputs |
| Full Adder | Adds 3 bits -> sum + carry |
| PLA | Implements SOP using AND + OR arrays |
| ALU | Performs arithmetic & logic operations |
| Tri-State Buffer | Output = 0, 1, or Z (high impedance) |

---

## 7. ALU Example Operations
- 000 ->A AND B  
- 001 ->A OR B  
- 010 ->A + B  
- 110 -> A – B  
- 111 -> SLT (set less than)

---

## 8. Moore’s Law & Enabling Technologies
- Transistor count doubles every ~2 years
---

## 9. Power & Performance
- **Dynamic Power:**
  - P = C * V^2 * f
- **Static Power:**
  - P = V * I_leakage
- Series transistors → slower than parallel

---



## Must-Remember Formulas

### Full Adder:
- Sum = A ⊕ B ⊕ Cin  
- Carry_out = AB + ACin + BCin  

### DeMorgan’s Laws:
- (X + Y)' = X' · Y'  
- (X · Y)' = X' + Y'  

### Canonical Forms:
- SOP: F = Σ m(indices where output = 1)
- POS: F = Π M(indices where output = 0)

---

## Common Simplification Theorems
- X + 0 = X  
- X + 1 = 1  
- X + X = X  
- X + X' = 1  
- X · X' = 0  
- X + XY = X (absorption)

---

##  Why CMOS Uses Both nMOS & pMOS
- nMOS:
  - Good at passing 0
  - Weak at passing 1
- pMOS:
  - Good at passing 1
  - Weak at passing 0
- Complementary design:
  - Prevents short circuits
  - Avoids floating outputs

---

##  Logical Completeness
- {AND, OR, NOT} -> complete
- NAND alone -> complete
- NOR alone -> complete

