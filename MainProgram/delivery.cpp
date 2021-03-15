#include<list>
#include<iostream>
#include<vector>
#include<limits>
#include "head1.h"
using namespace std;




int minDistance(vector<int> dist, bool sptSet[], int size) 
{ 
    // Initialize min value 
    int min = INT_MAX;
    int min_index; 
  
    for (int v = 0; v < size; v++){
        if (sptSet[v] == false && dist[v] <= min){
            min = dist[v];
            min_index = v; 
        }
    }
    return min_index; 
} 

vector<int> dijkstra(vector<vector<int>> &G,int start){
    int size = G.size();

    // initialiseSingleSource(G,s); 
    // S = 0; 
    // Q = G*V;
    // while(Q != 0){
    //     u = extractMin(Q); 
    //     S = S intersection u;
    //     for each vertex v = 
    // }

    vector<int> dist(size);          // Shortest Distance matrix (will hold all shortest paths)

    bool shortestSet[size];         // Set of vertices included in shortest path or not
    // Initialise all distances in cost matrix to INFINITY
    for(int i = 0; i < size; i++){
        dist[i] = INT_MAX;
        shortestSet[i] = false;
    }
    dist[start] = 0;
    for(int vertex = 0; vertex < size -1; vertex++){
        // This implementation of Dijkstras Algorithm is inspired from GeeksForGeeks
        int k = minDistance(dist,shortestSet,size); 
        shortestSet[k] = true;
        for(int j = 0; j<size; j++){
            if(!shortestSet[j] && G[k][j] && dist[k] != INT_MAX && dist[k] + G[k][j] < dist[j]){
                dist[j] = dist[k] + G[k][j];
            }
        }
    }
    return dist;
 
}

void mergeSortDeliveries(vector<item> &A, int min,int max){
    if (min<max){
    
        int mid = (min+max)/2;
        mergeSortDeliveries(A,min,mid);
        mergeSortDeliveries(A,mid+1,max);
        merge(A,min,mid,max);
    }
}

//Merge sort algorithm will be filled out below based on the incoming list of dates
void merge(vector<item> &A, int min, int mid, int max){
    int subleft = mid-min+1;
    int subright = max-mid;
    vector<item> L(subleft);
    vector<item> R(subright);
    for(int i = 0; i < subleft; i++){
        L[i] = A[min+i];
    }
    for(int j = 0; j < subright; j++){
        R[j] = A[mid+j+1];
    }

    L.push_back(item("dummy",numeric_limits<int>::max(),"dummy"));
    R.push_back(item("dummy",numeric_limits<int>::max(),"dummy"));
    int i = 0;
    int j = 0;

    for(int k = min; k <= max; k++){
        //cout << A.size() <<", " <<  A[k].ID << "\n";
        if(L[i].deliveryDate <= R[j].deliveryDate){
            A[k] = L[i];
            i = i+1;
        }else{
            A[k] = R[j];
            j = j+1;
        }
    }
}

// void mergeSortDeliveries(vector<int> &A, int min,int max){
//     if (min<max){
//         int mid = (min+max)/2;
//         mergeSortDeliveries(A,min,mid);
//         mergeSortDeliveries(A,mid+1,max);
//         merge(A,min,mid,max);
//     }
// }

// //Merge sort algorithm will be filled out below based on the incoming list of dates
// void merge(vector<int> &A, int min, int mid, int max){
//     int subleft = mid-min+1;
//     int subright = max-mid;
//     int L[subleft];
//     int R[subright];
//     for(int i = 0; i < subleft; i++){
//         L[i] = A[min+i];
//     }
//     for(int j = 0; j < subright; j++){
//         R[j] = A[mid+j+1];
//     }
//     L[subleft]=numeric_limits<int>::max();
//     R[subright]=numeric_limits<int>::max();
//     int i = 0;
//     int j = 0;

//     for(int k = min; k <= max; k++){
//         if(L[i]<=R[j]){
//             A[k] = L[i];
//             i = i+1;
//         }else{
//             A[k] = R[j];
//             j = j+1;
//         }

//     }
// }



void hashInsert(vector<item> &T, item x){
 
    int h = hashT(x.ID,x.deliveryLocation);
    int temp = h;
    //cout << h << "\n";
    if(T[h].ID.empty()){
        T[h] = x;
    }else{
        if(h < T.size()){
            T[h+1]=x;
        }else{
            for(int i =0; i<temp; i++){
                if(T[i].ID.empty()){
                     T[i] = x;
                }
            }
            cout << "Hash Table is full...\n";
        }
        
        //cout << x.ID;
    }

}
// Hashing function which will determine the key value of an item
int hashT(string name, string location){

    string hashString = name+location;
    int key = 7; 
    for(int i = 0; i < hashString.length(); i++){
        key = key*191*hashString.at(i); 
    }
    key = abs(key%499);
    
    return key;
}

//Hashing functions to search, insert, and delete items from the database. 
item hashSearch(vector<item> &T, int k, string name, string location){
    bool isFound = false;
    item found;
    int temp = k;
    //cout << k;
    while(!isFound){
        if(T[k].ID==name && T[k].deliveryLocation == location){
            found = T[k];
            isFound = true;
        }else{
            k++; 
            if(k > T.size()){
                for(int i =0; i <temp; i++){
                    if(T[i].ID==name && T[i].deliveryLocation == location){
                        found = T[i];
                        isFound = true;
                        break;
                    }
                }
        
                break;
            }
        }
    }
    return found;
}

void hashDelete(vector<item> &T, int k, string name, string location){
    bool isFound = false;
    item empty = item();
    int temp = k;
    while(!isFound){
        if(T[k].ID==name && T[k].deliveryLocation == location){
            T[k] = empty;
            cout << "Item has been removed\n";
            isFound = true;
        }else{
            k++; 
            if(k > T.size()){
                for(int i =0; i <temp; i++){
                    if(T[i].ID==name && T[i].deliveryLocation == location){
                        T[i]=empty;
                        isFound = true;
                        break;
                    }
                }
                cout << "Item not found\n";
                break;
            }
        }
    }
}

