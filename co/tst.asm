.data
n: .word 6
step: .word 0
.text
.globl main
main:
lw $t0, n
li $t1, 0
loop:
addi $t1, $t1, 1
andi $t2, $t0, 1
bne $t2, 0, odd_case
even_case:
div $t0, $t0, 2
j check_end
odd_case:
mul $t0, $t0, 3
addi $t0, $t0, 1
check_end:
bne $t0, 1, loop
sw $t1, step