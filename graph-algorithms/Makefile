main: kruskal dijkstra prim ford_fulkerson
	gcc kruskal.o builder.o graph.o pqueue.o union_find.o -o kruskal
	gcc dijkstra.o builder.o graph.o pqueue.o -o dijkstra
	rm *.o

ford_fulkerson: ford_fulkerson.o builder.o graph.o pqueue.o
	gcc ford_fulkerson.o builder.o graph.o pqueue.o -o ford_fulkerson

prim: prim.o builder.o graph.o pqueue.o
	gcc prim.o builder.o graph.o pqueue.o -o prim

kruskal: kruskal.o builder.o graph.o pqueue.o union_find.o
	gcc kruskal.o builder.o graph.o pqueue.o union_find.o -o kruskal

dijkstra: dijkstra.o builder.o graph.o pqueue.o
	gcc dijkstra.o builder.o graph.o pqueue.o -o dijkstra

ford_fulkerson.o: algorithms/ford_fulkerson.c
	gcc -c algorithms/ford_fulkerson.c

prim.o: algorithms/prim.c
	gcc -c algorithms/prim.c

kruskal.o: algorithms/kruskal.c
	gcc -c algorithms/kruskal.c

dijkstra.o: algorithms/dijkstra.c
	gcc -c algorithms/dijkstra.c

builder.o: sources/builder.c includes/builder.h
	gcc -c sources/builder.c

graph.o: sources/graph.c includes/graph.h
	gcc -c sources/graph.c

pqueue.o: sources/pqueue.c includes/pqueue.h
	gcc -c sources/pqueue.c

union_find.o: sources/union_find.c includes/union_find.h
	gcc -c sources/union_find.c

clean: 
	rm *.o