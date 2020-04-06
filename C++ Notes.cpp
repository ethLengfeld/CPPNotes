C++ Notes

// DATE 01/22/2019
compile with g++:
g++ <filename>.cpp
./<filename>.out


// don't need to specify a return statement, auto returns 0


// smallest program you can write in C++
int main(){}

// to properly cast
cast-name<type>(expression)
// maybe like
double x = 2.0;
int y = cast-name<int>(x);


// complier deduces the data type from assignment -> auto-fills generic
auto i = 0;

// 0 value is false. Any other value pos or neg is true


// when code is handled by complier then everything
// is figured out before run-time
// has no impact on the run-time speed.

// DATE 01/29/2020

// while
while(expression) {
	statements;
}


// goto statements
// goto make it harder to follow program flow and debug
goto gotoLbl;

gotoLbl:
...


// I/O

// namespace
// A named scope
// Similar to package in Java

// Using declarations
using namespace 'namespace'
-Exposes all the names from 'namespace'
-Saves keystrokes.. but there are risks
-Never in a header file! Only in .cpp
* Has put standard(std) in header file

// IOSTREAM Library
#include<iostream>
-Insertion or output operator <<
-Standard out: std::cout
-Standard error: std:cerr
-End of line: std::endl (preferable over "\n")

-Input operator >>
-Standard input: std::cin


int a, b, c;
std::cin >> a >> b >> c;


// exposing the  std::cout
#include  <iostream>
using  std::cout;

int  main(){
	cout  << "Enter  in 3 numbers: ";
	int a, b, c;
	std::cin  >> a >> b >> c;
	cout  << "You  entered: " << a << ", " << b << ", " << c << std::endl
		  << "Their  average  is: " << (a + b + c)/3.0  << std::endl;
}

// exposing the namespace std
#include  <iostream>
using  namespace std;

int  main(){
	cout  << "Enter  in 3 numbers: ";
	int a, b, c;
	cin  >> a >> b >> c;
	cout  << "You  entered: " << a << ", " << b << ", " << c << endl
		  << "Their  average  is: " << (a + b + c)/3.0  << endl;
}


// STRINGS
#include <string>

std::string is a sequence of char.


/* 
https://en.cppreference.com/w/cpp/string/basic_string
*/

// FOR loop
#include <string>
#include <iostream>
using namespace std;

int main() {
		string s("foobar");
		for(auto c: s) {
				cout << c << endl
		}
	
}

// Compilation
/*
-Preprocessing: Handle lines beginning with "#"
-Compilation: Code translated into assembly
-Assembly: The assembly code is translated into machine code or object code
-Linking: Links the machine code from multiple object files to create an executable
*/

/*
For each source file, you preprocess, compile and assemble
g++ -c -o src_name.o src_name.cpp

For each program, you link:
g++ -o exec_name src_name.o main.cpp
*/

// HEADER files
Usual extension: “.h”; contains:
the class and function prototypes (and the
function comments),
includes of libraries needed for the
prototypes, and
enums (and structs) used in the function
declarations.
Bad form to put using directives in header
files.

// SOURCE files
Source Files Usual extension: “.cpp”; contains:
the function definitions,
includes of libraries needed not already
included in the header,
any other internal enums, structs, etc...

// make sure using c++ version e.g. #include <cstring> not <string.h>


// GOOD PRACTICE! include these in header files
# ifndef IFNDEF_H
# define IFNDEF_H
/* Contents of header file goes here . */
# endif /* IFNDEF_H */


// WATCH OUT FOR TRIGRAPHS!!!
ex. 
??= is eqivalent to #


// Makefiles
# I’m a comment
#CXX will define what compiler we use
CXX=g++
#CXXFLAGS will define what flags we'd like with compilation
#Wall will give us all warnings
CXXFLAGS =- Wall

all: build

module.o: module.h

#make clean will run clean command
clean:
	# these spaces must be tabs
	-rm module.o
	# the - before rm tells it to continue even if there are errors 
	-rm hello

build: main.cpp module.o
	$(CXX) $(CXXFLAGS) -o hello main.cpp module .o


// Put all function comments within the header files

// * What happens in your code depends on the compiler that you use *




// DATE 02/05/2020


// STATIC INT
#include <iostream>
using namespace std;
int g(int a) {
	// this is declared static
	static int b = 0
	b =+ a;
	return b;
}

int main() {
	cout << g(1) << g(2) << endl;
	// out prints 13
	// default 0 is returned
}


// Pointers
// a pointer to an object, an object genral means an
// area in memory, but is also overloaded to mean an instance
// of a class.

// *Like reference in Java

// Arrays are like those in java


// References


// Caveat
#include <iostream>
using namespace std;
int foo() {
	int fooVar = 42;
}
int bar() {
	int barVar;
	cout << barVar;
}
int main() {
	bar();
	foo();
	bar();
}
// This out prints 042
// stack frame for the methods don't get reset.
// In this example foo() and bar() will be given
// an indentically sized stack frame


// MEMORY

// from bottom to top!
// TEXT - all functions -> RAM
// DATA - where global and static is found

// HEAP - read/write you manage this in C++ whereas java has auto garbage collector
// just a heap of memory can pull chuncks as needed

// STACK - locals managed by the compiler, popping and pushing 


// HEAP MEMORY
// *must clean up after yourself!

//Dynamically allocated using the new operator or malloc/calloc/realloc

// The memory is only deallocated when programmer decides - LIFETIME code


//THE STACK

// auto managed by compiler
// faster and no fragmentation
// try and keep everything on stack




// POINTERS
// contain address of of another variable
//

int *aPtr;
int aVar;
aPtr = &aVar;
aVar = 5;
*aPtr = 10;

// Syntax:
// type *ptrName; - Declaration
// & - address of operator

void someFunc(int *aPtr, int bVal){
	bVal = 4;
	*aPtr = 5;
	aPtr = &bVal;
	*aPtr = 7;
}
int main() {
	int i = 1;
	int j = 2;
	// send address of i
	// send a copy of the value in j
	someFunc(&i,j);
	
	printf("i=%d;j=%d",i,j);
}
// this will print out 'i=5;j=2'


// SEG FAULTS

int* foo() {
	int i = 10;
	return &i;
}
int main() {
	int* aPtr = foo();
	// results in seg fault because this address was created
	// from a function's stack frame.
}


// REFERENCE
int *aPtr;
int aVar;
int &aRef = aVar;
aVar = 5;
*aPtr = 10;
aRef = 6;

// Syntax
// type &refName; - Declaration

// * USE REFERENCES OVER POINTERS WHENEVER POSSIBLE *
// however syntactically references don't stand out like references do.


// DATE 02/12/2020

#include <iostream>

using namespace std
int& foo(int& a) {
	return a;
}
int main() {
	int i = 1;
	// unique to C++, foo(int&) returns a reference.
	foo(i) = 5;
	
	cout << i;
	// output will be 5
}

int myFunc(const int a); 
// OR
int  myFunc(int const a);

// promise that this value won't change
const

// STRUCTURES or struct 
// a group of one or more variables. Also, called a record

// struct example Bank Account:
-account numbers

enum typeAcct {CHK, SAV};
struct account {
	long acctNum;
	enum typeAcct acctType;
};

struct account acct1;

struct account acct2 = {12345, CHK};

struct account acct3 = {.acctNum = 123432, .acctType = SAV};

// Structure member operator (.)
cout << acct3.acctNum;
// Outputs 123432

// Pointer to struct 
(*ptrAcct).acctNum;
// OR
ptrAcct->acctNum;

// . has higher precedence than *


// to compare sturcts
// have to go through each member 



// Shallow Copy - copying the bit sof one struct to the other

typedef // a keyword used to create an aliad for another datatype
typedef cType newType

Ex:
typedef long unsigned int size_t;

typedef struct account {
	long acctNum;
	enum typeAcct acctType;
} acct;


// STL overview (Standard Template Library)

// STL is only C++!!!!!!!!!!!

// Containers:
// Vector
// List
// Set
// Map

//Iterators:
// input
// output
// forward
// bidirectional
// random access


// Algorithms:
// sorting
// searching
// max/min
// aggregation

// Functional Objects:
// unary functions
// binary functions


// VECTOR - the dynamic array list
// c++ equivalent of ArrayList

// On the Stack:
vector <int > v1; // Empty vector
vector <int > v2(v1 ); // Copy of v1
vector <int > v3 = v1; // Copy of v1
vector <int > v4 (10 ,42); // Ten 42s
vector <int > v5 (10); // Ten 0s
vector <int > v6 {1 ,2 ,3 ,4 ,5}; //1 to 5
vector <int > v7 = {1 ,2 ,3 ,4 ,5}; //1 to 5

// On the Heap:
vector <int > *p1; // Vector pointer , unassigned
vector <int > *p2 = new vector <int >; // Vector pointer
vector <int > *p3 = &v2; // Copy of addr of v2
vector <int > *p4 = new vector <int >(10 ,42); // Ten 42s
vector <int > *p5 = new vector <int >(10); // Ten 0s
vector <int > *p6 = new vector <int >{1 ,2 ,3 ,4 ,5}; //1 to 5

// Status
v.size(); // number of elements
v.capacity(); // number of elements that can be held in reserved spaces

// Adding/Removing
v.push_back(7); // add to the back
v.pop_back(7); // remove last item

// Random Access
v[0] =  7; // (0-based indexing)
int i = v[3];


// Iterators
vector<int>::iterator ite = v.begin();
// auto means we don't need to worry about getting the right value type
auto jtr = v.begin();
/*
	Forward: v.begin() (first element)/ v.end() (one past
	last element)
	Constant Forward (C++11): v.cbegin() / v.cend()
	Reverse: v.rbegin() / v.rend()
	Constant Reverse (C++11): v.crbegin() / v.crend()
*/

// member functions using iterators
v.insert(itr, 1); // Insert before itr. (There are other insert variants.)
v.erase(itr); // Remove item at itr. (Invalidates itr.)
v.erase(itr,jtr); // Remove items

// Range based for loop
vector <int > v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
for ( auto &i : v)
{
	cout << i << " ";
}

// OR using an iterator

for ( auto itr = v. begin(); itr != v.end(); ++itr )
{
cout << *itr << " ";
}

// iterator example:

// Erase all even numbers (C ++11 and later )
auto jtr = v. begin ();
// make sure you get an updated iterator v.end()
while (jtr != v.end ())
{
	if (* jtr % 2 == 0) {
		jtr = v. erase (jtr );
	} else {
		++ jtr;
	}
}


// vector example:
# include <vector >
# include <iostream >
using namespace std;
int main ()
{
	vector <char> v{’a’,’b’,’c’,’d’,’e’};
	
	cout << v; // compilation error
	cout << &v; // memory address
}


// SORTING Basics
#include <algorithm>

// must define function f which works as your comparison.
# include <vector >
# include <algorithm >
# include <iostream >
using namespace std;
bool f( const int &a, const int &b)
{
	if(a % 2 == 0 && b % 2 != 0)
		return true ;
	if(a % 2 != 0 && b % 2 == 0)
		return false ;
	return a > b;
}
int main ()
{
	vector <int > v{1 ,2 ,3 ,4 ,5};
	sort (v.begin(), v.end(), f);
	for ( auto &i: v)
		cout << i;
}



// DATE 02/19/2020

// TODO for program!!!!!!!!!
// do c++ style casting, write own method descriptions


// ASSOCIATIVE CONTAINERS

//map - key-value pairs; unique keys
//set - key-value pairs; unique keys
//multimap - repeated keys
//multiset - repeated keys

// map
// k is the key
m[k] = "foo" // Updates/inserts, at key k, the value "foo".
bar = m[k] // Retrieves the value at key k.
//Note m[k] adds k with empty value if key doesn’t exist.


// all values in map are stored as pair<T1, T2> p
//Elements in a map are stored as pairs.
p.first // First data member (key in a map)
p.second // Second data member (value in a map)

// Range-based for
for ( auto &p : m)
{
	cout << "key: " << p. first << endl
	<< " value : " << p. second << endl ;
}

// I/O
// given the input "2.5 2.5 2.5"
int a;
double b;
string c;
cin >> a >> b >> c;
cout << a << b << c;

// output = 2.52.5


// good idea to test stream.good() before computation
if(s) {.....} // tests s.good()
while (s >> a) {....}


// closing stream
s.close() // automatically flushes the stream

// a stream has ONE Marker. All operations happen relative to that marker.
seekg(pos) / seekp(pos) // set marker to absolute position of pos.

// I/O streams only have one marker



// ARRAYS
// C++ Heap Allocation (recommended)
int *a = new int[10]; // or
int *a = new int[10](); // zeros memory or
int *a = new int[10]{1,2,3,4,5,6,7,8,9,10}; //(C++11)

// Preventing Memory Leaks
// If you new [], you need to delete [] the memory!
delete [] a;




// DATE 02/26/2020

// Classes and the Rule of 3


// CLASSES
// provide a way of defining new types that
// group member variables and functions.

// Access COntol
public // members are accessible outside the class
private // members are only accessible inside the classs to its friends
protected // only accessible inside class, derived classes, and friends

// Class vs Struct
class is private
struct is public

/*Usual Practice: struct used for simple containers */



// ORGANIZING C++ CLASSES
SomeClass.h:
# ifndef HEADER_GUARD_MACRO // Unique macro name
# define HEADER_GUARD_MACRO
// includes need for class definition
class SomeClass {
// friends first
public :
// public members
// public constructors , copy - control
// public functions
private :
// private members
// private functions
}; // Don ’t forget the semi - colon !
# endif // HEADER_GUARD_MACRO



// Constructors
HockeyPlayer.h:
public :
// makes this default constructor
HockeyPlayer () = default ;
// name(n) will automatically assign n to name field
HockeyPlayer (std :: string n): name (n) {}
// could be called HockeyPlayer player = "ethan"; to prevent this use the word explicit


HockeyPlayer.h:
public :
HockeyPlayer () = default ;
HockeyPlayer (std :: string n, int g, int a):
name (n), goals (g), assists (a) {}
// this makes 
explicit HockeyPlayer (std :: string n): HockeyPlayer (n, 0, 0){}
private :
std :: string name {""};
int goals {0};
int assists {0};
int gamesPlayed {0};
double toi {0.0};
double penaltyMin {0.0};




// Best practice: write initializers in same order as they are
// declared:
Foo(int val): i(val), j(val) {}





// FRIENDS - let them play with private members
class HockeyPlayer {
friend std :: ostream &operator <<( std :: ostream &os , const HockeyPlayer & rhs );

<< // Operating Overload






// Rule of 3
// The Big Three

// In class Foo: (nearly always public)

// Copy Constructor (Copy c-tor)
Foo(const Foo&);

// Copy-Assignment (Copy op=)
Foo& operator=(const Foo&);

// Destructor (d-tor)
~Foo();


// All classes need rules for copying, assigning, and
// destroying.
// C++ will synthesize any of the big three if not defined.
// The synthesized versions are shallow bit-wise by default.



// Resource Acquisition Is Initialization (RAII)

// Key C++ Programming Technique
// Tie a resources scope to the life span of an object.
// Resources such as: heap memory, open sockets, open files,
// mutexes, database connections...

// Connection to the Rule of Three
// To avoid resource leaks, any class that controls resources
// require:
Copy c-tor
Copy op=
d-tor


// Fraction Class
# ifndef FRACTION_EX_H
# define FRACTION_EX_H
# include <iostream >
class UnsignedFraction {
	friend std :: ostream & operator <<( std :: ostream &, const UnsignedFraction &);
	friend std :: istream &operator >>( std :: istream &, UnsignedFraction &);
	friend UnsignedFraction operator +( const UnsignedFraction &, const UnsignedFraction &);
	friend bool operator ==( const UnsignedFraction &, const UnsignedFraction &);
	friend bool operator !=( const UnsignedFraction &, const UnsignedFraction &);
	friend bool operator <( const UnsignedFraction &, const UnsignedFraction &);
	
	public :
		UnsignedFraction () = default ;
		UnsignedFraction ( const unsigned long long n): num (n) {};
		UnsignedFraction ( const unsigned long long n,
		const unsigned long long d): num (n), denum (d) {};
		UnsignedFraction &operator =( const unsigned long long );
		UnsignedFraction &operator +=( const UnsignedFraction &);
		UnsignedFraction &operator ++(); // Prefix
		UnsignedFraction operator ++( int ); // Postfix
		unsigned long long &operator []( const unsigned int );
		const unsigned long long &operator []( const unsigned int ) const ;
		operator double () const ;
	private :
		unsigned long long num {0};
		unsigned long long denum {1};
};
# endif // FRACTION_EX_H

// DATE 03/28/2020
// Operator Overloading

// Overloadable:
+ - * / % ^ & | ~ ! , = ->
< > <= >= ++ – << >> == != && || ->*
+= -= /= %= ^= &= |= *= <<= >>= [] ()
new   new[]    delete    delete []

//Non-overloadable: 
. .* :: ?: sizeof

// Output Operator Overload
ostream &operator <<( ostream &os , const UnsignedFraction &rhs )
{
	os << rhs . num << "/" << rhs . denum ;
	return os;
}

// Input Operator Overload
istream &operator >>( istream &is , UnsignedFraction &rhs )
{
	string s;
	is >> rhs . num >> s >> rhs . denum ;
	if (! is || s != "/")
	{
		rhs . num = 0;
		rhs . denum = 1;
	}
	return is;
}

// Arithmetic Operator Overload
UnsignedFraction operator +( const UnsignedFraction &lhs , const UnsignedFraction &rhs )
{
	return UnsignedFraction ( lhs . num * rhs . denum + rhs . num * lhs.denum ,
								lhs . denum * rhs . denum );
}

// Comparison Operator Overload
bool operator ==( const UnsignedFraction &lhs , const UnsignedFraction &rhs )
{
	return lhs .num * rhs. denum == rhs . num * lhs. denum ;
}

bool operator !=( const UnsignedFraction &lhs , const UnsignedFraction &rhs )
{
	return !( lhs == rhs );
}

bool operator <( const UnsignedFraction &lhs , const UnsignedFraction &rhs)
{
	return lhs .num * rhs. denum < rhs .num * lhs . denum ;
}
/* if you define one of the < brackets you should define the other relational operators */


// Assignment Operators Overload
// MUST be member functions
UnsignedFraction &UnsignedFraction :: operator =( const unsigned long long rhs )
{
	if( this != &rhs ) {
		*this . num = rhs . num ;
		*this . denum = rhs. denum ;
	}
	return * this ;
}
UnsignedFraction &UnsignedFraction :: operator +=( const UnsignedFraction &rhs )
{
	*this = *this + rhs ;
	return *this ;
}

// Subscript Operators Overload
// MUST be member functions
// MUST have two versions; const and non-const
// The should be two:
	// A non-const version for setting.
	// A const version for getting.
unsigned long long &UnsignedFraction :: operator []( const unsigned int index )
{
	if( index % 2 == 0) return num ;
	return denum ;
}

const unsigned long long &UnsignedFraction :: operator []( const unsigned int index ) const
{
	return (*this)[index];
}

// Prefix and Postfix Operators Overload

UnsignedFraction &UnsignedFraction::operator++()
{
	num += denum ;
	return * this ;
}

UnsignedFraction UnsignedFraction :: operator ++(int)
{
	UnsignedFraction toRet (*this);
	++(*this);
	return toRet;
}

// Conversion Operators
// Must be a member function.
// Must be no return type and no parameters.
// Use explict modifier to prevent implicit use of conversion.
// Converts class instance to another data type.
// For data type to class instance, make a constructor with a single pararmeter

class UnsignedFraction {
	public :
		operator double () const ;
};
UnsignedFraction::operator double () const
{
	return static_cast <double>( num ) / denum ;
}



// DATE 03/28/2020
// Templates

// Both functions and classes can be templated.
// The templates are instructions to the compiler


// Compilation Stages:
/*
1 Template Compilation: The compiler checks the for syntax
errors such as missing semi-colon or misspelled names. No
runnable code is created.
2 Template Usage: The compiler verifies that the usage of
the template is correct: number of arguments is correct,
and data types appropriate.
3 Instantiation: The compiler creates the type specific code
from the usage, and compiles it, which may lead to type
specific errors.
*/


// Generic Functions


// Functions Templates
template<typename T> T combine(T a, T b)
{
	T c = a + b;
	return c;
}
// template keyword indicates a template.
// typename keyword indicates a undefined type.
// class keyword can be used instead of typename.
// T is the undefined typename (can be any name).
// Once declared in the template, T can be used like any other type.

# include <iostream >
template < typename T> T combine (T a, T b)
{
	T c = a + b;
	return c;
}
int main ()
{
	std :: cout << combine (2 ,3) << " "
				<< combine (2.0 , 3.5);
}
/* THIS WILL NOT COMPILE!! */
// However we could fix that with this
template<typename T, typename S> T combine(T a, S b)



// Non-type Template Parameters
template <typename T, int d> T combine (T a, T b)
{
	T c = a + b + d;
	return c;
}
// Non-type template parameters must be constant expression.
// Parameterizes the template by a constant value.



// Default Arguments for Generics
template < typename T=int , int d=3> T combine (T a, T b)
{
	T c = a + b + d;
	return c;
}
// Just like with function parameters, you can define default values for the template parameters


//Template Overloading
template < typename T> T combine (T a, T b)
{
	T c = a + b;
	return c;
}
template < typename T> T combine (T *a, T *b)
{
	T c = *a + *b;
	return c;
}
// Templates like functions can be overloaded.
// In the example, works the same for non-pointers and pointers.


// CLASS Templates
template <typename T>
class FooTemplate {
	public :
		FooTemplate (T in ): data (in ){};
		FooTemplate combine ( FooTemplate f);
		template <typename T2 > FooTemplate doSomething (T2 );
	private :
		T data {};
		static int c;
};
// Parameterized classes built by the compiler based on usage; similar to template functions.
/* Each generated class is its own class. */
// Same inline rules apply.



// DATE 04/06/2020
// More STL

// https://en.cppreference.com/w/cpp/header/algorithm

// STL Algorithms
// Parameter Patterns

alg(beg, end, other args);
alg(beg, end, dest, other args);
alg(beg, end, beg2, other args);
alg(beg, end, beg2, end2, other args);

// alg – The algorithm function name.
// beg and end – Begin and end iterators.
// dest – Destination begin iterator.
// beg2 and end2 – Destination begin and end iterators.
// other args – Often helper callable objects.


// Iterator Types

// Normal Iterators
	// Iterators defined for each container.
	// I.e., begin, end, cbegin, cend
	
// Reverse Iterators
	// Like normal iterators, but go back to front.
	// I.e., rbegin, rend, crbegin, crend
	// rend is one past the front.

// Move Iterators
	// Used for moving operations on containers.
	// Yields an rvalue reference (&&) when dereferenced.


// Header: these types require
#include <iterator>
// Stream Iterators
	// Iterator bound to an input or output stream.

// Insert Iterators
	// Iterator for inserting into containers.



// Reverse Iterator Example
# include <iostream >
# include <vector >
# include <algorithm >
using namespace std;
void pOut (int i)
{
cout << i << " ";
}
int main () {
vector <int > v = {1 ,2 ,3 ,5 ,8 ,42};
for_each (v. crbegin (), v. crend (), pOut );
}
// 42 8 5 3 2 1


// Stream Iterators

//Input Stream Iterator

// Works on any input stream and data type for which >> is defined.
istream_iterator<T> in(is);
	// in is the iterator name and is is an input stream.
istream_iterator<T> end;
	// end is the iterator name. No arguments sets the end value.
in1 == in2 or in1 != in2
	// Equality comparisons.
++in,in++
	// Sequential access through pre and post increment.
*in and in->mem
	// Dereferencing.


// Output Stream Iterator
// Works on any output stream and data type for which << is defined.
ostream_iterator<T> out(os);
	// out is the iterator name and os is an input stream.
ostream_iterator<T> out(os, d);
	// d is a c-style string appended to each output.
out1 = val
	// Value assignment.
*out, ++out,out++
	// Exists; returns out.


// Example
# include <iostream >
# include <vector >
# include <algorithm >
# include <iterator >
using namespace std;
int main () {
vector <int > v = {1 ,2 ,3 ,5 ,8 ,42};
fill_n (v. begin (), 10, 5); // gives seg-fault error. past vector length
ostream_iterator <int > out_itr (cout , " ");
copy (v. cbegin (), v. cend (), out_itr );
}



// Insert Iterator


// An adaptor that takes a container and yields an iterator that
// adds elements to that container.

it = val
	// Adds val to the container via push_back,
	// push_front, or insert depending on insert type.
*it,++it,it++
	// Exists; returns it.

// Insert Types
//ct is a container.
	back_inserter(ct);
		//Insert using push_back.
	front_inserter(ct);
		// Insert using push_front.
	inserter(ct, itr);
		// Inserts using insert; all insertions in
		// front of iterator itr.



// Iterator Hierarchy

// Random-access Iterator
	// Relational ops (<,>,<=,>=), add/sub ops (+,+=,-,-=) with
	// integral, sub op (-) between iterators, subscript op ([])
	
// Bidirectional Iterator
	// Pre and post --
	
// Forward Iterator
	// Can read and write (multiple times)
	
// Input/Output Iterator
	// Sequential, can read or write, pre and post ++, dereference (*
	// and ->)



// Functors

struct absInt {
	int operator ()( int val ) const {
		return val < 0 ? -val : val ;
	}
};
// Definition
	// Porte-monteau of “function” and “object”. It is an object that
	// behaves like a function, i.e., we can use the () operator and
	// provide pass in arguments.
	
//Creating a Functor
	// Overload the operator() with appropriate parameters.
	
	
	
// Container Adaptors

// Definition
	// An interface that makes a container behave like a particular
	// data structure.
// Types
	// stack: Default using deque
	// queue: Default using deque
	// priority_queue: Default using vector

// Example:
// A stack of ints based on deque
stack <int > stk ;
// A stack of ints based on a vector
stack <int , vector <int > > stk2 ;