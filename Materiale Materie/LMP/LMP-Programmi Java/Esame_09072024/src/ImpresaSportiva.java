import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class ImpresaSportiva
{
    private List<Sportivo> sportivi;

    public ImpresaSportiva() {
        this.sportivi = new ArrayList<>();
    }

    public void aggiungiSportivo(Sportivo sportivo) {
        this.sportivi.add(sportivo);
    }

    public List<String> ottieniGiocatoriConAlmenoNReti(int n) {
        List<String> risultati = new ArrayList<>();
        for (Sportivo sportivo : sportivi) {
            if (sportivo instanceof Giocatore) {
                Giocatore giocatore = (Giocatore) sportivo;
                if (giocatore.getLivelloStipendiale() >= 3) {
                    int mesiConAlmenoNReti = giocatore.contaMesiConAlmenoNReti(n);
                    if (mesiConAlmenoNReti > 0) {
                        risultati.add(giocatore.getNome() + ", " + giocatore.getCognome() + ", mesi con reti > " + n + ": " + mesiConAlmenoNReti);
                    }
                }
            }
        }
        return risultati;
    }

    public List<String> ottieniSportiviAssuntiStessoMeseAnno() {
        List<String> risultati = new ArrayList<>();
        for (int i = 0; i < sportivi.size(); i++) {
            Sportivo sportivo1 = sportivi.get(i);
            for (int j = i + 1; j < sportivi.size(); j++) {
                Sportivo sportivo2 = sportivi.get(j);
                if (sportivo1.getTipoSportivo() == sportivo2.getTipoSportivo() &&
                        sportivo1.getDataAssunzione().getYear() == sportivo2.getDataAssunzione().getYear() &&
                        sportivo1.getDataAssunzione().getMonth() == sportivo2.getDataAssunzione().getMonth()) {
                    risultati.add(sportivo1.getNome() + " " + sportivo1.getCognome() + " e " + sportivo2.getNome() + " " + sportivo2.getCognome() +
                            " assunti a " + sportivo1.getDataAssunzione().getMonth() + " del " + sportivo1.getDataAssunzione().getYear());
                }
            }
        }
        return risultati;
    }
}
