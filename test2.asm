;-----------------------------------------------------------
; asar func test code 2
;-----------------------------------------------------------

; define
!AAA = 4

; macro
macro Undi()
	print "UNknown DIff - undi. @$", pc
endmacro

; function
function test(n) = 4*n

org $8008

main:
	db test(!AAA)
	%Undi()
