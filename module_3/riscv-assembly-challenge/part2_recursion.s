.data

n:
.word 1
disk_msg:
.asciiz "Move disk "

from_msg:
.asciiz " from "

to_msg:
.asciiz " to "

newline:
.asciiz "\n"

.text
main:

lw a0, n

li a1, 'A'      # from
li a2, 'C'      # to
li a3, 'B'      # auxiliary

jal hanoi

li a0, 10
ecall
# hanoi(n, from, to, aux)
#
# a0 = n
# a1 = from
# a2 = to
# a3 = aux
hanoi:
addi sp, sp, -20
sw ra, 16(sp)
sw s0, 12(sp)
sw s1, 8(sp)
sw s2, 4(sp)
sw s3, 0(sp)

mv s0, a0 #n
mv s1, a1 # from
mv s2, a2 #to
mv s3, a3 # aux

#base case 
beq s0, zero, hanoi_done
# hanoi(n-1,from ,aux ,to)

addi a0, s0, -1
mv a1, s1
mv a2, s3
mv a3, s2
jal hanoi

#print
# Print "Move disk "
li a0, 4
la a1, disk_msg
ecall

# Print disk number
li a0, 1
mv a1, s0
ecall

# Print " from "
li a0, 4
la a1, from_msg
ecall

# Print source peg
li a0, 11
mv a1, s1
ecall

# Print " to "
li a0, 4
la a1, to_msg
ecall

# Print destination peg
li a0, 11
mv a1, s2
ecall

# New line
li a0, 4
la a1, newline
ecall
 # hanoi(n-1,aux,to,from)
 
addi a0, s0, -1
mv a1, s3
mv a2, s2
mv a3, s1
jal hanoi

hanoi_done:
lw s3, 0(sp)
lw s2, 4(sp)
lw s1, 8(sp)
lw s0, 12(sp)
lw ra, 16(sp)
addi sp, sp, 20
ret
