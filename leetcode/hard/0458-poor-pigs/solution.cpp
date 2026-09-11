class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pigs=0;
        int combinations =1;
        int state= minutesToTest/minutesToDie + 1;  //each pig has some state 
        //die at 0 , 5, 10 15, 20 or survive at the end 
        // so it state are 0 1 2 3 4 if states are 5
        // so two pigs can give 5*5 possibilities
        //for buckets 17 = (023) base 5 0 is the state of 1st 2 is the state of 2nd p and 3 is state of 3rd pig

        while(combinations< buckets){
            combinations*=state;
            pigs++;
        }
        return pigs;
    }
};