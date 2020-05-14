CC=gcc 
CFLAGS=-Wall -Werror -std=c99
all: BFS Bellman-Ford DFS Dijkstra Floyd-Warshall bfsQueue dfsRecursive euler hamiltonian strongly_connected_components topologicalSort transitiveClosure


BFS: BFS.c
	$(CC) -o BFS BFS.c
Bellman-Ford: Bellman-Ford.c
	$(CC) -o Bellman-Ford Bellman-Ford.c
DFS: DFS.c
	$(CC) -o DFS DFS.c
Dijkstra: Dijkstra.c
	$(CC) -o Dijkstra Dijkstra.c
Floyd-Warshall: Floyd-Warshall.c
	$(CC) -o Floyd-Warshall Floyd-Warshall.c
Graph.o: Graph.c Graph.h
	$(CC) $(CFLAGS) -c Graph.c
bfsQueue: Graph.o queue.o bfsQueue.o
	$(CC) Graph.o queue.o bfsQueue.o -o bfsQueue
bfsQueue.o: bfsQueue.c
	$(CC) $(CFLAGS) -c bfsQueue.c
dfsRecursive: Graph.o queue.o dfsRecursive.o
	$(CC) Graph.o queue.o dfsRecursive.o -o dfsRecursive
dfsRecursive.o: dfsRecursive.c
	$(CC) -c dfsRecursive.c
euler: Graph.o euler.o
	$(CC) Graph.o euler.o -o euler
euler.o: euler.c
	$(CC) $(CFLAGS) -c euler.c
hamiltonian: Graph.o hamiltonian.o
	$(CC) Graph.o hamiltonian.o -o hamiltonian
hamiltonian.o: hamiltonian.c
	$(CC) $(CFLAGS) -c hamiltonian.c
queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c
strongly_connected_components: strongly_connected_components.c
	$(CC) -o strongly_connected_components strongly_connected_components.c
topologicalSort: topologicalSort.c
	$(CC) -o topologicalSort topologicalSort.c
transitiveClosure: transitiveClosure.c
	$(CC) -o transitiveClosure transitiveClosure.c
# By 
#  .----------------.  .----------------.  .----------------.  .-----------------.  .----------------.  .----------------. 
# | .--------------. || .--------------. || .--------------. || .--------------. | | .--------------. || .--------------. |
# | |  _________   | || | _____  _____ | || |      __      | || | ____  _____  | | | |  ____  ____  | || |     ____     | |
# | | |  _   _  |  | || ||_   _||_   _|| || |     /  \     | || ||_   \|_   _| | | | | |_   ||   _| | || |   .'    `.   | |
# | | |_/ | | \_|  | || |  | |    | |  | || |    / /\ \    | || |  |   \ | |   | | | |   | |__| |   | || |  /  .--.  \  | |
# | |     | |      | || |  | '    ' |  | || |   / ____ \   | || |  | |\ \| |   | | | |   |  __  |   | || |  | |    | |  | |
# | |    _| |_     | || |   \ `--' /   | || | _/ /    \ \_ | || | _| |_\   |_  | | | |  _| |  | |_  | || |  \  `--'  /  | |
# | |   |_____|    | || |    `.__.'    | || ||____|  |____|| || ||_____|\____| | | | | |____||____| | || |   `.____.'   | |
# | |              | || |              | || |              | || |              | | | |              | || |              | |
# | '--------------' || '--------------' || '--------------' || '--------------' | | '--------------' || '--------------' |
#  '----------------'  '----------------'  '----------------'  '----------------'   '----------------'  '----------------' 
 
#  Email :    z5261243@unsw.edu.au
#             hhoanhtuann@gmail.com