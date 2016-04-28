package Robos;

public class RoboRevoltado extends Robo {

    public RoboRevoltado(String name) {
        super(name);
    }

    @Override
    public void tipo() {
        System.out.println("Revoltado");
    }

    @Override
    public void sorteOuReves(int ajuste) {
        if (ajuste > 0) {
            setPosicao(ajuste + getPosicao());
        }
    }

    @Override
    public String StringTipo() {
        return "Revoltado";
    }

}
