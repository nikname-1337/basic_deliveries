#include<iostream>
#include<random>
using namespace std;
// built from this C code: https://stackoverflow.com/questions/33150887/generate-adjacency-matrix-of-undirected-graph
int main(int argc, char const *argv[])
{
    /* code */
    #define INFTY 0
    int **edge;
    int N=8000;

edge= (int **) malloc(N * sizeof(int *));
for (int i = 0; i < N; i++)
{
    edge[i] = (int *) malloc(N * sizeof(int));
}

srand(0);
for(int i = 0; i < N; i++)
{
    for(int j = i; j < N; j++)
    {
        if(i == j){
            edge[i][j] = 0;
        }

        else{
            int p = rand()%3;
            if(p == 1){
                int r = rand() % 50 + 1;
                int val = (r == 5)? INFTY: r;
                edge[i][j] = val;
                edge[j][i] = val;  // If there is edge from i to j, then there
                               // must be edge from j to i
            }else{
                edge[i][j] = 0;
                edge[j][i] = 0;
            }
            
        }

    }
}
    cout << N << "\n";
    for (int i =0; i < N; i++){
        for(int j =0; j < N; j++){
            cout << edge[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

