	.text
	.globl main
main:
	li $t0, 10
	li $t1, 5
	li $t2, 8
	li $t3, 3
	li $t4, 20
	li $t5, 4
	add $t6, $t0, $t1
	sub $t7, $t2, $t3
	mul $t8, $t6, $t7
	div $t4, $t5
	mflo $t9
	add $t9, $t8, $t9
	li $v0 10
	syscall
