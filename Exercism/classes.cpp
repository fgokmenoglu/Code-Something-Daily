/*
 * INTRODUCTION
 * It is time to get to one of the core paradigms of C++: object-oriented programming (OOP). 
 * OOP is centered around classes - user-defined types of data with their own set of related functions.
 *
 * Classes can have member variables and member functions. They are accessed by the member selection operator .. 
 * Just as variables outside of classes, it is advisable to initialize member variables with a value upon declaration. 
 * This value will then become the default for newly created objects of this class.
 *
 * Classes offer the option to restrict access to their members. 
 * The two basic access specifiers are private and public. private members are not accessible from outside the class. 
 * public members can be accessed freely. All members of a class are private by default. 
 * Only members explicitly marked with public are freely usable outside of the class.
 *
 * Constructors offer the possibility to assign values to member variables at object creation. 
 * They have the same name as the class and do not have a return type. 
 * A class can have several constructors. This is useful if you do not always have a need to set all variables.
 * Constructors are a big topic and have many nuances. If you are not explicitly defining a constructor for your class, then 
 * - and only then - the compiler will do the job for you, no arguments are passed. 
 * All variables are set to the value that was stated in the definition of the class. 
 * If you had not given any values in that definition, the variables might be uninitialized, which might have unintended consequences.
 *
 * NOTES
 * Structs came from the language's original C roots and are as old as C++ itself. 
 * They are effectively the same thing as classes with one important exception. By default, everything in a class is private. 
 * Structs, on the other hand, are public until defined otherwise. 
 * Conventionally, the struct keyword is often used for data-only structures. 
 * The class keyword is preferred for objects that need to ensure certain properties. 
 */

