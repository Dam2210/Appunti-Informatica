package Pacchetto2;

import Pacchetto1.*;

public class B
{
    String nome = "Damiano";
    //Senza nessuna parola davanti al tipo della variabile viene impostato in automatico il modificatore di default questo significa che
    //la variabile nome può essere usata nella stessa classe in cui è dichiarato e in ogni classe del pacchetto nella quale è
    //dichiarata, in questo caso in C può essere usata ma non in Main in quanto fanno parte di due pacchetti diversi.

    public String nome1 = "Massimo";
    //con la parola public davati al tipo della variabile possiamo usarla sia nello stesso pacchetto, quindi anche nella stessa classe,
    //ma anche in pacchetti diversi, in realtà con public la variabile può essere utilizzata ovunque
}
