import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args)
    {
        Fabbrica fab1 = new Fabbrica(1.30);

        Componente comp1 = new Componente("marmitta", "Italia", 10, 34.5);

        Componente comp2 = new Componente("ruota", "Germania", 5, 20.5);

        List<Componente> componenti = new ArrayList<>();

        componenti.add(comp1);
        componenti.add(comp2);


        System.out.println("-----------------------------------");

        int tempo_max = Prodotto.tempoMax(componenti);

        int num_componenti = Prodotto.numComponenti(componenti);
        double costo_realizzazione = tempo_max * fab1.costo_fabbricazione;


        double costo_complessivo_componenti = Componente.costoComplessivo(componenti);

        System.out.println("il costo complessivo dei componenti è: " + costo_complessivo_componenti);

        double costo_produzione = Prodotto.costoProduzione(costo_complessivo_componenti, costo_realizzazione);

        System.out.println("il costo di produzione è: " + costo_produzione);

        Prodotto prod1 = new Prodotto("D09", "Esempio", costo_produzione, 450.5, componenti, num_componenti, tempo_max, 45, costo_realizzazione);

        System.out.println(prod1.toString());

        System.out.println("il fattore guadagno per ogni prodotto è: " + prod1.FATTORE_GUADAGNO);

        Prodotto.rankingGuadagnoTempo(prod1);



    }
}