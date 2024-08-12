# cVec Library

## Overview

`cVec` is a simple dynamic array (vector) implementation in C. It provides basic functionalities to create, add, and remove elements from a dynamic array.

## Features

- **Dynamic resizing**: Automatically resizes the array as elements are added or removed.
- **Memory management**: Handles memory allocation and deallocation.
- **Element removal**: Supports removing elements by index or by value.
- **Transfer data**: Transfer data from one cVec to another.
## Installation

To use the `cVec` library, simply include the `cVec.h` file in your project and compile it with your source code.


#include "cVec.h"

# Usage
# Creating a Vector
```c

cVec* vec = create_cVec();
```
# Adding an Element
```c
int* value = (int*)malloc(sizeof(int));
*value = 42;
cVec_add(vec, value);
```
# Removing the Last Element
```c
cVec_remove_last(vec);
```

# Removing an Element by Index
```c
cVec_remove_object_by_index(vec, 0); // Removes the first element
```
# Removing an Element by Value
```c
cVec_remove_object_by_argument(vec, value);
```
# Transfer data
```c
// Erase data from vec_dest and transfer data from vec_source
cVec_erase_transfer(vec_dest, vec_source);

// Append data from vec_source to vec_dest, keeping existing data in vec_dest
cVec_transfer(vec_dest, vec_source);
````

# Destroying the Vector
```c
cVec_destroy(vec);
```
Example
```c
#include "cVec.h"
#include <stdio.h>
int main() {
    cVec* vec = create_cVec();

    int* value1 = (int*)malloc(sizeof(int));
    *value1 = 10;
    cVec_add(vec, value1);

    int* value2 = (int*)malloc(sizeof(int));
    *value2 = 20;
    cVec_add(vec, value2);

    printf("Vector size: %d\n", vec->size); // Output: Vector size: 2

    cVec_remove_last(vec);
    printf("Vector size after removing last: %d\n", vec->size); // Output: Vector size after removing last: 1

    cVec_destroy(vec);
    return 0;
}
```
## License
This project is licensed under the MIT License - see the LICENSE file for details.