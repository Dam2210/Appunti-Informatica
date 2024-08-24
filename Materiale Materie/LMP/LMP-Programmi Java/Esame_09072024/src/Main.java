import java.time.LocalDate;
import java.util.List;

public class Main {
    public static void main(String[] args)
    {

        ImpresaSportiva impresa = new ImpresaSportiva();

        Giocatore gioc1 = new Giocatore("Marco", "Bianchi", LocalDate.of(2024, 7, 9), 4);

        Giocatore gioc2 = new Giocatore("Mario", "Rossi", LocalDate.of(2012, 2, 6), 3);

        impresa.aggiungiSportivo(gioc1);
        impresa.aggiungiSportivo(gioc2);

        Allenatore allenatore = new Allenatore("Paolo", "Verdi", LocalDate.of(2021, 3, 5), 2);
        impresa.aggiungiSportivo(allenatore);

        Allenatore allenatore2 = new Allenatore("Luigi", "Neri", LocalDate.of(2021, 3, 18), 2);
        impresa.aggiungiSportivo(allenatore2);

        System.out.println("---------------------------------------");

        gioc1.incrementaRetiSegnate(12);
        gioc1.incrementaRetiSegnate(12);
        gioc1.incrementaRetiSegnate(2);
        gioc1.incrementaRetiSegnate(2);
        gioc2.incrementaRetiSegnate(12);
        gioc2.incrementaRetiSegnate(12);


        System.out.println(gioc1.toString());

        System.out.println("---------------------------------------");

        System.out.println(gioc2.toString());

        System.out.println(allenatore.toString());


        System.out.println("Giocatori con almeno 2 reti in un mese:");
        List<String> giocatoriConAlmeno2Reti = impresa.ottieniGiocatoriConAlmenoNReti(2);
        for (String s : giocatoriConAlmeno2Reti) {
            System.out.println(s);
        }

        System.out.println("Sportivi assunti nello stesso mese dello stesso anno:");
        List<String> sportiviAssuntiStessoMeseAnno = impresa.ottieniSportiviAssuntiStessoMeseAnno();
        for (String s : sportiviAssuntiStessoMeseAnno) {
            System.out.println(s);
        }

    }

}