// Secret knowledge of the Zhang family:
namespace zhang {
    int bank_number_part(int secret_modifier) {
        int zhang_part{8'541};
        return (zhang_part*secret_modifier) % 10000;
    }
    namespace red {
        int code_fragment() {return 512;}
    }
    namespace blue {
        int code_fragment() {return 677;}
    }
}

// Secret knowledge of the Khan family:
namespace khan {
    int bank_number_part(int secret_modifier) {
        int khan_part{4'142};
        return (khan_part*secret_modifier) % 10000;
    }
    namespace red {
        int code_fragment() {return 148;}
    }
    namespace blue {
        int code_fragment() {return 875;}
    }
}

// Secret knowledge of the Garcia family:
namespace garcia {
    int bank_number_part(int secret_modifier) {
        int garcia_part{4'023};
        return (garcia_part*secret_modifier) % 10000;
    }
    namespace red {
        int code_fragment() {return 118;}
    }
    namespace blue {
        int code_fragment() {return 923;}
    }
}

/* 
Task 1: 
  Define a namespace called estate_executor. The code from the next tasks should be defined in the body of the estate_executor namespace.
  
Task 2: 
  This is your big moment. Only you have the secret modifier key to reveal the secret account number.
  Define the assemble_account_number(int secret_modifier) function that takes the secret modifier as an argument and returns the assembled account number as an int.
  To get the correct number, you have to sum up the bank_number_part from each of the three families.

Task 3:
  The instructions in the testament ask you to add all the blue and then all the red fragments. The resulting code is obtained by multiplying both sums.
  Define the assemble_code() function that returns the resulting code by combining the fragments from the three families to a single integer. 
  The function does not have any arguments and relies solely on the information in the relevant namespaces from the families.
*/
namespace estate_executor {
    int assemble_account_number(int secret_modifier) {
        return zhang::bank_number_part(secret_modifier) + 
               khan::bank_number_part(secret_modifier) + 
               garcia::bank_number_part(secret_modifier);
    }

    int assemble_code() {
        int redSum = zhang::red::code_fragment() + 
                     khan::red::code_fragment() + 
                     garcia::red::code_fragment();

        int blueSum = zhang::blue::code_fragment() + 
                      khan::blue::code_fragment() + 
                      garcia::blue::code_fragment();

        return redSum * blueSum;
    }
}
