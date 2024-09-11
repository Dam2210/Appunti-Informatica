import java.time.LocalDate;

public class PreparatoreAtletico extends Sportivo {
    public PreparatoreAtletico(String nome, String cognome, LocalDate dataAssunzione, int livelloStipendiale) {
        super(nome, cognome, dataAssunzione, TipoSportivo.PREPARATORE_ATLETICO, livelloStipendiale);
    }
}
