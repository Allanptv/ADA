import java.util.Scanner;

public class Palindromo{

    public static void ehPalindromo(String palindromo){
        boolean ehPali = true;
        

        palindromo = palindromo.replaceAll("\\s", "");
        palindromo = palindromo.replaceAll(",", "");
        palindromo = palindromo.toLowerCase();

        int j = palindromo.length()-1;

        for(int i = 0; i < palindromo.length()-1; i++){
               // System.out.print(palindromo.length());
            if(palindromo.charAt(i) != palindromo.charAt(j)){
                //System.out.print(palindromo.charAt(i) + ", " + palindromo.charAt(j));
                ehPali = false;
                i = palindromo.length();
            }
            j--;
        }

        if(ehPali == true){
            System.out.println("SIM");
        }else{
            System.out.println("NAO");
        }

    }
    
    public static void main(String[] args){
        Scanner read = new Scanner(System.in);

        String palindromo = "";

        palindromo = read.nextLine();

        while(!palindromo.contains("FIM")){
            ehPalindromo(palindromo);
            palindromo = read.nextLine();
        }

    }

}
