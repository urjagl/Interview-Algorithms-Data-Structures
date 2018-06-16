https://www.geeksforgeeks.org/fundamentals-of-algorithms/#AnalysisofAlgorithms

Class and Object and Enum 
- Class is a blueprint that describes the behaviour/state of that object it supports. 
- Object is an instance of a class (like a member)
- Enum is a user-defined data type that consists of integral constants.

Instantiation - to instantiate a class is to create an object
- An instantiated object is given a name and created in memory using the structure described within a class declaration. 

Method: its a member function of a class.

virtual method: A virtual function that can be expected to be redefined in derived classes. so when you refer to a derived class using a pointer or a reference to the base class, we can call a virtual function for that object, and execute the derived class's version of the function. 

pure virtual method: has no implementation of its own in the base/parent class, makes the class abstract, it is required to be implemented by a derived class. they cannot be instantiated directly and these classes serve only as an interface. 

signed and unsigned int: 
Signed can be both positive and negative, unsigned that can never be negative

class/static method: Static method belongs to a class rather than an instance of a class, it can be invoked without the need for creating an instance of a class. 

static/class initializer: the static initializer is a static{} block of code inside java class, and run only one time before the constructor or main method is called. 

constructor: A constructor is a kind of member function that initializes and instance of its class. 

destructor/finalizer: destructor is a member function which deletes and object

inheritance: inheritance enables new objects to take on the properties of existing objects, basis for inheritance - superclass, a class that inherits subclass. 
adv: Reusability 

Encapsulation and Abstraction: 
(finance guy example)
encapsulation is the process of combining data and functions into a single unit called class. data cannot be accessed directly, attributes of the class are kept private and public getter and setter methods are provided tp manipulate these attributes.


Data abstraction(man driving example)
Abstraction is a process of hiding the implementation details from the user, only the functionality will be provided to the user. In other words, the user will have the information on what the object does instead of how it does it.
avoids code duplication, increases reusability, use to avoid low level code, increase security. 

Polymorphism: means having many forms, ability of a message to be displayed in a more than one form: 
- Compile time (Overloading: functions, operators)
- Runtime : overriding (inheritance - member functions.)

Difference between mutex and a semaphore ?
- A mutex provides mutual exclusion, only one thread can acquire it and proceed with their work, protect the critical section to achieve atomic access. Whereas a semaphore is a signalling mechanism, it can allow multiple threads to access a finite instance of resources. 

overloading: same name functions which behave differently based on parameters passed on to them. 

overriding: when derived class function has to do something added or different job than the base class. 

composition/aggregation : relationships between classes, (owns a, has-a, is- a)

Multiple inheritance: when a class inherits from multiple classes (Person, Student, Faculty, TA, example)

interface: An interface describes the behavior or capabilities of a C++ class without committing to a particular implementation of that class. like an abstract class just serves as an interface

functions signature: names, parameters(type, number order)

A static member and an instance member:
static members are shared with all objects of the class.
instance members belong to the object that they are instantiated from. 

Difference between pointers and references 
A pointer is the memory address whereas a reference is just an alias for an object. 

 Regular Expressions ?
Email: '[\w\w.-]+@[\w\.-]+'
Phone: (\d{3}[-\.\s]??\d{3}[-\.\s]??\d{4}|
		\(\d{3}\)\s*\d{3}[-\.\s]??\d{4})+?

Difference between final, finally, finalize Java? 



4. What is multithreaded programming? What is deadlock ? 



5. You have a stream of infinite queries (ie: real time Google search queries that people are entering). Describe how you would go about finding a good estimate of 1000 samples from this never ending set of data and then write code for it.




6. Describe the data structure used to manage memory (Stack)?



7. Which sort will you use to sort 1 million integers?


8. Difference between static, final, const, Java or C++ ?



9. What method would you use to look up a word in a dictionary?



10. Imagine you have a closet full of shirts. It’s very hard to find a shirt. So what can you do to organize your shirts for easy retrieval?


11. Implement 3 stacks in a single array 













Sorting: 

1. QuickSort : This is when we pick up a random element from the array, as our pivot and then we place all the elements smaller than the pivot to its left and the greater elements to the right, inserting the pivot in the middle, and performing recursive calls on each side now. 
The average run time is nlogn, because the partition is recursively log n, and n times for each level. 

The worst case is when the array is either sorted in increasing and decreasing order and now we pick up a pivot as the last element, so n^2. 

2. MergeSort:(Divide and conquer algo) MergeSort is when the list/is recursively divided into two parts, until one single element, and then while merging it's sorted, the lower in the two lists is inserted first and then the pointer is incrememnted.

Now where is this insertion taking place, this is where the space complexity issue comes in. We have to use memory O(n) while merging. 

Why is quicksort better for sorting arrays, and mergesort better for sorting linked lists ? 

- Quicksort requries a lot of random access to its element when inserting, swapping, and with arrays this is O(1), amortized running time. 

- In case of linked lists, nodes may not be adjacent in memory, we can insert items in the middle in O(1) time and space, so the merge operation of merge sort can be implemented without extra space for linked lists. In LL, we cannot do a random access, so we would have to traverse through each and every node, the overhead is more for quick sort. merge sort accesses data sequentially, need of random access is low. 


Massive amount of data: 
External sorting : QUickSOrt, MergeSort, 

databases use an external merge sort to sort sets of data that are too large to be loaded entirely into memory. 

- Heap Sort: Sort an almost sorted array, or finding the k-largest or smallesg element in an array

- Radix and counting sorts are fast but they require structured data, external memory and they do not have the caching benefits of quicksort. These are good when the sorting integers with a limited range. 

- Binary Sorting: this is useful when there is a search i need to do, O(log n) time. 





































