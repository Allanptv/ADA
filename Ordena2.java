import java.util.Scanner;

public class Ordena2{

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

    public static void ordenar2(String[] frase, String[] frase2, int tam){
    	String aux = "";
	for(int i = 0; i < tam - 1; i++){
		for(int j = 0; j < tam-1-i; j++){
			if(frase2[j].compareTo(frase2[j+1]) > 0){
				aux = frase[j];
				frase[j] = frase[j+1];
				frase[j+1] = aux;
				aux = frase2[j];
				frase2[j] = frase2[j+1];
				frase2[j+1] = aux;
			}	
		}
		
	}
    }

    public static void printVetor(String[] frases, int tam){
        for(int i = 0; i < tam; i++){
            System.out.println(frases[i]);
        }
    }

    public static void main(String[] args){

        //int tam = tamanho();
        int i = 0;
	String prhase = "";

        String[] frase = new String[100];
        String[] f = new String[100];

        prhase = read.nextLine();

        while(!prhase.contains("FIM")){
            frase[i] = prhase;
	    
	    prhase = prhase.replace(" ", "z");
	    prhase = prhase.replace(",", "z");

	    f[i] = prhase;
	    i++;
            prhase = read.nextLine();    
        }

        ordenar2(frase, f, i);
        printVetor(frase, i);

    }
}
