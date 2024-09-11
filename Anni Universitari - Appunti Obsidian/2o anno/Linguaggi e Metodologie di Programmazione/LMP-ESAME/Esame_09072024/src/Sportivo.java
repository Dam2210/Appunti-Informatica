import java.time.LocalDate;

public abstract class Sportivo {
    private static int numeroIscrizioneProgressivo = 1;

    private String nome;
    private String cognome;
    private LocalDate dataAssunzione;
    private String numeroIscrizione;
    private TipoSportivo tipoSportivo;
    private int livelloStipendiale;

    public Sportivo(String nome, String cognome, LocalDate dataAssunzione, TipoSportivo tipoSportivo, int livelloStipendiale) {
        this.nome = nome;
        this.cognome = cognome;
        this.dataAssunzione = dataAssunzione;
        this.numeroIscrizione = "TEAM_" + numeroIscrizioneProgressivo++;
        this.tipoSportivo = tipoSportivo;
        this.livelloStipendiale = livelloStipendiale;
    }

    // Getters and Setters
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCognome() {
        return cognome;
    }

    public void setCognome(String cognome) {
        this.cognome = cognome;
    }

    public LocalDate getDataAssunzione() {
        return dataAssunzione;
    }

    public void setDataAssunzione(LocalDate dataAssunzione) {
        this.dataAssunzione = dataAssunzione;
    }

    public String getNumeroIscrizione() {
        return numeroIscrizione;
    }

    public TipoSportivo getTipoSportivo() {
        return tipoSportivo;
    }

    public int getLivelloStipendiale() {
        return livelloStipendiale;
    }

    public void setLivelloStipendiale(int livelloStipendiale) {
        this.livelloStipendiale = livelloStipendiale;
    }

    @Override
    public String toString() {
        return "Sportivo{" +
                "nome='" + nome + '\'' +
                ", cognome='" + cognome + '\'' +
                ", dataAssunzione=" + dataAssunzione +
                ", numeroIscrizione='" + numeroIscrizione + '\'' +
                ", tipoSportivo=" + tipoSportivo +
                ", livelloStipendiale=" + livelloStipendiale +
                '}';
    }
}

enum TipoSportivo {
    GIOCATORE,
    ALLENATORE,
    PREPARATORE_ATLETICO,
    MEDICO
}
