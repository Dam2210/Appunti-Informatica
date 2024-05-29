import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Vino {
    String nome;
    String colore;
    String colore_bacca;
    String cantina;
    int anno_bottiglia;
    String persistenza;
    String acid;
    String equilibrio;
    int n_bott;

    Vino(String nome, String colore, String colore_bacca, String cantina, int anno_bottiglia, String persistenza, String acid, String equilibrio, int n_bott) {
        this.nome = nome;
        this.colore = colore;
        this.colore_bacca = colore_bacca;
        this.cantina = cantina;
        this.anno_bottiglia = anno_bottiglia;
        this.persistenza = persistenza;
        this.acid = acid;
        this.equilibrio = equilibrio;
        this.n_bott = n_bott;
    }

    public String toString() {
        String stampa_vino = this.nome + "\n" + this.colore + "\n" + this.colore_bacca + "\n" + this.cantina + "\n" + this.anno_bottiglia + "\n" + this.persistenza + "\n" + this.acid + "\n" + this.equilibrio + "\n" + this.n_bott + "\n"; //+ "\n" + this.eta + "\n"+ this.colorePreferito;
        return stampa_vino;
    }

    public static Vino scanVino()
    {
        Scanner scanner = new Scanner(System.in);

        System.out.println("nome: ");
        String nome = scanner.nextLine();

        System.out.println("colore: ");
        System.out.println("1. rosso");
        System.out.println("2. bianco");
        System.out.println("3. rosè");

        int scelta1 = scanner.nextInt();
        String valore1;

        switch (scelta1) {
            case 1:
                valore1 = "rosso";
                break;
            case 2:
                valore1 = "bianco";
                break;
            case 3:
                   valore1 = "rosè";
                   break;
            default:
                valore1 = "scelta non valida";
                break;
        }
        String colore = valore1;
        scanner.nextLine();

        System.out.println("colore bacca: ");
        String colore_bacca;
        if(valore1.equals("rosè"))
        {
            System.out.println("il vino è rosè quindo di default la bacca è di colore rosso");
            colore_bacca = "rosso";
        }
        else
        {
            System.out.println("1. rosso");
            System.out.println("2. bianco");
            int scelta2 = scanner.nextInt();
            String valore2;

            switch (scelta2) {
                case 1:
                    valore2 = "rosso";
                    break;
                case 2:
                    valore2 = "bianco";
                    break;
                default:
                    valore2 = "scelta non valida";
                    break;
            }
            colore_bacca = valore2;
            scanner.nextLine();
        }

        System.out.println("cantina: ");
        String cantina = scanner.nextLine();

        System.out.println("anno bottiglia: ");
        int anno_bottiglia = scanner.nextInt();
        scanner.nextLine();

        System.out.println("persistenza: ");
        System.out.println("1. corto");
        System.out.println("2. lungo");

        int scelta3 = scanner.nextInt();
        String valore3;

        switch (scelta3) {
            case 1:
                valore3 = "corto";
                break;
            case 2:
                valore3 = "lungo";
                break;
            default:
                valore3 = "scelta non valida";
                break;
        }
        String persistenza = valore3;
        scanner.nextLine();

        System.out.println("acidità: ");
        System.out.println("1. stretto");
        System.out.println("2. largo");

        int scelta4 = scanner.nextInt();
        String valore4;

        switch (scelta4) {
            case 1:
                valore4 = "stretto";
                break;
            case 2:
                valore4 = "largo";
                break;
            default:
                valore4 = "scelta non valida";
                break;
        }
        String acid = valore4;
        scanner.nextLine();

        System.out.println("equilibrio: ");
        System.out.println("1. caldo");
        System.out.println("2. morbido");

        int scelta5 = scanner.nextInt();
        String valore5;

        switch (scelta5) {
            case 1:
                valore5 = "caldo";
                break;
            case 2:
                valore5 = "morbido";
                break;
            default:
                valore5 = "scelta non valida";
                break;
        }
        String equilibrio = valore5;
        scanner.nextLine();

        System.out.println("bottiglie in cantina: ");
        int n_bott = scanner.nextInt();
        scanner.nextLine();

        Vino vino = new Vino(nome, colore, colore_bacca, cantina, anno_bottiglia, persistenza, acid, equilibrio, n_bott);

        return vino;
    }

    public static void stampaArray(List<Vino> vini)
    {
        System.out.println("i vini inseriti sono: \n");
        for (Vino vino : vini) {
            System.out.println(vino);
        }
    }
}
