
bomb：     文件格式 elf32-i386


Disassembly of section .init:

080486f4 <_init>:
 80486f4:	53                   	push   %ebx
 80486f5:	83 ec 08             	sub    $0x8,%esp
 80486f8:	e8 13 02 00 00       	call   8048910 <__x86.get_pc_thunk.bx>
 80486fd:	81 c3 03 39 00 00    	add    $0x3903,%ebx
 8048703:	8b 83 fc ff ff ff    	mov    -0x4(%ebx),%eax
 8048709:	85 c0                	test   %eax,%eax
 804870b:	74 05                	je     8048712 <_init+0x1e>
 804870d:	e8 be 01 00 00       	call   80488d0 <__sprintf_chk@plt+0x10>
 8048712:	83 c4 08             	add    $0x8,%esp
 8048715:	5b                   	pop    %ebx
 8048716:	c3                   	ret    

Disassembly of section .plt:

08048720 <read@plt-0x10>:
 8048720:	ff 35 04 c0 04 08    	pushl  0x804c004
 8048726:	ff 25 08 c0 04 08    	jmp    *0x804c008
 804872c:	00 00                	add    %al,(%eax)
	...

08048730 <read@plt>:
 8048730:	ff 25 0c c0 04 08    	jmp    *0x804c00c
 8048736:	68 00 00 00 00       	push   $0x0
 804873b:	e9 e0 ff ff ff       	jmp    8048720 <_init+0x2c>

08048740 <fflush@plt>:
 8048740:	ff 25 10 c0 04 08    	jmp    *0x804c010
 8048746:	68 08 00 00 00       	push   $0x8
 804874b:	e9 d0 ff ff ff       	jmp    8048720 <_init+0x2c>

08048750 <fgets@plt>:
 8048750:	ff 25 14 c0 04 08    	jmp    *0x804c014
 8048756:	68 10 00 00 00       	push   $0x10
 804875b:	e9 c0 ff ff ff       	jmp    8048720 <_init+0x2c>

08048760 <signal@plt>:
 8048760:	ff 25 18 c0 04 08    	jmp    *0x804c018
 8048766:	68 18 00 00 00       	push   $0x18
 804876b:	e9 b0 ff ff ff       	jmp    8048720 <_init+0x2c>

08048770 <sleep@plt>:
 8048770:	ff 25 1c c0 04 08    	jmp    *0x804c01c
 8048776:	68 20 00 00 00       	push   $0x20
 804877b:	e9 a0 ff ff ff       	jmp    8048720 <_init+0x2c>

08048780 <alarm@plt>:
 8048780:	ff 25 20 c0 04 08    	jmp    *0x804c020
 8048786:	68 28 00 00 00       	push   $0x28
 804878b:	e9 90 ff ff ff       	jmp    8048720 <_init+0x2c>

08048790 <__stack_chk_fail@plt>:
 8048790:	ff 25 24 c0 04 08    	jmp    *0x804c024
 8048796:	68 30 00 00 00       	push   $0x30
 804879b:	e9 80 ff ff ff       	jmp    8048720 <_init+0x2c>

080487a0 <strcpy@plt>:
 80487a0:	ff 25 28 c0 04 08    	jmp    *0x804c028
 80487a6:	68 38 00 00 00       	push   $0x38
 80487ab:	e9 70 ff ff ff       	jmp    8048720 <_init+0x2c>

080487b0 <getenv@plt>:
 80487b0:	ff 25 2c c0 04 08    	jmp    *0x804c02c
 80487b6:	68 40 00 00 00       	push   $0x40
 80487bb:	e9 60 ff ff ff       	jmp    8048720 <_init+0x2c>

080487c0 <puts@plt>:
 80487c0:	ff 25 30 c0 04 08    	jmp    *0x804c030
 80487c6:	68 48 00 00 00       	push   $0x48
 80487cb:	e9 50 ff ff ff       	jmp    8048720 <_init+0x2c>

080487d0 <__memmove_chk@plt>:
 80487d0:	ff 25 34 c0 04 08    	jmp    *0x804c034
 80487d6:	68 50 00 00 00       	push   $0x50
 80487db:	e9 40 ff ff ff       	jmp    8048720 <_init+0x2c>

080487e0 <exit@plt>:
 80487e0:	ff 25 38 c0 04 08    	jmp    *0x804c038
 80487e6:	68 58 00 00 00       	push   $0x58
 80487eb:	e9 30 ff ff ff       	jmp    8048720 <_init+0x2c>

080487f0 <__libc_start_main@plt>:
 80487f0:	ff 25 3c c0 04 08    	jmp    *0x804c03c
 80487f6:	68 60 00 00 00       	push   $0x60
 80487fb:	e9 20 ff ff ff       	jmp    8048720 <_init+0x2c>

08048800 <write@plt>:
 8048800:	ff 25 40 c0 04 08    	jmp    *0x804c040
 8048806:	68 68 00 00 00       	push   $0x68
 804880b:	e9 10 ff ff ff       	jmp    8048720 <_init+0x2c>

08048810 <__isoc99_sscanf@plt>:
 8048810:	ff 25 44 c0 04 08    	jmp    *0x804c044
 8048816:	68 70 00 00 00       	push   $0x70
 804881b:	e9 00 ff ff ff       	jmp    8048720 <_init+0x2c>

08048820 <fopen@plt>:
 8048820:	ff 25 48 c0 04 08    	jmp    *0x804c048
 8048826:	68 78 00 00 00       	push   $0x78
 804882b:	e9 f0 fe ff ff       	jmp    8048720 <_init+0x2c>

08048830 <__errno_location@plt>:
 8048830:	ff 25 4c c0 04 08    	jmp    *0x804c04c
 8048836:	68 80 00 00 00       	push   $0x80
 804883b:	e9 e0 fe ff ff       	jmp    8048720 <_init+0x2c>

08048840 <__printf_chk@plt>:
 8048840:	ff 25 50 c0 04 08    	jmp    *0x804c050
 8048846:	68 88 00 00 00       	push   $0x88
 804884b:	e9 d0 fe ff ff       	jmp    8048720 <_init+0x2c>

08048850 <socket@plt>:
 8048850:	ff 25 54 c0 04 08    	jmp    *0x804c054
 8048856:	68 90 00 00 00       	push   $0x90
 804885b:	e9 c0 fe ff ff       	jmp    8048720 <_init+0x2c>

08048860 <__fprintf_chk@plt>:
 8048860:	ff 25 58 c0 04 08    	jmp    *0x804c058
 8048866:	68 98 00 00 00       	push   $0x98
 804886b:	e9 b0 fe ff ff       	jmp    8048720 <_init+0x2c>

08048870 <gethostbyname@plt>:
 8048870:	ff 25 5c c0 04 08    	jmp    *0x804c05c
 8048876:	68 a0 00 00 00       	push   $0xa0
 804887b:	e9 a0 fe ff ff       	jmp    8048720 <_init+0x2c>

08048880 <strtol@plt>:
 8048880:	ff 25 60 c0 04 08    	jmp    *0x804c060
 8048886:	68 a8 00 00 00       	push   $0xa8
 804888b:	e9 90 fe ff ff       	jmp    8048720 <_init+0x2c>

08048890 <connect@plt>:
 8048890:	ff 25 64 c0 04 08    	jmp    *0x804c064
 8048896:	68 b0 00 00 00       	push   $0xb0
 804889b:	e9 80 fe ff ff       	jmp    8048720 <_init+0x2c>

080488a0 <close@plt>:
 80488a0:	ff 25 68 c0 04 08    	jmp    *0x804c068
 80488a6:	68 b8 00 00 00       	push   $0xb8
 80488ab:	e9 70 fe ff ff       	jmp    8048720 <_init+0x2c>

080488b0 <__ctype_b_loc@plt>:
 80488b0:	ff 25 6c c0 04 08    	jmp    *0x804c06c
 80488b6:	68 c0 00 00 00       	push   $0xc0
 80488bb:	e9 60 fe ff ff       	jmp    8048720 <_init+0x2c>

080488c0 <__sprintf_chk@plt>:
 80488c0:	ff 25 70 c0 04 08    	jmp    *0x804c070
 80488c6:	68 c8 00 00 00       	push   $0xc8
 80488cb:	e9 50 fe ff ff       	jmp    8048720 <_init+0x2c>

Disassembly of section .plt.got:

080488d0 <.plt.got>:
 80488d0:	ff 25 fc bf 04 08    	jmp    *0x804bffc
 80488d6:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

080488e0 <_start>:
 80488e0:	31 ed                	xor    %ebp,%ebp
 80488e2:	5e                   	pop    %esi
 80488e3:	89 e1                	mov    %esp,%ecx
 80488e5:	83 e4 f0             	and    $0xfffffff0,%esp
 80488e8:	50                   	push   %eax
 80488e9:	54                   	push   %esp
 80488ea:	52                   	push   %edx
 80488eb:	68 e0 9e 04 08       	push   $0x8049ee0
 80488f0:	68 80 9e 04 08       	push   $0x8049e80
 80488f5:	51                   	push   %ecx
 80488f6:	56                   	push   %esi
 80488f7:	68 db 89 04 08       	push   $0x80489db
 80488fc:	e8 ef fe ff ff       	call   80487f0 <__libc_start_main@plt>
 8048901:	f4                   	hlt    
 8048902:	66 90                	xchg   %ax,%ax
 8048904:	66 90                	xchg   %ax,%ax
 8048906:	66 90                	xchg   %ax,%ax
 8048908:	66 90                	xchg   %ax,%ax
 804890a:	66 90                	xchg   %ax,%ax
 804890c:	66 90                	xchg   %ax,%ax
 804890e:	66 90                	xchg   %ax,%ax

08048910 <__x86.get_pc_thunk.bx>:
 8048910:	8b 1c 24             	mov    (%esp),%ebx
 8048913:	c3                   	ret    
 8048914:	66 90                	xchg   %ax,%ax
 8048916:	66 90                	xchg   %ax,%ax
 8048918:	66 90                	xchg   %ax,%ax
 804891a:	66 90                	xchg   %ax,%ax
 804891c:	66 90                	xchg   %ax,%ax
 804891e:	66 90                	xchg   %ax,%ax

08048920 <deregister_tm_clones>:
 8048920:	b8 a3 c3 04 08       	mov    $0x804c3a3,%eax
 8048925:	2d a0 c3 04 08       	sub    $0x804c3a0,%eax
 804892a:	83 f8 06             	cmp    $0x6,%eax
 804892d:	76 1a                	jbe    8048949 <deregister_tm_clones+0x29>
 804892f:	b8 00 00 00 00       	mov    $0x0,%eax
 8048934:	85 c0                	test   %eax,%eax
 8048936:	74 11                	je     8048949 <deregister_tm_clones+0x29>
 8048938:	55                   	push   %ebp
 8048939:	89 e5                	mov    %esp,%ebp
 804893b:	83 ec 14             	sub    $0x14,%esp
 804893e:	68 a0 c3 04 08       	push   $0x804c3a0
 8048943:	ff d0                	call   *%eax
 8048945:	83 c4 10             	add    $0x10,%esp
 8048948:	c9                   	leave  
 8048949:	f3 c3                	repz ret 
 804894b:	90                   	nop
 804894c:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi

08048950 <register_tm_clones>:
 8048950:	b8 a0 c3 04 08       	mov    $0x804c3a0,%eax
 8048955:	2d a0 c3 04 08       	sub    $0x804c3a0,%eax
 804895a:	c1 f8 02             	sar    $0x2,%eax
 804895d:	89 c2                	mov    %eax,%edx
 804895f:	c1 ea 1f             	shr    $0x1f,%edx
 8048962:	01 d0                	add    %edx,%eax
 8048964:	d1 f8                	sar    %eax
 8048966:	74 1b                	je     8048983 <register_tm_clones+0x33>
 8048968:	ba 00 00 00 00       	mov    $0x0,%edx
 804896d:	85 d2                	test   %edx,%edx
 804896f:	74 12                	je     8048983 <register_tm_clones+0x33>
 8048971:	55                   	push   %ebp
 8048972:	89 e5                	mov    %esp,%ebp
 8048974:	83 ec 10             	sub    $0x10,%esp
 8048977:	50                   	push   %eax
 8048978:	68 a0 c3 04 08       	push   $0x804c3a0
 804897d:	ff d2                	call   *%edx
 804897f:	83 c4 10             	add    $0x10,%esp
 8048982:	c9                   	leave  
 8048983:	f3 c3                	repz ret 
 8048985:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
 8048989:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

08048990 <__do_global_dtors_aux>:
 8048990:	80 3d c8 c3 04 08 00 	cmpb   $0x0,0x804c3c8
 8048997:	75 13                	jne    80489ac <__do_global_dtors_aux+0x1c>
 8048999:	55                   	push   %ebp
 804899a:	89 e5                	mov    %esp,%ebp
 804899c:	83 ec 08             	sub    $0x8,%esp
 804899f:	e8 7c ff ff ff       	call   8048920 <deregister_tm_clones>
 80489a4:	c6 05 c8 c3 04 08 01 	movb   $0x1,0x804c3c8
 80489ab:	c9                   	leave  
 80489ac:	f3 c3                	repz ret 
 80489ae:	66 90                	xchg   %ax,%ax

080489b0 <frame_dummy>:
 80489b0:	b8 10 bf 04 08       	mov    $0x804bf10,%eax
 80489b5:	8b 10                	mov    (%eax),%edx
 80489b7:	85 d2                	test   %edx,%edx
 80489b9:	75 05                	jne    80489c0 <frame_dummy+0x10>
 80489bb:	eb 93                	jmp    8048950 <register_tm_clones>
 80489bd:	8d 76 00             	lea    0x0(%esi),%esi
 80489c0:	ba 00 00 00 00       	mov    $0x0,%edx
 80489c5:	85 d2                	test   %edx,%edx
 80489c7:	74 f2                	je     80489bb <frame_dummy+0xb>
 80489c9:	55                   	push   %ebp
 80489ca:	89 e5                	mov    %esp,%ebp
 80489cc:	83 ec 14             	sub    $0x14,%esp
 80489cf:	50                   	push   %eax
 80489d0:	ff d2                	call   *%edx
 80489d2:	83 c4 10             	add    $0x10,%esp
 80489d5:	c9                   	leave  
 80489d6:	e9 75 ff ff ff       	jmp    8048950 <register_tm_clones>

080489db <main>:
 80489db:	8d 4c 24 04          	lea    0x4(%esp),%ecx
 80489df:	83 e4 f0             	and    $0xfffffff0,%esp
 80489e2:	ff 71 fc             	pushl  -0x4(%ecx)
 80489e5:	55                   	push   %ebp
 80489e6:	89 e5                	mov    %esp,%ebp
 80489e8:	53                   	push   %ebx
 80489e9:	51                   	push   %ecx
 80489ea:	8b 01                	mov    (%ecx),%eax
 80489ec:	8b 59 04             	mov    0x4(%ecx),%ebx
 80489ef:	83 f8 01             	cmp    $0x1,%eax
 80489f2:	0f 84 01 01 00 00    	je     8048af9 <main+0x11e>
 80489f8:	83 f8 02             	cmp    $0x2,%eax
 80489fb:	0f 85 24 01 00 00    	jne    8048b25 <main+0x14a>
 8048a01:	83 ec 08             	sub    $0x8,%esp
 8048a04:	68 08 9f 04 08       	push   $0x8049f08
 8048a09:	ff 73 04             	pushl  0x4(%ebx)
 8048a0c:	e8 0f fe ff ff       	call   8048820 <fopen@plt>
 8048a11:	a3 d0 c3 04 08       	mov    %eax,0x804c3d0
 8048a16:	83 c4 10             	add    $0x10,%esp
 8048a19:	85 c0                	test   %eax,%eax
 8048a1b:	0f 84 e7 00 00 00    	je     8048b08 <main+0x12d>
 8048a21:	e8 7b 06 00 00       	call   80490a1 <initialize_bomb>
 8048a26:	83 ec 0c             	sub    $0xc,%esp
 8048a29:	68 8c 9f 04 08       	push   $0x8049f8c
 8048a2e:	e8 8d fd ff ff       	call   80487c0 <puts@plt>
 8048a33:	c7 04 24 c8 9f 04 08 	movl   $0x8049fc8,(%esp)
 8048a3a:	e8 81 fd ff ff       	call   80487c0 <puts@plt>
 8048a3f:	e8 4d 07 00 00       	call   8049191 <read_line>
 8048a44:	89 04 24             	mov    %eax,(%esp)
 8048a47:	e8 f6 00 00 00       	call   8048b42 <phase_1>
 8048a4c:	e8 3f 08 00 00       	call   8049290 <phase_defused>
 8048a51:	c7 04 24 f4 9f 04 08 	movl   $0x8049ff4,(%esp)
 8048a58:	e8 63 fd ff ff       	call   80487c0 <puts@plt>
 8048a5d:	e8 2f 07 00 00       	call   8049191 <read_line>
 8048a62:	89 04 24             	mov    %eax,(%esp)
 8048a65:	e8 fb 00 00 00       	call   8048b65 <phase_2>
 8048a6a:	e8 21 08 00 00       	call   8049290 <phase_defused>
 8048a6f:	c7 04 24 41 9f 04 08 	movl   $0x8049f41,(%esp)
 8048a76:	e8 45 fd ff ff       	call   80487c0 <puts@plt>
 8048a7b:	e8 11 07 00 00       	call   8049191 <read_line>
 8048a80:	89 04 24             	mov    %eax,(%esp)
 8048a83:	e8 44 01 00 00       	call   8048bcc <phase_3>
 8048a88:	e8 03 08 00 00       	call   8049290 <phase_defused>
 8048a8d:	c7 04 24 5f 9f 04 08 	movl   $0x8049f5f,(%esp)
 8048a94:	e8 27 fd ff ff       	call   80487c0 <puts@plt>
 8048a99:	e8 f3 06 00 00       	call   8049191 <read_line>
 8048a9e:	89 04 24             	mov    %eax,(%esp)
 8048aa1:	e8 5e 02 00 00       	call   8048d04 <phase_4>
 8048aa6:	e8 e5 07 00 00       	call   8049290 <phase_defused>
 8048aab:	c7 04 24 20 a0 04 08 	movl   $0x804a020,(%esp)
 8048ab2:	e8 09 fd ff ff       	call   80487c0 <puts@plt>
 8048ab7:	e8 d5 06 00 00       	call   8049191 <read_line>
 8048abc:	89 04 24             	mov    %eax,(%esp)
 8048abf:	e8 b9 02 00 00       	call   8048d7d <phase_5>
 8048ac4:	e8 c7 07 00 00       	call   8049290 <phase_defused>
 8048ac9:	c7 04 24 6e 9f 04 08 	movl   $0x8049f6e,(%esp)
 8048ad0:	e8 eb fc ff ff       	call   80487c0 <puts@plt>
 8048ad5:	e8 b7 06 00 00       	call   8049191 <read_line>
 8048ada:	89 04 24             	mov    %eax,(%esp)
 8048add:	e8 2a 03 00 00       	call   8048e0c <phase_6>
 8048ae2:	e8 a9 07 00 00       	call   8049290 <phase_defused>
 8048ae7:	83 c4 10             	add    $0x10,%esp
 8048aea:	b8 00 00 00 00       	mov    $0x0,%eax
 8048aef:	8d 65 f8             	lea    -0x8(%ebp),%esp
 8048af2:	59                   	pop    %ecx
 8048af3:	5b                   	pop    %ebx
 8048af4:	5d                   	pop    %ebp
 8048af5:	8d 61 fc             	lea    -0x4(%ecx),%esp
 8048af8:	c3                   	ret    
 8048af9:	a1 c0 c3 04 08       	mov    0x804c3c0,%eax
 8048afe:	a3 d0 c3 04 08       	mov    %eax,0x804c3d0
 8048b03:	e9 19 ff ff ff       	jmp    8048a21 <main+0x46>
 8048b08:	ff 73 04             	pushl  0x4(%ebx)
 8048b0b:	ff 33                	pushl  (%ebx)
 8048b0d:	68 0a 9f 04 08       	push   $0x8049f0a
 8048b12:	6a 01                	push   $0x1
 8048b14:	e8 27 fd ff ff       	call   8048840 <__printf_chk@plt>
 8048b19:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 8048b20:	e8 bb fc ff ff       	call   80487e0 <exit@plt>
 8048b25:	83 ec 04             	sub    $0x4,%esp
 8048b28:	ff 33                	pushl  (%ebx)
 8048b2a:	68 27 9f 04 08       	push   $0x8049f27
 8048b2f:	6a 01                	push   $0x1
 8048b31:	e8 0a fd ff ff       	call   8048840 <__printf_chk@plt>
 8048b36:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 8048b3d:	e8 9e fc ff ff       	call   80487e0 <exit@plt>

08048b42 <phase_1>:
 8048b42:	83 ec 14             	sub    $0x14,%esp
 8048b45:	68 44 a0 04 08       	push   $0x804a044
 8048b4a:	ff 74 24 1c          	pushl  0x1c(%esp)
 8048b4e:	e8 e9 04 00 00       	call   804903c <strings_not_equal>
 8048b53:	83 c4 10             	add    $0x10,%esp
 8048b56:	85 c0                	test   %eax,%eax
 8048b58:	75 04                	jne    8048b5e <phase_1+0x1c>
 8048b5a:	83 c4 0c             	add    $0xc,%esp
 8048b5d:	c3                   	ret    
 8048b5e:	e8 ce 05 00 00       	call   8049131 <explode_bomb>
 8048b63:	eb f5                	jmp    8048b5a <phase_1+0x18>

08048b65 <phase_2>:
 8048b65:	53                   	push   %ebx
 8048b66:	83 ec 30             	sub    $0x30,%esp
 8048b69:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 8048b6f:	89 44 24 24          	mov    %eax,0x24(%esp)
 8048b73:	31 c0                	xor    %eax,%eax
 8048b75:	8d 44 24 0c          	lea    0xc(%esp),%eax
 8048b79:	50                   	push   %eax
 8048b7a:	ff 74 24 3c          	pushl  0x3c(%esp)
 8048b7e:	e8 d3 05 00 00       	call   8049156 <read_six_numbers>
 8048b83:	83 c4 10             	add    $0x10,%esp
 8048b86:	83 7c 24 04 00       	cmpl   $0x0,0x4(%esp)
 8048b8b:	78 07                	js     8048b94 <phase_2+0x2f>
 8048b8d:	bb 01 00 00 00       	mov    $0x1,%ebx
 8048b92:	eb 0f                	jmp    8048ba3 <phase_2+0x3e>
 8048b94:	e8 98 05 00 00       	call   8049131 <explode_bomb>
 8048b99:	eb f2                	jmp    8048b8d <phase_2+0x28>
 8048b9b:	83 c3 01             	add    $0x1,%ebx
 8048b9e:	83 fb 06             	cmp    $0x6,%ebx
 8048ba1:	74 12                	je     8048bb5 <phase_2+0x50>
 8048ba3:	89 d8                	mov    %ebx,%eax
 8048ba5:	03 04 9c             	add    (%esp,%ebx,4),%eax
 8048ba8:	39 44 9c 04          	cmp    %eax,0x4(%esp,%ebx,4)
 8048bac:	74 ed                	je     8048b9b <phase_2+0x36>
 8048bae:	e8 7e 05 00 00       	call   8049131 <explode_bomb>
 8048bb3:	eb e6                	jmp    8048b9b <phase_2+0x36>
 8048bb5:	8b 44 24 1c          	mov    0x1c(%esp),%eax
 8048bb9:	65 33 05 14 00 00 00 	xor    %gs:0x14,%eax
 8048bc0:	75 05                	jne    8048bc7 <phase_2+0x62>
 8048bc2:	83 c4 28             	add    $0x28,%esp
 8048bc5:	5b                   	pop    %ebx
 8048bc6:	c3                   	ret    
 8048bc7:	e8 c4 fb ff ff       	call   8048790 <__stack_chk_fail@plt>

08048bcc <phase_3>:
 8048bcc:	83 ec 1c             	sub    $0x1c,%esp
 8048bcf:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax  
 8048bd5:	89 44 24 0c          	mov    %eax,0xc(%esp)
 8048bd9:	31 c0                	xor    %eax,%eax
 8048bdb:	8d 44 24 08          	lea    0x8(%esp),%eax
 8048bdf:	50                   	push   %eax
 8048be0:	8d 44 24 08          	lea    0x8(%esp),%eax
 8048be4:	50                   	push   %eax
 8048be5:	68 0f a2 04 08       	push   $0x804a20f
 8048bea:	ff 74 24 2c          	pushl  0x2c(%esp)
 8048bee:	e8 1d fc ff ff       	call   8048810 <__isoc99_sscanf@plt>
 8048bf3:	83 c4 10             	add    $0x10,%esp
 8048bf6:	83 f8 01             	cmp    $0x1,%eax
 8048bf9:	7e 16                	jle    8048c11 <phase_3+0x45>
 8048bfb:	83 7c 24 04 07       	cmpl   $0x7,0x4(%esp)
 8048c00:	0f 87 8e 00 00 00    	ja     8048c94 <phase_3+0xc8>
 8048c06:	8b 44 24 04          	mov    0x4(%esp),%eax
 8048c0a:	ff 24 85 a0 a0 04 08 	jmp    *0x804a0a0(,%eax,4)
 8048c11:	e8 1b 05 00 00       	call   8049131 <explode_bomb>
 8048c16:	eb e3                	jmp    8048bfb <phase_3+0x2f>
 8048c18:	b8 3b 00 00 00       	mov    $0x3b,%eax
 8048c1d:	eb 05                	jmp    8048c24 <phase_3+0x58>
 8048c1f:	b8 00 00 00 00       	mov    $0x0,%eax
 8048c24:	2d 9d 00 00 00       	sub    $0x9d,%eax
 8048c29:	05 fd 00 00 00       	add    $0xfd,%eax
 8048c2e:	2d ba 00 00 00       	sub    $0xba,%eax
 8048c33:	05 ba 00 00 00       	add    $0xba,%eax
 8048c38:	2d ba 00 00 00       	sub    $0xba,%eax
 8048c3d:	05 ba 00 00 00       	add    $0xba,%eax
 8048c42:	2d ba 00 00 00       	sub    $0xba,%eax
 8048c47:	83 7c 24 04 05       	cmpl   $0x5,0x4(%esp)
 8048c4c:	7f 06                	jg     8048c54 <phase_3+0x88>
 8048c4e:	3b 44 24 08          	cmp    0x8(%esp),%eax
 8048c52:	74 05                	je     8048c59 <phase_3+0x8d>
 8048c54:	e8 d8 04 00 00       	call   8049131 <explode_bomb>
 8048c59:	8b 44 24 0c          	mov    0xc(%esp),%eax
 8048c5d:	65 33 05 14 00 00 00 	xor    %gs:0x14,%eax
 8048c64:	75 3a                	jne    8048ca0 <phase_3+0xd4>
 8048c66:	83 c4 1c             	add    $0x1c,%esp
 8048c69:	c3                   	ret    
 8048c6a:	b8 00 00 00 00       	mov    $0x0,%eax
 8048c6f:	eb b8                	jmp    8048c29 <phase_3+0x5d>
 8048c71:	b8 00 00 00 00       	mov    $0x0,%eax
 8048c76:	eb b6                	jmp    8048c2e <phase_3+0x62>
 8048c78:	b8 00 00 00 00       	mov    $0x0,%eax
 8048c7d:	eb b4                	jmp    8048c33 <phase_3+0x67>
 8048c7f:	b8 00 00 00 00       	mov    $0x0,%eax
 8048c84:	eb b2                	jmp    8048c38 <phase_3+0x6c>
 8048c86:	b8 00 00 00 00       	mov    $0x0,%eax
 8048c8b:	eb b0                	jmp    8048c3d <phase_3+0x71>
 8048c8d:	b8 00 00 00 00       	mov    $0x0,%eax
 8048c92:	eb ae                	jmp    8048c42 <phase_3+0x76>
 8048c94:	e8 98 04 00 00       	call   8049131 <explode_bomb>
 8048c99:	b8 00 00 00 00       	mov    $0x0,%eax
 8048c9e:	eb a7                	jmp    8048c47 <phase_3+0x7b>
 8048ca0:	e8 eb fa ff ff       	call   8048790 <__stack_chk_fail@plt>

08048ca5 <func4>:
 8048ca5:	56                   	push   %esi
 8048ca6:	53                   	push   %ebx
 8048ca7:	83 ec 04             	sub    $0x4,%esp
 8048caa:	8b 4c 24 10          	mov    0x10(%esp),%ecx
 8048cae:	8b 44 24 14          	mov    0x14(%esp),%eax
 8048cb2:	8b 5c 24 18          	mov    0x18(%esp),%ebx
 8048cb6:	89 de                	mov    %ebx,%esi
 8048cb8:	29 c6                	sub    %eax,%esi
 8048cba:	89 f2                	mov    %esi,%edx
 8048cbc:	c1 ea 1f             	shr    $0x1f,%edx
 8048cbf:	01 f2                	add    %esi,%edx
 8048cc1:	d1 fa                	sar    %edx
 8048cc3:	01 c2                	add    %eax,%edx
 8048cc5:	39 ca                	cmp    %ecx,%edx
 8048cc7:	7f 0f                	jg     8048cd8 <func4+0x33>
 8048cc9:	b8 00 00 00 00       	mov    $0x0,%eax
 8048cce:	39 ca                	cmp    %ecx,%edx
 8048cd0:	7c 1b                	jl     8048ced <func4+0x48>
 8048cd2:	83 c4 04             	add    $0x4,%esp
 8048cd5:	5b                   	pop    %ebx
 8048cd6:	5e                   	pop    %esi
 8048cd7:	c3                   	ret    
 8048cd8:	83 ec 04             	sub    $0x4,%esp
 8048cdb:	83 ea 01             	sub    $0x1,%edx
 8048cde:	52                   	push   %edx
 8048cdf:	50                   	push   %eax
 8048ce0:	51                   	push   %ecx
 8048ce1:	e8 bf ff ff ff       	call   8048ca5 <func4>
 8048ce6:	83 c4 10             	add    $0x10,%esp
 8048ce9:	01 c0                	add    %eax,%eax
 8048ceb:	eb e5                	jmp    8048cd2 <func4+0x2d>
 8048ced:	83 ec 04             	sub    $0x4,%esp
 8048cf0:	53                   	push   %ebx
 8048cf1:	83 c2 01             	add    $0x1,%edx
 8048cf4:	52                   	push   %edx
 8048cf5:	51                   	push   %ecx
 8048cf6:	e8 aa ff ff ff       	call   8048ca5 <func4>
 8048cfb:	83 c4 10             	add    $0x10,%esp
 8048cfe:	8d 44 00 01          	lea    0x1(%eax,%eax,1),%eax
 8048d02:	eb ce                	jmp    8048cd2 <func4+0x2d>

08048d04 <phase_4>:
 8048d04:	83 ec 1c             	sub    $0x1c,%esp
 8048d07:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 8048d0d:	89 44 24 0c          	mov    %eax,0xc(%esp)
 8048d11:	31 c0                	xor    %eax,%eax
 8048d13:	8d 44 24 08          	lea    0x8(%esp),%eax
 8048d17:	50                   	push   %eax
 8048d18:	8d 44 24 08          	lea    0x8(%esp),%eax
 8048d1c:	50                   	push   %eax
 8048d1d:	68 0f a2 04 08       	push   $0x804a20f
 8048d22:	ff 74 24 2c          	pushl  0x2c(%esp)
 8048d26:	e8 e5 fa ff ff       	call   8048810 <__isoc99_sscanf@plt>
 8048d2b:	83 c4 10             	add    $0x10,%esp
 8048d2e:	83 f8 02             	cmp    $0x2,%eax
 8048d31:	74 33                	je     8048d66 <phase_4+0x62>
 8048d33:	e8 f9 03 00 00       	call   8049131 <explode_bomb>
 8048d38:	83 ec 04             	sub    $0x4,%esp
 8048d3b:	6a 0e                	push   $0xe
 8048d3d:	6a 00                	push   $0x0
 8048d3f:	ff 74 24 10          	pushl  0x10(%esp)
 8048d43:	e8 5d ff ff ff       	call   8048ca5 <func4>
 8048d48:	83 c4 10             	add    $0x10,%esp
 8048d4b:	83 f8 02             	cmp    $0x2,%eax
 8048d4e:	74 1f                	je     8048d6f <phase_4+0x6b>
 8048d50:	e8 dc 03 00 00       	call   8049131 <explode_bomb>
 8048d55:	8b 44 24 0c          	mov    0xc(%esp),%eax
 8048d59:	65 33 05 14 00 00 00 	xor    %gs:0x14,%eax
 8048d60:	75 16                	jne    8048d78 <phase_4+0x74>
 8048d62:	83 c4 1c             	add    $0x1c,%esp
 8048d65:	c3                   	ret    
 8048d66:	83 7c 24 04 0e       	cmpl   $0xe,0x4(%esp)
 8048d6b:	76 cb                	jbe    8048d38 <phase_4+0x34>
 8048d6d:	eb c4                	jmp    8048d33 <phase_4+0x2f>
 8048d6f:	83 7c 24 08 02       	cmpl   $0x2,0x8(%esp)
 8048d74:	75 da                	jne    8048d50 <phase_4+0x4c>
 8048d76:	eb dd                	jmp    8048d55 <phase_4+0x51>
 8048d78:	e8 13 fa ff ff       	call   8048790 <__stack_chk_fail@plt>

08048d7d <phase_5>:
 8048d7d:	83 ec 1c             	sub    $0x1c,%esp
 8048d80:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 8048d86:	89 44 24 0c          	mov    %eax,0xc(%esp)
 8048d8a:	31 c0                	xor    %eax,%eax
 8048d8c:	8d 44 24 08          	lea    0x8(%esp),%eax
 8048d90:	50                   	push   %eax
 8048d91:	8d 44 24 08          	lea    0x8(%esp),%eax
 8048d95:	50                   	push   %eax
 8048d96:	68 0f a2 04 08       	push   $0x804a20f
 8048d9b:	ff 74 24 2c          	pushl  0x2c(%esp)
 8048d9f:	e8 6c fa ff ff       	call   8048810 <__isoc99_sscanf@plt>
 8048da4:	83 c4 10             	add    $0x10,%esp
 8048da7:	83 f8 01             	cmp    $0x1,%eax
 8048daa:	7e 54                	jle    8048e00 <phase_5+0x83>
 8048dac:	8b 44 24 04          	mov    0x4(%esp),%eax
 8048db0:	83 e0 0f             	and    $0xf,%eax
 8048db3:	89 44 24 04          	mov    %eax,0x4(%esp)
 8048db7:	83 f8 0f             	cmp    $0xf,%eax
 8048dba:	74 2e                	je     8048dea <phase_5+0x6d>
 8048dbc:	b9 00 00 00 00       	mov    $0x0,%ecx
 8048dc1:	ba 00 00 00 00       	mov    $0x0,%edx
 8048dc6:	83 c2 01             	add    $0x1,%edx
 8048dc9:	8b 04 85 c0 a0 04 08 	mov    0x804a0c0(,%eax,4),%eax
 8048dd0:	01 c1                	add    %eax,%ecx
 8048dd2:	83 f8 0f             	cmp    $0xf,%eax
 8048dd5:	75 ef                	jne    8048dc6 <phase_5+0x49>
 8048dd7:	c7 44 24 04 0f 00 00 	movl   $0xf,0x4(%esp)
 8048dde:	00 
 8048ddf:	83 fa 0f             	cmp    $0xf,%edx
 8048de2:	75 06                	jne    8048dea <phase_5+0x6d>
 8048de4:	3b 4c 24 08          	cmp    0x8(%esp),%ecx
 8048de8:	74 05                	je     8048def <phase_5+0x72>
 8048dea:	e8 42 03 00 00       	call   8049131 <explode_bomb>
 8048def:	8b 44 24 0c          	mov    0xc(%esp),%eax
 8048df3:	65 33 05 14 00 00 00 	xor    %gs:0x14,%eax
 8048dfa:	75 0b                	jne    8048e07 <phase_5+0x8a>
 8048dfc:	83 c4 1c             	add    $0x1c,%esp
 8048dff:	c3                   	ret    
 8048e00:	e8 2c 03 00 00       	call   8049131 <explode_bomb>
 8048e05:	eb a5                	jmp    8048dac <phase_5+0x2f>
 8048e07:	e8 84 f9 ff ff       	call   8048790 <__stack_chk_fail@plt>

08048e0c <phase_6>:
 8048e0c:	56                   	push   %esi
 8048e0d:	53                   	push   %ebx
 8048e0e:	83 ec 4c             	sub    $0x4c,%esp
 8048e11:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 8048e17:	89 44 24 44          	mov    %eax,0x44(%esp)
 8048e1b:	31 c0                	xor    %eax,%eax
 8048e1d:	8d 44 24 14          	lea    0x14(%esp),%eax
 8048e21:	50                   	push   %eax
 8048e22:	ff 74 24 5c          	pushl  0x5c(%esp)
 8048e26:	e8 2b 03 00 00       	call   8049156 <read_six_numbers>
 8048e2b:	83 c4 10             	add    $0x10,%esp
 8048e2e:	be 00 00 00 00       	mov    $0x0,%esi
 8048e33:	eb 1c                	jmp    8048e51 <phase_6+0x45>
 8048e35:	83 c6 01             	add    $0x1,%esi
 8048e38:	83 fe 06             	cmp    $0x6,%esi
 8048e3b:	74 2e                	je     8048e6b <phase_6+0x5f>
 8048e3d:	89 f3                	mov    %esi,%ebx
 8048e3f:	8b 44 9c 0c          	mov    0xc(%esp,%ebx,4),%eax
 8048e43:	39 44 b4 08          	cmp    %eax,0x8(%esp,%esi,4)
 8048e47:	74 1b                	je     8048e64 <phase_6+0x58>
 8048e49:	83 c3 01             	add    $0x1,%ebx
 8048e4c:	83 fb 05             	cmp    $0x5,%ebx
 8048e4f:	7e ee                	jle    8048e3f <phase_6+0x33>
 8048e51:	8b 44 b4 0c          	mov    0xc(%esp,%esi,4),%eax
 8048e55:	83 e8 01             	sub    $0x1,%eax
 8048e58:	83 f8 05             	cmp    $0x5,%eax
 8048e5b:	76 d8                	jbe    8048e35 <phase_6+0x29>
 8048e5d:	e8 cf 02 00 00       	call   8049131 <explode_bomb>
 8048e62:	eb d1                	jmp    8048e35 <phase_6+0x29>
 8048e64:	e8 c8 02 00 00       	call   8049131 <explode_bomb>
 8048e69:	eb de                	jmp    8048e49 <phase_6+0x3d>
 ////////////////////////
 8048e6b:	bb 00 00 00 00       	mov    $0x0,%ebx
 8048e70:	89 de                	mov    %ebx,%esi
 8048e72:	8b 4c 9c 0c          	mov    0xc(%esp,%ebx,4),%ecx
 8048e76:	b8 01 00 00 00       	mov    $0x1,%eax
 8048e7b:	ba 3c c1 04 08       	mov    $0x804c13c,%edx
 8048e80:	83 f9 01             	cmp    $0x1,%ecx
 8048e83:	7e 0a                	jle    8048e8f <phase_6+0x83>
 8048e85:	8b 52 08             	mov    0x8(%edx),%edx
 8048e88:	83 c0 01             	add    $0x1,%eax
 8048e8b:	39 c8                	cmp    %ecx,%eax
 8048e8d:	75 f6                	jne    8048e85 <phase_6+0x79>
 8048e8f:	89 54 b4 24          	mov    %edx,0x24(%esp,%esi,4)
 8048e93:	83 c3 01             	add    $0x1,%ebx
 8048e96:	83 fb 06             	cmp    $0x6,%ebx
 8048e99:	75 d5                	jne    8048e70 <phase_6+0x64>
 /////////////////////////////////////////
 8048e9b:	8b 5c 24 24          	mov    0x24(%esp),%ebx
 8048e9f:	89 d9                	mov    %ebx,%ecx
 8048ea1:	b8 01 00 00 00       	mov    $0x1,%eax
 8048ea6:	8b 54 84 24          	mov    0x24(%esp,%eax,4),%edx
 8048eaa:	89 51 08             	mov    %edx,0x8(%ecx)
 8048ead:	83 c0 01             	add    $0x1,%eax
 8048eb0:	89 d1                	mov    %edx,%ecx
 8048eb2:	83 f8 06             	cmp    $0x6,%eax
 8048eb5:	75 ef                	jne    8048ea6 <phase_6+0x9a>
 /////////////////////////////////////////
 8048eb7:	c7 42 08 00 00 00 00 	movl   $0x0,0x8(%edx)
 8048ebe:	be 05 00 00 00       	mov    $0x5,%esi
 8048ec3:	eb 08                	jmp    8048ecd <phase_6+0xc1>
 8048ec5:	8b 5b 08             	mov    0x8(%ebx),%ebx
 8048ec8:	83 ee 01             	sub    $0x1,%esi
 8048ecb:	74 10                	je     8048edd <phase_6+0xd1>
 8048ecd:	8b 43 08             	mov    0x8(%ebx),%eax
 8048ed0:	8b 00                	mov    (%eax),%eax
 8048ed2:	39 03                	cmp    %eax,(%ebx)
 8048ed4:	7e ef                	jle    8048ec5 <phase_6+0xb9>
 8048ed6:	e8 56 02 00 00       	call   8049131 <explode_bomb>
 8048edb:	eb e8                	jmp    8048ec5 <phase_6+0xb9>
 8048edd:	8b 44 24 3c          	mov    0x3c(%esp),%eax
 8048ee1:	65 33 05 14 00 00 00 	xor    %gs:0x14,%eax
 8048ee8:	75 06                	jne    8048ef0 <phase_6+0xe4>
 8048eea:	83 c4 44             	add    $0x44,%esp
 8048eed:	5b                   	pop    %ebx
 8048eee:	5e                   	pop    %esi
 8048eef:	c3                   	ret    
 8048ef0:	e8 9b f8 ff ff       	call   8048790 <__stack_chk_fail@plt>

08048ef5 <fun7>:
 8048ef5:	53                   	push   %ebx
 8048ef6:	83 ec 08             	sub    $0x8,%esp
 8048ef9:	8b 54 24 10          	mov    0x10(%esp),%edx
 8048efd:	8b 4c 24 14          	mov    0x14(%esp),%ecx
 8048f01:	85 d2                	test   %edx,%edx
 8048f03:	74 3a                	je     8048f3f <fun7+0x4a>
 8048f05:	8b 1a                	mov    (%edx),%ebx
 8048f07:	39 cb                	cmp    %ecx,%ebx
 8048f09:	7f 21                	jg     8048f2c <fun7+0x37>
 8048f0b:	b8 00 00 00 00       	mov    $0x0,%eax
 8048f10:	39 cb                	cmp    %ecx,%ebx
 8048f12:	74 13                	je     8048f27 <fun7+0x32>
 8048f14:	83 ec 08             	sub    $0x8,%esp
 8048f17:	51                   	push   %ecx
 8048f18:	ff 72 08             	pushl  0x8(%edx)
 8048f1b:	e8 d5 ff ff ff       	call   8048ef5 <fun7>
 8048f20:	83 c4 10             	add    $0x10,%esp
 8048f23:	8d 44 00 01          	lea    0x1(%eax,%eax,1),%eax
 8048f27:	83 c4 08             	add    $0x8,%esp
 8048f2a:	5b                   	pop    %ebx
 8048f2b:	c3                   	ret    
 8048f2c:	83 ec 08             	sub    $0x8,%esp
 8048f2f:	51                   	push   %ecx
 8048f30:	ff 72 04             	pushl  0x4(%edx)
 8048f33:	e8 bd ff ff ff       	call   8048ef5 <fun7>
 8048f38:	83 c4 10             	add    $0x10,%esp
 8048f3b:	01 c0                	add    %eax,%eax
 8048f3d:	eb e8                	jmp    8048f27 <fun7+0x32>
 8048f3f:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8048f44:	eb e1                	jmp    8048f27 <fun7+0x32>

08048f46 <secret_phase>:
 8048f46:	53                   	push   %ebx
 8048f47:	83 ec 08             	sub    $0x8,%esp
 8048f4a:	e8 42 02 00 00       	call   8049191 <read_line>
 8048f4f:	83 ec 04             	sub    $0x4,%esp
 8048f52:	6a 0a                	push   $0xa
 8048f54:	6a 00                	push   $0x0
 8048f56:	50                   	push   %eax
 8048f57:	e8 24 f9 ff ff       	call   8048880 <strtol@plt>
 8048f5c:	89 c3                	mov    %eax,%ebx
 8048f5e:	8d 40 ff             	lea    -0x1(%eax),%eax
 8048f61:	83 c4 10             	add    $0x10,%esp
 8048f64:	3d e8 03 00 00       	cmp    $0x3e8,%eax
 8048f69:	77 32                	ja     8048f9d <secret_phase+0x57>
 8048f6b:	83 ec 08             	sub    $0x8,%esp
 8048f6e:	53                   	push   %ebx
 8048f6f:	68 88 c0 04 08       	push   $0x804c088
 8048f74:	e8 7c ff ff ff       	call   8048ef5 <fun7>
 8048f79:	83 c4 10             	add    $0x10,%esp
 8048f7c:	83 f8 05             	cmp    $0x5,%eax
 8048f7f:	74 05                	je     8048f86 <secret_phase+0x40>
 8048f81:	e8 ab 01 00 00       	call   8049131 <explode_bomb>
 8048f86:	83 ec 0c             	sub    $0xc,%esp
 8048f89:	68 70 a0 04 08       	push   $0x804a070
 8048f8e:	e8 2d f8 ff ff       	call   80487c0 <puts@plt>
 8048f93:	e8 f8 02 00 00       	call   8049290 <phase_defused>
 8048f98:	83 c4 18             	add    $0x18,%esp
 8048f9b:	5b                   	pop    %ebx
 8048f9c:	c3                   	ret    
 8048f9d:	e8 8f 01 00 00       	call   8049131 <explode_bomb>
 8048fa2:	eb c7                	jmp    8048f6b <secret_phase+0x25>

08048fa4 <sig_handler>:
 8048fa4:	83 ec 18             	sub    $0x18,%esp
 8048fa7:	68 00 a1 04 08       	push   $0x804a100
 8048fac:	e8 0f f8 ff ff       	call   80487c0 <puts@plt>
 8048fb1:	c7 04 24 03 00 00 00 	movl   $0x3,(%esp)
 8048fb8:	e8 b3 f7 ff ff       	call   8048770 <sleep@plt>
 8048fbd:	83 c4 08             	add    $0x8,%esp
 8048fc0:	68 c2 a1 04 08       	push   $0x804a1c2
 8048fc5:	6a 01                	push   $0x1
 8048fc7:	e8 74 f8 ff ff       	call   8048840 <__printf_chk@plt>
 8048fcc:	83 c4 04             	add    $0x4,%esp
 8048fcf:	ff 35 c4 c3 04 08    	pushl  0x804c3c4
 8048fd5:	e8 66 f7 ff ff       	call   8048740 <fflush@plt>
 8048fda:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8048fe1:	e8 8a f7 ff ff       	call   8048770 <sleep@plt>
 8048fe6:	c7 04 24 ca a1 04 08 	movl   $0x804a1ca,(%esp)
 8048fed:	e8 ce f7 ff ff       	call   80487c0 <puts@plt>
 8048ff2:	c7 04 24 10 00 00 00 	movl   $0x10,(%esp)
 8048ff9:	e8 e2 f7 ff ff       	call   80487e0 <exit@plt>

08048ffe <invalid_phase>:
 8048ffe:	83 ec 10             	sub    $0x10,%esp
 8049001:	ff 74 24 14          	pushl  0x14(%esp)
 8049005:	68 d2 a1 04 08       	push   $0x804a1d2
 804900a:	6a 01                	push   $0x1
 804900c:	e8 2f f8 ff ff       	call   8048840 <__printf_chk@plt>
 8049011:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 8049018:	e8 c3 f7 ff ff       	call   80487e0 <exit@plt>

0804901d <string_length>:
 804901d:	8b 54 24 04          	mov    0x4(%esp),%edx
 8049021:	80 3a 00             	cmpb   $0x0,(%edx)
 8049024:	74 10                	je     8049036 <string_length+0x19>
 8049026:	b8 00 00 00 00       	mov    $0x0,%eax
 804902b:	83 c0 01             	add    $0x1,%eax
 804902e:	80 3c 02 00          	cmpb   $0x0,(%edx,%eax,1)
 8049032:	75 f7                	jne    804902b <string_length+0xe>
 8049034:	f3 c3                	repz ret 
 8049036:	b8 00 00 00 00       	mov    $0x0,%eax
 804903b:	c3                   	ret    

0804903c <strings_not_equal>:
 804903c:	57                   	push   %edi
 804903d:	56                   	push   %esi
 804903e:	53                   	push   %ebx
 804903f:	8b 5c 24 10          	mov    0x10(%esp),%ebx
 8049043:	8b 74 24 14          	mov    0x14(%esp),%esi
 8049047:	53                   	push   %ebx
 8049048:	e8 d0 ff ff ff       	call   804901d <string_length>
 804904d:	89 c7                	mov    %eax,%edi
 804904f:	89 34 24             	mov    %esi,(%esp)
 8049052:	e8 c6 ff ff ff       	call   804901d <string_length>
 8049057:	83 c4 04             	add    $0x4,%esp
 804905a:	ba 01 00 00 00       	mov    $0x1,%edx
 804905f:	39 c7                	cmp    %eax,%edi
 8049061:	74 06                	je     8049069 <strings_not_equal+0x2d>
 8049063:	89 d0                	mov    %edx,%eax
 8049065:	5b                   	pop    %ebx
 8049066:	5e                   	pop    %esi
 8049067:	5f                   	pop    %edi
 8049068:	c3                   	ret    
 8049069:	0f b6 03             	movzbl (%ebx),%eax
 804906c:	84 c0                	test   %al,%al
 804906e:	74 23                	je     8049093 <strings_not_equal+0x57>
 8049070:	3a 06                	cmp    (%esi),%al
 8049072:	75 26                	jne    804909a <strings_not_equal+0x5e>
 8049074:	83 c3 01             	add    $0x1,%ebx
 8049077:	83 c6 01             	add    $0x1,%esi
 804907a:	0f b6 03             	movzbl (%ebx),%eax
 804907d:	84 c0                	test   %al,%al
 804907f:	74 0b                	je     804908c <strings_not_equal+0x50>
 8049081:	3a 06                	cmp    (%esi),%al
 8049083:	74 ef                	je     8049074 <strings_not_equal+0x38>
 8049085:	ba 01 00 00 00       	mov    $0x1,%edx
 804908a:	eb d7                	jmp    8049063 <strings_not_equal+0x27>
 804908c:	ba 00 00 00 00       	mov    $0x0,%edx
 8049091:	eb d0                	jmp    8049063 <strings_not_equal+0x27>
 8049093:	ba 00 00 00 00       	mov    $0x0,%edx
 8049098:	eb c9                	jmp    8049063 <strings_not_equal+0x27>
 804909a:	ba 01 00 00 00       	mov    $0x1,%edx
 804909f:	eb c2                	jmp    8049063 <strings_not_equal+0x27>

080490a1 <initialize_bomb>:
 80490a1:	83 ec 14             	sub    $0x14,%esp
 80490a4:	68 a4 8f 04 08       	push   $0x8048fa4
 80490a9:	6a 02                	push   $0x2
 80490ab:	e8 b0 f6 ff ff       	call   8048760 <signal@plt>
 80490b0:	83 c4 1c             	add    $0x1c,%esp
 80490b3:	c3                   	ret    

080490b4 <initialize_bomb_solve>:
 80490b4:	f3 c3                	repz ret 

080490b6 <blank_line>:
 80490b6:	56                   	push   %esi
 80490b7:	53                   	push   %ebx
 80490b8:	83 ec 04             	sub    $0x4,%esp
 80490bb:	8b 74 24 10          	mov    0x10(%esp),%esi
 80490bf:	0f b6 1e             	movzbl (%esi),%ebx
 80490c2:	84 db                	test   %bl,%bl
 80490c4:	74 1b                	je     80490e1 <blank_line+0x2b>
 80490c6:	e8 e5 f7 ff ff       	call   80488b0 <__ctype_b_loc@plt>
 80490cb:	83 c6 01             	add    $0x1,%esi
 80490ce:	0f be db             	movsbl %bl,%ebx
 80490d1:	8b 00                	mov    (%eax),%eax
 80490d3:	f6 44 58 01 20       	testb  $0x20,0x1(%eax,%ebx,2)
 80490d8:	75 e5                	jne    80490bf <blank_line+0x9>
 80490da:	b8 00 00 00 00       	mov    $0x0,%eax
 80490df:	eb 05                	jmp    80490e6 <blank_line+0x30>
 80490e1:	b8 01 00 00 00       	mov    $0x1,%eax
 80490e6:	83 c4 04             	add    $0x4,%esp
 80490e9:	5b                   	pop    %ebx
 80490ea:	5e                   	pop    %esi
 80490eb:	c3                   	ret    

080490ec <skip>:
 80490ec:	53                   	push   %ebx
 80490ed:	83 ec 08             	sub    $0x8,%esp
 80490f0:	83 ec 04             	sub    $0x4,%esp
 80490f3:	ff 35 d0 c3 04 08    	pushl  0x804c3d0
 80490f9:	6a 50                	push   $0x50
 80490fb:	a1 cc c3 04 08       	mov    0x804c3cc,%eax
 8049100:	8d 04 80             	lea    (%eax,%eax,4),%eax
 8049103:	c1 e0 04             	shl    $0x4,%eax
 8049106:	05 e0 c3 04 08       	add    $0x804c3e0,%eax
 804910b:	50                   	push   %eax
 804910c:	e8 3f f6 ff ff       	call   8048750 <fgets@plt>
 8049111:	89 c3                	mov    %eax,%ebx
 8049113:	83 c4 10             	add    $0x10,%esp
 8049116:	85 c0                	test   %eax,%eax
 8049118:	74 10                	je     804912a <skip+0x3e>
 804911a:	83 ec 0c             	sub    $0xc,%esp
 804911d:	50                   	push   %eax
 804911e:	e8 93 ff ff ff       	call   80490b6 <blank_line>
 8049123:	83 c4 10             	add    $0x10,%esp
 8049126:	85 c0                	test   %eax,%eax
 8049128:	75 c6                	jne    80490f0 <skip+0x4>
 804912a:	89 d8                	mov    %ebx,%eax
 804912c:	83 c4 08             	add    $0x8,%esp
 804912f:	5b                   	pop    %ebx
 8049130:	c3                   	ret    

08049131 <explode_bomb>:
 8049131:	83 ec 18             	sub    $0x18,%esp
 8049134:	68 e3 a1 04 08       	push   $0x804a1e3
 8049139:	e8 82 f6 ff ff       	call   80487c0 <puts@plt>
 804913e:	c7 04 24 ec a1 04 08 	movl   $0x804a1ec,(%esp)
 8049145:	e8 76 f6 ff ff       	call   80487c0 <puts@plt>
 804914a:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 8049151:	e8 8a f6 ff ff       	call   80487e0 <exit@plt>

08049156 <read_six_numbers>:
 8049156:	83 ec 0c             	sub    $0xc,%esp
 8049159:	8b 44 24 14          	mov    0x14(%esp),%eax
 804915d:	8d 50 14             	lea    0x14(%eax),%edx
 8049160:	52                   	push   %edx
 8049161:	8d 50 10             	lea    0x10(%eax),%edx
 8049164:	52                   	push   %edx
 8049165:	8d 50 0c             	lea    0xc(%eax),%edx
 8049168:	52                   	push   %edx
 8049169:	8d 50 08             	lea    0x8(%eax),%edx
 804916c:	52                   	push   %edx
 804916d:	8d 50 04             	lea    0x4(%eax),%edx
 8049170:	52                   	push   %edx
 8049171:	50                   	push   %eax
 8049172:	68 03 a2 04 08       	push   $0x804a203
 8049177:	ff 74 24 2c          	pushl  0x2c(%esp)
 804917b:	e8 90 f6 ff ff       	call   8048810 <__isoc99_sscanf@plt>
 8049180:	83 c4 20             	add    $0x20,%esp
 8049183:	83 f8 05             	cmp    $0x5,%eax
 8049186:	7e 04                	jle    804918c <read_six_numbers+0x36>
 8049188:	83 c4 0c             	add    $0xc,%esp
 804918b:	c3                   	ret    
 804918c:	e8 a0 ff ff ff       	call   8049131 <explode_bomb>

08049191 <read_line>:
 8049191:	57                   	push   %edi
 8049192:	56                   	push   %esi
 8049193:	53                   	push   %ebx
 8049194:	e8 53 ff ff ff       	call   80490ec <skip>
 8049199:	85 c0                	test   %eax,%eax
 804919b:	74 4b                	je     80491e8 <read_line+0x57>
 804919d:	8b 15 cc c3 04 08    	mov    0x804c3cc,%edx
 80491a3:	8d 1c 92             	lea    (%edx,%edx,4),%ebx
 80491a6:	c1 e3 04             	shl    $0x4,%ebx
 80491a9:	81 c3 e0 c3 04 08    	add    $0x804c3e0,%ebx
 80491af:	b8 00 00 00 00       	mov    $0x0,%eax
 80491b4:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
 80491b9:	89 df                	mov    %ebx,%edi
 80491bb:	f2 ae                	repnz scas %es:(%edi),%al
 80491bd:	f7 d1                	not    %ecx
 80491bf:	83 e9 01             	sub    $0x1,%ecx
 80491c2:	83 f9 4e             	cmp    $0x4e,%ecx
 80491c5:	0f 8f 8d 00 00 00    	jg     8049258 <read_line+0xc7>
 80491cb:	8d 04 92             	lea    (%edx,%edx,4),%eax
 80491ce:	c1 e0 04             	shl    $0x4,%eax
 80491d1:	c6 84 01 df c3 04 08 	movb   $0x0,0x804c3df(%ecx,%eax,1)
 80491d8:	00 
 80491d9:	83 c2 01             	add    $0x1,%edx
 80491dc:	89 15 cc c3 04 08    	mov    %edx,0x804c3cc
 80491e2:	89 d8                	mov    %ebx,%eax
 80491e4:	5b                   	pop    %ebx
 80491e5:	5e                   	pop    %esi
 80491e6:	5f                   	pop    %edi
 80491e7:	c3                   	ret    
 80491e8:	a1 c0 c3 04 08       	mov    0x804c3c0,%eax
 80491ed:	39 05 d0 c3 04 08    	cmp    %eax,0x804c3d0
 80491f3:	74 40                	je     8049235 <read_line+0xa4>
 80491f5:	83 ec 0c             	sub    $0xc,%esp
 80491f8:	68 33 a2 04 08       	push   $0x804a233
 80491fd:	e8 ae f5 ff ff       	call   80487b0 <getenv@plt>
 8049202:	83 c4 10             	add    $0x10,%esp
 8049205:	85 c0                	test   %eax,%eax
 8049207:	75 45                	jne    804924e <read_line+0xbd>
 8049209:	a1 c0 c3 04 08       	mov    0x804c3c0,%eax
 804920e:	a3 d0 c3 04 08       	mov    %eax,0x804c3d0
 8049213:	e8 d4 fe ff ff       	call   80490ec <skip>
 8049218:	85 c0                	test   %eax,%eax
 804921a:	75 81                	jne    804919d <read_line+0xc>
 804921c:	83 ec 0c             	sub    $0xc,%esp
 804921f:	68 15 a2 04 08       	push   $0x804a215
 8049224:	e8 97 f5 ff ff       	call   80487c0 <puts@plt>
 8049229:	c7 04 24 00 00 00 00 	movl   $0x0,(%esp)
 8049230:	e8 ab f5 ff ff       	call   80487e0 <exit@plt>
 8049235:	83 ec 0c             	sub    $0xc,%esp
 8049238:	68 15 a2 04 08       	push   $0x804a215
 804923d:	e8 7e f5 ff ff       	call   80487c0 <puts@plt>
 8049242:	c7 04 24 08 00 00 00 	movl   $0x8,(%esp)
 8049249:	e8 92 f5 ff ff       	call   80487e0 <exit@plt>
 804924e:	83 ec 0c             	sub    $0xc,%esp
 8049251:	6a 00                	push   $0x0
 8049253:	e8 88 f5 ff ff       	call   80487e0 <exit@plt>
 8049258:	83 ec 0c             	sub    $0xc,%esp
 804925b:	68 3e a2 04 08       	push   $0x804a23e
 8049260:	e8 5b f5 ff ff       	call   80487c0 <puts@plt>
 8049265:	a1 cc c3 04 08       	mov    0x804c3cc,%eax
 804926a:	8d 50 01             	lea    0x1(%eax),%edx
 804926d:	89 15 cc c3 04 08    	mov    %edx,0x804c3cc
 8049273:	6b c0 50             	imul   $0x50,%eax,%eax
 8049276:	05 e0 c3 04 08       	add    $0x804c3e0,%eax
 804927b:	ba 59 a2 04 08       	mov    $0x804a259,%edx
 8049280:	b9 04 00 00 00       	mov    $0x4,%ecx
 8049285:	89 c7                	mov    %eax,%edi
 8049287:	89 d6                	mov    %edx,%esi
 8049289:	f3 a5                	rep movsl %ds:(%esi),%es:(%edi)
 804928b:	e8 a1 fe ff ff       	call   8049131 <explode_bomb>

08049290 <phase_defused>:
 8049290:	83 ec 6c             	sub    $0x6c,%esp
 8049293:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 8049299:	89 44 24 5c          	mov    %eax,0x5c(%esp)
 804929d:	31 c0                	xor    %eax,%eax
 804929f:	83 3d cc c3 04 08 06 	cmpl   $0x6,0x804c3cc
 80492a6:	74 11                	je     80492b9 <phase_defused+0x29>
 80492a8:	8b 44 24 5c          	mov    0x5c(%esp),%eax
 80492ac:	65 33 05 14 00 00 00 	xor    %gs:0x14,%eax
 80492b3:	75 7b                	jne    8049330 <phase_defused+0xa0>
 80492b5:	83 c4 6c             	add    $0x6c,%esp
 80492b8:	c3                   	ret    
 80492b9:	83 ec 0c             	sub    $0xc,%esp
 80492bc:	8d 44 24 18          	lea    0x18(%esp),%eax
 80492c0:	50                   	push   %eax
 80492c1:	8d 44 24 18          	lea    0x18(%esp),%eax
 80492c5:	50                   	push   %eax
 80492c6:	8d 44 24 18          	lea    0x18(%esp),%eax
 80492ca:	50                   	push   %eax
 80492cb:	68 69 a2 04 08       	push   $0x804a269
 80492d0:	68 d0 c4 04 08       	push   $0x804c4d0
 80492d5:	e8 36 f5 ff ff       	call   8048810 <__isoc99_sscanf@plt>
 80492da:	83 c4 20             	add    $0x20,%esp
 80492dd:	83 f8 03             	cmp    $0x3,%eax
 80492e0:	74 12                	je     80492f4 <phase_defused+0x64>
 80492e2:	83 ec 0c             	sub    $0xc,%esp
 80492e5:	68 98 a1 04 08       	push   $0x804a198
 80492ea:	e8 d1 f4 ff ff       	call   80487c0 <puts@plt>
 80492ef:	83 c4 10             	add    $0x10,%esp
 80492f2:	eb b4                	jmp    80492a8 <phase_defused+0x18>
 80492f4:	83 ec 08             	sub    $0x8,%esp
 80492f7:	68 72 a2 04 08       	push   $0x804a272
 80492fc:	8d 44 24 18          	lea    0x18(%esp),%eax
 8049300:	50                   	push   %eax
 8049301:	e8 36 fd ff ff       	call   804903c <strings_not_equal>
 8049306:	83 c4 10             	add    $0x10,%esp
 8049309:	85 c0                	test   %eax,%eax
 804930b:	75 d5                	jne    80492e2 <phase_defused+0x52>
 804930d:	83 ec 0c             	sub    $0xc,%esp
 8049310:	68 38 a1 04 08       	push   $0x804a138
 8049315:	e8 a6 f4 ff ff       	call   80487c0 <puts@plt>
 804931a:	c7 04 24 60 a1 04 08 	movl   $0x804a160,(%esp)
 8049321:	e8 9a f4 ff ff       	call   80487c0 <puts@plt>
 8049326:	e8 1b fc ff ff       	call   8048f46 <secret_phase>
 804932b:	83 c4 10             	add    $0x10,%esp
 804932e:	eb b2                	jmp    80492e2 <phase_defused+0x52>
 8049330:	e8 5b f4 ff ff       	call   8048790 <__stack_chk_fail@plt>

08049335 <sigalrm_handler>:
 8049335:	83 ec 0c             	sub    $0xc,%esp
 8049338:	6a 00                	push   $0x0
 804933a:	68 c8 a2 04 08       	push   $0x804a2c8
 804933f:	6a 01                	push   $0x1
 8049341:	ff 35 a0 c3 04 08    	pushl  0x804c3a0
 8049347:	e8 14 f5 ff ff       	call   8048860 <__fprintf_chk@plt>
 804934c:	c7 04 24 01 00 00 00 	movl   $0x1,(%esp)
 8049353:	e8 88 f4 ff ff       	call   80487e0 <exit@plt>

08049358 <rio_readlineb>:
 8049358:	55                   	push   %ebp
 8049359:	57                   	push   %edi
 804935a:	56                   	push   %esi
 804935b:	53                   	push   %ebx
 804935c:	83 ec 1c             	sub    $0x1c,%esp
 804935f:	83 f9 01             	cmp    $0x1,%ecx
 8049362:	76 79                	jbe    80493dd <rio_readlineb+0x85>
 8049364:	89 d7                	mov    %edx,%edi
 8049366:	89 c3                	mov    %eax,%ebx
 8049368:	89 4c 24 0c          	mov    %ecx,0xc(%esp)
 804936c:	bd 01 00 00 00       	mov    $0x1,%ebp
 8049371:	8d 70 0c             	lea    0xc(%eax),%esi
 8049374:	eb 0a                	jmp    8049380 <rio_readlineb+0x28>
 8049376:	e8 b5 f4 ff ff       	call   8048830 <__errno_location@plt>
 804937b:	83 38 04             	cmpl   $0x4,(%eax)
 804937e:	75 66                	jne    80493e6 <rio_readlineb+0x8e>
 8049380:	8b 43 04             	mov    0x4(%ebx),%eax
 8049383:	85 c0                	test   %eax,%eax
 8049385:	7f 23                	jg     80493aa <rio_readlineb+0x52>
 8049387:	83 ec 04             	sub    $0x4,%esp
 804938a:	68 00 20 00 00       	push   $0x2000
 804938f:	56                   	push   %esi
 8049390:	ff 33                	pushl  (%ebx)
 8049392:	e8 99 f3 ff ff       	call   8048730 <read@plt>
 8049397:	89 43 04             	mov    %eax,0x4(%ebx)
 804939a:	83 c4 10             	add    $0x10,%esp
 804939d:	85 c0                	test   %eax,%eax
 804939f:	78 d5                	js     8049376 <rio_readlineb+0x1e>
 80493a1:	85 c0                	test   %eax,%eax
 80493a3:	74 48                	je     80493ed <rio_readlineb+0x95>
 80493a5:	89 73 08             	mov    %esi,0x8(%ebx)
 80493a8:	eb d6                	jmp    8049380 <rio_readlineb+0x28>
 80493aa:	8b 4b 08             	mov    0x8(%ebx),%ecx
 80493ad:	0f b6 11             	movzbl (%ecx),%edx
 80493b0:	83 c1 01             	add    $0x1,%ecx
 80493b3:	89 4b 08             	mov    %ecx,0x8(%ebx)
 80493b6:	83 e8 01             	sub    $0x1,%eax
 80493b9:	89 43 04             	mov    %eax,0x4(%ebx)
 80493bc:	83 c7 01             	add    $0x1,%edi
 80493bf:	88 57 ff             	mov    %dl,-0x1(%edi)
 80493c2:	80 fa 0a             	cmp    $0xa,%dl
 80493c5:	74 09                	je     80493d0 <rio_readlineb+0x78>
 80493c7:	83 c5 01             	add    $0x1,%ebp
 80493ca:	3b 6c 24 0c          	cmp    0xc(%esp),%ebp
 80493ce:	75 b0                	jne    8049380 <rio_readlineb+0x28>
 80493d0:	c6 07 00             	movb   $0x0,(%edi)
 80493d3:	89 e8                	mov    %ebp,%eax
 80493d5:	83 c4 1c             	add    $0x1c,%esp
 80493d8:	5b                   	pop    %ebx
 80493d9:	5e                   	pop    %esi
 80493da:	5f                   	pop    %edi
 80493db:	5d                   	pop    %ebp
 80493dc:	c3                   	ret    
 80493dd:	89 d7                	mov    %edx,%edi
 80493df:	bd 01 00 00 00       	mov    $0x1,%ebp
 80493e4:	eb ea                	jmp    80493d0 <rio_readlineb+0x78>
 80493e6:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 80493eb:	eb 05                	jmp    80493f2 <rio_readlineb+0x9a>
 80493ed:	b8 00 00 00 00       	mov    $0x0,%eax
 80493f2:	85 c0                	test   %eax,%eax
 80493f4:	75 0c                	jne    8049402 <rio_readlineb+0xaa>
 80493f6:	83 fd 01             	cmp    $0x1,%ebp
 80493f9:	75 d5                	jne    80493d0 <rio_readlineb+0x78>
 80493fb:	bd 00 00 00 00       	mov    $0x0,%ebp
 8049400:	eb d1                	jmp    80493d3 <rio_readlineb+0x7b>
 8049402:	bd ff ff ff ff       	mov    $0xffffffff,%ebp
 8049407:	eb ca                	jmp    80493d3 <rio_readlineb+0x7b>

08049409 <submitr>:
 8049409:	55                   	push   %ebp
 804940a:	57                   	push   %edi
 804940b:	56                   	push   %esi
 804940c:	53                   	push   %ebx
 804940d:	81 ec 60 a0 00 00    	sub    $0xa060,%esp
 8049413:	8b 9c 24 74 a0 00 00 	mov    0xa074(%esp),%ebx
 804941a:	8b 84 24 7c a0 00 00 	mov    0xa07c(%esp),%eax
 8049421:	89 44 24 0c          	mov    %eax,0xc(%esp)
 8049425:	8b 84 24 80 a0 00 00 	mov    0xa080(%esp),%eax
 804942c:	89 44 24 10          	mov    %eax,0x10(%esp)
 8049430:	8b 84 24 84 a0 00 00 	mov    0xa084(%esp),%eax
 8049437:	89 44 24 14          	mov    %eax,0x14(%esp)
 804943b:	8b b4 24 88 a0 00 00 	mov    0xa088(%esp),%esi
 8049442:	8b 84 24 8c a0 00 00 	mov    0xa08c(%esp),%eax
 8049449:	89 44 24 18          	mov    %eax,0x18(%esp)
 804944d:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 8049453:	89 84 24 50 a0 00 00 	mov    %eax,0xa050(%esp)
 804945a:	31 c0                	xor    %eax,%eax
 804945c:	c7 44 24 30 00 00 00 	movl   $0x0,0x30(%esp)
 8049463:	00 
 8049464:	6a 00                	push   $0x0
 8049466:	6a 01                	push   $0x1
 8049468:	6a 02                	push   $0x2
 804946a:	e8 e1 f3 ff ff       	call   8048850 <socket@plt>
 804946f:	83 c4 10             	add    $0x10,%esp
 8049472:	85 c0                	test   %eax,%eax
 8049474:	0f 88 04 01 00 00    	js     804957e <submitr+0x175>
 804947a:	89 c5                	mov    %eax,%ebp
 804947c:	83 ec 0c             	sub    $0xc,%esp
 804947f:	53                   	push   %ebx
 8049480:	e8 eb f3 ff ff       	call   8048870 <gethostbyname@plt>
 8049485:	83 c4 10             	add    $0x10,%esp
 8049488:	85 c0                	test   %eax,%eax
 804948a:	0f 84 40 01 00 00    	je     80495d0 <submitr+0x1c7>
 8049490:	8d 5c 24 30          	lea    0x30(%esp),%ebx
 8049494:	c7 44 24 30 00 00 00 	movl   $0x0,0x30(%esp)
 804949b:	00 
 804949c:	c7 44 24 34 00 00 00 	movl   $0x0,0x34(%esp)
 80494a3:	00 
 80494a4:	c7 44 24 38 00 00 00 	movl   $0x0,0x38(%esp)
 80494ab:	00 
 80494ac:	c7 44 24 3c 00 00 00 	movl   $0x0,0x3c(%esp)
 80494b3:	00 
 80494b4:	66 c7 44 24 30 02 00 	movw   $0x2,0x30(%esp)
 80494bb:	6a 0c                	push   $0xc
 80494bd:	ff 70 0c             	pushl  0xc(%eax)
 80494c0:	8b 40 10             	mov    0x10(%eax),%eax
 80494c3:	ff 30                	pushl  (%eax)
 80494c5:	8d 44 24 40          	lea    0x40(%esp),%eax
 80494c9:	50                   	push   %eax
 80494ca:	e8 01 f3 ff ff       	call   80487d0 <__memmove_chk@plt>
 80494cf:	0f b7 84 24 84 a0 00 	movzwl 0xa084(%esp),%eax
 80494d6:	00 
 80494d7:	66 c1 c8 08          	ror    $0x8,%ax
 80494db:	66 89 44 24 42       	mov    %ax,0x42(%esp)
 80494e0:	83 c4 0c             	add    $0xc,%esp
 80494e3:	6a 10                	push   $0x10
 80494e5:	53                   	push   %ebx
 80494e6:	55                   	push   %ebp
 80494e7:	e8 a4 f3 ff ff       	call   8048890 <connect@plt>
 80494ec:	83 c4 10             	add    $0x10,%esp
 80494ef:	85 c0                	test   %eax,%eax
 80494f1:	0f 88 49 01 00 00    	js     8049640 <submitr+0x237>
 80494f7:	ba ff ff ff ff       	mov    $0xffffffff,%edx
 80494fc:	b8 00 00 00 00       	mov    $0x0,%eax
 8049501:	89 d1                	mov    %edx,%ecx
 8049503:	89 f7                	mov    %esi,%edi
 8049505:	f2 ae                	repnz scas %es:(%edi),%al
 8049507:	89 cb                	mov    %ecx,%ebx
 8049509:	f7 d3                	not    %ebx
 804950b:	89 d1                	mov    %edx,%ecx
 804950d:	8b 7c 24 08          	mov    0x8(%esp),%edi
 8049511:	f2 ae                	repnz scas %es:(%edi),%al
 8049513:	89 4c 24 18          	mov    %ecx,0x18(%esp)
 8049517:	89 d1                	mov    %edx,%ecx
 8049519:	8b 7c 24 0c          	mov    0xc(%esp),%edi
 804951d:	f2 ae                	repnz scas %es:(%edi),%al
 804951f:	89 cf                	mov    %ecx,%edi
 8049521:	f7 d7                	not    %edi
 8049523:	89 7c 24 1c          	mov    %edi,0x1c(%esp)
 8049527:	89 d1                	mov    %edx,%ecx
 8049529:	8b 7c 24 10          	mov    0x10(%esp),%edi
 804952d:	f2 ae                	repnz scas %es:(%edi),%al
 804952f:	8b 54 24 1c          	mov    0x1c(%esp),%edx
 8049533:	2b 54 24 18          	sub    0x18(%esp),%edx
 8049537:	29 ca                	sub    %ecx,%edx
 8049539:	8d 44 5b fd          	lea    -0x3(%ebx,%ebx,2),%eax
 804953d:	8d 44 02 7b          	lea    0x7b(%edx,%eax,1),%eax
 8049541:	3d 00 20 00 00       	cmp    $0x2000,%eax
 8049546:	0f 87 56 01 00 00    	ja     80496a2 <submitr+0x299>
 804954c:	8d 94 24 4c 40 00 00 	lea    0x404c(%esp),%edx
 8049553:	b9 00 08 00 00       	mov    $0x800,%ecx
 8049558:	b8 00 00 00 00       	mov    $0x0,%eax
 804955d:	89 d7                	mov    %edx,%edi
 804955f:	f3 ab                	rep stos %eax,%es:(%edi)
 8049561:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
 8049566:	89 f7                	mov    %esi,%edi
 8049568:	f2 ae                	repnz scas %es:(%edi),%al
 804956a:	f7 d1                	not    %ecx
 804956c:	89 cb                	mov    %ecx,%ebx
 804956e:	83 eb 01             	sub    $0x1,%ebx
 8049571:	0f 84 07 06 00 00    	je     8049b7e <submitr+0x775>
 8049577:	89 d7                	mov    %edx,%edi
 8049579:	e9 b0 01 00 00       	jmp    804972e <submitr+0x325>
 804957e:	8b 44 24 14          	mov    0x14(%esp),%eax
 8049582:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
 8049588:	c7 40 04 72 3a 20 43 	movl   $0x43203a72,0x4(%eax)
 804958f:	c7 40 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%eax)
 8049596:	c7 40 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%eax)
 804959d:	c7 40 10 61 62 6c 65 	movl   $0x656c6261,0x10(%eax)
 80495a4:	c7 40 14 20 74 6f 20 	movl   $0x206f7420,0x14(%eax)
 80495ab:	c7 40 18 63 72 65 61 	movl   $0x61657263,0x18(%eax)
 80495b2:	c7 40 1c 74 65 20 73 	movl   $0x73206574,0x1c(%eax)
 80495b9:	c7 40 20 6f 63 6b 65 	movl   $0x656b636f,0x20(%eax)
 80495c0:	66 c7 40 24 74 00    	movw   $0x74,0x24(%eax)
 80495c6:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 80495cb:	e9 d0 04 00 00       	jmp    8049aa0 <submitr+0x697>
 80495d0:	8b 44 24 14          	mov    0x14(%esp),%eax
 80495d4:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
 80495da:	c7 40 04 72 3a 20 44 	movl   $0x44203a72,0x4(%eax)
 80495e1:	c7 40 08 4e 53 20 69 	movl   $0x6920534e,0x8(%eax)
 80495e8:	c7 40 0c 73 20 75 6e 	movl   $0x6e752073,0xc(%eax)
 80495ef:	c7 40 10 61 62 6c 65 	movl   $0x656c6261,0x10(%eax)
 80495f6:	c7 40 14 20 74 6f 20 	movl   $0x206f7420,0x14(%eax)
 80495fd:	c7 40 18 72 65 73 6f 	movl   $0x6f736572,0x18(%eax)
 8049604:	c7 40 1c 6c 76 65 20 	movl   $0x2065766c,0x1c(%eax)
 804960b:	c7 40 20 73 65 72 76 	movl   $0x76726573,0x20(%eax)
 8049612:	c7 40 24 65 72 20 61 	movl   $0x61207265,0x24(%eax)
 8049619:	c7 40 28 64 64 72 65 	movl   $0x65726464,0x28(%eax)
 8049620:	66 c7 40 2c 73 73    	movw   $0x7373,0x2c(%eax)
 8049626:	c6 40 2e 00          	movb   $0x0,0x2e(%eax)
 804962a:	83 ec 0c             	sub    $0xc,%esp
 804962d:	55                   	push   %ebp
 804962e:	e8 6d f2 ff ff       	call   80488a0 <close@plt>
 8049633:	83 c4 10             	add    $0x10,%esp
 8049636:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 804963b:	e9 60 04 00 00       	jmp    8049aa0 <submitr+0x697>
 8049640:	8b 44 24 14          	mov    0x14(%esp),%eax
 8049644:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
 804964a:	c7 40 04 72 3a 20 55 	movl   $0x55203a72,0x4(%eax)
 8049651:	c7 40 08 6e 61 62 6c 	movl   $0x6c62616e,0x8(%eax)
 8049658:	c7 40 0c 65 20 74 6f 	movl   $0x6f742065,0xc(%eax)
 804965f:	c7 40 10 20 63 6f 6e 	movl   $0x6e6f6320,0x10(%eax)
 8049666:	c7 40 14 6e 65 63 74 	movl   $0x7463656e,0x14(%eax)
 804966d:	c7 40 18 20 74 6f 20 	movl   $0x206f7420,0x18(%eax)
 8049674:	c7 40 1c 74 68 65 20 	movl   $0x20656874,0x1c(%eax)
 804967b:	c7 40 20 73 65 72 76 	movl   $0x76726573,0x20(%eax)
 8049682:	66 c7 40 24 65 72    	movw   $0x7265,0x24(%eax)
 8049688:	c6 40 26 00          	movb   $0x0,0x26(%eax)
 804968c:	83 ec 0c             	sub    $0xc,%esp
 804968f:	55                   	push   %ebp
 8049690:	e8 0b f2 ff ff       	call   80488a0 <close@plt>
 8049695:	83 c4 10             	add    $0x10,%esp
 8049698:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 804969d:	e9 fe 03 00 00       	jmp    8049aa0 <submitr+0x697>
 80496a2:	8b 44 24 14          	mov    0x14(%esp),%eax
 80496a6:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
 80496ac:	c7 40 04 72 3a 20 52 	movl   $0x52203a72,0x4(%eax)
 80496b3:	c7 40 08 65 73 75 6c 	movl   $0x6c757365,0x8(%eax)
 80496ba:	c7 40 0c 74 20 73 74 	movl   $0x74732074,0xc(%eax)
 80496c1:	c7 40 10 72 69 6e 67 	movl   $0x676e6972,0x10(%eax)
 80496c8:	c7 40 14 20 74 6f 6f 	movl   $0x6f6f7420,0x14(%eax)
 80496cf:	c7 40 18 20 6c 61 72 	movl   $0x72616c20,0x18(%eax)
 80496d6:	c7 40 1c 67 65 2e 20 	movl   $0x202e6567,0x1c(%eax)
 80496dd:	c7 40 20 49 6e 63 72 	movl   $0x72636e49,0x20(%eax)
 80496e4:	c7 40 24 65 61 73 65 	movl   $0x65736165,0x24(%eax)
 80496eb:	c7 40 28 20 53 55 42 	movl   $0x42555320,0x28(%eax)
 80496f2:	c7 40 2c 4d 49 54 52 	movl   $0x5254494d,0x2c(%eax)
 80496f9:	c7 40 30 5f 4d 41 58 	movl   $0x58414d5f,0x30(%eax)
 8049700:	c7 40 34 42 55 46 00 	movl   $0x465542,0x34(%eax)
 8049707:	83 ec 0c             	sub    $0xc,%esp
 804970a:	55                   	push   %ebp
 804970b:	e8 90 f1 ff ff       	call   80488a0 <close@plt>
 8049710:	83 c4 10             	add    $0x10,%esp
 8049713:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049718:	e9 83 03 00 00       	jmp    8049aa0 <submitr+0x697>
 804971d:	88 17                	mov    %dl,(%edi)
 804971f:	8d 7f 01             	lea    0x1(%edi),%edi
 8049722:	83 c6 01             	add    $0x1,%esi
 8049725:	83 eb 01             	sub    $0x1,%ebx
 8049728:	0f 84 50 04 00 00    	je     8049b7e <submitr+0x775>
 804972e:	0f b6 16             	movzbl (%esi),%edx
 8049731:	8d 4a d6             	lea    -0x2a(%edx),%ecx
 8049734:	b8 01 00 00 00       	mov    $0x1,%eax
 8049739:	80 f9 0f             	cmp    $0xf,%cl
 804973c:	77 0d                	ja     804974b <submitr+0x342>
 804973e:	b8 d9 ff 00 00       	mov    $0xffd9,%eax
 8049743:	d3 e8                	shr    %cl,%eax
 8049745:	83 f0 01             	xor    $0x1,%eax
 8049748:	83 e0 01             	and    $0x1,%eax
 804974b:	80 fa 5f             	cmp    $0x5f,%dl
 804974e:	74 cd                	je     804971d <submitr+0x314>
 8049750:	84 c0                	test   %al,%al
 8049752:	74 c9                	je     804971d <submitr+0x314>
 8049754:	89 d0                	mov    %edx,%eax
 8049756:	83 e0 df             	and    $0xffffffdf,%eax
 8049759:	83 e8 41             	sub    $0x41,%eax
 804975c:	3c 19                	cmp    $0x19,%al
 804975e:	76 bd                	jbe    804971d <submitr+0x314>
 8049760:	80 fa 20             	cmp    $0x20,%dl
 8049763:	74 58                	je     80497bd <submitr+0x3b4>
 8049765:	8d 42 e0             	lea    -0x20(%edx),%eax
 8049768:	3c 5f                	cmp    $0x5f,%al
 804976a:	76 09                	jbe    8049775 <submitr+0x36c>
 804976c:	80 fa 09             	cmp    $0x9,%dl
 804976f:	0f 85 c5 03 00 00    	jne    8049b3a <submitr+0x731>
 8049775:	83 ec 0c             	sub    $0xc,%esp
 8049778:	0f b6 d2             	movzbl %dl,%edx
 804977b:	52                   	push   %edx
 804977c:	68 d4 a3 04 08       	push   $0x804a3d4
 8049781:	6a 08                	push   $0x8
 8049783:	6a 01                	push   $0x1
 8049785:	8d 84 24 68 80 00 00 	lea    0x8068(%esp),%eax
 804978c:	50                   	push   %eax
 804978d:	e8 2e f1 ff ff       	call   80488c0 <__sprintf_chk@plt>
 8049792:	0f b6 84 24 6c 80 00 	movzbl 0x806c(%esp),%eax
 8049799:	00 
 804979a:	88 07                	mov    %al,(%edi)
 804979c:	0f b6 84 24 6d 80 00 	movzbl 0x806d(%esp),%eax
 80497a3:	00 
 80497a4:	88 47 01             	mov    %al,0x1(%edi)
 80497a7:	0f b6 84 24 6e 80 00 	movzbl 0x806e(%esp),%eax
 80497ae:	00 
 80497af:	88 47 02             	mov    %al,0x2(%edi)
 80497b2:	83 c4 20             	add    $0x20,%esp
 80497b5:	8d 7f 03             	lea    0x3(%edi),%edi
 80497b8:	e9 65 ff ff ff       	jmp    8049722 <submitr+0x319>
 80497bd:	c6 07 2b             	movb   $0x2b,(%edi)
 80497c0:	8d 7f 01             	lea    0x1(%edi),%edi
 80497c3:	e9 5a ff ff ff       	jmp    8049722 <submitr+0x319>
 80497c8:	01 c6                	add    %eax,%esi
 80497ca:	29 c3                	sub    %eax,%ebx
 80497cc:	74 24                	je     80497f2 <submitr+0x3e9>
 80497ce:	83 ec 04             	sub    $0x4,%esp
 80497d1:	53                   	push   %ebx
 80497d2:	56                   	push   %esi
 80497d3:	55                   	push   %ebp
 80497d4:	e8 27 f0 ff ff       	call   8048800 <write@plt>
 80497d9:	83 c4 10             	add    $0x10,%esp
 80497dc:	85 c0                	test   %eax,%eax
 80497de:	7f e8                	jg     80497c8 <submitr+0x3bf>
 80497e0:	e8 4b f0 ff ff       	call   8048830 <__errno_location@plt>
 80497e5:	83 38 04             	cmpl   $0x4,(%eax)
 80497e8:	0f 85 b0 00 00 00    	jne    804989e <submitr+0x495>
 80497ee:	89 f8                	mov    %edi,%eax
 80497f0:	eb d6                	jmp    80497c8 <submitr+0x3bf>
 80497f2:	83 7c 24 08 00       	cmpl   $0x0,0x8(%esp)
 80497f7:	0f 88 a1 00 00 00    	js     804989e <submitr+0x495>
 80497fd:	89 6c 24 40          	mov    %ebp,0x40(%esp)
 8049801:	c7 44 24 44 00 00 00 	movl   $0x0,0x44(%esp)
 8049808:	00 
 8049809:	8d 44 24 4c          	lea    0x4c(%esp),%eax
 804980d:	89 44 24 48          	mov    %eax,0x48(%esp)
 8049811:	b9 00 20 00 00       	mov    $0x2000,%ecx
 8049816:	8d 94 24 4c 20 00 00 	lea    0x204c(%esp),%edx
 804981d:	8d 44 24 40          	lea    0x40(%esp),%eax
 8049821:	e8 32 fb ff ff       	call   8049358 <rio_readlineb>
 8049826:	85 c0                	test   %eax,%eax
 8049828:	0f 8e d6 00 00 00    	jle    8049904 <submitr+0x4fb>
 804982e:	83 ec 0c             	sub    $0xc,%esp
 8049831:	8d 84 24 58 80 00 00 	lea    0x8058(%esp),%eax
 8049838:	50                   	push   %eax
 8049839:	8d 44 24 3c          	lea    0x3c(%esp),%eax
 804983d:	50                   	push   %eax
 804983e:	8d 84 24 60 60 00 00 	lea    0x6060(%esp),%eax
 8049845:	50                   	push   %eax
 8049846:	68 db a3 04 08       	push   $0x804a3db
 804984b:	8d 84 24 68 20 00 00 	lea    0x2068(%esp),%eax
 8049852:	50                   	push   %eax
 8049853:	e8 b8 ef ff ff       	call   8048810 <__isoc99_sscanf@plt>
 8049858:	8b 44 24 4c          	mov    0x4c(%esp),%eax
 804985c:	83 c4 20             	add    $0x20,%esp
 804985f:	3d c8 00 00 00       	cmp    $0xc8,%eax
 8049864:	0f 84 a6 01 00 00    	je     8049a10 <submitr+0x607>
 804986a:	83 ec 08             	sub    $0x8,%esp
 804986d:	8d 94 24 54 80 00 00 	lea    0x8054(%esp),%edx
 8049874:	52                   	push   %edx
 8049875:	50                   	push   %eax
 8049876:	68 ec a2 04 08       	push   $0x804a2ec
 804987b:	6a ff                	push   $0xffffffff
 804987d:	6a 01                	push   $0x1
 804987f:	ff 74 24 30          	pushl  0x30(%esp)
 8049883:	e8 38 f0 ff ff       	call   80488c0 <__sprintf_chk@plt>
 8049888:	83 c4 14             	add    $0x14,%esp
 804988b:	55                   	push   %ebp
 804988c:	e8 0f f0 ff ff       	call   80488a0 <close@plt>
 8049891:	83 c4 10             	add    $0x10,%esp
 8049894:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049899:	e9 02 02 00 00       	jmp    8049aa0 <submitr+0x697>
 804989e:	8b 44 24 14          	mov    0x14(%esp),%eax
 80498a2:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
 80498a8:	c7 40 04 72 3a 20 43 	movl   $0x43203a72,0x4(%eax)
 80498af:	c7 40 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%eax)
 80498b6:	c7 40 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%eax)
 80498bd:	c7 40 10 61 62 6c 65 	movl   $0x656c6261,0x10(%eax)
 80498c4:	c7 40 14 20 74 6f 20 	movl   $0x206f7420,0x14(%eax)
 80498cb:	c7 40 18 77 72 69 74 	movl   $0x74697277,0x18(%eax)
 80498d2:	c7 40 1c 65 20 74 6f 	movl   $0x6f742065,0x1c(%eax)
 80498d9:	c7 40 20 20 74 68 65 	movl   $0x65687420,0x20(%eax)
 80498e0:	c7 40 24 20 73 65 72 	movl   $0x72657320,0x24(%eax)
 80498e7:	c7 40 28 76 65 72 00 	movl   $0x726576,0x28(%eax)
 80498ee:	83 ec 0c             	sub    $0xc,%esp
 80498f1:	55                   	push   %ebp
 80498f2:	e8 a9 ef ff ff       	call   80488a0 <close@plt>
 80498f7:	83 c4 10             	add    $0x10,%esp
 80498fa:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 80498ff:	e9 9c 01 00 00       	jmp    8049aa0 <submitr+0x697>
 8049904:	8b 44 24 14          	mov    0x14(%esp),%eax
 8049908:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
 804990e:	c7 40 04 72 3a 20 43 	movl   $0x43203a72,0x4(%eax)
 8049915:	c7 40 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%eax)
 804991c:	c7 40 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%eax)
 8049923:	c7 40 10 61 62 6c 65 	movl   $0x656c6261,0x10(%eax)
 804992a:	c7 40 14 20 74 6f 20 	movl   $0x206f7420,0x14(%eax)
 8049931:	c7 40 18 72 65 61 64 	movl   $0x64616572,0x18(%eax)
 8049938:	c7 40 1c 20 66 69 72 	movl   $0x72696620,0x1c(%eax)
 804993f:	c7 40 20 73 74 20 68 	movl   $0x68207473,0x20(%eax)
 8049946:	c7 40 24 65 61 64 65 	movl   $0x65646165,0x24(%eax)
 804994d:	c7 40 28 72 20 66 72 	movl   $0x72662072,0x28(%eax)
 8049954:	c7 40 2c 6f 6d 20 73 	movl   $0x73206d6f,0x2c(%eax)
 804995b:	c7 40 30 65 72 76 65 	movl   $0x65767265,0x30(%eax)
 8049962:	66 c7 40 34 72 00    	movw   $0x72,0x34(%eax)
 8049968:	83 ec 0c             	sub    $0xc,%esp
 804996b:	55                   	push   %ebp
 804996c:	e8 2f ef ff ff       	call   80488a0 <close@plt>
 8049971:	83 c4 10             	add    $0x10,%esp
 8049974:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049979:	e9 22 01 00 00       	jmp    8049aa0 <submitr+0x697>
 804997e:	8b 44 24 14          	mov    0x14(%esp),%eax
 8049982:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
 8049988:	c7 40 04 72 3a 20 43 	movl   $0x43203a72,0x4(%eax)
 804998f:	c7 40 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%eax)
 8049996:	c7 40 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%eax)
 804999d:	c7 40 10 61 62 6c 65 	movl   $0x656c6261,0x10(%eax)
 80499a4:	c7 40 14 20 74 6f 20 	movl   $0x206f7420,0x14(%eax)
 80499ab:	c7 40 18 72 65 61 64 	movl   $0x64616572,0x18(%eax)
 80499b2:	c7 40 1c 20 68 65 61 	movl   $0x61656820,0x1c(%eax)
 80499b9:	c7 40 20 64 65 72 73 	movl   $0x73726564,0x20(%eax)
 80499c0:	c7 40 24 20 66 72 6f 	movl   $0x6f726620,0x24(%eax)
 80499c7:	c7 40 28 6d 20 73 65 	movl   $0x6573206d,0x28(%eax)
 80499ce:	c7 40 2c 72 76 65 72 	movl   $0x72657672,0x2c(%eax)
 80499d5:	c6 40 30 00          	movb   $0x0,0x30(%eax)
 80499d9:	83 ec 0c             	sub    $0xc,%esp
 80499dc:	55                   	push   %ebp
 80499dd:	e8 be ee ff ff       	call   80488a0 <close@plt>
 80499e2:	83 c4 10             	add    $0x10,%esp
 80499e5:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 80499ea:	e9 b1 00 00 00       	jmp    8049aa0 <submitr+0x697>
 80499ef:	85 c0                	test   %eax,%eax
 80499f1:	74 4b                	je     8049a3e <submitr+0x635>
 80499f3:	b9 00 20 00 00       	mov    $0x2000,%ecx
 80499f8:	8d 94 24 4c 20 00 00 	lea    0x204c(%esp),%edx
 80499ff:	8d 44 24 40          	lea    0x40(%esp),%eax
 8049a03:	e8 50 f9 ff ff       	call   8049358 <rio_readlineb>
 8049a08:	85 c0                	test   %eax,%eax
 8049a0a:	0f 8e 6e ff ff ff    	jle    804997e <submitr+0x575>
 8049a10:	0f b6 94 24 4c 20 00 	movzbl 0x204c(%esp),%edx
 8049a17:	00 
 8049a18:	b8 0d 00 00 00       	mov    $0xd,%eax
 8049a1d:	29 d0                	sub    %edx,%eax
 8049a1f:	75 ce                	jne    80499ef <submitr+0x5e6>
 8049a21:	0f b6 94 24 4d 20 00 	movzbl 0x204d(%esp),%edx
 8049a28:	00 
 8049a29:	b8 0a 00 00 00       	mov    $0xa,%eax
 8049a2e:	29 d0                	sub    %edx,%eax
 8049a30:	75 bd                	jne    80499ef <submitr+0x5e6>
 8049a32:	0f b6 84 24 4e 20 00 	movzbl 0x204e(%esp),%eax
 8049a39:	00 
 8049a3a:	f7 d8                	neg    %eax
 8049a3c:	eb b1                	jmp    80499ef <submitr+0x5e6>
 8049a3e:	b9 00 20 00 00       	mov    $0x2000,%ecx
 8049a43:	8d 94 24 4c 20 00 00 	lea    0x204c(%esp),%edx
 8049a4a:	8d 44 24 40          	lea    0x40(%esp),%eax
 8049a4e:	e8 05 f9 ff ff       	call   8049358 <rio_readlineb>
 8049a53:	85 c0                	test   %eax,%eax
 8049a55:	7e 68                	jle    8049abf <submitr+0x6b6>
 8049a57:	83 ec 08             	sub    $0x8,%esp
 8049a5a:	8d 84 24 54 20 00 00 	lea    0x2054(%esp),%eax
 8049a61:	50                   	push   %eax
 8049a62:	8b 7c 24 20          	mov    0x20(%esp),%edi
 8049a66:	57                   	push   %edi
 8049a67:	e8 34 ed ff ff       	call   80487a0 <strcpy@plt>
 8049a6c:	89 2c 24             	mov    %ebp,(%esp)
 8049a6f:	e8 2c ee ff ff       	call   80488a0 <close@plt>
 8049a74:	0f b6 17             	movzbl (%edi),%edx
 8049a77:	b8 4f 00 00 00       	mov    $0x4f,%eax
 8049a7c:	83 c4 10             	add    $0x10,%esp
 8049a7f:	29 d0                	sub    %edx,%eax
 8049a81:	75 13                	jne    8049a96 <submitr+0x68d>
 8049a83:	0f b6 57 01          	movzbl 0x1(%edi),%edx
 8049a87:	b8 4b 00 00 00       	mov    $0x4b,%eax
 8049a8c:	29 d0                	sub    %edx,%eax
 8049a8e:	75 06                	jne    8049a96 <submitr+0x68d>
 8049a90:	0f b6 47 02          	movzbl 0x2(%edi),%eax
 8049a94:	f7 d8                	neg    %eax
 8049a96:	85 c0                	test   %eax,%eax
 8049a98:	0f 95 c0             	setne  %al
 8049a9b:	0f b6 c0             	movzbl %al,%eax
 8049a9e:	f7 d8                	neg    %eax
 8049aa0:	8b bc 24 4c a0 00 00 	mov    0xa04c(%esp),%edi
 8049aa7:	65 33 3d 14 00 00 00 	xor    %gs:0x14,%edi
 8049aae:	0f 85 2a 01 00 00    	jne    8049bde <submitr+0x7d5>
 8049ab4:	81 c4 5c a0 00 00    	add    $0xa05c,%esp
 8049aba:	5b                   	pop    %ebx
 8049abb:	5e                   	pop    %esi
 8049abc:	5f                   	pop    %edi
 8049abd:	5d                   	pop    %ebp
 8049abe:	c3                   	ret    
 8049abf:	8b 44 24 14          	mov    0x14(%esp),%eax
 8049ac3:	c7 00 45 72 72 6f    	movl   $0x6f727245,(%eax)
 8049ac9:	c7 40 04 72 3a 20 43 	movl   $0x43203a72,0x4(%eax)
 8049ad0:	c7 40 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%eax)
 8049ad7:	c7 40 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%eax)
 8049ade:	c7 40 10 61 62 6c 65 	movl   $0x656c6261,0x10(%eax)
 8049ae5:	c7 40 14 20 74 6f 20 	movl   $0x206f7420,0x14(%eax)
 8049aec:	c7 40 18 72 65 61 64 	movl   $0x64616572,0x18(%eax)
 8049af3:	c7 40 1c 20 73 74 61 	movl   $0x61747320,0x1c(%eax)
 8049afa:	c7 40 20 74 75 73 20 	movl   $0x20737574,0x20(%eax)
 8049b01:	c7 40 24 6d 65 73 73 	movl   $0x7373656d,0x24(%eax)
 8049b08:	c7 40 28 61 67 65 20 	movl   $0x20656761,0x28(%eax)
 8049b0f:	c7 40 2c 66 72 6f 6d 	movl   $0x6d6f7266,0x2c(%eax)
 8049b16:	c7 40 30 20 73 65 72 	movl   $0x72657320,0x30(%eax)
 8049b1d:	c7 40 34 76 65 72 00 	movl   $0x726576,0x34(%eax)
 8049b24:	83 ec 0c             	sub    $0xc,%esp
 8049b27:	55                   	push   %ebp
 8049b28:	e8 73 ed ff ff       	call   80488a0 <close@plt>
 8049b2d:	83 c4 10             	add    $0x10,%esp
 8049b30:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049b35:	e9 66 ff ff ff       	jmp    8049aa0 <submitr+0x697>
 8049b3a:	a1 1c a3 04 08       	mov    0x804a31c,%eax
 8049b3f:	8b 5c 24 14          	mov    0x14(%esp),%ebx
 8049b43:	89 03                	mov    %eax,(%ebx)
 8049b45:	a1 5b a3 04 08       	mov    0x804a35b,%eax
 8049b4a:	89 43 3f             	mov    %eax,0x3f(%ebx)
 8049b4d:	8d 7b 04             	lea    0x4(%ebx),%edi
 8049b50:	83 e7 fc             	and    $0xfffffffc,%edi
 8049b53:	29 fb                	sub    %edi,%ebx
 8049b55:	89 d8                	mov    %ebx,%eax
 8049b57:	be 1c a3 04 08       	mov    $0x804a31c,%esi
 8049b5c:	29 de                	sub    %ebx,%esi
 8049b5e:	83 c0 43             	add    $0x43,%eax
 8049b61:	c1 e8 02             	shr    $0x2,%eax
 8049b64:	89 c1                	mov    %eax,%ecx
 8049b66:	f3 a5                	rep movsl %ds:(%esi),%es:(%edi)
 8049b68:	83 ec 0c             	sub    $0xc,%esp
 8049b6b:	55                   	push   %ebp
 8049b6c:	e8 2f ed ff ff       	call   80488a0 <close@plt>
 8049b71:	83 c4 10             	add    $0x10,%esp
 8049b74:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049b79:	e9 22 ff ff ff       	jmp    8049aa0 <submitr+0x697>
 8049b7e:	8d 84 24 4c 40 00 00 	lea    0x404c(%esp),%eax
 8049b85:	50                   	push   %eax
 8049b86:	ff 74 24 14          	pushl  0x14(%esp)
 8049b8a:	ff 74 24 14          	pushl  0x14(%esp)
 8049b8e:	ff 74 24 14          	pushl  0x14(%esp)
 8049b92:	68 60 a3 04 08       	push   $0x804a360
 8049b97:	68 00 20 00 00       	push   $0x2000
 8049b9c:	6a 01                	push   $0x1
 8049b9e:	8d bc 24 68 20 00 00 	lea    0x2068(%esp),%edi
 8049ba5:	57                   	push   %edi
 8049ba6:	e8 15 ed ff ff       	call   80488c0 <__sprintf_chk@plt>
 8049bab:	b8 00 00 00 00       	mov    $0x0,%eax
 8049bb0:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
 8049bb5:	f2 ae                	repnz scas %es:(%edi),%al
 8049bb7:	f7 d1                	not    %ecx
 8049bb9:	8d 41 ff             	lea    -0x1(%ecx),%eax
 8049bbc:	89 44 24 28          	mov    %eax,0x28(%esp)
 8049bc0:	83 c4 20             	add    $0x20,%esp
 8049bc3:	89 c3                	mov    %eax,%ebx
 8049bc5:	8d b4 24 4c 20 00 00 	lea    0x204c(%esp),%esi
 8049bcc:	bf 00 00 00 00       	mov    $0x0,%edi
 8049bd1:	85 c0                	test   %eax,%eax
 8049bd3:	0f 85 f5 fb ff ff    	jne    80497ce <submitr+0x3c5>
 8049bd9:	e9 1f fc ff ff       	jmp    80497fd <submitr+0x3f4>
 8049bde:	e8 ad eb ff ff       	call   8048790 <__stack_chk_fail@plt>

08049be3 <init_timeout>:
 8049be3:	53                   	push   %ebx
 8049be4:	83 ec 08             	sub    $0x8,%esp
 8049be7:	8b 5c 24 10          	mov    0x10(%esp),%ebx
 8049beb:	85 db                	test   %ebx,%ebx
 8049bed:	74 24                	je     8049c13 <init_timeout+0x30>
 8049bef:	83 ec 08             	sub    $0x8,%esp
 8049bf2:	68 35 93 04 08       	push   $0x8049335
 8049bf7:	6a 0e                	push   $0xe
 8049bf9:	e8 62 eb ff ff       	call   8048760 <signal@plt>
 8049bfe:	85 db                	test   %ebx,%ebx
 8049c00:	b8 00 00 00 00       	mov    $0x0,%eax
 8049c05:	0f 48 d8             	cmovs  %eax,%ebx
 8049c08:	89 1c 24             	mov    %ebx,(%esp)
 8049c0b:	e8 70 eb ff ff       	call   8048780 <alarm@plt>
 8049c10:	83 c4 10             	add    $0x10,%esp
 8049c13:	83 c4 08             	add    $0x8,%esp
 8049c16:	5b                   	pop    %ebx
 8049c17:	c3                   	ret    

08049c18 <init_driver>:
 8049c18:	57                   	push   %edi
 8049c19:	56                   	push   %esi
 8049c1a:	53                   	push   %ebx
 8049c1b:	83 ec 28             	sub    $0x28,%esp
 8049c1e:	8b 74 24 38          	mov    0x38(%esp),%esi
 8049c22:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 8049c28:	89 44 24 24          	mov    %eax,0x24(%esp)
 8049c2c:	31 c0                	xor    %eax,%eax
 8049c2e:	6a 01                	push   $0x1
 8049c30:	6a 0d                	push   $0xd
 8049c32:	e8 29 eb ff ff       	call   8048760 <signal@plt>
 8049c37:	83 c4 08             	add    $0x8,%esp
 8049c3a:	6a 01                	push   $0x1
 8049c3c:	6a 1d                	push   $0x1d
 8049c3e:	e8 1d eb ff ff       	call   8048760 <signal@plt>
 8049c43:	83 c4 08             	add    $0x8,%esp
 8049c46:	6a 01                	push   $0x1
 8049c48:	6a 1d                	push   $0x1d
 8049c4a:	e8 11 eb ff ff       	call   8048760 <signal@plt>
 8049c4f:	83 c4 0c             	add    $0xc,%esp
 8049c52:	6a 00                	push   $0x0
 8049c54:	6a 01                	push   $0x1
 8049c56:	6a 02                	push   $0x2
 8049c58:	e8 f3 eb ff ff       	call   8048850 <socket@plt>
 8049c5d:	83 c4 10             	add    $0x10,%esp
 8049c60:	85 c0                	test   %eax,%eax
 8049c62:	0f 88 a9 00 00 00    	js     8049d11 <init_driver+0xf9>
 8049c68:	89 c3                	mov    %eax,%ebx
 8049c6a:	83 ec 0c             	sub    $0xc,%esp
 8049c6d:	68 ec a3 04 08       	push   $0x804a3ec
 8049c72:	e8 f9 eb ff ff       	call   8048870 <gethostbyname@plt>
 8049c77:	83 c4 10             	add    $0x10,%esp
 8049c7a:	85 c0                	test   %eax,%eax
 8049c7c:	0f 84 da 00 00 00    	je     8049d5c <init_driver+0x144>
 8049c82:	8d 7c 24 0c          	lea    0xc(%esp),%edi
 8049c86:	c7 44 24 0c 00 00 00 	movl   $0x0,0xc(%esp)
 8049c8d:	00 
 8049c8e:	c7 44 24 10 00 00 00 	movl   $0x0,0x10(%esp)
 8049c95:	00 
 8049c96:	c7 44 24 14 00 00 00 	movl   $0x0,0x14(%esp)
 8049c9d:	00 
 8049c9e:	c7 44 24 18 00 00 00 	movl   $0x0,0x18(%esp)
 8049ca5:	00 
 8049ca6:	66 c7 44 24 0c 02 00 	movw   $0x2,0xc(%esp)
 8049cad:	6a 0c                	push   $0xc
 8049caf:	ff 70 0c             	pushl  0xc(%eax)
 8049cb2:	8b 40 10             	mov    0x10(%eax),%eax
 8049cb5:	ff 30                	pushl  (%eax)
 8049cb7:	8d 44 24 1c          	lea    0x1c(%esp),%eax
 8049cbb:	50                   	push   %eax
 8049cbc:	e8 0f eb ff ff       	call   80487d0 <__memmove_chk@plt>
 8049cc1:	66 c7 44 24 1e 3b 6e 	movw   $0x6e3b,0x1e(%esp)
 8049cc8:	83 c4 0c             	add    $0xc,%esp
 8049ccb:	6a 10                	push   $0x10
 8049ccd:	57                   	push   %edi
 8049cce:	53                   	push   %ebx
 8049ccf:	e8 bc eb ff ff       	call   8048890 <connect@plt>
 8049cd4:	83 c4 10             	add    $0x10,%esp
 8049cd7:	85 c0                	test   %eax,%eax
 8049cd9:	0f 88 e9 00 00 00    	js     8049dc8 <init_driver+0x1b0>
 8049cdf:	83 ec 0c             	sub    $0xc,%esp
 8049ce2:	53                   	push   %ebx
 8049ce3:	e8 b8 eb ff ff       	call   80488a0 <close@plt>
 8049ce8:	66 c7 06 4f 4b       	movw   $0x4b4f,(%esi)
 8049ced:	c6 46 02 00          	movb   $0x0,0x2(%esi)
 8049cf1:	83 c4 10             	add    $0x10,%esp
 8049cf4:	b8 00 00 00 00       	mov    $0x0,%eax
 8049cf9:	8b 54 24 1c          	mov    0x1c(%esp),%edx
 8049cfd:	65 33 15 14 00 00 00 	xor    %gs:0x14,%edx
 8049d04:	0f 85 eb 00 00 00    	jne    8049df5 <init_driver+0x1dd>
 8049d0a:	83 c4 20             	add    $0x20,%esp
 8049d0d:	5b                   	pop    %ebx
 8049d0e:	5e                   	pop    %esi
 8049d0f:	5f                   	pop    %edi
 8049d10:	c3                   	ret    
 8049d11:	c7 06 45 72 72 6f    	movl   $0x6f727245,(%esi)
 8049d17:	c7 46 04 72 3a 20 43 	movl   $0x43203a72,0x4(%esi)
 8049d1e:	c7 46 08 6c 69 65 6e 	movl   $0x6e65696c,0x8(%esi)
 8049d25:	c7 46 0c 74 20 75 6e 	movl   $0x6e752074,0xc(%esi)
 8049d2c:	c7 46 10 61 62 6c 65 	movl   $0x656c6261,0x10(%esi)
 8049d33:	c7 46 14 20 74 6f 20 	movl   $0x206f7420,0x14(%esi)
 8049d3a:	c7 46 18 63 72 65 61 	movl   $0x61657263,0x18(%esi)
 8049d41:	c7 46 1c 74 65 20 73 	movl   $0x73206574,0x1c(%esi)
 8049d48:	c7 46 20 6f 63 6b 65 	movl   $0x656b636f,0x20(%esi)
 8049d4f:	66 c7 46 24 74 00    	movw   $0x74,0x24(%esi)
 8049d55:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049d5a:	eb 9d                	jmp    8049cf9 <init_driver+0xe1>
 8049d5c:	c7 06 45 72 72 6f    	movl   $0x6f727245,(%esi)
 8049d62:	c7 46 04 72 3a 20 44 	movl   $0x44203a72,0x4(%esi)
 8049d69:	c7 46 08 4e 53 20 69 	movl   $0x6920534e,0x8(%esi)
 8049d70:	c7 46 0c 73 20 75 6e 	movl   $0x6e752073,0xc(%esi)
 8049d77:	c7 46 10 61 62 6c 65 	movl   $0x656c6261,0x10(%esi)
 8049d7e:	c7 46 14 20 74 6f 20 	movl   $0x206f7420,0x14(%esi)
 8049d85:	c7 46 18 72 65 73 6f 	movl   $0x6f736572,0x18(%esi)
 8049d8c:	c7 46 1c 6c 76 65 20 	movl   $0x2065766c,0x1c(%esi)
 8049d93:	c7 46 20 73 65 72 76 	movl   $0x76726573,0x20(%esi)
 8049d9a:	c7 46 24 65 72 20 61 	movl   $0x61207265,0x24(%esi)
 8049da1:	c7 46 28 64 64 72 65 	movl   $0x65726464,0x28(%esi)
 8049da8:	66 c7 46 2c 73 73    	movw   $0x7373,0x2c(%esi)
 8049dae:	c6 46 2e 00          	movb   $0x0,0x2e(%esi)
 8049db2:	83 ec 0c             	sub    $0xc,%esp
 8049db5:	53                   	push   %ebx
 8049db6:	e8 e5 ea ff ff       	call   80488a0 <close@plt>
 8049dbb:	83 c4 10             	add    $0x10,%esp
 8049dbe:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049dc3:	e9 31 ff ff ff       	jmp    8049cf9 <init_driver+0xe1>
 8049dc8:	83 ec 0c             	sub    $0xc,%esp
 8049dcb:	68 ec a3 04 08       	push   $0x804a3ec
 8049dd0:	68 ac a3 04 08       	push   $0x804a3ac
 8049dd5:	6a ff                	push   $0xffffffff
 8049dd7:	6a 01                	push   $0x1
 8049dd9:	56                   	push   %esi
 8049dda:	e8 e1 ea ff ff       	call   80488c0 <__sprintf_chk@plt>
 8049ddf:	83 c4 14             	add    $0x14,%esp
 8049de2:	53                   	push   %ebx
 8049de3:	e8 b8 ea ff ff       	call   80488a0 <close@plt>
 8049de8:	83 c4 10             	add    $0x10,%esp
 8049deb:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049df0:	e9 04 ff ff ff       	jmp    8049cf9 <init_driver+0xe1>
 8049df5:	e8 96 e9 ff ff       	call   8048790 <__stack_chk_fail@plt>

08049dfa <driver_post>:
 8049dfa:	53                   	push   %ebx
 8049dfb:	83 ec 08             	sub    $0x8,%esp
 8049dfe:	8b 54 24 10          	mov    0x10(%esp),%edx
 8049e02:	8b 44 24 18          	mov    0x18(%esp),%eax
 8049e06:	8b 5c 24 1c          	mov    0x1c(%esp),%ebx
 8049e0a:	85 c0                	test   %eax,%eax
 8049e0c:	75 17                	jne    8049e25 <driver_post+0x2b>
 8049e0e:	85 d2                	test   %edx,%edx
 8049e10:	74 05                	je     8049e17 <driver_post+0x1d>
 8049e12:	80 3a 00             	cmpb   $0x0,(%edx)
 8049e15:	75 34                	jne    8049e4b <driver_post+0x51>
 8049e17:	66 c7 03 4f 4b       	movw   $0x4b4f,(%ebx)
 8049e1c:	c6 43 02 00          	movb   $0x0,0x2(%ebx)
 8049e20:	83 c4 08             	add    $0x8,%esp
 8049e23:	5b                   	pop    %ebx
 8049e24:	c3                   	ret    
 8049e25:	83 ec 04             	sub    $0x4,%esp
 8049e28:	ff 74 24 18          	pushl  0x18(%esp)
 8049e2c:	68 fa a3 04 08       	push   $0x804a3fa
 8049e31:	6a 01                	push   $0x1
 8049e33:	e8 08 ea ff ff       	call   8048840 <__printf_chk@plt>
 8049e38:	66 c7 03 4f 4b       	movw   $0x4b4f,(%ebx)
 8049e3d:	c6 43 02 00          	movb   $0x0,0x2(%ebx)
 8049e41:	83 c4 10             	add    $0x10,%esp
 8049e44:	b8 00 00 00 00       	mov    $0x0,%eax
 8049e49:	eb d5                	jmp    8049e20 <driver_post+0x26>
 8049e4b:	83 ec 04             	sub    $0x4,%esp
 8049e4e:	53                   	push   %ebx
 8049e4f:	ff 74 24 1c          	pushl  0x1c(%esp)
 8049e53:	68 11 a4 04 08       	push   $0x804a411
 8049e58:	52                   	push   %edx
 8049e59:	68 19 a4 04 08       	push   $0x804a419
 8049e5e:	68 6e 3b 00 00       	push   $0x3b6e
 8049e63:	68 ec a3 04 08       	push   $0x804a3ec
 8049e68:	e8 9c f5 ff ff       	call   8049409 <submitr>
 8049e6d:	83 c4 20             	add    $0x20,%esp
 8049e70:	eb ae                	jmp    8049e20 <driver_post+0x26>
 8049e72:	66 90                	xchg   %ax,%ax
 8049e74:	66 90                	xchg   %ax,%ax
 8049e76:	66 90                	xchg   %ax,%ax
 8049e78:	66 90                	xchg   %ax,%ax
 8049e7a:	66 90                	xchg   %ax,%ax
 8049e7c:	66 90                	xchg   %ax,%ax
 8049e7e:	66 90                	xchg   %ax,%ax

08049e80 <__libc_csu_init>:
 8049e80:	55                   	push   %ebp
 8049e81:	57                   	push   %edi
 8049e82:	56                   	push   %esi
 8049e83:	53                   	push   %ebx
 8049e84:	e8 87 ea ff ff       	call   8048910 <__x86.get_pc_thunk.bx>
 8049e89:	81 c3 77 21 00 00    	add    $0x2177,%ebx
 8049e8f:	83 ec 0c             	sub    $0xc,%esp
 8049e92:	8b 6c 24 20          	mov    0x20(%esp),%ebp
 8049e96:	8d b3 0c ff ff ff    	lea    -0xf4(%ebx),%esi
 8049e9c:	e8 53 e8 ff ff       	call   80486f4 <_init>
 8049ea1:	8d 83 08 ff ff ff    	lea    -0xf8(%ebx),%eax
 8049ea7:	29 c6                	sub    %eax,%esi
 8049ea9:	c1 fe 02             	sar    $0x2,%esi
 8049eac:	85 f6                	test   %esi,%esi
 8049eae:	74 25                	je     8049ed5 <__libc_csu_init+0x55>
 8049eb0:	31 ff                	xor    %edi,%edi
 8049eb2:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
 8049eb8:	83 ec 04             	sub    $0x4,%esp
 8049ebb:	ff 74 24 2c          	pushl  0x2c(%esp)
 8049ebf:	ff 74 24 2c          	pushl  0x2c(%esp)
 8049ec3:	55                   	push   %ebp
 8049ec4:	ff 94 bb 08 ff ff ff 	call   *-0xf8(%ebx,%edi,4)
 8049ecb:	83 c7 01             	add    $0x1,%edi
 8049ece:	83 c4 10             	add    $0x10,%esp
 8049ed1:	39 fe                	cmp    %edi,%esi
 8049ed3:	75 e3                	jne    8049eb8 <__libc_csu_init+0x38>
 8049ed5:	83 c4 0c             	add    $0xc,%esp
 8049ed8:	5b                   	pop    %ebx
 8049ed9:	5e                   	pop    %esi
 8049eda:	5f                   	pop    %edi
 8049edb:	5d                   	pop    %ebp
 8049edc:	c3                   	ret    
 8049edd:	8d 76 00             	lea    0x0(%esi),%esi

08049ee0 <__libc_csu_fini>:
 8049ee0:	f3 c3                	repz ret 

Disassembly of section .fini:

08049ee4 <_fini>:
 8049ee4:	53                   	push   %ebx
 8049ee5:	83 ec 08             	sub    $0x8,%esp
 8049ee8:	e8 23 ea ff ff       	call   8048910 <__x86.get_pc_thunk.bx>
 8049eed:	81 c3 13 21 00 00    	add    $0x2113,%ebx
 8049ef3:	83 c4 08             	add    $0x8,%esp
 8049ef6:	5b                   	pop    %ebx
 8049ef7:	c3                   	ret    
