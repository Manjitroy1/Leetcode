class Solution {
    public boolean isPalindrome(int x) {
        if(x<0) return false;
        
        // int a=x;
        // int num=0;
        // while(a>0){
        //     num= num*10 + (a%10);
        //     a/=10;
        // }
        // return num==x;
        String first = Integer.toString(x);
        String second = new StringBuilder(first).reverse().toString();

        return first.equals(second);

    }
}