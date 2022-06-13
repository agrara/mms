	.file	"main.c"
	.text
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"%s %d %lf\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$1872, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-1856(%rbp), %rax
	movq	%rax, %rdi
	call	carGenerator@PLT
	leaq	-1864(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-1864(%rbp), %eax
	movl	%eax, %edi
	call	getComparator@PLT
	movl	$0, -1860(%rbp)
	jmp	.L2
.L3:
	movl	-1860(%rbp), %eax
	cltq
	imulq	$184, %rax, %rax
	addq	%rbp, %rax
	subq	$1680, %rax
	movq	(%rax), %rcx
	movl	-1860(%rbp), %eax
	cltq
	imulq	$184, %rax, %rax
	addq	%rbp, %rax
	subq	$1688, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %edx
	movl	-1860(%rbp), %eax
	cltq
	imulq	$184, %rax, %rax
	addq	%rbp, %rax
	subq	$1856, %rax
	movq	(%rax), %rax
	movq	%rcx, %xmm0
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	addl	$1, -1860(%rbp)
.L2:
	cmpl	$9, -1860(%rbp)
	jle	.L3
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
