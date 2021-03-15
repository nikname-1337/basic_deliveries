#include <iostream>
#include <vector>
#include <random>
#include <functional> //for std::function
#include <algorithm>  //for std::generate_n
// code from https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
typedef std::vector<char> char_array;
using namespace std;
char_array charset()
{
    //Change this to suit
    return char_array( 
    {'0','1','2','3','4',
    '5','6','7','8','9',
    'A','B','C','D','E','F',
    'G','H','I','J','K',
    'L','M','N','O','P',
    'Q','R','S','T','U',
    'V','W','X','Y','Z',
    'a','b','c','d','e','f',
    'g','h','i','j','k',
    'l','m','n','o','p',
    'q','r','s','t','u',
    'v','w','x','y','z'
    });
};    

// given a function that generates a random character,
// return a string of the requested length
std::string random_string( size_t length, std::function<char(void)> rand_char )
{
    std::string str(length,0);
    std::generate_n( str.begin(), length, rand_char );
    return str;
}

int main()
{
    int NUM = 50000;
    //0) create the character set.
    //   yes, you can use an array here, 
    //   but a function is cleaner and more flexible
    const auto ch_set = charset();

    //1) create a non-deterministic random number generator      
    std::default_random_engine rng(std::random_device{}());

    //2) create a random number "shaper" that will give
    //   us uniformly distributed indices into the character set
    std::uniform_int_distribution<> dist(0, ch_set.size()-1);

    //3) create a function that ties them together, to get:
    //   a non-deterministic uniform distribution from the 
    //   character set of your choice.
    auto randchar = [ ch_set,&dist,&rng ](){return ch_set[ dist(rng) ];};

    //4) set the length of the string you want and profit!        
    auto length = 6;
    int d = 20200210;
    std::cout<< NUM << endl;
    // For generating hashing test and modified for mergesort data
    for(int i = 0; i <NUM; i++){
        std::cout<<random_string(length,randchar)<<" "<< rand()*(rand()%17+1)<< " " << random_string(4,randchar) <<"\n";
    }
    
    return 0;
}
