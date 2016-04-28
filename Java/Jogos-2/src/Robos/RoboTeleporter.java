package Robos;

public class RoboTeleporter extends Robo {

    public RoboTeleporter(String name) {
        super(name);
    }

    @Override
    public void tipo() {
        System.out.println("Teleporter");
    }

    @Override
    public void atualizaPosicao() {
        int posicao = sortearSalto();
        setPosicao((int) posicao + getPosicao());
    }

    @Override
    public void sorteOuReves(int ajuste) {
        if (ajuste < 0) {
            setPosicao((int) -1 * ajuste + getPosicao());
        } else {
            setPosicao((int) ajuste + getPosicao());
        }

    }

    @Override
    public String StringTipo() {
        return "Teleporter";
    }

}
