public class Macchina extends Veicolo //la classe Macchina eredita la classe astratta Veicolo ed è costretta ad implementare i metodi astratti della classe ereditata.
{

    @Override //sovrascriviamo i metodi astratti della classe astratta Veicolo
    void muovi()
    {
        System.out.println("La macchina si muove...");
    }

    @Override
    void frena()
    {
        System.out.println("La macchina frena.");
    }
}
