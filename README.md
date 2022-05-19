# Standard Algorithms Library
This is a library that I have created for myself to write out various standard algorithms. Currently
I am only focusing on sorting, but I will populate it with other types in time.

## Building and Installing
The first thing that you need to do is clone the repository.
``` Bash
git clone https://github.com/orlando21lara/std_algo.git
```
Then make the provided scripts executable by running
``` Bash
cd std_algo
chmod +x build.sh
chmod +x install.sh
chmod +x uninstall.sh
```
If you would just like to build the library **without** installing it into your machine then run the
`build.sh` script.
```Bash
./build.sh
```

If you would prefer to install it, simply run the `install.sh` script and on linux this will install
to the /usr/local directory.
``` Bash
./install.sh
```
Lastly if you want to uninstall then run the `uninstall.sh` script which will remove all the files
that were installed, but it won't delete the created subdirectories. All the files and directories
that are installed are mentioned when installing and uninstalling so you can also manually delete
them if you prefer.

## Testing your Installation
To test the installation, first create a source file and call it main.cpp:
``` cpp
#include <iostream>
#include <vector>
#include "std_algo/sort.h"

void printVector(const std::vector<int>& v)
{
    std::cout << "( ";
    for(const int& elem : v)
    {
	std::cout << elem << " ";
    }
    std::cout << ")" << std::endl;
}

int main()
{
    std::cout << "Simple program to test the std_algo library" << std::endl;
    std::vector<int> vec = {4,71,9,3,84,7,53,6,76,101};
    
    std::cout << "Vector before sorting: ";
    printVector(vec);

    mergeSort(vec);

    std::cout << "Vector after sorting: ";
    printVector(vec);
    return 0;
}
```

Then compile the `main.cpp` and link the library.

If you installed the library run:
```bash
g++ main.cpp -lstd_algo
```
If you just built it, then you must specify the path to the header files and the library file:
```bash
g++ main.cpp -I<std_algo-install-path>/include -L<std_algo-install-path>/lib -lstd_algo
```

If your instalation is correct then you should see the following output:
```
Simple program to test the std_algo library
Vector before sorting: ( 4 71 9 3 84 7 53 6 76 101 )
Vector after sorting: ( 3 4 6 7 9 53 71 76 84 101 )
```

## Building Project along your CMake Project
I will provide an example here later, but this is done like with any other static library.

## Adding the library to your CMake Project
I will provide an example here later, but this is done like with any other static library.
