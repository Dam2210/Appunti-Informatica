import java.util.List;


public class Prodotto
{
    final double FATTORE_GUADAGNO = 3;
    String id;
    String etichetta;
    double costo_prod;
    double prezzo_acquirenti;
    List<Componente> componenti;
    int num_componenti;
    int tempo_tot_stimato; //per l'ordine dei componenti
    int tempo_prodotto_finito;
    double costo_realizzazione;

    Prodotto(String id, String etichetta, double costo_prod, double prezzo_acquirenti, List<Componente> componenti, int num_componenti, int tempo_tot_stimato, int tempo_prodotto_finito, double costo_realizzazione)
    {
        this.id = id;
        this.etichetta = etichetta;
        this.costo_prod = costo_prod;
        this.prezzo_acquirenti = prezzo_acquirenti;
        this.componenti = componenti;
        this.num_componenti = num_componenti;
        this.tempo_tot_stimato = tempo_tot_stimato;
        this.tempo_prodotto_finito = tempo_prodotto_finito;
        this.costo_realizzazione = costo_realizzazione;
    }

    public String toString()
    {
        String stampa_prodotto = this.id + "\n" + this.etichetta + "\n" + this.costo_prod + "\n" + this.prezzo_acquirenti + "\n" + this.componenti + "\n" + this.num_componenti + "\n" + this.tempo_tot_stimato + "\n" + this.tempo_prodotto_finito + "\n";
        return stampa_prodotto;
    }

    public static double costoProduzione(double costo_complessivo_componeti, double costo_realizzazione_prodotto)
    {
        double costo_prod = costo_complessivo_componeti + costo_realizzazione_prodotto;
        return costo_prod;
    }

    public static int numComponenti(List<Componente> componenti)
    {
        int num_componenti = 0;
            for(Componente componente : componenti)
            {
                System.out.println(componente.toString());
                num_componenti += 1;
            }
            return num_componenti;
    }

    public static int tempoMax(List<Componente> componenti)
    {
        int tempo_max = 0;
        for(Componente componente : componenti)
        {
            if (tempo_max < componente.tempo_ordinazione)
            {
                tempo_max = componente.tempo_ordinazione;
            }
        }
        return tempo_max;
    }

    public static void rankingGuadagnoTempo(Prodotto prod)
    {
        double ranking = prod.FATTORE_GUADAGNO + prod.tempo_prodotto_finito;
        System.out.println("il ranking di guadagno tempo è: " + ranking);
    }


}
