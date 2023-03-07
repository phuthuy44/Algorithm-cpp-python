//Using Dynamic Algorithm 

#include <iostream>
using namespace std;
const int N = 20;        
const int INF = INT_MAX; 
int n;
int graph[N][N];

void docfile(FILE *f, int a[][N], int &n);
int tsp(int n, bool visited[], int curr, int count, int cost, int &min_cost);
int main(int argc, char **argv)
{
    FILE *f;
    docfile(f, graph, n);
    bool visited[n];
    for (int i = 0; i < n; ++i)
    {
        visited[i] = false;
    }
    visited[0] = true;

    int min_cost = INF;
    tsp(n, visited, 0, 1, 0, min_cost);

    cout << "Minimum cost: " << min_cost << endl;

    return 0;
}
void docfile(FILE *f, int a[][N], int &n)
{
    f = fopen("tsp_15vertex.txt", "rt");
    fscanf(f, "%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(f, "%d", &a[i][j]);
        }
    }
    fclose(f);
}
int tsp(int n, bool visited[], int curr, int count, int cost, int &min_cost)
{
    if (count == n && graph[curr][0])
    {
        min_cost = min(min_cost, cost + graph[curr][0]);
        return min_cost;
    }

    for (int i = 0; i < n; ++i)
    {
        if (!visited[i] && graph[curr][i])
        {
            visited[i] = true;
            tsp(n, visited, i, count + 1, cost + graph[curr][i], min_cost);
            visited[i] = false;
        }
    }

    return min_cost;
}
