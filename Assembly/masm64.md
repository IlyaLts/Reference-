# Registers
| Register | Volatile/Nonvolatile | Usage |
| --- | --- | --- |
| RAX | Volatile | Return value register |
| RBX | Nonvolatile | Callee-saved register |
| RCX | Volatile | First integer argument |
| RDX | Volatile | Second integer argument |
| R8 | Volatile | Third integer argument |
| R9 | Volatile | Fourth integer argument |
| R10 | Volatile | Scratch register |
| R11 | Volatile | Scratch register |
| R12 | Nonvolatile | Callee-saved register |
| R13 | Nonvolatile | Callee-saved register |
| R14 | Nonvolatile | Callee-saved register |
| R15 | Nonvolatile | Callee-saved register |
| RDI | Nonvolatile | Callee-saved register |
| RSI | Nonvolatile | Callee-saved register |
| RBP | Nonvolatile | Optional frame pointer |
| RSP | Nonvolatile | Stack pointer |
| RIP | Nonvolatile | Instruction pointer |

| SSE Register | Volatile/Nonvolatile | Usage |
| --- | --- | --- |
| XMM0 | Volatile | First floating-point argument |
| XMM1 | Volatile | Second floating-point argument |
| XMM2 | Volatile | Third floating-point argument |
| XMM3 | Volatile | Fourth floating-point argument |
| XMM4 | Volatile | Scratch register |
| XMM5 | Volatile | Scratch register |
| XMM6-XMM15 | Nonvolatile | Callee-saved registers |

| 128-bit register | 64-bit register | Lower 32 bits | Lower 16 bits | Higher 8 bits | Lower 8 bits |
| --- | --- | --- | --- | --- | --- |
|  | RAX | EAX | AX | AH | AL |
|  | RBX | EBX | BX | BH | BL |
|  | RCX | ECX | CX | CH | CL |
|  | RDX | EDX | DX | DH | DL |
|  | R8 | R8D | R8W |  | R8B |
|  | R9 | R9D | R9W |  | R9B |
|  | R10 | R10D | R10W |  | R10B |
|  | R11 | R11D | R11W |  | R11B |
|  | R12 | R12D | R12W |  | R12B |
|  | R13 | R13D | R13W |  | R13B |
|  | R14 | R14D | R14W |  | R14B |
|  | R15 | R15D | R15W |  | R15B |
|  | RDI | EDI | DI |  | DIL |
|  | RSI | ESI | SI |  | SIL |
|  | RBP | EBP | BP |  | BPL |
|  | RSP | ESP | SP |  | SPL |
|  | RIP | EIP | IP |  |  |
| XMM0-XMM15 |  |  |  |  |  |

# Data types
| Bits | Name | Short name |
| --- | --- | --- |
| 8 | BYTE | DB |
| 16 | WORD | DW |
| 32 | DWORD | DD |
| 64 | QWORD | DQ |
| 80 | TWORD | DT |
| 128 | OWORD |  |

- `REAL4`, `REAL8`, `REAL10` ; define floating-point data of 32-bit, 64-bit, and 80-bit respectively
- `PTR` ; override the default size of a memory operand
- `TYPE` ; return the size in bytes of a variable or a type
- `LENGTH` ; return the number of elements in an array
- `SIZEOF` ; return the size in bytes of an array

Some examples of using these directives and operators are:

```
var1 BYTE 0x12 ; define a byte variable with value 0x12
var2 DWORD 12345678h ; define a dword variable with value 0x12345678
var3 REAL4 3.14 ; define a real4 variable with value 3.14
mov al, BYTE PTR [var1] ; move the byte value at var1 into al
mov rax, QWORD PTR [var2] ; move the qword value at var2 into rax
movss xmm0, REAL4 PTR [var3] ; move the real4 value at var3 into xmm0
mov rcx, TYPE var1 ; move the size of var1 (1 byte) into rcx
array1 BYTE 10 DUP(0) ; define an array of 10 bytes initialized to zero
mov rdx, LENGTH array1 ; move the length of array1 (10 elements) into rdx
mov r8, SIZEOF array1 ; move the size of array1 (10 bytes) into r8
```

# EQU directive
The EQU directive is used for defining constants in x64 MASM assembly. The syntax of the EQU directive is as follows:

` CONSTANT_NAME EQU expression `

For example, you can define a constant for the window style like this:

` WS_OVERLAPPEDWINDOW equ 0CF0000h `

You can then use this constant value in your code, like this:

` mov r9d, WS_OVERLAPPEDWINDOW ; third argument: dwStyle `

# DUP
DUP is an operator that means duplicate. It is used to declare an array of data by repeating a value or
an expression a specified number of times.

For example, ` array1 db 10 DUP (0) ` declares an array of 10 bytes,
each initialized to zero.

# ? symbol in data section
According to the web search results, the ? symbol in the data section of x64 MASM assembly means
that the data is uninitialized. This means that the data is not stored in the compiled binary,
but allocated by the OS loader at run-time. This reduces the size of the compiled program.
For example, ` .data? bigArray DWORD 5000 DUP (?) ` declares a large block of uninitialized data.

# Difference between .data and .data?
The main difference between .data and .data? in MASM x64 assembly is that .data declares initialized data,
while .data? declares uninitialized data. Initialized data is stored in the compiled binary,
while uninitialized data is allocated by the OS loader at run-time. This can reduce the size of the compiled program.

# Shadow space
Shadow space in x64 masm assembly is a reserved area on the stack that is used to store the first four arguments of a function call. Shadow space is required by the Windows x64 calling convention, which specifies that the first four arguments are passed in registers (rcx, rdx, r8, and r9), but the called function can save them on the stack if needed. Shadow space can also be used for debugging purposes, as it allows the debugger to inspect the arguments of a function call.

You should add shadow space in x64 masm assembly whenever you call a function that follows the Windows x64 calling convention. The size of the shadow space is 32 bytes (8 bytes for each argument), plus 8 bytes for the return address that is pushed by the call instruction. Therefore, you should subtract 40 bytes from rsp before calling a function, and add 40 bytes after returning from it. For example:

```
sub rsp, 40 ; allocate shadow space
mov rcx, arg1 ; first argument
mov rdx, arg2 ; second argument
mov r8, arg3 ; third argument
mov r9, arg4 ; fourth argument
call MyFunc ; call function
add rsp, 40 ; deallocate shadow space
```
Note that you should also maintain the stack alignment of 16 bytes when allocating shadow space. This means that if you push or pop any values on the stack before or after calling a function, you should adjust the size of the shadow space accordingly. For example:

```
push rax ; save rax on stack
sub rsp, 32 ; allocate shadow space (32 instead of 40 because push already subtracted 8)
mov rcx, arg1 ; first argument
mov rdx, arg2 ; second argument
mov r8, arg3 ; third argument
mov r9, arg4 ; fourth argument
call MyFunc ; call function
add rsp, 32 ; deallocate shadow space
pop rax ; restore rax from stack
```

# CALL instruction
The call instruction in x64 assembly language is used to invoke a subroutine or a function. It pushes the address of the next instruction (the return address) onto the stack and then jumps to the target address specified by the operand. There are different variants of the call instruction depending on the operand type:

```
call rel32 ; call a near procedure using a 32-bit relative offset
call r/m64 ; call a near procedure using a 64-bit register or memory operand
callf ptr16:32 ; call a far procedure using a 16-bit selector and a 32-bit offset
callf m16:64 ; call a far procedure using a memory operand that contains a 16-bit selector and a 64-bit offset
```

Some examples of call instructions in x64 assembly are:

```
call foo ; call a near procedure named foo
call [rax] ; call a near procedure whose address is in rax
callf 0x1234:0x5678 ; call a far procedure with selector 0x1234 and offset 0x5678
callf [rbx] ; call a far procedure whose selector and offset are in rbx
```

# Difference between INVOKE and CALL
The main difference between INVOKE and CALL in MASM x64 assembly is that INVOKE is a directive that
generates a CALL instruction and the code to pass the arguments to the function according to the calling convention
CALL is an instruction that transfers control to the function at the address given by an expression.

For example, if you have a function that takes two arguments and follows the Windows x64 calling convention, you can use INVOKE like this:

` INVOKE foo, 10, 20 `

This will generate the following code:
```
MOV RCX, 10 ; first argument
MOV RDX, 20 ; second argument
SUB RSP, 32 ; reserve shadow space
CALL foo ; call function
ADD RSP, 32 ; restore stack pointer
```

Alternatively, you can use CALL directly like this:
```
MOV RCX, 10 ; first argument
MOV RDX, 20 ; second argument
SUB RSP, 32 ; reserve shadow space
CALL foo ; call function
ADD RSP, 32 ; restore stack pointer
```

The advantage of using INVOKE is that it simplifies the code and handles the calling convention for you. The disadvantage is that it may not be available or supported in some versions of MASM or for some functions. In that case, you have to use CALL and manage the arguments and stack yourself.

# RET instruction
The ret instruction is used to return from a procedure or a function. It transfers control to the return address located
on the stack. This address is usually placed on the stack by a call instruction, which invokes the procedure or function.
The ret instruction pops the return address from the stack and jumps to it, resuming the execution flow at the instruction 
following the call. The ret instruction can also take an optional argument that specifies how many bytes to pop from the stack after returning. This is useful for some calling conventions that require the callee to clean up the stack arguments.

For example:
```
; a simple function that adds two numbers
add_func:
    push ebp
    mov ebp, esp
    mov eax, [ebp+8]  ; get first argument
    add eax, [ebp+12] ; add second argument
    mov esp, ebp
    pop ebp
    ret 8             ; return and pop 8 bytes of arguments

; main program
main:
    push 10           ; push second argument
    push 5            ; push first argument
    call add_func     ; call function
    ; eax now contains 15
```

Yes, there is a way to move 32 bits from rax to xmm0 in x64 masm assembly. You can use the movd instruction, which moves a doubleword (32 bits) between a general-purpose register and a low-order doubleword of an xmm register. For example:

movd xmm0, eax ; move the low 32 bits of rax to xmm0

# Conditional jumps
| Instruction | Mnemonic | C example | Flags |
| --- | --- | --- | --- |
| j (jmp) |	Jump | break; |	(Unconditional) |
| je (jz) |	Jump if equal (zero) | if (x == y) | ZF |
| jne (jnz) | Jump if not equal (nonzero) |	if (x != y) | !ZF |
| jg (jnle) | Jump if greater |	if (x > y), signed | !ZF && !(SF ^ OF) |
| jge (jnl) | Jump if greater or equal | if (x >= y), signed | !(SF ^ OF) |
| jl (jnge) | Jump if less | if (x < y), signed | SF ^ OF |
| jle (jng) | Jump if less or equal | if (x <= y), signed | (SF ^ OF) || ZF |
| ja (jnbe) | Jump if above | if (x > y), unsigned | !CF && !ZF |
| jae (jnb) | Jump if above or equal | if (x >= y), unsigned | !CF |
| jb (jnae) | Jump if below | if (x < y), unsigned | CF |
| jbe (jna) | Jump if below or equal | if (x <= y), unsigned | CF || ZF |
| js | Jump if sign bit | if (x < 0), signed | SF |
| jns |	Jump if not sign bit | if (x >= 0), signed | !SF |
| jc | Jump if carry bit | N/A | CF |
| jnc |	Jump if not carry bit |	N/A | !CF |
| jo | Jump if overflow bit | N/A |	OF |
| jno |	Jump if not overflow bit | N/A | !OF |

# Difference between JMP and LOOP instructions
JMP and LOOP are two types of instructions in assembly language that can be used to implement loops. JMP is an unconditional jump that transfers the control flow to a specified address. LOOP is a conditional jump that decrements the ECX register and jumps to a label if ECX is not zero.

The difference between JMP and LOOP is that JMP does not change any register value or flag, while LOOP modifies the ECX register and the zero flag. JMP can be used to create any kind of loop, while LOOP can only be used for counting loops that use ECX as the counter. JMP can also be used to exit a loop or jump to another part of the code, while LOOP can only jump back to the same label.

Some advantages of using LOOP over JMP are that it is more readable, concise and saves one instruction (DEC ECX). Some disadvantages are that it is less flexible, slower and only works with ECX1. Depending on the architecture and the optimization level, one may be preferred over the other.

# Comparing two float values
One possible way to compare two float values in xmm0 and xmm1 in x64 masm assembly is to use the comiss instruction, which compares two scalar single-precision floating-point values and sets the EFLAGS register accordingly1. Then, you can use conditional jump instructions such as jb (jump below) or ja (jump above) to branch based on the comparison result.

For example:
```
movss xmm0, [b] ; load float value from b
movss xmm1, [c] ; load float value from c
comiss xmm0, xmm1 ; compare xmm0 and xmm1
jb less_than ; jump if b < c
ja greater_than ; jump if b > c
; otherwise b == c

less_than: ; do something if b < c greater_than: ; do something if b > c
```

# ALIGN
To align global variables in masm x64, you can use the ALIGN directive with a number that specifies the alignment boundary in bytes. For example, ALIGN 16 will align the next variable or instruction on a 16-byte boundary. This can improve the performance and memory access of your code.

However, the ALIGN directive does not work for local variables that are declared on the stack with the LOCAL directive. The stack alignment is determined by the operating system and the calling convention. For Windows x64, the stack is aligned on an 8-byte boundary by default. If you need a different alignment for your local variables, you may need to use manual padding or alignment instructions.

Here is an example of using the ALIGN directive for global variables in masm x64:

```
.data
; align global variables on 16-byte boundary
ALIGN 16
var1 QWORD 12345678h
var2 QWORD 87654321h
var3 QWORD 0

.code
main proc
    ; declare local variables on stack
    LOCAL var4:QWORD
    LOCAL var5:QWORD
    LOCAL var6:QWORD

    ; do something with variables

    ret
main endp
```

Alternatively, you can use the grouped sections feature of PECOFF to create a new section with a different alignment and merge it with the .text section at link time. For example, you can use something like this:

```
_TEXT$FOO SEGMENT ALIGN (64)
align 64
_TEXT$FOO ENDS
```

This will create a new section named `_TEXT$FOO` with an alignment of 64 bytes and merge it with the `_TEXT` section after the `$` sign is ignored. This way, you can have some code or data aligned on a 64-byte boundary within the `_TEXT` section.

# LABEL directive
A label in x64 masm assembly is a symbol that represents the address of a memory location or a code block. It can be used to name data or instructions, and to create references for branching or looping2. A label can be declared with the LABEL directive, which assigns the current location-counter value and the given type to the label name. For example:

```
myLabel LABEL DWORD ; declares a label for a DWORD variable
myProc  LABEL PROC  ; declares a label for a procedure
```

Another example:

```
myLabel LABEL DWORD ; declares a label for a DWORD variable
myProc  LABEL PROC  ; declares a label for a procedure

mov eax, myLabel ; moves the value of the DWORD variable to eax
call myProc      ; calls the procedure
```

# TYPEDEF directive
Typedef creates a new type name for an existing type. It can be used to simplify declarations and improve readability. For example:

```
TYPEDEF DWORD PTR DWORDPTR ; defines DWORDPTR as a pointer to a DWORD
TYPEDEF REAL4 REAL ; defines REAL as an alias for REAL4
```

# Difference between TYPEDEF and LABEL
A typedef in x64 masm assembly is a directive that creates a new type name for an existing type. It can be used to simplify declarations and improve readability. For example:

```
TYPEDEF DWORD PTR DWORDPTR ; defines DWORDPTR as a pointer to a DWORD
TYPEDEF REAL4 REAL ; defines REAL as an alias for REAL4
```

A label in x64 masm assembly is a symbol that represents the address of a memory location or a code block. It can be used to name data or instructions, and to create references for branching or looping. A label can be declared with the LABEL directive, which assigns the current location-counter value and the given type to the label name. For example:

```
myLabel LABEL DWORD ; declares a label for a DWORD variable
myProc  LABEL PROC  ; declares a label for a procedure
```

The difference between typedef and label is that typedef creates a new type name, while label creates a new symbol name. Typedef does not allocate any memory, while label does. Typedef can be used to declare variables or parameters of the new type, while label can be used to reference data or code at the given address.

# OPTION directive
## casemap
` Option casemap:none ` in x64 masm assembly is a directive that tells the assembler to treat symbols as case-sensitive.
This means that symbols with different capitalization are considered different and cannot be used interchangeably.
For example, if you have:
` option casemap:none MyLabel: mov eax, 1 `

Then you cannot use mylabel or MYLABEL to refer to the same location as MyLabel. You have to use the exact same spelling and case.

`Option casemap:none ` can be useful if you want to avoid name conflicts or follow a consistent naming convention.
However, it can also introduce errors if you mistype a symbol name or forget the case.

By default, option casemap is set to all, which means that symbols are case-insensitive and can be used with any capitalization.
For example, if you have:
` option casemap:all MyLabel: mov eax, 1 `

Then you can use mylabel, MYLABEL, or any other variation to refer to the same location as MyLabel.

# PROTO
The PROTO directive in x64 MASM assembly is used to prototype a function or procedure.
This means that it specifies the name, parameters and types of the function or procedure.
This can help you use the INVOKE directive to call the function or procedure with the correct arguments.

For example, if you have a function named foo that takes two arguments, a DWORD and a VARARG,
and follows the Windows x64 calling convention, you can use PROTO like this:  
` foo PROTO :DWORD, :VARARG `

This will tell the assembler that foo is a function that takes a DWORD and a variable number of arguments. Then you can use INVOKE to call foo like this:  
` INVOKE foo, 10, 20 `

# INCLUDELIB
The INCLUDLIB directive in x64 MASM assembly is used to inform the linker that the current module should be linked with a library file.
A library file is a file that contains compiled code for functions or procedures that can be used by other modules. For example,
kernel32.lib is a library file that contains the code for Windows API functions.

To use the INCLUDLIB directive, you need to specify the name of the library file as a parameter. For example:  
` INCLUDLIB kernel32.lib` 

This will tell the linker to link the current module with kernel32.lib. You also need to declare the external symbols that you want to use from the library file with the EXTERN or EXTRN directive. For example:  
` EXTERN ExitProcess:PROC `

This will declare ExitProcess as an external symbol that is defined in kernel32.lib. Then you can use the INVOKE or CALL instruction to call ExitProcess from your module.

The advantage of using INCLUDLIB is that it simplifies the linking process and allows you
to use functions or procedures from other modules. The disadvantage is that you need to know
the name and location of the library file and the symbols that it contains.

# INCLUDE
The INCLUDE directive in x64 MASM assembly is used to insert source code from another file into
the current file during assembly. This can help you reuse code from other modules or include
predefined macros or constants.

For example:  
` INCLUDE macros.inc `

This will insert the code from macros.inc into the current file. You need to specify the name
of the file as a parameter. The name must be enclosed in angle brackets if it includes a backslash,
semicolon, greater-than symbol, less-than symbol, single quotation mark, or double quotation mark.

The advantage of using INCLUDE is that it simplifies the code and allows you to organize your code into separate files.
The disadvantage is that you need to know the name and location of the file and the symbols that it contains.

# STRUCTURES
x64 MASM assembly supports structures. Structures are data types that contain a sequence of fields of different types.
You can use the STRUCT directive to declare a structure type with the specified fields.

For example:
```
Point STRUCT
    x DWORD ?
    y DWORD ?
Point ENDS
```

This declares a structure type named Point that has two fields: x and y, both of type DWORD.
You can use the ENDS directive to mark the end of the structure definition.

You can use the TYPEDEF directive to create an alias for a structure type. For example: ` Point TYPEDEF Point `

This creates an alias named Point for the structure type Point. You can use either name to refer
to the same structure type.

You can use the LABEL directive to create an instance of a structure type. For example:  
` p1 Point ?`  
or  
` p1 Point <>`

This creates an instance of Point named p. You can use the dot operator to access the fields of a structure instance.

For example:
```
MOV p1.x, 10 ; assign 10 to p1.x
MOV p1.y, 20 ; assign 20 to p1.y
```

You can also use the STRUCT directive to declare and initialize a structure instance at the same time.

For example:  
` p2 Point <10, 20> `

This creates and initializes an instance of Point named p with x = 10 and y = 202.

# UNIONS
x64 MASM assembler supports union. Union is a data type that contains a set of fields that share the same memory space.
You can use the UNION directive to declare a union type with the specified fields1.

For example:  
```
Data UNION
    dw DWORD ?
    db BYTE 4 DUP (?)
Data ENDS
```

This declares a union type named Data that has two fields: dw and db, both occupying 4 bytes. You can use the ENDS directive to mark the end of the union definition.

You can use the TYPEDEF directive to create an alias for a union type. For example:
` Data TYPEDEF Data `

This creates an alias named Data for the union type Data. You can use either name to refer to the same union type.

You can use the LABEL directive to create an instance of a union type. For example:
` d1 LABEL Data `

This creates an instance of Data named d. You can use the dot operator to access the fields of a union instance.

For example:
```
MOV d1.dw, 0x12345678 ; assign 0x12345678 to d1.dw
MOV AL, d1.db[0] ; load AL with the first byte of d1.db
```

You can also use the STRUCT directive to declare and initialize a union instance at the same time. For example:
` d2 Data <0x12345678> `

This creates and initializes an instance of Data named d2 with dw = 0x12345678 and db = {0x78, 0x56, 0x34, 0x12}.

# Reference
https://www.felixcloutier.com/x86/
https://c9x.me/x86/
https://docs.oracle.com/cd/E19120-01/open.solaris/817-5477/index.html
