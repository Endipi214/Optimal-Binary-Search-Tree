# Course Project: Optimal Binary Search Tree (OBST) Implementation

This project implements and benchmarks different algorithms for constructing Optimal Binary Search Trees, submitted as part of a data structures and algorithms course. The implementation includes both standard Binary Search Trees (BST) and Optimal Binary Search Trees (OBST) with comprehensive performance analysis.

## Project Overview

The project demonstrates the construction of optimal binary search trees using three different dynamic programming approaches:
- **Memoization**: Top-down recursive approach with caching
- **Tabulation**: Bottom-up iterative approach  
- **Knuth's Algorithm**: Optimized O(n²) algorithm using the quadrangle inequality

## Features

### Binary Search Tree (BST)
The standard BST implementation provides:
- **Tree Construction**: Build trees from integer keys
- **Search Operations**: Find nodes with O(log n) average complexity
- **Insertion/Deletion**: Dynamic tree modification
- **Tree Traversals**: 
  - In-order (LNR): Left → Node → Right
  - Pre-order (NLR): Node → Left → Right  
  - Post-order (LRN): Left → Right → Node
  - Level-order: Breadth-first traversal
- **Tree Visualization**: Level-by-level tree structure display

### Optimal Binary Search Tree (OBST)
The OBST implementation extends BST with optimization features:
- **Weight-Based Optimization**: Uses success and failure weights to minimize expected search cost
- **Statistical Formalization**: Converts integer weight arrays into normalized probability distributions
- **Cost Calculation**: Computes the minimum expected search cost for the optimal tree structure
- **Multiple Algorithms**: Implements three different approaches for comparison
- **Performance Analysis**: Built-in benchmarking and timing capabilities

#### Weight Processing
The system takes arrays of integers representing:
- **Success Weights**: Probability weights for successful key searches
- **Failure Weights**: Probability weights for unsuccessful searches (gaps between keys)

These integer arrays are automatically normalized into statistical probability distributions where the sum of all probabilities equals 1.0.

### Benchmarking System
- **Automated Testing**: Configurable input sizes and repetition counts
- **Performance Metrics**: Execution time measurement for each algorithm
- **Cost Comparison**: Expected search cost analysis
- **Random Input Generation**: Automatic test case creation
- **Custom Input Support**: User-defined weights and keys
- **Tree Visualization**: Visual output for small trees (≤20 nodes)

## Building and Running

### Prerequisites
- CMake 3.28 or higher
- C++17 compatible compiler
- Standard C++ library

### Build Instructions

1. **Clone or extract the project files**

2. **Create build directory and configure:**
```bash
mkdir build
cd build
cmake ..
```

3. **Compile the project:**
```bash
cmake --build .
```

4. **Run the executable:**
```bash
./bin/main
```

### Alternative Build Commands
You can also use make directly after cmake configuration:
```bash
mkdir build && cd build
cmake ..
make
./bin/main
```

## Usage

When you run the program, you'll see an interactive menu:

```
===== OBST Benchmark Menu =====
1. Run benchmark with random input
2. Run benchmark with custom input
Select an option (1 or 2):
```

### Option 1: Random Input Benchmark
- Specify the input size (number of keys)
- Choose number of benchmark repetitions
- Keys are automatically generated as: 10, 20, 30, ..., n×10
- Success and failure weights are randomly generated

### Option 2: Custom Input Benchmark
- Specify the number of keys
- Keys are automatically generated as: 10, 20, 30, ..., n×10
- Manually input success weights (n integers)
- Manually input failure weights (n+1 integers)

### Example Usage Session

```bash
./bin/main
===== OBST Benchmark Menu =====
1. Run benchmark with random input
2. Run benchmark with custom input
Select an option (1 or 2): 2
Enter the number of keys: 4
Keys will be automatically generated as 10, 20, 30, ...
Please enter 4 success weights (space-separated): 3 2 4 1
Please enter 5 failure weights (space-separated): 2 3 1 1 1
```

### Output Features
- **Tree Structure**: Visual representation for small trees
- **Algorithm Comparison**: Side-by-side performance metrics
- **Cost Analysis**: Expected search cost for each algorithm
- **Execution Time**: Precise timing measurements
- **Input Display**: Shows keys, success weights, and failure weights used

### Tree Size Considerations
- Trees with ≤20 nodes: Full visualization and detailed output
- Trees with >20 nodes: Performance metrics only (visualization skipped for readability)

## File Structure

```
├── CMakeLists.txt              # Build configuration
├── include/
│   ├── BinarySearchTree.hpp    # BST class definition
│   ├── OptimalBinarySearchTree.hpp # OBST class definition
│   └── Benchmark.hpp           # Benchmarking utilities
├── source/
│   ├── BinarySearchTree.cpp    # BST implementation
│   ├── OptimalBinarySearchTree.cpp # OBST implementation
│   ├── Benchmark.cpp           # Benchmarking implementation
│   └── main.cpp               # Program entry point
└── README.md                  # This file
```

## Algorithm Complexity

| Algorithm | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Memoization | O(n³) | O(n²) |
| Tabulation | O(n³) | O(n²) |
| Knuth's Algorithm | O(n²) | O(n²) |

## Course Context

This implementation serves as a comprehensive study of:
- Dynamic programming optimization techniques
- Tree data structure implementations
- Algorithm performance analysis and comparison
- Statistical probability applications in computer science
- Empirical algorithm evaluation methodologies

## Credits

- Authors:
  - Nguyen Danh Phuong (Student ID: 24120504, GitHub: Endipi214)
  - Nguyen Pham Xuan Cuong (Student ID: 24120499)
  - Huynh Bao Khang (Student ID: 24120507)
- Course: CSC10004 – Data Structures & Algorithm
- Institution: VNU University of Science
