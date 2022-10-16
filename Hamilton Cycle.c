#include <stdio.h>
#define MAX 25
int x[MAX];
void Next_Vertex(int G[MAX][MAX], int n, int k)
{
    int j;
    while (1)
    {

        x[k] = (x[k] + 1) % (n + 1);
        if (x[k] == 0)
            return;
        if (G[x[k - 1]][x[k]] != 0)

        {
            for (j = 1; j <= k - 1; j++)
            {
                if (x[j] == x[k])
                    break;
            }
            if (j == k)
            {
                if ((k < n) || ((k == n) && (G[x[n]][x[1]] != 0)))
                    return;
            }
        }
    }
}
void H_Cycle(int G[][MAX], int n, int k)
{
    int i;
    while (1)
    {
        Next_Vertex(G, n, k);
        if (x[k] == 0)
            return;

        if (k == n)
        {
            printf("\n");
            for (i = 1; i <= n; i++)
                printf(" %d", x[i]);

            printf(" %d", x[1]);
        }
        else
            H_Cycle(G, n, k + 1);
    }
}
int main()
{
    int i, j, v1, v2, Edges, n, G[MAX][MAX];
    printf("\n\t Program for Hamiltonian Cycle ");
    printf("\n Enter the number of vertices of graph: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            G[i][j] = 0;
            x[i] = 0;
        }
    }
    printf("\n Enter the total number of edges: ");
    scanf("%d", &Edges);
    for (i = 1; i <= Edges; i++)
    {
        printf("\n Enter the edge: ");
        scanf("%d%d", &v1, &v2);
        G[v1][v2] = 1;
        G[v2][v1] = 1;
    }

    x[1] = 1;
    printf("\n Hamiltonian cycle ...\n");
    H_Cycle(G, n, 2);
    return 0;
}