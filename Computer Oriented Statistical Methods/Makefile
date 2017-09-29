CC=gcc

all: Gauss_Elimination lagrange_theorem MEAN MEDIAN Seidal simpson variance

Gauss_Elimination:
	gcc -Wall -Werror Gauss_Elimination.c -o Gauss_Elimination

lagrange_theorem:
	gcc -Wall -Werror lagrange_theorem.C -o lagrange_theorem

MEAN:
	gcc -Wall -Werror MEAN.C -o MEAN

MEDIAN:
	gcc -Wall -Werror MEAN.C -o MEDIAN

Seidal:
	gcc -Wall -Werror Seidal.C -o Seidal

simpson:
	gcc -Wall -Werror "simpson's 1-3rd rule.c" -o "simpson's 1-3rd rule"

variance:
	gcc -Wall -Werror variance.c -o variance -lm

clean:
	rm -f Gauss_Elimination lagrange_theorem MEAN MEDIAN Seidal \
    "simpson's 1-3rd rule" variance
