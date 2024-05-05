/*
 * John keeps a backup of his old personal phone book as a text file. 
 * On each line of the file he can find the phone number (formated as +X-abc-def-ghij 
 * where X stands for one or two digits), the corresponding name between < and > and the address.
 * 
 * Unfortunately everything is mixed, things are not always in the same order; 
 * parts of lines are cluttered with non-alpha-numeric characters (except inside phone number and name).
 *
 * Examples of John's phone book lines:
 * "/+1-541-754-3010 156 Alphand_St. <J Steeve>\n"
 * " 133, Green, Rd. <E Kustur> NY-56423 ;+1-541-914-3010!\n"
 * "<Anastasia> +48-421-674-8974 Via Quirinal Roma\n"
 *
 * Could you help John with a program that, 
 * given the lines of his phone book and a phone number num returns a string for this number: 
 * "Phone => num, Name => name, Address => adress"
 *
 * Examples:
 * s = "/+1-541-754-3010 156 Alphand_St. <J Steeve>\n 133, Green, Rd. <E Kustur> NY-56423 ;+1-541-914-3010!\n"
 * phone(s, "1-541-754-3010") should return "Phone => 1-541-754-3010, Name => J Steeve, Address => 156 Alphand St."
 * 
 * It can happen that there are many people for a phone number num, then return : "Error => Too many people: num"
 * or it can happen that the number num is not in the phone book, in that case return: "Error => Not found: num"
 */
#include <string>
#include <regex>
#include <sstream>

class PhoneDir {
public:
    static std::string phone(const std::string& orgdr, std::string num) {
        std::regex phonePattern("\\+\\d{1,2}-\\d{3}-\\d{3}-\\d{4}");
        std::regex namePattern("<[^>]+>");
        std::istringstream iss(orgdr);
        std::string line;
        std::string result;
        int count = 0;

        while (getline(iss, line)) {
            std::smatch phoneMatch, nameMatch;
            if (std::regex_search(line, phoneMatch, phonePattern)) {
                std::string foundPhone = phoneMatch.str();
                // Normalize phone format to match 'num'
                std::string normalizedPhone = foundPhone.substr(1); // Removes the leading '+'

                if (normalizedPhone == num) {
                    if (++count > 1) {
                        return "Error => Too many people: " + num;
                    }

                    std::regex_search(line, nameMatch, namePattern);
                    std::string name = nameMatch.str().substr(1, nameMatch.str().size() - 2); // Remove < and >

                    // Clean up the address by removing the phone number and name
                    std::string address = std::regex_replace(line, phonePattern, "");
                    address = std::regex_replace(address, namePattern, "");
                    address = std::regex_replace(address, std::regex("[^\\w\\s,.-]"), " ");
                    address = std::regex_replace(address, std::regex("_"), " "); // Replace underscores with spaces
                    address = std::regex_replace(address, std::regex("\\b,\\s+(?![0-9]|\\s*$)"), " "); // Remove commas that are not preceding numbers
                    address = std::regex_replace(address, std::regex("\\s+"), " "); // Replace multiple spaces with one
                    address = std::regex_replace(address, std::regex("^\\s+|\\s+$"), ""); // Trim spaces from start and end

                    result = "Phone => " + num + ", Name => " + name + ", Address => " + address;
                }
            }
        }

        if (count == 0) {
            return "Error => Not found: " + num;
        }

        return result;
    }
};
