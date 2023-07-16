
include windows.inc
includelib kernel32.lib

.const

;mf_vTbl struct
;    dq ?
;    dq ?
;    dq 0
;mf_vTbl ends

TableOfFunctions struct
    dq DoInitSuccess ;00
    dq DoNothing ;08
    dq DoNothing ;10
    dq DoReturnFalseByte ;18
    dq DoReturn  ;20
    dq DoReturn  ;28
    dq DoReturn  ;30
    dq DoReturnFalseQword  ;38 - Wildlands
    dq DoReturn  ;40
    dq DoReturn  ;48
    dq DoReturnFalseByte ;50
    dq DoNothing ;58
    dq DoNothing ;60
    dq DoReturnFalseQword  ;68 - Wildlands
    dq DoReturnFalseByte ;70
    dq DoReturnFalseDword ;78
    dq DoReturn  ;80
    dq DoReturn  ;88
    dq DoReturn  ;90
    dq DoReturn  ;98
    dq DoReturn  ;A0
    dq DoReturn  ;A8
    dq DoReturn  ;B0
    dq DoReturn  ;B8
    dq DoReturn  ;C0
    dq DoReturn  ;C8
    dq DoReturn  ;D0
    dq DoReturn  ;D8
    dq DoReturn  ;E0
    dq DoReturn  ;E8
    dq DoReturn  ;F0
    dq DoInitSuccess ;F8
    dq DoNothing ;100
    dq DoNothing ;108
    dq DoReturnTrueByte ;110
    dq DoReturn  ;118
    dq DoReturnTrueByte ;120
    dq DoReturn  ;128
    dq DoReturnFalseDword ;130
    dq DoReturn  ;138
    dq DoNothing ;140
    dq DoReturn  ;148
    dq DoReturnTrueByte ;150
    dq DoReturnTrueByte ;158
    dq DoNothing ;160
    dq DoReturn  ;168
    dq DoReturn  ;170
    dq DoReturnFalseByte ;178
    dq DoReturn  ;180
    dq DoReturnFalseDword ;188
    dq DoReturn  ;190
    dq DoInitSuccess ;198
    dq DoReturn  ;1A0
    dq DoReturn  ;1A8
    dq DoReturn  ;1B0
    dq DoReturn  ;1B8
    dq DoNothing ;1C0
    dq DoReturn  ;1C8
    dq DoReturn  ;1D0
    dq DoReturnFalseByte ;1D8
    dq DoReturn  ;1E0
    dq 0
TableOfFunctions ends

.data

szDllLoaded         db "EasyAntiCheat_x64 loaded.",0
szDllUnloaded       db "EasyAntiCheat_x64 unloaded.",0
szInitSuccess       db "EasyAntiCheat successfully initialized.",0
align 16
;mf_GameClient mf_vTbl<DoNothing,DoNothing>
mf_GameClient TableOfFunctions<>
align 16
g_GameClient dq 0

