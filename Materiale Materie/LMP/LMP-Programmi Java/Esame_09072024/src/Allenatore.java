import java.time.LocalDate;

public class Allenatore extends Sportivo {
    public Allenatore(String nome, String cognome, LocalDate dataAssunzione, int livelloStipendiale) {
        super(nome, cognome, dataAssunzione, TipoSportivo.ALLENATORE, livelloStipendiale);
    }


}
