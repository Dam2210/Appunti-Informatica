import java.time.LocalDate;

public class Medico extends Sportivo {
    public Medico(String nome, String cognome, LocalDate dataAssunzione, int livelloStipendiale) {
        super(nome, cognome, dataAssunzione, TipoSportivo.MEDICO, livelloStipendiale);
    }
}

