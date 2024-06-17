/*
 * You are the best freelancer in the city. 
 * Everybody knows you, but what they don't know, 
 * is that you are actually offloading your work to other freelancers 
 * and and you rarely need to do any work. You're living the life!
 *
 * To make this process easier you need to write a method called 
 * workNeeded to figure out how much time you need to contribute to a project. 
 * 
 * Giving the amount of time in minutes needed to complete the project 
 * and an array of pair values representing other freelancers' time in [Hours, Minutes] format 
 * ie. [[2, 33], [3, 44]] calculate how much time you will need to contribute to the project (if at all) 
 * and return a string depending on the case.
 *
 * If we need to contribute time to the project 
 * then return "I need to work x hour(s) and y minute(s)"
 * If we don't have to contribute any time to the project 
 * then return "Easy Money!"
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
