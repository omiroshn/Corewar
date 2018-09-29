.name           "test_add"
.comment        "Just a basic add test"

	ld		%3, r3
	ld		%4, r4
	add		r3, r4, r5
	zjmp	%5
	