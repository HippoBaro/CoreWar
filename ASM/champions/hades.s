.name "ades"
.comment "merrand est énervé"
l2:	sti r1, %:sacha, %1
sti r1, %:sacha, %6
and r1, %0, r1
fork %:sacha
sacha:	live %1
live %1
zjmp %:sacha