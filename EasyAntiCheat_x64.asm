
.686
.mmx
.xmm
.x64

option casemap:none
option win64:11
option frame:auto
option stackbase:rsp

_WIN64 EQU 1
WINVER equ 0501h

include EasyAntiCheat_x64.inc

.code

DoInitSuccess proc frame
    mov rax,r8
    lea rdx,[szInitSuccess]
    mov r8,r9
    xor ecx,ecx
    jmp rax
DoInitSuccess endp

align 16

DoNothing proc frame
    ret
DoNothing endp

align 16

DoReturn proc frame
    ret
DoReturn endp

align 16

DoReturnTrueByte proc frame
    mov al,1
    ret
DoReturnTrueByte endp

align 16

DoReturnFalseByte proc frame
    xor al,al
    ret
DoReturnFalseByte endp

align 16

DoReturnFalseDword proc frame
    xor eax,eax
    ret
DoReturnFalseDword endp

align 16

DoReturnFalseQword proc frame
    xor rax,rax
    ret
DoReturnFalseQword endp

align 16

CreateGameClient proc frame uses rbx
    lea rbx,[mf_GameClient]
    lea rax,[g_GameClient]
    mov [rax],rbx                      ;bind the member-functions pointer at 0x0 in our g_GameClient
    ret                                ;and return g_GameClient in rax
CreateGameClient endp

align 16

start:

;option prologue:none
;option epilogue:none

DllMain proc frame hModule:HMODULE, dwReason:DWORD, lpReserved:LPVOID
    .if dwReason == DLL_PROCESS_ATTACH
        invoke DisableThreadLibraryCalls,hModule
        invoke OutputDebugString,addr szDllLoaded
    .elseif dwReason == DLL_PROCESS_DETACH
        invoke OutputDebugString,addr szDllUnloaded
    .endif
    mov rax,TRUE
    ret
DllMain endp

;option prologue:PROLOGUEDEF
;option epilogue:EPILOGUEDEF

end start
