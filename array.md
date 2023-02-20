STATIC ARRAY (**compile time constant, no changing**)

Definition: collection of elements of the same type placed in contiguous memory locations


Typical declaration is:

  <data_type> name [<size>];
 
  
Initializing:
  
  int foo [5] = { 16, 2, 77, 40, 12071 }; 
  
  int foo[] { 10, 20, 30 }; // compiler figures out the length of the array for you
  
  int foo[0] = 1; //Assignments don’t work if the array is const.
  
  
obs: int baz [5] = { }; -> all 5 ints are initialized with zero
  
obs: int foo [5] = { 16, 2, 77, 40 }; -> if left out the value of those is 0
  
obs: int array[5]; // uninitialized (cause int doesn't self-initialize)
  
obs: string array[5]; // Initialize all elements to an empty string
  
  
  **Enum as array index**
```cpp
enum StudentNames{
    kenny, // 0
    kyle, // 1
    stan, // 2
    butters, // 3
    cartman, // 4
    max_students // 5 };

int main(){
    int testScores[max_students]{}; // allocate 5 integers
    testScores[stan] = 76;

    return 0;}
```
Enum class (don’t have an implicit conversion to integer, so add static_cast to convert the enumerator to an integer)
```cpp
enum class StudentNames{
    kenny, // 0
    kyle, // 1
    stan, // 2
    butters, // 3
    cartman, // 4
    wendy, // 5
    max_students // 6
};

int main(){
    int testScores[static_cast(StudentNames::max_students)]{}; // allocate 6 integers
    testScores[static_cast(StudentNames::stan)] = 76;

    return 0;
}
  //OR
namespace StudentNames{ //?????????
    enum StudentNames{
        kenny, // 0
        kyle, // 1
        stan, // 2
        butters, // 3
        cartman, // 4
        wendy, // 5
        max_students // 6
    };
}

int main(){
    int testScores[StudentNames::max_students]{}; // allocate 6 integers
    testScores[StudentNames::stan] = 76;

    return 0;
}
  
```
  
  
MULTIDIMENSIONAL ARRAY
  
  int arr[3][5] = {{1, 2, 3, 4, 5}{6, 7, 8, 9, 10}{11, 12, 13, 14, 15}}
  
  char century [3][4][5];

obs: Multidimensional arrays can contain as many indices as needed. But be careful because of the amount of memory needed for an array increases exponentially with each dimension

obs: array with initialized lists can omit only the left lenght especification
  
OBS: STRING IS AN ARRAY OF CHARACTERS WITH NULL TERMINATOR('\0')  

-> 2 types of string: ps: C-style string has fixed buffer sizes, harder to use

-> #include <string_view> //no copy created just view, swap string for string_view when creating

obs: view modification functions: <nameofstrview>.remove_prefix(<nofchartoremove>); or .remove_suffix(<n>);

obs: string_view doesn’t use '\0', it keeps track of its length.

ps: no using strlen in string_view (cause it expects null terminator)
  

  
**How to pass an array to a function:**
  
  **Pass particular element to function:**
```cpp
void pass(int arr){<body>}
int main(){...
  pass(arr[3]);  
}
```
  
  **Pass whole array into the function:**
```cpp
void pass(int arr[]){<body>} // no copy original array passed 
int main(){... //changing in function changes original argument
  pass(arr);
}
```
obs: **No copy** original array passed to function
  
std::size(<array_name>) function from the <iterator> header can be used to determine the length of arrays.

obs: this will not work for arrays that have been passed to functions!
  
  -> works for vector too
OR
  older version: sizeof(<array_name>)/sizeof(<arra_element>)
  
    - only works in fixed-leght array, and same function that array is declared in
  
    - If used on an array that has been passed to another function returns size of pointer
 
  **Selection Sort**: lives in the <algorithm> header
  
  -> std::sort(std::begin(array), std::end(array))
  
 -> std::sort(std::begin(array), std::end(array), <)
                                                     
 **Bubble sort** works by comparing adjacent pairs of elements, and swapping them if the criteria is met (lots of ways to optimize bubble sort).
                                                     
swap(<this>, <for this>) //in header <utility>
  
  
