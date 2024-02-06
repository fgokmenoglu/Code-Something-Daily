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
 */

/* CLASSES AND HEADERS
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

/*
 * #ifndef (ending with #endif) is called an include guard. 
 * It ensures that the content of the file is included only once during the compilation to avoid errors.
 */

// HEADER FILE
#ifndef DOCTOR_DATA_H
#define DOCTOR_DATA_H

#include <string>

namespace star_map {
    enum class System {
        Sol,
        BetaHydri,
        EpsilonEridani,
        AlphaCentauri,
        DeltaEridani,
        Omicron2Eridani
        // Other systems can be added here.
    };
}

namespace heaven {
    class Vessel {
    public:
        // Constructor
        Vessel(const std::string& name, int gen, star_map::System sys = star_map::System::Sol);

        // Getter for name
        std::string get_name() const;

        // Member function
        Vessel replicate(const std::string& new_name) const;

        // Functions to manage busters
        void make_buster();
        bool shoot_buster();

        // Public member variables
        std::string name;
        star_map::System current_system;
        int generation;
        int busters;

    private:
        // Any private member variables can be added here.
    };

    // Non-member functions
    std::string get_older_bob(const Vessel& v1, const Vessel& v2);
    bool in_the_same_system(const Vessel& v1, const Vessel& v2);
}

#endif // DOCTOR_DATA_H

// SOURCE FILE
#include "doctor_data.h"

namespace heaven {

    Vessel::Vessel(const std::string& name, int gen, star_map::System sys) 
        : name(name), current_system(sys), generation(gen), busters(0) {
    }

    std::string Vessel::get_name() const {
        return name;
    }

    Vessel Vessel::replicate(const std::string& new_name) const {
        return Vessel(new_name, this->generation + 1, this->current_system);
    }

    void Vessel::make_buster() {
        busters++;
    }

    bool Vessel::shoot_buster() {
        if (busters > 0) {
            busters--;
            return true;
        }
        return false;
    }

    std::string get_older_bob(const Vessel& v1, const Vessel& v2) {
        return (v1.generation < v2.generation) ? v1.get_name() : v2.get_name();
    }

    bool in_the_same_system(const Vessel& v1, const Vessel& v2) {
        return v1.current_system == v2.current_system;
    }
}
