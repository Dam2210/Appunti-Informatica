
import java.util.ArrayList;
import java.util.List;

public class Main
{
    public static void main(String[] args)
    {
        /*
        LMP: Programmazione Orientata agli Oggetti – a.a. 2022/23
        1° Appello Sessione Estiva del 22/06/2023

        Una enoteca ha la necessità di tenere traccia dei vini e delle grappe mostrati nella sua carta e di quelli presenti
        nella cantina, di modo da poter dire immediatamente se un vino è ordinabile al tavolo o, quantomeno, se è
        possibile farne un ordine per recapito a casa o semplicemente per rifornimento scorte.

        Ogni vino sarà descritto da:
        - nome
        - colore: (valori: rosso, bianco, rosé)
        - colore bacca d’uva: (valori: rosso, bianco)
        - cantina
        - anno di imbottigliamento
        - persistenza (valori: corto/lungo)
        - acidità (valori: stretto/largo)
        - equilibrio (valori: caldo/morbido)

        Le grappe invece sono descritte da:
        - nome
        - tipo (valori: giovane, giovane aromatica, aromatizzata, invecchiata, barricata, riserva)
        - botte (valori: diversi variabili, è una dimensione aperta, ma barrique deve essere un valore possibile)
        - cantina
        - tempo (in mesi) in botte

        Come verifiche di integrità:
        - per i vini, se sono rossi o rosé il colore dell’uva deve essere rosso
        - per le grappe, devono valere:
        o almeno questi numeri di mesi in botte a seconda del tipo:
        ▪ invecchiata o barricata: almeno 12
        ▪ riserva: almeno 18
        o barricata: la botte deve essere una barrique

        per ogni vino/grappa, il gestore dell’enoteca vuole sapere:
        • se è disponibile
        • il numero di bottiglie in cantina
        • fornitori e, per ogni fornitore, il tempo di ordinazione (che oltre che dipendere dal fornitore, può variare
        col tempo, a seconda della produzione etc.. e non è quini una caratteristica intrinseca del prodotto) ed
        il prezzo

        Per ogni fornitore si vuole solo sapere:
        • denominazione
        • p.IVA
        • regione
         */

        /*
        Vino vino1 = new Vino("Tavernello", "rosso", "rosso", "Tenuta San Guido", 2019, "corto", "stretto", "caldo", 50);
        Vino vino2 = new Vino("Vermentino", "bianco", "bianco", "Castellani", 2019, "lungo", "largo", "morbido", 20);

        System.out.println(vino1.toString());
        System.out.println(vino2.toString());

        int richiesta = 1;
        */

        List<Vino> vini = new ArrayList<Vino>();

        for(int i = 0; i < 1; i++)
        {
            Vino vino = Vino.scanVino();
            vini.add(vino);
        }

        System.out.println("vino 1: \n" + vini.get(0).toString());

        Vino.stampaArray(vini);

        //Vino.stampaArray(vini);


    }
}