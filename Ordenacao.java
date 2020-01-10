import java.util.Scanner;

public class Ordenacao{

    static Scanner read = new Scanner(System.in);

    /*public static void ordena(String[] frase){
        String aux = "";
        int k = 0;
        for(int i = 0; i < frase.length; i++){
            k = 0;
            for(int j = 0; j < frase.length; j++){
                if(frase[j].charAt(k) < frase[i].charAt(k)){
                    aux = frase[j];
                    frase[j] = frase[i];
                    frase[i] = aux;
                    k++;
                    j = frase.length;
                }
            }    
        }
    }*/

    public static void ordena2(String[] frase){
    	String aux = "";
	for(int i = 0; i < frase.length-1; i++){
		for(int j = 0; j < frase.length-1-i; j++){
			if(frase[j].compareTo(frase[j+1]) > 0){
				aux = frase[j];
				frase[j] = frase[j+1];
				frase[j+1] = aux;
			}	
		}
		
	}
    }

    public static void printVetor(String[] frases){
        for(int i = 0; i < frases.length; i++){
            System.out.println(frases[i]);
        }
    }

    public static int tamanho(){
       // Scanner read = new Scanner(System.in);
        String frase = "";

        int tam = 0;

        frase = read.nextLine();

        while(!frase.contains("FIM")){
            tam++;
            frase = read.nextLine();
        }

        return tam;
    }

    public static void main(String[] args){

        //int tam = tamanho();
        int i = 0;

        String[] frase = new String[100];
        

        frase[i] = read.nextLine();

        while(!frase[i].contains("FIM")){
            i++;
            frase[i] = read.nextLine();    
        }

        
       // System.out.println(i);
        String[] frase2 = new String[i];

        for(int j = 0; j < i; j++){
            frase2[j] = frase[j];
        }

        ordena2(frase2);
        printVetor(frase2);

    }
}
