.data

instructions:
.word 0x007302B3
.word 0x00A30293
.word 0x00532423
.word 0x00628463
.word 0x123452B7
.word 0x010000EF

space: .asciiz " "
newline: .asciiz "\n"

.text
.globl main

main:

    la t0, instructions
    li t1, 6

loop:

    beqz t1, exit

    lw t2, 0(t0)

    # opcode = bits [6:0]
    andi a0, t2, 0x7F
    li a7, 1
    ecall

    la a0, space
    li a7, 4
    ecall

    # rd = bits [11:7]
    srli t3, t2, 7
    andi a0, t3, 0x1F
    li a7, 1
    ecall

    la a0, space
    li a7, 4
    ecall

    # funct3 = bits [14:12]
    srli t3, t2, 12
    andi a0, t3, 0x7
    li a7, 1
    ecall

    la a0, space
    li a7, 4
    ecall

    # rs1 = bits [19:15]
    srli t3, t2, 15
    andi a0, t3, 0x1F
    li a7, 1
    ecall

    la a0, newline
    li a7, 4
    ecall

    addi t0, t0, 4
    addi t1, t1, -1

    j loop

exit:

    li a7, 10
    ecall
