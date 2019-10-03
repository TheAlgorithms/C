int maxNumberOfBalloons(char * text){
    /* 
        0 -> b, 
        1 -> a,
        2 -> l,
        3 -> l,
        4 -> o,
        5 -> o,
        6 -> n
    */
    int count_letters[7] = {0};
    
    /* Count the number of each letter */
    for(int i = 0; text[i] != '\0'; i++){
        if(text[i] == 'b') {
            count_letters[0]++;
        }else if(text[i] == 'a') {
            count_letters[1]++;
        }else if(text[i] == 'l') {
            count_letters[2]++;
            count_letters[3]++;
        }else if(text[i] == 'o') {
            count_letters[4]++;
            count_letters[5]++;
        }else if(text[i] == 'n') {
            count_letters[6]++;
        }
    }
    
    /* Divide by 2 the repeted letters */
    count_letters[2] /= 2;
    count_letters[3] /= 2;
    count_letters[4] /= 2;
    count_letters[5] /= 2;
    
    /* Max number of times which we can write ballon is equal to min value of letters on count_letter */
    int min_counter_ballons;
    for(int i = 0; i < 7; i++){
        if(i == 0){
            min_counter_ballons = count_letters[i];
        }else if(count_letters[i] < min_counter_ballons){
            min_counter_ballons = count_letters[i];
        }
    }
    
    return min_counter_ballons;
}

