.name "Flugegehaimen"
.comment "Prepare Uranus!"

cycle:
	st		r1, 6
	live	%0
	ld		%-4, r2
	st		r1, r2

	st		r1, 6
	live	%0
	st		r1, 6
	live	%0
	st		r1, 6
	live	%0
	st		r1, 6
	live	%0
	st		r1, 6
	live	%0
	st		r1, 6
	live	%0
	st		r1, 6
	live	%0
	st		r1, 6
	live	%0
	st		r1, 6
	live	%0
	st		r1, 6
	live	%0
	st		r1, 6
	live	%0
	st		r1, 6
	live	%0
	st		r1, 6
	live	%0

	
	fork	%11
	add     r6,r7,r8
	zjmp	%:cycle

	st		r1, 6
	live	%0
