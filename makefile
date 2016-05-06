all: gcd

gcd: gcd.c
	gcc gcd.c -o gcd

test: gcd
	./gcd -t

clean:
	rm -f gcd
