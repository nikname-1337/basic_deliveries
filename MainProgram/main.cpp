#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<list>
#include<chrono>
#include "head1.h"
using namespace std;


int main(int argc, char const *argv[])
{
    cout << "----------------------------------------------------\n";
    cout << "              Make a choice of command\n";
    cout << "----------------------------------------------------\n";
    cout << "1. Enter a new delivery\n";
    cout << "2. Search for item in delivery list\n";
    cout << "3. Delete Item from delivery list\n";
    cout << "4. Display sorted current delivery schedule\n";
    cout << "5. Delivery time to your location\n";
    cout << "6. Exit Program\n";
    
    int BUCKETS = 1171; 

    if (argc < 2) {
        cout << "-------------------------------------------\n";
        cout << "Please supply the name of the input file/s\n";
        cout << "-------------------------------------------\n";
    } 
    else { 
		// Read input
		ifstream inFile(argv[1]);
		int n, deliveryDate;
        string name, deliveryLocation;
		inFile >> n;
        cout << "There are currently: " << n << " deliveries.\n";
        vector<item> goods(n); 
        vector<item> hashedGoods(BUCKETS*n);
        //chrono::nanoseconds totalTime;
		for (int i = 0; i < n; i++) {
			inFile  >> name >> deliveryDate >> deliveryLocation;
            
            goods[i] = (item(name,deliveryDate,deliveryLocation));
            //auto start = chrono::steady_clock::now();
            hashInsert(hashedGoods, item(name,deliveryDate,deliveryLocation));
            //auto end = chrono::steady_clock::now();
            //auto diff = end - start;
            //totalTime = totalTime + diff;
            //Code to test functionality was here (may or may not be all deleted in final revision)

            //cout << goods[i].ID << "\n";       

		}
        //cout << chrono::duration <double, nano> (totalTime).count() << " ns" << endl;
		inFile.close();
        inFile.clear();
        inFile.open(argv[2]);
        int size;
        int elem;
        inFile >> size; 
        cout << "Graph of size: " << size << "\n";
        vector<vector<int>> graph(size, vector<int> (size));
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                inFile >> elem;
                // cout <<" "<< elem <<", ";
                graph[i][j] = elem;
            }
            // cout << "\n";
        }
        inFile.close();
    int x;
    while(true){
    cin >> x;
    if(!cin){
       cout << "Invalid string was entered \n";
       cin.clear();
       cin.ignore();
       continue;
    }
    string yn = "y";
    switch(x){
        case 1:
            while(yn == "y"){
                string name, location; 
                int date;
                cout << "Enter item name: ";
                cin >> name;
                //cin.clear();
                //cin.ignore(10000, '\n');
                cout<< "\nEnter the delivery required delivery date (YYYYMMDD): ";
                cin >> date;
                cin.clear();
                cin.ignore(10000, '\n');
                cout<< "\nEnter location: ";
                cin >> location;
                //cin.clear();
                //cin.ignore(10000,'\n');
                
                hashInsert(hashedGoods,item(name,date,location));
               
                cout << "===\n";
                cout << "Enter another delivery? (y/n) \n";
                cin >> yn;
            }
            break;
        case 2:
            {
            string n;
            string loc;
            cout<< "Search for item by item name and delivery location\n";
            cout << "\nEnter Name: "; 
            cin >> n;
            cout << "\nEnter Location: ";
            cin >> loc; 

            item found = hashSearch(hashedGoods,hashT(n,loc),n,loc);
            if(found.ID.empty()){
                cout << "Item not found!\n";
            }else{
                cout <<"ItemID: " << found.ID <<" | Delivery date: " << to_string(found.deliveryDate).substr(6,2) << "/" << to_string(found.deliveryDate).substr(4,2)<< "/" << to_string(found.deliveryDate).substr(0,4)<< "\n";
            }
            break;
            }
        case 3:
            {
            cout<< "Enter the item name and delivery location to remove the item\n";
            string n;
            string loc;
            cout << "Enter Name: "; 
            cin >> n;
            cout << "\nEnter Location: ";
            cin >> loc; 
            hashDelete(hashedGoods,hashT(n,loc),n,loc);
            break;
            }
        case 4:
        {
            cout << "This is the current delivery schedule\n";
            cout << "\t---\n";
            //auto start = chrono::steady_clock::now();
            mergeSortDeliveries(goods,0,goods.size()-1);
            //auto end = chrono::steady_clock::now();
            //auto diff = end - start;
            
            // cout << goods.size() << "\n";
            //* Function I used to debug merge sort algorithm

            // Print the resulting list in order
            for(int i = 0; i < n; i++){
                //cout << testarr.size();
                cout <<"Priority No. " << i+1<<" | "<< goods.at(i).ID << " | ";
                cout << goods.at(i).deliveryDate << "\n";
                //cout << to_string(goods.at(i).deliveryDate).substr(6,2) << "/" << to_string(goods.at(i).deliveryDate).substr(4,2)<< "/" << to_string(goods.at(i).deliveryDate).substr(0,4)<< "\n";
                //cout << goods.size() << "\n";
            }
            //cout << chrono::duration <double, nano> (diff).count() << " ns" << endl;
            
            // for(int i = 0; i < n; i++){
            //     //cout << testarr.size();
            //     cout <<i<<" , "<< goods[i].ID << "\n";
            // }
            break;
        }
        case 5:
        {
            // Code for printing adjacency matrix used for testing commented out
            // cout << "This is the adjacancy matrix: \n"; 
            // for(int i = 0; i < size; i++){
            //     for(int j = 0; j < size; j++){ 
            //         cout <<" "<< graph[i][j] <<" ";    
            //     }
            // cout << "\n";
            // }
            cout << "Enter Current Location: ";
            int L;
            cin >> L; 
            cout << "\n";
            if(L > size -1 ){
                cout << "This vertex is out of bounds\n";
            }else{
                //Uncomment the below lines for CPU time to print
                //auto start = chrono::steady_clock::now();
                vector<int> result = dijkstra(graph,L);
                //auto end = chrono::steady_clock::now();
                //auto diff = end - start;
                cout << "Location\tDistance from: "<< L <<"\n"; 
                for (int i = 0; i < size; i++){
                    cout << i << "\t\t" << result[i] << "\n"; 
                }
                //cout << chrono::duration <double, nano> (diff).count() << " ns" << endl;


            }
            
            break;
        }
        case 6:
            cout<< "Program will now exit!\n"; 
            return 0;
        default:
            cout<< "Invalid input, please select a valid input\n";
            break;
    }
    cout << "Make a new selection\n"; 
    
    //cout << "Is this happening";
    };
    //cout << x;
    return 0;
    }
}
