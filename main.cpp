/*
 Project 4 - Part 3 / 9
 Video: Chapter 4 Part 3 
 Casting

 Create a branch named Part3
 
 do not remove anything from main().  you'll be revising your main() to work with these new code changes.
 
    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.

 1) remove your functions that accepted a User-Defined Type
 
 2) remove any getValue() functions if you added them
 
 3) move all of your add/subtract/multiply/divide implementations out of the class.
  
 4) add user-defined conversion functions that convert to the numeric type your object holds.
        i.e. if your type holds an int, you'll need an operator int() function.
 
 5) make your member variable private.
         this conversion function should be the ONLY WAY to access the held value.
         use the proper casting technique to invoke this conversion function
 
 6) make sure it compiles & runs without errors.
 
 7) use your knowledge of casting to remove any conversion warnings. 

 8) insert 'part3();' before the 'good to go' at the end of your main(); 
        move this part3 function to before main()

 9) click the [run] button.  Clear up any errors or warnings as best you can.

 */

void part3()
{
    FloatType ft( 5.5f );
    DoubleType dt( 11.1 );
    IntType it ( 34 );
    DoubleType pi( 3.14 );

    std::cout << "The result of FloatType^4 divided by IntType is: " << ft.multiply( ft ).multiply( ft ).divide( it ) << std::endl;
    std::cout << "The result of DoubleType times 3 plus IntType is : " << dt.multiply( 3 ).add( it ) << std::endl;
    std::cout << "The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: " << it.divide( pi ).multiply( dt ).subtract( ft ) << std::endl;
    std::cout << "An operation followed by attempts to divide by 0, which are ignored and warns user: " << std::endl;
    std::cout << it.multiply(it).divide(0).divide(0.0f).divide(0.0) << std::endl;
    
    std::cout << "FloatType x IntType  =  " << it.multiply( ft ) << std::endl;
    std::cout << "(IntType + DoubleType + FloatType) x 24 = " << it.add( dt ).add( ft ).multiply( 24 ) << std::endl;
}

/*
your program should generate the following output EXACTLY.
This includes the warnings.
The output should have zero warnings.
Use a service like https://www.diffchecker.com/diff to compare your output. 

FloatType add result=4
FloatType subtract result=2
FloatType multiply result=4
FloatType divide result=0.25

DoubleType add result=4
DoubleType subtract result=2
DoubleType multiply result=4
DoubleType divide result=0.8

IntType add result=4
IntType subtract result=2
IntType multiply result=4
IntType divide result=1

Chain calculation = 590
New value of ft = (ft + 3.0f) * 1.5f / 5.0f = 0.975
---------------------

Initial value of dt: 0.8
Initial value of it: 590
Use of function concatenation (mixed type arguments) 
New value of dt = (dt * it) / 5.0f + ft = 95.375
---------------------

Intercept division by 0 
New value of it = it / 0 = error: integer division by zero is an error and will crash the program!
590
New value of ft = ft / 0 = warning: floating point division by zero!
inf
New value of dt = dt / 0 = warning: floating point division by zero!
inf
---------------------

The result of FloatType^4 divided by IntType is: 26.9136
The result of DoubleType times 3 plus IntType is : 67.3
The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: 711
An operation followed by attempts to divide by 0, which are ignored and warns user: 
error: integer division by zero is an error and will crash the program!
error: integer division by zero is an error and will crash the program!
error: integer division by zero is an error and will crash the program!
505521
FloatType x IntType  =  13143546
(IntType + DoubleType + FloatType) x 24 = 315447336
good to go!

*/

struct A {};
struct HeapA
{ 
    HeapA() : a(new A) {}
    ~HeapA()
    {
        delete a;
    }
    A* a = nullptr;
};




/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */
 
 #include <iostream>
 
 struct DoubleType;
 struct IntType;

struct FloatType
{
    float* value;

    FloatType(float input);
    ~FloatType();

    FloatType& add(float input);
    FloatType& add(const FloatType& input);
    FloatType& add(const DoubleType& input);
    FloatType& add(const IntType& input);
    FloatType& subtract(float input);
    FloatType& subtract(const FloatType& input);
    FloatType& subtract(const DoubleType& input);
    FloatType& subtract(const IntType& input);
    FloatType& multiply(float input);
    FloatType& multiply(const FloatType& input);
    FloatType& multiply(const DoubleType& input);
    FloatType& multiply(const IntType& input);
    FloatType& divide(float input);
    FloatType& divide(const FloatType& input);
    FloatType& divide(const DoubleType& input);
    FloatType& divide(const IntType& input);
};

struct DoubleType
{
    double* value;

    DoubleType(double input);
    ~DoubleType();

    DoubleType& add(double input);
    DoubleType& add(const DoubleType& input);
    DoubleType& add(const FloatType& input);
    DoubleType& add(const IntType& input);
    DoubleType& subtract(double input);
    DoubleType& subtract(const DoubleType& input);
    DoubleType& subtract(const FloatType& input);
    DoubleType& subtract(const IntType& input);
    DoubleType& multiply(double input);
    DoubleType& multiply(const DoubleType& input);
    DoubleType& multiply(const FloatType& input);
    DoubleType& multiply(const IntType& input);
    DoubleType& divide(double input);
    DoubleType& divide(const DoubleType& input);
    DoubleType& divide(const FloatType& input);
    DoubleType& divide(const IntType& input);
};

struct IntType
{
    int* value;

    IntType(int input);
    ~IntType();

    IntType& add(int input);
    IntType& add(const IntType& input);
    IntType& add(const FloatType& input);
    IntType& add(const DoubleType& input);
    IntType& subtract(int input);
    IntType& subtract(const IntType& input);
    IntType& subtract(const FloatType& input);
    IntType& subtract(const DoubleType& input);
    IntType& multiply(int input);
    IntType& multiply(const IntType& input);
    IntType& multiply(const FloatType& input);
    IntType& multiply(const DoubleType& input);
    IntType& divide(int input);
    IntType& divide(const IntType& input);
    IntType& divide(const FloatType& input);
    IntType& divide(const DoubleType& input);
};

// =========FLOATTYPE FUNCTION DEFINITIONS==================

FloatType::FloatType(float input) : value(new float(input))
{
}

FloatType::~FloatType()
{
    delete value;
}

FloatType& FloatType::add(float input)
{
    *value += input;
    return *this;
}

FloatType& FloatType::add(const FloatType& input)
{
    return this->add(*input.value);
}

FloatType& FloatType::add(const DoubleType& input)
{
    return this->add(*input.value);
}

FloatType& FloatType::add(const IntType& input)
{
    return this->add(*input.value);
}

FloatType& FloatType::subtract(float input)
{
    *value -= input;
    return *this;
}

FloatType& FloatType::subtract(const FloatType& input)
{
    return this->subtract(*input.value);
}

FloatType& FloatType::subtract(const DoubleType& input)
{
    return this->subtract(*input.value);
}

FloatType& FloatType::subtract(const IntType& input)
{
    return this->subtract(*input.value);
}

FloatType& FloatType::multiply(float input)
{
    *value *= input;
    return *this;
}

FloatType& FloatType::multiply(const FloatType& input)
{
    return this->multiply(*input.value);
}


FloatType& FloatType::multiply(const DoubleType& input)
{
    return this->multiply(*input.value);
}

FloatType& FloatType::multiply(const IntType& input)
{
    return this->multiply(*input.value);
}

FloatType& FloatType::divide(float input)
{
    if(input == 0.f) 
        std::cout << "warning: floating point division by zero!" << std::endl;

    *value /= input;
    return *this;
}

FloatType& FloatType::divide(const FloatType& input)
{
    return this->divide(*input.value);
}

FloatType& FloatType::divide(const DoubleType& input)
{
    return this->divide(*input.value);
}

FloatType& FloatType::divide(const IntType& input)
{
    return this->divide(*input.value);
}

// ==========DOUBLETYPE FUNCTION DEFINITIONS================

DoubleType::DoubleType(double input) : value(new double(input))
{
}

DoubleType::~DoubleType()
{
    delete value;
}

DoubleType& DoubleType::add(double input)
{
    *value += input;
    return *this;
}

DoubleType& DoubleType::add(const FloatType& input)
{
    return this->add(*input.value);
}

DoubleType& DoubleType::add(const DoubleType& input)
{
    return this->add(*input.value);
}

DoubleType& DoubleType::add(const IntType& input)
{
    return this->add(*input.value);
}

DoubleType& DoubleType::subtract(double input)
{
    *value -= input;
    return *this;
}

DoubleType& DoubleType::subtract(const FloatType& input)
{
    return this->subtract(*input.value);
}

DoubleType& DoubleType::subtract(const DoubleType& input)
{
    return this->subtract(*input.value);
}

DoubleType& DoubleType::subtract(const IntType& input)
{
    return this->subtract(*input.value);
}

DoubleType& DoubleType::multiply(double input)
{
    *value *= input;
    return *this;
}

DoubleType& DoubleType::multiply(const FloatType& input)
{
    return this->multiply(*input.value);
}

DoubleType& DoubleType::multiply(const DoubleType& input)
{
    return this->multiply(*input.value);
}

DoubleType& DoubleType::multiply(const IntType& input)
{
    return this->multiply(*input.value);
}

DoubleType& DoubleType::divide(double input)
{
    if(input == 0.0) 
        std::cout << "warning: floating point division by zero!" << std::endl;

    *value /= input;
    return *this;
}

DoubleType& DoubleType::divide(const FloatType& input)
{
    return this->divide(*input.value);
}

DoubleType& DoubleType::divide(const DoubleType& input)
{
   return this->divide(*input.value);
}

DoubleType& DoubleType::divide(const IntType& input)
{
    return this->divide(*input.value);
}

// =======INTTYPE FUNCTIONS DEFINITIONS====================

IntType::IntType(int input) : value(new int(input))
{
}

IntType::~IntType()
{
    delete value;
}

IntType& IntType::add(int input)
{
    *value += input;
    return *this;
}

IntType& IntType::add(const FloatType& input)
{
    return this->add(*input.value);
}

IntType& IntType::add(const DoubleType& input)
{
    return this->add(*input.value);
}

IntType& IntType::add(const IntType& input)
{
    return this->add(*input.value);
}

IntType& IntType::subtract(int input)
{
    *value -= input;
    return *this;
}

IntType& IntType::subtract(const FloatType& input)
{
    return this->subtract(*input.value);
}

IntType& IntType::subtract(const DoubleType& input)
{
    return this->subtract(*input.value);
}

IntType& IntType::subtract(const IntType& input)
{
    return this->subtract(*input.value);
}

IntType& IntType::multiply(int input)
{
    *value *= input;
    return *this;
}

IntType& IntType::multiply(const FloatType& input)
{
    return this->multiply(*input.value);
}

IntType& IntType::multiply(const DoubleType& input)
{
    return this->multiply(*input.value);
}

IntType& IntType::multiply(const IntType& input)
{
    return this->multiply(*input.value);
}

IntType& IntType::divide(int input)
{ 
    if(input == 0)
    {
        std::cout << "error: integer division by zero is an error and will crash the program!" << std::endl;
        return *this;
    }

    *value /= input;
    return *this;
}

IntType& IntType::divide(const FloatType& input)
{
    return this->divide(*input.value);
}

IntType& IntType::divide(const DoubleType& input)
{
    return this->divide(*input.value);
}

IntType& IntType::divide(const IntType& input)
{
    return this->divide(*input.value);
}


// ==============   MAIN()  ===============================

int main()
{   
    //testing instruction 0
        HeapA heapA; 

    //assign heap primitives
    FloatType ft ( 2.0f );
    DoubleType dt ( 2 );
    IntType it ( 2 ) ;

    std::cout << "FloatType add result=" << *ft.add( 2.0f ).value << std::endl;
    std::cout << "FloatType subtract result=" << *ft.subtract( 2.0f ).value << std::endl;
    std::cout << "FloatType multiply result=" << *ft.multiply( 2.0f ).value << std::endl;
    std::cout << "FloatType divide result=" << *ft.divide( 16.0f).value << std::endl << std::endl;

    std::cout << "DoubleType add result=" << *dt.add(2.0).value << std::endl;
    std::cout << "DoubleType subtract result=" << *dt.subtract(2.0).value << std::endl;
    std::cout << "DoubleType multiply result=" << *dt.multiply(2.0).value << std::endl;
    std::cout << "DoubleType divide result=" << *dt.divide(5.f).value << std::endl << std::endl;

    std::cout << "IntType add result=" << *it.add(2).value << std::endl;
    std::cout << "IntType subtract result=" << *it.subtract(2).value << std::endl;
    std::cout << "IntType multiply result=" << *it.multiply(2).value << std::endl;
    std::cout << "IntType divide result=" << *it.divide(3).value << std::endl << std::endl;
    std::cout << "Chain calculation = " << *(it.multiply(1000).divide(2).subtract(10).add(100)).value << std::endl;

        // FloatType object instanciation and method tests
    // --------
    std::cout << "New value of ft = (ft + 3.0f) * 1.5f / 5.0f = " << *ft.add( 3.0f ).multiply(1.5f).divide(5.0f).value << std::endl;
       
    std::cout << "---------------------\n" << std::endl; 
    
    // DoubleType/IntType object instanciation and method tests
    // --------
    std::cout << "Initial value of dt: " << *dt.value << std::endl;
    std::cout << "Initial value of it: " << *it.value << std::endl;
    // --------
    std::cout << "Use of function concatenation (mixed type arguments) " << std::endl;
    std::cout << "New value of dt = (dt * it) / 5.0f + ft = " << *(dt.multiply(it).divide(5.0f).add(ft).value) << std::endl;

    std::cout << "---------------------\n" << std::endl; 
    
    // Intercept division by 0
    // --------
    std::cout << "Intercept division by 0 " << std::endl;
    std::cout << "New value of it = it / 0 = " << *it.divide(0).value << std::endl;
    std::cout << "New value of ft = ft / 0 = " << *ft.divide(0).value << std::endl;
    std::cout << "New value of dt = dt / 0 = " << *dt.divide(0).value << std::endl;

    std::cout << "---------------------\n" << std::endl; 

    std::cout << "good to go!\n";

    return 0;
}


