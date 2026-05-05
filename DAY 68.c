#include <stdio.h>

#define MAX 100

int main() {
    int n;
    scanf("%d", &n);

    int adj[MAX][MAX];
    int indegree[MAX] = {0};

    // Input adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);

            if (adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }

    int queue[MAX];
    int front = 0, rear = 0;

    // Push all nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        count++;

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;

                if (indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }

    // Check for cycle
    if (count != n) {
        printf("\nCycle detected. Topological sort not possible.\n");
    }

    return 0;
}