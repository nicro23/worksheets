	.text
	.globl main
main:
	li $t0, 0x87654321	
	andi $t1, $t0, 0xf
	andi $t2, $t0, 0xf0000000
	srl $t2, $t0, 28
	nor $t3, $t1, $t2
	andi $t4, $t3, 0xf
	li $v0, 10
	syscall