	.file	"ex1.c"
	.comm	size,4,4
	.section	.rodata
.LC0:
	.string	"aliceinwonderland.txt"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$.LC0, %edi
	call	parser
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.globl	hash
	.type	hash, @function
hash:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	%edx, -32(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L4
.L5:
	movq	-24(%rbp), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	addl	%eax, -8(%rbp)
	addq	$1, -24(%rbp)
.L4:
	movq	-24(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L5
	movl	-8(%rbp), %eax
	cltd
	idivl	-28(%rbp)
	movl	%edx, %eax
	cltd
	idivl	-32(%rbp)
	movl	%edx, -4(%rbp)
	movl	-4(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	hash, .-hash
	.globl	collision_count
	.type	collision_count, @function
collision_count:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$88, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -72(%rbp)
	movl	%esi, -76(%rbp)
	movl	%edx, -80(%rbp)
	movl	%ecx, -84(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	%rsp, %rax
	movq	%rax, %rbx
	movl	-84(%rbp), %eax
	movslq	%eax, %rdx
	subq	$1, %rdx
	movq	%rdx, -40(%rbp)
	movslq	%eax, %rdx
	movq	%rdx, %r10
	movl	$0, %r11d
	movslq	%eax, %rdx
	movq	%rdx, %r8
	movl	$0, %r9d
	cltq
	salq	$2, %rax
	leaq	3(%rax), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %edi
	movl	$0, %edx
	divq	%rdi
	imulq	$16, %rax, %rax
	subq	%rax, %rsp
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -32(%rbp)
	movl	$0, -56(%rbp)
	jmp	.L8
.L9:
	movq	-32(%rbp), %rax
	movl	-56(%rbp), %edx
	movslq	%edx, %rdx
	movl	$-1, (%rax,%rdx,4)
	addl	$1, -56(%rbp)
.L8:
	movl	-56(%rbp), %eax
	cmpl	-84(%rbp), %eax
	jl	.L9
	movl	$0, -52(%rbp)
	movl	$0, -48(%rbp)
	jmp	.L10
.L13:
	movl	-48(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	-84(%rbp), %edx
	movl	-80(%rbp), %ecx
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	hash
	movl	%eax, -44(%rbp)
	movq	-32(%rbp), %rax
	movl	-44(%rbp), %edx
	movslq	%edx, %rdx
	movl	(%rax,%rdx,4), %eax
	cmpl	$-1, %eax
	jne	.L11
	movq	-32(%rbp), %rax
	movl	-44(%rbp), %edx
	movslq	%edx, %rdx
	movl	$1, (%rax,%rdx,4)
	jmp	.L12
.L11:
	addl	$1, -52(%rbp)
.L12:
	addl	$1, -48(%rbp)
.L10:
	movl	-48(%rbp), %eax
	cmpl	-76(%rbp), %eax
	jl	.L13
	movl	-52(%rbp), %eax
	movq	%rbx, %rsp
	movq	-24(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L15
	call	__stack_chk_fail
.L15:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	collision_count, .-collision_count
	.section	.rodata
.LC1:
	.string	"r"
.LC2:
	.string	"error in opneing file"
.LC3:
	.string	"%[^ \n\t]%*c"
	.text
	.globl	parser
	.type	parser, @function
parser:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$160, %rsp
	movq	%rdi, -152(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-152(%rbp), %rax
	movl	$.LC1, %esi
	movq	%rax, %rdi
	call	fopen
	movq	%rax, -128(%rbp)
	cmpq	$0, -128(%rbp)
	jne	.L17
	movl	$.LC2, %edi
	call	puts
	movl	$1, %edi
	call	exit
.L17:
	movl	$100, %edi
	call	malloc
	movq	%rax, -120(%rbp)
	movl	$100, size(%rip)
	movl	$15, -132(%rbp)
	jmp	.L18
.L19:
	leaq	-112(%rbp), %rdx
	movq	-128(%rbp), %rax
	movl	$.LC3, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_fscanf
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	puts
.L18:
	movl	-132(%rbp), %eax
	leal	-1(%rax), %edx
	movl	%edx, -132(%rbp)
	testl	%eax, %eax
	jne	.L19
	movq	-120(%rbp), %rax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L21
	call	__stack_chk_fail
.L21:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	parser, .-parser
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.10) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
