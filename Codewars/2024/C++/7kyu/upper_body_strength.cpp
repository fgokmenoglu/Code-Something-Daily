/*
 * Alex is transitioning from website design to coding and wants to sharpen his skills with CodeWars.
 * He can do ten kata in an hour, but when he makes a mistake, he must do pushups. 
 * These pushups really tire poor Alex out, so every time he does them they take twice as long. 
 * His first set of redemption pushups takes 5 minutes. 
 * Create a function, alexMistakes, that takes two arguments: the number of kata he needs to complete, 
 * and the time in minutes he has to complete them. Your function should return how many mistakes Alex can afford to make.
 */
unsigned alexMistakes(unsigned numberOfKatas, unsigned timeLimit) {
    // Calculate time spent on katas
    unsigned timeForKatas = (numberOfKatas * 60) / 10;  // 6 minutes per kata
    
    // Calculate remaining time
    if (timeLimit <= timeForKatas) {
        return 0;  // No time for mistakes
    }
    unsigned remainingTime = timeLimit - timeForKatas;
    
    // Calculate mistakes
    unsigned mistakes = 0;
    unsigned pushupTime = 5;  // Start with 5 minutes
    
    while (remainingTime >= pushupTime) {
        remainingTime -= pushupTime;
        mistakes++;
        pushupTime *= 2;  // Double the time for next pushup
    }
    
    return mistakes;
}
