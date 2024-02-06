/* 
 * INTRODUCTION
 * In C++, declarations are often separated from definitions. 
 * Declarations are grouped into so-called header files, with the respective implementations placed in source files. 
 * You can think of the header files as an API. 
 * The header file will tell you what a codebase has to offer without going into the details of how.
 *
 * The most common file extension for header files is .h. Some projects use .hpp or skip the extension completely.
 * The definitions are located in a separate .cpp file. 
 * To reunite the parts, the source file starts by including the respective header file.
 * 
 * CLASSES AND HEADERS
 * Classes can become very complex and their relation to the header / source partition might be confusing. 
 * One possible layout is to keep all the implementation details in the source file and all the declarations and member variables in the header:
 */ 

 // A file named robot_flower.h
 #if !defined(ROBOT_FLOWER_H)
 #define ROBOT_FLOWER_H
 #include <string>
 namespace robots {
   class Flower {
     private:
       bool needs_water{};
       int size{};
       std::string name{};
     public:
       Flower(std::string name, int size = 0);
       void give_water();
       std::string get_name();
       int get_size();
       void start_next_day();
   };
 }
 #endif
 
 // A file named robot_flower.cpp
 #include "robot_flower.h"
 robots::Flower::Flower(std::string name, int size) {this->name = "Robotica " + name; this->size = size;}
 void robots::Flower::start_next_day() {if (!needs_water) ++size; needs_water = true;}
 std::string robots::Flower::get_name() {return name;}
 int robots::Flower::get_size() {return size;}
 
/* 
 * When the header is used as an API overview, that is where a person would look for information like default values. 
 * The size parameter's default of the constructor is therefore handled in the header and not in the implementation. 
 * The definitions in the source file are prefixed with the namespace robots and the class type Flower.
 */
