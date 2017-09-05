;-----------------------------------------------------------
; asar func test code 1
;-----------------------------------------------------------

; define
!AAA = 4

; macro
macro Undi()
	print "UNknown DIff - undi. @$", pc
endmacro

; function
function test(n) = 2*n

org $8000

main:
	db test(!AAA)
	%Undi()


