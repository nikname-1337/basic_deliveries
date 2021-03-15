#include<iostream>
#include<vector>
#include<list>

class item{
    public:
        std::string ID;
        int deliveryDate;
        std::string deliveryLocation;
        int dRun;   //Deliver run number 
        item() {  //Empty item default constructor

        }

        item(std::string a, int b,std::string c) {
            ID = a;
            deliveryDate = b;
            deliveryLocation = c;
        }
};



void merge(std::vector<item> &A, int min, int mid, int max);
void mergeSortDeliveries(std::vector<item> &A, int min,int max);
item hashSearch(std::vector<item> &T, int k, std::string name, std::string location);
void hashInsert(std::vector<item> &T, item x);
int hashT(std::string name, std::string location);
void hashDelete(std::vector<item> &T, int k, std::string name, std::string location);
std::vector<int> dijkstra(std::vector<std::vector<int>>&G,int start);
int minDistance(std::vector<int> dist, bool sptSet[], int size);