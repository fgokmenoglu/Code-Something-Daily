/*

 */
#include <iostream>
#include <vector>
#include <string>

std::string workNeeded(int projectMinutes, std::vector<std::pair<int, int>> freelancers) {
    int totalFreelancerMinutes = 0;
    
    // Convert all freelancers' time to minutes and sum them up
    for (const auto& freelancer : freelancers) {
        totalFreelancerMinutes += freelancer.first * 60 + freelancer.second;
    }
    
    // Calculate the remaining minutes needed for the project
    int remainingMinutes = projectMinutes - totalFreelancerMinutes;
    
    if (remainingMinutes <= 0) {
        return "Easy Money!";
    }
    
    // Convert remaining minutes to hours and minutes
    int hours = remainingMinutes / 60;
    int minutes = remainingMinutes % 60;
    
    return "I need to work " + std::to_string(hours) + " hour(s) and " + std::to_string(minutes) + " minute(s)";
}
