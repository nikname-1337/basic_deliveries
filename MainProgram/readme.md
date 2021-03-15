# Readme - u5834991



Compile and run the code using these commands once in the required file directory/folder. 

    g++ -std=c++11 main.cpp delivery.cpp -o program
    ./program.exe ./delivery.txt ./location.txt

The main function provides a basic graphical user interface and handles the input of data from the text file. The delivery.txt file is the file containing a simple list of deliveries. The provided test files can be replaced as input to the program as explained, which will allow for the empiral testing as the test files contain lists of different sizes for testing. 
I used the following code to test the CPU time of a portion of code.

    auto start = chrono::steady_clock::now();
    /* code */
    auto end = chrono::steady_clock::now();
    auto diff = end - start;   // difference between start and end clock time
    cout << chrono::duration <double, nano> (diff).count() << " ns" << endl;  // Convert to printable format


Testing Guide for Marking 
----
I utilised the code above which can be uncommented and then following the below procedures can obtain ns time. 

---

Functionality 1 - Merge Sort

---
Simply change the command for running the program to:

    ./program.exe ./test-f1-1.txt ./location.txt
    ./program.exe ./test-f1-2.txt ./location.txt
    ./program.exe ./test-f1-3.txt ./location.txt
    ./program.exe ./test-f1-4.txt ./location.txt
    ./program.exe ./test-f1-5.txt ./location.txt

In the program run the 4th option with these files to sort and display item list. 

---

Functionality 2 - Hashing

---

    ./program.exe ./test-f2-1.txt ./location.txt
    ./program.exe ./test-f2-2.txt ./location.txt
    ./program.exe ./test-f2-3.txt ./location.txt
    ./program.exe ./test-f2-4.txt ./location.txt
    ./program.exe ./test-f2-5.txt ./location.txt

The program automatically does hash insert on every input file so you can get this data on initial execution. 
Additionally around the 1,2,3 insertion, lookup, deletion functionalities of the code all use the hash table data structure which can be used through the program interface. 

---
Functionality 3 - Dijkstras' Algorithm

---

    ./program.exe ./delivery.txt ./test-f3-1.txt
    ./program.exe ./delivery.txt ./test-f3-2.txt
    ./program.exe ./delivery.txt ./test-f3-3.txt
    ./program.exe ./delivery.txt ./test-f3-4.txt
    ./program.exe ./delivery.txt ./test-f3-5.txt

    // Additional files take forever to generate but used for the empirical analysis 
    ./program.exe ./delivery.txt ./test-f3-6.txt  //This file was 500MB and made the compressed file over 200MB hence removed but it contained a 15k by 15k matrix for 15000 vertices for Dijkstra's
    ./program.exe ./delivery.txt ./test-f3-7.txt

The program's 5th option runs Dijkstra's algorithm to obtain a list of shortest paths to each point from a given point. This function efficiently allows you to calculate the time complexity of the algorithm. 
A potential addition/revision to this function is that rather than printing an absurdely long list of shortest path distances to each vertex, we can just print the one the user wants. I had done this previously as it is easy to hide the entire list, but for the sake of this assignment and showing that the algorithm works I have it printing the list. 


---





### Additional notes

- delivery.txt and location.txt are hand tested files that I have kept to showcase the program functionality. 
- The test cases for empirical analysis 5 of which have been kept 
- This application was tested on windows 10, with the following commands and ran successfully as per the design document






