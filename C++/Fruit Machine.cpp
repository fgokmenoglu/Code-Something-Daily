/*
 * TASK
 * You will be given three reels of different images and told at which index the reels stop. From this information your job is to return the score of the resulted reels.
 *
 * RULES
 * 1. There are always exactly three reels
 * 2. Each reel has 10 different items.
 * 3. The three reel inputs may be different.
 * 4. The spin array represents the index of where the reels finish.
 * 5. The three spin inputs may be different
 * 6. Three of the same is worth more than two of the same
 * 7. Two of the same plus one "Wild" is double the score.
 * 8. No matching items returns 0.
 *
 * SCORING
 * Item    Three of the same    Two of the same    Two of the same plus one Wild
 * Wild    100                  10                 N/A
 * Wild    100                  10                 N/A
 * Wild    100                  10                 N/A
 * Wild    100                  10                 N/A
 * Wild    100                  10                 N/A
 * Wild    100                  10                 N/A
 * Wild    100                  10                 N/A
 * Wild    100                  10                 N/A
 * Wild    100                  10                 N/A
 * Wild    100                  10                 N/A
 *
 * RETURNS
 * Return an integer of the score.
 *
 * EXAMPLE
 * reel1 = {"Wild","Star","Bell","Shell","Seven","Cherry","Bar","King","Queen","Jack"}
 * reel2 = {"Wild","Star","Bell","Shell","Seven","Cherry","Bar","King","Queen","Jack"}
 * reel3 = {"Wild","Star","Bell","Shell","Seven","Cherry","Bar","King","Queen","Jack"}
 * spin  = {5,5,5}
 * result = fruit({reel1, reel2, reel3}, spin)
 * 
 * reel1[5] == "Cherry"
 * reel2[5] == "Cherry"
 * reel3[5] == "Cherry"
 * 
 * Cherry + Cherry + Cherry == 50
 * 
 * result == 50
 */
