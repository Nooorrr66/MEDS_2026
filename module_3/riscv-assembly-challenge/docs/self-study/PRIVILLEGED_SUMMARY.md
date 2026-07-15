# RISC-V Privileged ISA (Machine Mode) – One-Page Summary

## Machine Mode (M-Mode)
- Highest privilege level in RISC-V.
- Entered after reset.
- Controls hardware, traps, interrupts, CSRs, and lower privilege modes.

---

# Important Machine CSRs

| CSR | Purpose |
|------|----------|
| `misa` | Reports supported ISA width (RV32/RV64) and extensions |
| `mvendorid` | CPU vendor ID |
| `marchid` | Processor architecture ID |
| `mimpid` | Implementation version |
| `mhartid` | Hardware thread (hart) ID |
| `mstatus` | Current processor state |
| `mtvec` | Trap handler address |
| `medeleg` | Delegate exceptions to S-mode |
| `mideleg` | Delegate interrupts to S-mode |
| `mie` | Interrupt enable bits |
| `mip` | Pending interrupts |
| `mcycle` | Clock cycle counter |
| `minstret` | Retired instruction counter |
| `mcounteren` | Allows lower modes to read counters |
| `mcountinhibit` | Stops selected counters |

---

# `misa`
Contains:
- XLEN (RV32/RV64)
- Supported ISA extensions

Common extension bits:

| Bit | Extension |
|-----|-----------|
| A | Atomic |
| C | Compressed |
| F | Float |
| D | Double Float |
| I | Base ISA |
| M | Multiply/Divide |
| S | Supervisor Mode |
| U | User Mode |
| V | Vector |
| X | Non-standard |

---

# `mstatus`

Main processor status register.

Important fields:

| Field | Purpose |
|--------|----------|
| MIE | Global machine interrupts |
| MPIE | Previous interrupt enable |
| MPP | Previous privilege mode |
| MPRV | Memory accesses use MPP privilege |
| MXR | Executable pages become readable |
| SUM | Supervisor may access User pages |
| FS | Floating-point state |
| VS | Vector state |
| XS | Other extension state |
| SD | Dirty-state summary |
| MBE/SBE/UBE | Endianness control |

---

# Interrupt Stack

Trap Entry:
- Save current interrupt enable into `MPIE`
- Clear `MIE`
- Save previous privilege in `MPP`

`MRET`:
- Restore privilege
- Restore interrupts
- Set `MPIE = 1`

---

# Trap Vector (`mtvec`)

Two modes:

| Mode | Description |
|------|-------------|
| 0 | Direct → all traps go to BASE |
| 1 | Vectored → interrupts go to BASE + 4 × cause |

---

# Exception & Interrupt Delegation

## `medeleg`
Delegates exceptions to Supervisor mode.

## `mideleg`
Delegates interrupts to Supervisor mode.

Without delegation:
```
All traps → Machine Mode
```

With delegation:
```
S/U Mode trap → Supervisor Mode
```

---

# Interrupt Registers

## `mie`
Interrupt Enable bits.

## `mip`
Pending Interrupt bits.

Common interrupt sources:

- MSI – Machine Software Interrupt
- MTI – Machine Timer Interrupt
- MEI – Machine External Interrupt
- SSI/STI/SEI – Supervisor equivalents

Interrupt occurs when:
```
Interrupt Pending
AND
Interrupt Enabled
AND
Global MIE enabled
AND
Not delegated
```

Priority:
```
MEI
MSI
MTI
SEI
SSI
STI
LCOFI
```

---

# Performance Counters

Important counters:

- `mcycle`
- `minstret`
- `mhpmcounter3-31`

Used for:
- Performance analysis
- Profiling
- Benchmarking

---

# `mcounteren`

Allows S/U mode to read:

- cycle
- time
- instret
- performance counters

If disabled:
```
Illegal Instruction Exception
```

---

# `mcountinhibit`

Stops selected counters from incrementing.

Useful for:
- Power saving
- Accurate benchmarking

---

# Extension State (FS / VS / XS)

Possible states:

| Value | Meaning |
|--------|---------|
| Off | Disabled |
| Initial | Default state |
| Clean | Saved, unchanged |
| Dirty | Modified |

If Dirty:
```
OS must save context during context switch.
```

`SD = 1`
→ At least one extension is Dirty.

---

# Memory Privilege Bits

## MPRV
Loads/stores use privilege stored in `MPP`.

## MXR
Allows reading executable pages.

## SUM
Supervisor can access User pages.

---

# Endianness

Instruction fetch:
- Always Little Endian

Data accesses:
Controlled by:

- MBE
- SBE
- UBE

---

# Important Trap Flow

Exception/Interrupt
↓
Save PC (`mepc`)
↓
Save Cause (`mcause`)
↓
Update `mstatus`
↓
Jump to `mtvec`
↓
Handle trap
↓
`MRET`
↓
Resume execution

---

