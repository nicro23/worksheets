	.text
	.globl main
main:
	li	$t1, 0x24681357
	andi 	$t2, $t1, 0xff
	ori	$t3, $t1, 0x00ff0000
	li $v0, 10
	syscall