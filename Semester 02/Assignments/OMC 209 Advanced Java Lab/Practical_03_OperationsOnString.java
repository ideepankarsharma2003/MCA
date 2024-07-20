public class Practical_03_OperationsOnString {
    public static  void  charDigitCount(String s){
        int char_count= 0;
        int digits= 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i)>=48 && s.charAt(i)<=57) digits++;
            else char_count++;
        }

        System.out.println("Length of the given string: "+ s.length());
        System.out.println("Total number of non-digit characters in the string are: "+ char_count);
        System.out.println("Total number of digit characters in the string are: "+ digits);
    }

    public static  void  palindromeCheck(String s){
        String checkstr= s.toLowerCase();
        String reverse_s= new StringBuilder(checkstr).reverse().toString();
        if (checkstr.equals(reverse_s)){
            System.out.println(String.format("'''%s''' is a palindrome.", s));
        }else System.out.println(String.format("'''%s''' isn't a palindrome.", s));
    }

    public static void main(String[] args) {
        Practical_03_OperationsOnString.palindromeCheck("The Amazing Spiderman 3");
        Practical_03_OperationsOnString.charDigitCount("The Amazing Spiderman 3");
    }
}
