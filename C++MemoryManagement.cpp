// C++ Code to manage memory manually and with smart pointers
#include <iostream> // For std::cout, std::endl
#include <vector>   // For std::vector (to avoid raw array issues for multiple objects)
#include <memory>   // For smart pointers (to show modern C++ approach)

// A simple class to demonstrate memory allocation/deallocation
class MyObject
{
public:
    int value;
    // Constructor
    MyObject(int val) : value(val)
    {
        std::cout << "MyObject(" << value << ") created." << std::endl;
    }
    // Destructor
    ~MyObject()
    {
        std::cout << "MyObject(" << value << ") destroyed." << std::endl;
    }
};

// Function demonstrating manual allocation and deallocation
void manualMemoryFunction()
{
    std::cout << "\n--- Manual Memory Management ---" << std::endl;

    // 1. Basic Allocation and Deallocation
    // Allocate a single MyObject on the heap
    MyObject *obj1 = new MyObject(10);
    std::cout << "obj1 value: " << obj1->value << std::endl;
    // Deallocate the object when no longer needed
    delete obj1;
    obj1 = nullptr; // Set to nullptr to avoid dangling pointer

    // 2. Demonstrating a potential memory leak
    std::cout << "\n--- Potential Memory Leak Scenario ---" << std::endl;
    MyObject *leakObj = new MyObject(20);
    // If we forget to call 'delete leakObj' here, this memory will be leaked.
    std::cout << "Leak object created. Forgetting to delete it..." << std::endl;
    // The pointer 'leakObj' goes out of scope, but the allocated memory is not freed.

    // 3. Demonstrating a dangling pointer
    std::cout << "\n--- Dangling Pointer Scenario ---" << std::endl;
    MyObject *danglePtr = new MyObject(30);
    delete danglePtr; // Memory is freed
    // danglePtr is now a dangling pointer: it points to freed memory.
    // Using it is undefined behavior.
    // std::cout << "Attempting to use dangling pointer: " << danglePtr->value << std::endl;

    // 4. Allocating an array
    std::cout << "\n--- Allocating an Array ---" << std::endl;
    MyObject *objArray = new MyObject[3]{MyObject(40), MyObject(41), MyObject(42)};
    std::cout << "objArray[0] value: " << objArray[0].value << std::endl;
    // Must use 'delete[]' for arrays
    delete[] objArray;
    objArray = nullptr;

    std::cout << "--- End of Manual Memory Management Section ---" << std::endl;
}

// Function demonstrating modern C++ with smart pointers
void smartPointerFunction()
{
    std::cout << "\n--- Smart Pointer Memory Management ---" << std::endl;

    // 1. std::unique_ptr: Exclusive ownership
    std::cout << "std::unique_ptr demo:" << std::endl;
    std::unique_ptr<MyObject> u_ptr = std::make_unique<MyObject>(50); // Allocated on heap
    std::cout << "u_ptr value: " << u_ptr->value << std::endl;
    // No 'delete' needed. Memory automatically freed when u_ptr goes out of scope.

    // Transfer ownership
    std::unique_ptr<MyObject> u_ptr_moved = std::move(u_ptr);
    // std::cout << "u_ptr after move: " << u_ptr->value << std::endl; // Compile error: u_ptr is moved
    std::cout << "u_ptr_moved value: " << u_ptr_moved->value << std::endl;

    // 2. std::shared_ptr: Shared ownership (reference counting)
    std::cout << "\nstd::shared_ptr demo:" << std::endl;
    std::shared_ptr<MyObject> s_ptr1 = std::make_shared<MyObject>(60);
    std::cout << "s_ptr1 value: " << s_ptr1->value << std::endl;
    std::cout << "s_ptr1 use count: " << s_ptr1.use_count() << std::endl;

    std::shared_ptr<MyObject> s_ptr2 = s_ptr1; // s_ptr2 also points to the same object
    std::cout << "s_ptr2 value: " << s_ptr2->value << std::endl;
    std::cout << "s_ptr1 use count after s_ptr2: " << s_ptr1.use_count() << std::endl;

    // Object destroyed when last shared_ptr goes out of scope.
    std::cout << "s_ptr1 and s_ptr2 will go out of scope at end of function." << std::endl;
    std::cout << "--- End of Smart Pointer Memory Management Section ---" << std::endl;
}

// Main function to demonstrate memory management
int main()
{
    std::cout << "--- C++ Memory Management ---" << std::endl;

    manualMemoryFunction();
    smartPointerFunction();

    // The leaked object from manualMemoryFunction will only be truly reclaimed
    // when the program exits. This highlights the leak.

    std::cout << "--- End of C++ program ---" << std::endl;
    return 0;
}