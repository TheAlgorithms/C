CC = gcc
FLAG = -o

all: naive_search  rabin_karp_search boyer_moore_search

naive_search      : naive_search.c
	$(CC) $(FLAG) naive_search naive_search.c
rabin_karp_search : rabin_karp_search
	$(CC) $(FLAG) rabin_karp_search rabin_karp_search.c
boyer_moore_search: boyer_moore_search boyer_moore_search.c
	$(CC) $(FLAG) boyer_moore_search boyer_moore_search.c

clean:
	rm naive_search rabin_karp_search boyer_moore_search
