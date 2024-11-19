	.text
	.globl main
main:
	li $t0, 0x12345678
	andi $t1, $t0, 0xffffff00
	ori $t2, $t1, 0xab
	srl $t3, $t0, 16
	sll $t4, $t0, 16
	or  $t5, $t3, $t4
	syscall
	
