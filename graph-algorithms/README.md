# Graph Algorithms

## Before Start

All algorithms consumes the [input.txt](input.txt) file, the input format is:

The first line contains 3 integers, V, E & D, number of vertex, number of edges and the directed graph indicator: 0 or 1, 1 if the graph is directed or 0 if undirected.

The following E lines contains 3 integers, the lines should have, v1, v2 and w, the origin, destination and weight of the edge respectively.

The last line, will be exclusively for dijkstra and ford fulkerson algorithms, the format should be:

```
i d
```

the initial and destination vertex path.

### Examples

#### Directed Graph

```
4 2 1
1 2 4
2 3 1
```

#### Undirected Graph

```
4 2 0
1 2 4
2 3 1
```

## Get Started

On the main folder, to compile files, execute:

```
make
```

ou

```
make main
```


to run the algorithms:

```
./algorithm_name < input.txt
```
