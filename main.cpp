#include <iostream>
#include <cstdio>
#include <ctime>
#include <boost/container/flat_map.hpp>
#include <boost/container/stable_vector.hpp>
#include <vector>


using namespace std;

void test_function(){
    srand( (unsigned)time(NULL) );
    for(int i=0;i<100;i++) {
        boost::container::flat_map<int, int> test_map;
        boost::container::stable_vector<int> test_keys;
        // Insert random keys
        for (int i = 0; i < 100000; i++) {
            int random_key = rand() % 100000;
            test_map[random_key] = 0;
            test_keys.push_back(random_key);
        }

        for (int key : test_keys) {
            test_map[key] += 1;
        }
    }

}



int main() {
    std::clock_t start;
    double duration;

    start = clock();

    test_function();

    duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout<<"Total time: "<< duration <<'\n';
}
