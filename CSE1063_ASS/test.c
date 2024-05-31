#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 5000

int matrix[MAX_VERTICES][MAX_VERTICES];

int main() {
    int i, j, n;
    int totalin = 0, totalout = 0;

    printf("Enter Number of Vertices: ");
    scanf("%d", &n);

    if (n > MAX_VERTICES) {
        printf("Number of vertices should be less than or equal to %d.\n", MAX_VERTICES);
        return 1;
    }

    srand(time(NULL)); // Seed the random number generator

    double start = clock(); // Start the timer

    // Generating the graph with random edges
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = rand() % 2; // Randomly assign 0 or 1 to matrix[i][j]
        }
    }

    // Calculate in-degree and out-degree for each vertex
    for (i = 0; i < n; i++) {
        int indegree = 0, outdegree = 0;
        for (j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                outdegree++; // Count outgoing edges for vertex i
            }
            if (matrix[j][i] == 1) {
                indegree++; // Count incoming edges for vertex i
            }
        }
        totalin += indegree;
        totalout += outdegree;
    }

    double t = (clock() - start) * 1000.0 / CLOCKS_PER_SEC; // Calculate the elapsed time in milliseconds

    printf("\n\nTotal In Degree is = %d\nTotal Out Degree is = %d\n", totalin, totalout);
    printf("\n\nComputational time of this function: %.2f milliseconds\n\t\t\t\tor %.3f seconds\n", t, t / 1000.0);

    return 0;
}
