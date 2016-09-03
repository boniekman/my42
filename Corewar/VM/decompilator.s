.name "decompilator"
.comment "I zill decompile you"

ld %21547865, r2
ld %1879179374, r3
ld %110, r4
begin:	st r1, 6
		live %1
		fork %:start

hook:	st r2, 110
		add	r3, r4, r3
		sti	r3, %:hook, %1
		and %0, %0, r12
zjmp %:begin
and %0, %0, r12
and %0, %0, r12
and %0, %0, r12
and %0, %0, r12
and %0, %0, r12
and %0, %0, r12
and %0, %0, r12
and %0, %0, r12
and %0, %0, r12
and %0, %0, r12
and %0, %0, r12
and %0, %0, r12
and %0, %0, r12
and %0, %0, r12

start: ld %21547865, r6
ld %1879179374, r7
ld %110, r8
begin2:	st r1, 6
		live %1

hook2:	st r6, 110
		add	r7, r8, r7
		sti	r7, %:hook2, %1
		and %0, %0, r12
zjmp %:begin2
