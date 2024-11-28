	.text
	.globl main
main:
	li $t0, 10
	li $t1, 2
	li $t2, 5
	mul $t3, $t1, $t2
	div $t0, $t1
	mflo $t4
	sub $t5, $t3, $t4
	add $t6, $t0, $t5
	li $v0, 10
	syscall 