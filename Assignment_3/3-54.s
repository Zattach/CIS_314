	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_decode2
	.p2align	4, 0x90
_decode2:                               ## @decode2
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	movl	12(%ebp), %eax
	subl	16(%ebp), %eax
	movl	%eax, %ecx
	andl	$1, %ecx
	negl	%ecx
	imull	8(%ebp), %eax
	xorl	%ecx, %eax
	popl	%ebp
	retl

	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	pushl	%eax
	calll	L1$pb
L1$pb:
	popl	%eax
	subl	$8, %esp
	leal	L_.str-L1$pb(%eax), %esi
	pushl	$-2
	pushl	%esi
	calll	_printf
	addl	$8, %esp
	pushl	$-16
	pushl	%esi
	calll	_printf
	addl	$16, %esp
	xorl	%eax, %eax
	addl	$4, %esp
	popl	%esi
	popl	%ebp
	retl

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d\n"


.subsections_via_symbols
