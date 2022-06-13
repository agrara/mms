	.file	"car.c"
	.text
	.globl	alphaCompare
	.type	alphaCompare, @function
alphaCompare:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$0, -4(%rbp)
	cmpl	$19, -4(%rbp)
	jg	.L2
	movq	-24(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	movq	(%rax,%rdx,8), %rcx
	movq	-32(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	movq	(%rax,%rdx,8), %rax
	cmpq	%rax, %rcx
	ja	.L3
	movq	-24(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	movq	(%rax,%rdx,8), %rax
	testq	%rax, %rax
	je	.L4
	movq	-32(%rbp), %rax
	testq	%rax, %rax
	jne	.L4
.L3:
	movl	$1, %eax
	jmp	.L1
.L4:
	movq	-24(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	movq	(%rax,%rdx,8), %rcx
	movq	-32(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	movq	(%rax,%rdx,8), %rax
	cmpq	%rax, %rcx
	jb	.L6
	movq	-32(%rbp), %rax
	movl	-4(%rbp), %edx
	movslq	%edx, %rdx
	movq	(%rax,%rdx,8), %rax
	testq	%rax, %rax
	je	.L7
	movq	-24(%rbp), %rax
	testq	%rax, %rax
	jne	.L7
.L6:
	movl	$-1, %eax
	jmp	.L1
.L7:
	movl	$0, %eax
	jmp	.L1
.L2:
.L1:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	alphaCompare, .-alphaCompare
	.globl	alphaCompare_r
	.type	alphaCompare_r, @function
alphaCompare_r:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	alphaCompare
	cmpl	$1, %eax
	jne	.L9
	movl	$-1, %eax
	jmp	.L10
.L9:
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	alphaCompare
	cmpl	$-1, %eax
	jne	.L11
	movl	$1, %eax
	jmp	.L10
.L11:
	movl	$0, %eax
.L10:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	alphaCompare_r, .-alphaCompare_r
	.globl	speedCompare
	.type	speedCompare, @function
speedCompare:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movzbl	168(%rax), %edx
	movq	-16(%rbp), %rax
	movzbl	168(%rax), %eax
	cmpb	%al, %dl
	jbe	.L13
	movl	$1, %eax
	jmp	.L14
.L13:
	movq	-16(%rbp), %rax
	movzbl	168(%rax), %edx
	movq	-8(%rbp), %rax
	movzbl	168(%rax), %eax
	cmpb	%al, %dl
	jbe	.L15
	movl	$-1, %eax
	jmp	.L14
.L15:
	movl	$0, %eax
.L14:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	speedCompare, .-speedCompare
	.globl	speedCompare_r
	.type	speedCompare_r, @function
speedCompare_r:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movzbl	168(%rax), %edx
	movq	-16(%rbp), %rax
	movzbl	168(%rax), %eax
	cmpb	%al, %dl
	jnb	.L17
	movl	$1, %eax
	jmp	.L18
.L17:
	movq	-16(%rbp), %rax
	movzbl	168(%rax), %edx
	movq	-8(%rbp), %rax
	movzbl	168(%rax), %eax
	cmpb	%al, %dl
	jnb	.L19
	movl	$-1, %eax
	jmp	.L18
.L19:
	movl	$0, %eax
.L18:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	speedCompare_r, .-speedCompare_r
	.globl	priceCompare
	.type	priceCompare, @function
priceCompare:
.LFB10:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movsd	176(%rax), %xmm0
	movq	-16(%rbp), %rax
	movsd	176(%rax), %xmm1
	subsd	%xmm1, %xmm0
	movq	.LC0(%rip), %xmm1
	andpd	%xmm0, %xmm1
	movsd	.LC1(%rip), %xmm0
	comisd	%xmm1, %xmm0
	jbe	.L31
	movl	$0, %eax
	jmp	.L20
.L31:
	movq	-8(%rbp), %rax
	movsd	176(%rax), %xmm0
	movq	-16(%rbp), %rax
	movsd	176(%rax), %xmm1
	comisd	%xmm1, %xmm0
	jbe	.L32
	movl	$1, %eax
	jmp	.L20
.L32:
	movq	-8(%rbp), %rax
	movsd	176(%rax), %xmm1
	movq	-16(%rbp), %rax
	movsd	176(%rax), %xmm0
	comisd	%xmm1, %xmm0
	jbe	.L33
	movl	$-1, %eax
	jmp	.L20
.L33:
.L20:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	priceCompare, .-priceCompare
	.globl	priceCompare_r
	.type	priceCompare_r, @function
priceCompare_r:
.LFB11:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movsd	176(%rax), %xmm0
	movq	-16(%rbp), %rax
	movsd	176(%rax), %xmm1
	subsd	%xmm1, %xmm0
	movq	.LC0(%rip), %xmm1
	andpd	%xmm0, %xmm1
	movsd	.LC1(%rip), %xmm0
	comisd	%xmm1, %xmm0
	jbe	.L45
	movl	$0, %eax
	jmp	.L34
.L45:
	movq	-8(%rbp), %rax
	movsd	176(%rax), %xmm1
	movq	-16(%rbp), %rax
	movsd	176(%rax), %xmm0
	comisd	%xmm1, %xmm0
	jbe	.L46
	movl	$1, %eax
	jmp	.L34
.L46:
	movq	-8(%rbp), %rax
	movsd	176(%rax), %xmm0
	movq	-16(%rbp), %rax
	movsd	176(%rax), %xmm1
	comisd	%xmm1, %xmm0
	jbe	.L47
	movl	$-1, %eax
	jmp	.L34
.L47:
.L34:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	priceCompare_r, .-priceCompare_r
	.globl	getComparator
	.type	getComparator, @function
getComparator:
.LFB12:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	cmpl	$0, -4(%rbp)
	jle	.L49
	cmpl	$6, -4(%rbp)
	jle	.L50
.L49:
	movl	$0, %eax
	jmp	.L51
.L50:
	cmpl	$6, -4(%rbp)
	ja	.L52
	movl	-4(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L54(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L54(%rip), %rdx
	addq	%rdx, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L54:
	.long	.L52-.L54
	.long	.L59-.L54
	.long	.L58-.L54
	.long	.L57-.L54
	.long	.L56-.L54
	.long	.L55-.L54
	.long	.L53-.L54
	.text
.L59:
	leaq	alphaCompare(%rip), %rax
	jmp	.L51
.L58:
	leaq	alphaCompare_r(%rip), %rax
	jmp	.L51
.L57:
	leaq	speedCompare(%rip), %rax
	jmp	.L51
.L56:
	leaq	speedCompare_r(%rip), %rax
	jmp	.L51
.L55:
	leaq	priceCompare(%rip), %rax
	jmp	.L51
.L53:
	leaq	priceCompare_r(%rip), %rax
	jmp	.L51
.L52:
	movl	$0, %eax
.L51:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	getComparator, .-getComparator
	.globl	carGenerator
	.type	carGenerator, @function
carGenerator:
.LFB13:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	$0, %edi
	call	time@PLT
	movl	%eax, %edi
	call	srand@PLT
	movl	$0, -12(%rbp)
	jmp	.L61
.L65:
	call	rand@PLT
	movslq	%eax, %rdx
	imulq	$1321528399, %rdx, %rdx
	shrq	$32, %rdx
	movl	%edx, %ecx
	sarl	$3, %ecx
	cltd
	subl	%edx, %ecx
	movl	%ecx, %edx
	imull	$26, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	leal	65(%rdx), %eax
	movslq	%eax, %rdx
	movl	-12(%rbp), %eax
	cltq
	imulq	$184, %rax, %rcx
	movq	-24(%rbp), %rax
	addq	%rcx, %rax
	movq	%rdx, (%rax)
	call	rand@PLT
	movslq	%eax, %rdx
	imulq	$-1840700269, %rdx, %rdx
	shrq	$32, %rdx
	addl	%eax, %edx
	movl	%edx, %ecx
	sarl	$2, %ecx
	cltd
	subl	%edx, %ecx
	movl	%ecx, %edx
	movl	%edx, %ecx
	sall	$3, %ecx
	subl	%edx, %ecx
	subl	%ecx, %eax
	movl	%eax, %edx
	leal	3(%rdx), %eax
	movl	%eax, -4(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L62
.L64:
	call	rand@PLT
	movslq	%eax, %rdx
	imulq	$1321528399, %rdx, %rdx
	shrq	$32, %rdx
	movl	%edx, %ecx
	sarl	$3, %ecx
	cltd
	subl	%edx, %ecx
	movl	%ecx, %edx
	imull	$26, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	leal	97(%rdx), %eax
	cltq
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	imulq	$184, %rdx, %rcx
	movq	-24(%rbp), %rdx
	addq	%rcx, %rdx
	movq	%rax, %rcx
	movl	-8(%rbp), %eax
	cltq
	movq	%rcx, (%rdx,%rax,8)
	movl	-4(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -8(%rbp)
	jne	.L63
	movl	-12(%rbp), %eax
	cltq
	imulq	$184, %rax, %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-8(%rbp), %eax
	addl	$1, %eax
	cltq
	movq	$0, (%rdx,%rax,8)
.L63:
	addl	$1, -8(%rbp)
.L62:
	movl	-8(%rbp), %eax
	cmpl	-4(%rbp), %eax
	jl	.L64
	call	rand@PLT
	movslq	%eax, %rdx
	imulq	$42735993, %rdx, %rdx
	shrq	$32, %rdx
	movl	%edx, %ecx
	sarl	%ecx
	cltd
	subl	%edx, %ecx
	movl	%ecx, %edx
	imull	$201, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	movl	%edx, %ecx
	movl	-12(%rbp), %eax
	cltq
	imulq	$184, %rax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	leal	100(%rcx), %edx
	movb	%dl, 168(%rax)
	call	rand@PLT
	movslq	%eax, %rdx
	imulq	$1801439851, %rdx, %rdx
	shrq	$32, %rdx
	movl	%edx, %ecx
	sarl	$22, %ecx
	cltd
	subl	%edx, %ecx
	movl	%ecx, %edx
	imull	$10000000, %edx, %edx
	subl	%edx, %eax
	movl	%eax, %edx
	cvtsi2sdl	%edx, %xmm0
	movl	-12(%rbp), %eax
	cltq
	imulq	$184, %rax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movsd	.LC2(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movsd	%xmm0, 176(%rax)
	addl	$1, -12(%rbp)
.L61:
	cmpl	$9, -12(%rbp)
	jle	.L65
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	carGenerator, .-carGenerator
	.section	.rodata
	.align 16
.LC0:
	.long	4294967295
	.long	2147483647
	.long	0
	.long	0
	.align 8
.LC1:
	.long	1202590843
	.long	1065646817
	.align 8
.LC2:
	.long	0
	.long	1079574528
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
