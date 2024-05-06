package Pacchetto1;
import Pacchetto2.*;

public class A
{
    protected String nome = "Anna";
    //con la parola protected prima del tipo della variabile significa che questa può essere usata nella stessa classe,
    //nello stesso pacchetto e all'interno di una classe figlia, come C, che si trova anche in un pacchetto diverso,
    //ma non può essere usata in una classe in un pacchetto diverso che non eredita la classe stessa.

    private String nome2 = "Carlo";
    //con private davanti al tipo della variabile questa può essere usata esclusivamente nella stessa classe, quindi solo in A
}
