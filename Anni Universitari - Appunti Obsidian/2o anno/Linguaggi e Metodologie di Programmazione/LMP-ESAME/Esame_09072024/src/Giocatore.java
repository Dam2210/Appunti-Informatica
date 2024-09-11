import java.time.LocalDate;
import java.util.Arrays;

public class Giocatore extends Sportivo {
    private int[] retiSegnatePerMese = new int[12];

    public Giocatore(String nome, String cognome, LocalDate dataAssunzione, int livelloStipendiale) {
        super(nome, cognome, dataAssunzione, TipoSportivo.GIOCATORE, livelloStipendiale);
    }

    public void incrementaRetiSegnate(int mese) {
        if (mese < 1 || mese > 12) {
            throw new IllegalArgumentException("Il mese deve essere compreso tra 1 e 12");
        }
        retiSegnatePerMese[mese - 1]++;
    }

    public int getRetiSegnate(int mese) {
        if (mese < 1 || mese > 12) {
            throw new IllegalArgumentException("Il mese deve essere compreso tra 1 e 12");
        }
        return retiSegnatePerMese[mese - 1];
    }

    public void resetRetiSegnateAnnuali() {
        Arrays.fill(retiSegnatePerMese, 0);
    }

    public int contaMesiConAlmenoNReti(int n)
    {
        int count = 0;
        for (int reti : retiSegnatePerMese) {
            if (reti >= n) {
                count++;
            }
        }
        return count;
    }

    @Override
    public String toString() {
        return super.toString() + ", retiSegnatePerMese=" + Arrays.toString(retiSegnatePerMese);
    }
}
