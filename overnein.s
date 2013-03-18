.name "It's over"
.comment "NEIN NEIN NEIN NEIN"
mode assegai

check
check
check
check
nop
nop
nop
nop
nop
nop
nop

check
check
mode auricom
ll r4, 42
ll r4, 42
mode icaras
mode icaras
mode auricom
mode qirex

#usefull code here
ll r1, LOOP - MODING
ll r2, 427
ll r3, 434 - END + LOOP
ldb [r1], 0, END - LOOP

MODING:
mode feisar
LOOP:
        stb [r2], 0, 12
        check
        b r3
END: