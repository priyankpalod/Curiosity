/*
See the effect of branch prediction!
Sorted array takes an order of magnitude less to do conditional sum since the if(data[c]>=128) branch is much predictable then.

###############################################################################
Without sort, time ./a.out
###############################################################################

21.773
sum = 314931600000

real    0m21.799s
user    0m21.772s
sys 0m0.000s

###############################################################################

###############################################################################
With sort, time ./a.out
###############################################################################

7.91469
sum = 314931600000

real    0m7.925s
user    0m7.920s
sys 0m0.000s

###############################################################################


*/

#include <algorithm>
#include <ctime>
#include <iostream>

int main()
{
    // Generate data
    const unsigned arraySize = 32768;
    int data[arraySize];

    for (unsigned c = 0; c < arraySize; ++c)
        data[c] = std::rand() % 256;

    // !!! With this, the next loop runs faster
    // std::sort(data, data + arraySize);

    // Test
    clock_t start = clock();
    long long sum = 0;

    for (unsigned i = 0; i < 100000; ++i)
    {
        // Primary loop
        for (unsigned c = 0; c < arraySize; ++c)
        {
            if (data[c] >= 128)
                sum += data[c];
        }
    }

    double elapsedTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

    std::cout << elapsedTime << std::endl;
    std::cout << "sum = " << sum << std::endl;
}