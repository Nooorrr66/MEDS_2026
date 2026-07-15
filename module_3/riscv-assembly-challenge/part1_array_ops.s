.data

array:
.word 12,-5,7,-14,20,0,-3,9,15,-8,2,-1

size:
.word 12

sum_msg:
.asciiz "Sum: "

min_msg:
.asciiz "\nMin: "

max_msg:
.asciiz "\nMax: "

neg_msg:
.asciiz "\nNegative Count: "

sorted_msg:
.asciiz "\nSorted Array: "

.text
main:
    

#---------------------------------
# Print Sum
#---------------------------------

    la a0, array
    la t1, size
    lw a1, 0(t1)

    jal sum_array

    mv t0, a0

    li a0, 4
    la a1, sum_msg
    ecall

    li a0, 1
    mv a1, t0
    ecall


#---------------------------------
# Print Minimum
#---------------------------------

    la a0, array
    la t1, size
    lw a1, 0(t1)

    jal find_min

    mv t0, a0

    li a0, 4
    la a1, min_msg
    ecall

    li a0, 1
    mv a1, t0
    ecall


#---------------------------------
# Print Maximum
#---------------------------------

    la a0, array
    la t1, size
    lw a1, 0(t1)

    jal find_max

    mv t0, a0

    li a0, 4
    la a1, max_msg
    ecall

    li a0, 1
    mv a1, t0
    ecall


#---------------------------------
# Print Negative Count
#---------------------------------

    la a0, array
    la t1, size
    lw a1, 0(t1)

    jal count_negative

    mv t0, a0

    li a0, 4
    la a1, neg_msg
    ecall

    li a0, 1
    mv a1, t0
    ecall
#--------------------------------
# print array
#--------------------------------
    # Sort the array
    la a0, array
    la t1, size
    lw a1, 0(t1)
    jal selection_sort

    # Print "Sorted Array:"
    li a0, 4
    la a1, sorted_msg
    ecall

    # Print the sorted array
    la a0, array
    la t1, size
    lw a1, 0(t1)
    jal print_array

#---------------------------------
# Exit
#---------------------------------

    li a0, 10
    ecall
sum_array:
    addi sp, sp, -16    #stack space
    sw ra, 12(sp)
    sw s0, 8(sp)
    sw s1, 4(sp)
    sw s2, 0(sp)
#initialize prologue
    mv s0, a0    #pointer to array
    li s1, 0     # i=0
    li s2, 0     # sum =0
sum_loop:
    bge s1, a1, sum_done  #checks if the loop is finished
    lw t0, 0(s0)          #load the current element
    add s2, s2, t0        #adds to running sum
    addi s0, s0, 4        #moves to the next array element
    addi s1, s1, 1        #increments

    j sum_loop            #jump back to top

sum_done:
    mv a0, s2             # return value = sum
    lw s2, 0(sp)          #reloading the stack
    lw s1, 4(sp)
    lw s0, 8(sp)
    lw ra, 12(sp)
    addi sp, sp, 16

    ret    
find_max:
    addi sp, sp, -16
    sw ra, 12(sp)
    sw s0, 8(sp)
    sw s1, 4(sp)
    sw s2, 0(sp)

    mv s0, a0
    lw s2, 0(s0)
    li s1, 1
    addi s0, s0, 4
max_loop:
    bge s1, a1, max_done

    lw t0, 0(s0)

    ble t0, s2, skip_max  # if current <= max, don't change max

    mv s2, t0                 # otherwise, new max = current

skip_max:
    addi s0, s0, 4
    addi s1, s1, 1
    j max_loop
max_done:
    mv a0, s2

    lw s2, 0(sp)
    lw s1, 4(sp)
    lw s0, 8(sp)
    lw ra, 12(sp)
    addi sp, sp, 16
    ret

#--------------------
find_min:
    addi sp, sp, -16
    sw ra, 12(sp)
    sw s0, 8(sp)
    sw s1, 4(sp)
    sw s2, 0(sp)

    mv s0, a0
    lw s2, 0(s0)
    li s1, 1
    addi s0, s0, 4
min_loop:
    bge s1, a1, min_done

    lw t0, 0(s0)

    bge t0, s2, skip_min   # if current <= min, don't change min

    mv s2, t0                 # otherwise, new min = current

skip_min:
    addi s0, s0, 4
    addi s1, s1, 1
    j min_loop
min_done:
    mv a0, s2

    lw s2, 0(sp)
    lw s1, 4(sp)
    lw s0, 8(sp)
    lw ra, 12(sp)
    addi sp, sp, 16
    ret
    
#---------------
count_negative:
    addi sp, sp, -16
    sw ra, 12(sp)
    sw s0, 8(sp)
    sw s1, 4(sp)
    sw s2, 0(sp)

    mv s0, a0
    li s2, 0
    li s1, 0
    
neg_loop:
    bge s1, a1, neg_done

    lw t0, 0(s0)

    bge t0, zero, skip_neg

    addi s2, s2, 1

skip_neg:
    addi s0, s0, 4
    addi s1, s1, 1
    j neg_loop
neg_done:
    mv a0, s2

    lw s2, 0(sp)
    lw s1, 4(sp)
    lw s0, 8(sp)
    lw ra, 12(sp)
    addi sp, sp, 16
    ret
    
#bonus selection sort
selection_sort:
    addi sp, sp, -24

    sw ra, 20(sp)
    sw s0, 16(sp)
    sw s1, 12(sp)
    sw s2, 8(sp)
    sw s3, 4(sp)
    sw s4, 0(sp)

    mv s0, a0      # array
    mv s1, a1      # size

    li s2, 0       # i = 0

outer_loop:

    addi t0, s1, -1

    bge s2, t0, sort_done

    mv s4, s2      # min = i

    addi s3, s2, 1 # j = i+1

inner_loop:
    bge s3, s1, swap_elements

    slli t0, s3, 2
    add  t0, s0, t0
    lw   t1, 0(t0)

    slli t2, s4, 2
    add  t2, s0, t2
    lw   t3, 0(t2)

    blt  t1, t3, update_min

continue_inner:
    addi s3, s3, 1
    j inner_loop

update_min:
    mv s4, s3
    j continue_inner
    
    
swap_elements:

    beq s4, s2, next_outer
    slli t0, s2, 2
    add  t0, s0, t0
    #min index cal
    slli t1, s4, 2
    add  t1, s0, t1
    #load values
    lw t2, 0(t0)
    lw t3, 0(t1)
    #swap
    sw t3, 0(t0)
    sw t2, 0(t1)
    
next_outer:
    addi s2, s2, 1
    j outer_loop
    
sort_done:

    lw s4, 0(sp)
    lw s3, 4(sp)
    lw s2, 8(sp)
    lw s1, 12(sp)
    lw s0, 16(sp)
    lw ra, 20(sp)

    addi sp, sp, 24
    ret
print_array:
    
    addi sp, sp, -16

    sw ra, 12(sp)
    sw s0, 8(sp)
    sw s1, 4(sp)
    sw s2, 0(sp)

    mv s0, a0
    mv s2, a1
    li s1, 0

print_loop:
    bge s1, s2, print_done

    lw t0, 0(s0)

    li a0, 1
    mv a1, t0
    ecall

    li a0, 11
    li a1, ' '
    ecall

    addi s0, s0, 4
    addi s1, s1, 1
    j print_loop

print_done:
    li a0, 11
    li a1, '\n'
    ecall

    lw s2, 0(sp)
    lw s1, 4(sp)
    lw s0, 8(sp)
    lw ra, 12(sp)

    addi sp, sp, 16
    ret 
