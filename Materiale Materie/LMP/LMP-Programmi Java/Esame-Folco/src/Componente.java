import java.util.List;

public class Componente
{
    String nome;
    String paese;
    int tempo_ordinazione; //in giorni ad esempio: tempo_ordinazione = 12 --> il componente ci mette 12 giorni per essere ordinato
    double costo;

    Componente(String nome, String paese, int tempo_ordinazione, double costo)
    {
        this.nome = nome;
        this.paese = paese;
        this.tempo_ordinazione = tempo_ordinazione;
        this.costo = costo;
    }
    public String toString()
    {
        String stampa_comp = this.nome + "\n" + this.paese + "\n" + this.tempo_ordinazione + "\n" + this.costo + "\n";
        return stampa_comp;
    }


    public static double costoComplessivo(List<Componente> componenti)
    {
        double costo_complessivo = 0;
        for(Componente componente : componenti)
        {
            costo_complessivo = costo_complessivo + componente.costo;
        }
        return costo_complessivo;
    }
}
