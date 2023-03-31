; On functions that the compiler recognizes as subject to buffer overrun problems,
; the compiler allocates space on the stack before the return address. On function
; entry, the allocated space is loaded with a security cookie that is computed once
; at module load. On function exit, and during frame unwinding on 64-bit operating systems,
; a helper function is called to make sure that the value of the cookie is still the same.
; A different value indicates that an overwrite of the stack may have occurred. If a different
; value is detected, the process is terminated.

cookie=dword ptr -4

push ebp
mov ebp, esp
sub esp, 1Ch ; 1Ch for example
mov eax, __security_cookie
xor eax, ebp
mov [ebp+cookie], eax

xor eax, eax
mov ecx, [ebp+cookie]
xor ecx, ebp
call @__security_check_cookie@4 ; or just __security_check_cookie
mov esp, ebp
pop ebp
retn

__security_check_cookie proc near
cmp rcx, cs:__security_cookie
jnz short ReportFailure
rol rcx, 10h
test cx, 0FFFh
jun short RestoreRcx
retn

Restore Rcx: ; stack cookie
ror rcx, 10h

ReportFailure:
jmp __report_gsfailure
__security_check_cookie endp
