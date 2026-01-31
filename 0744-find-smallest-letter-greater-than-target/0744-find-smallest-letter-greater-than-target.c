char nextGreatestLetter(char* letters, int lettersSize, char target) {
    char ch ;
    for(int i=0 ;i<lettersSize  ;i++){
        if(letters[i]>target){
            ch=letters[i];
            return ch;
        }
    }
    return letters[0];
}