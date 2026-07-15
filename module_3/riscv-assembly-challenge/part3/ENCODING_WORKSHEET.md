# Part 3 – Instruction Encoding Worksheet

## 1. R-Type

Instruction:
```
add x5, x6, x7
```

Fields

| Field | Binary |
|-------|---------|
| funct7 | 0000000 |
| rs2 | 00111 |
| rs1 | 00110 |
| funct3 | 000 |
| rd | 00101 |
| opcode | 0110011 |

Binary

```
0000000 00111 00110 000 00101 0110011
```

Hex

```
0x007302B3
```

---

## 2. I-Type

Instruction

```
addi x5, x6, 10
```

Fields

| Field | Binary |
|-------|---------|
| imm | 000000001010 |
| rs1 | 00110 |
| funct3 | 000 |
| rd | 00101 |
| opcode | 0010011 |

Binary

```
000000001010 00110 000 00101 0010011
```

Hex

```
0x00A30293
```

---

## 3. S-Type

Instruction

```
sw x5, 8(x6)
```

Fields

| Field | Binary |
|-------|---------|
| imm[11:5] | 0000000 |
| rs2 | 00101 |
| rs1 | 00110 |
| funct3 | 010 |
| imm[4:0] | 01000 |
| opcode | 0100011 |

Binary

```
0000000 00101 00110 010 01000 0100011
```

Hex

```
0x00532423
```

---

## 4. B-Type

Instruction

```
beq x5, x6, 8
```

Fields

| Field | Binary |
|-------|---------|
| imm | 8 |
| rs2 | 00110 |
| rs1 | 00101 |
| funct3 | 000 |
| opcode | 1100011 |

Hex

```
0x00628463
```

---

## 5. U-Type

Instruction

```
lui x5, 0x12345
```

Fields

| Field | Binary |
|-------|---------|
| imm[31:12] | 00010010001101000101 |
| rd | 00101 |
| opcode | 0110111 |

Hex

```
0x123452B7
```

---

## 6. J-Type

Instruction

```
jal x1, 16
```

Fields

| Field | Binary |
|-------|---------|
| imm | 16 |
| rd | 00001 |
| opcode | 1101111 |

Hex

```
0x010000EF
```
