# Hash and Graph Algorithm Toolkit

This project was created to practice and enhance my skills in data structures and algorithms. By combining a custom hash function with a chaining hash table and Dijkstra's shortest path algorithm, the project provides a practical application of key computer science concepts. The toolkit is designed to handle efficient data storage and retrieval as well as graph traversal and pathfinding, demonstrating comprehensive proficiency in these areas.

## Features

- **Hash Table with Custom Hash Function**: Efficiently categorizes and stores string tokens.
- **Dijkstra's Algorithm**: Computes shortest paths in undirected graphs.
- **Performance Analysis**: Includes standard deviation calculations for hash table distribution and shortest path matrices.

## Requirements

- C++ Compiler (GCC recommended)
- Makefile

## Setup and Compilation

### Custom Hash Table

1. Navigate to the `CustomHashTable` directory:

   ```bash
   cd CustomHashTable
   ```

2. Build the project using the Makefile:

   ```bash
   make
   ```

3. Prepare your input file (`inputs/input.txt`) with the following format:

   ```
   5
   Amazon
   Boeing
   apple
   Applebee
   abandon
   banana
   elephant
   boring
   barbaric
   ```

4. Run the hash table program:
   ```bash
   ./hash_encoder < inputs/input.txt
   ```

### Dijkstra's Algorithm

1. Navigate to the `DijkstraAlgorithm` directory:

   ```bash
   cd DijkstraAlgorithm
   ```

2. Build the project using the Makefile:

   ```bash
   make
   ```

3. Prepare your graph input file (`inputs/graph.txt`) with the following format:

   ```
   8 10
   1 2
   1 4
   1 5
   2 3
   2 4
   3 4
   3 5
   3 6
   6 7
   6 8
   ```

4. Run the Dijkstra's algorithm program:
   ```bash
   ./dijkstra < inputs/graph.txt
   ```

## Output

### Custom Hash Table

- Contents of the first 5 slots.
- Slot lengths.
- Standard deviation of slot lengths.

### Dijkstra's Algorithm

- Adjacency matrix of the graph.
- List of vertices with odd degrees.
- Shortest path lengths from each odd-degree vertex.

## File Structure

- `CustomHashTable/`: Contains the source code and inputs for the custom hash table project.
- `DijkstraAlgorithm/`: Contains the source code and inputs for the Dijkstra's algorithm project.
- `README.md`: Project documentation.

## Author

- [Your Name](https://github.com/yourusername)

Feel free to reach out if you have any questions or suggestions!
