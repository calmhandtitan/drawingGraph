# drawingGraph
Draw graph with given details and save as jpeg file using DOT(graph description language)

#About input file:

The input file should contain details of the graph in the following manner.

The first line should have two integers `n`, `m` both separated by a whitespace, where `n` is the number of nodes in the graph and `m` is the number of edges.

`m` lines follow.

Each of the next `m` lines contains 2 integers a, b separated by whitespace.

**NOTE**: The input file can have any filename with any extension.


#Compilation:

`$ gcc createGraph.c -o createGraph`

#Execution:

`$ ./createGraph` 

`$ Enter filename whose graph to draw>> ` 

enter the filename on the prompt and the graph is drawn and saved to a jpeg image having filename: `inputFileName_graph.jpg` where inputFileName is same as the filename entered by the user.
