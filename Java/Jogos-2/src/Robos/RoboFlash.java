package Robos;

public class RoboFlash extends Robo {

    public RoboFlash(String name) {
        super(name);
    }

    @Override
    public void tipo() {
        System.out.println("Flash");
    }

    @Override
    public void atualizaPosicao() {
        int posicao = 2 * sortearSalto();
        setPosicao((int) posicao + getPosicao());
    }

    @Override
    public void sorteOuReves(int ajuste) {
        if (ajuste < 0) {
            setPosicao((int) 0.5 * ajuste + getPosicao());
        } else {
            setPosicao((int) 2 * ajuste + getPosicao());
        }
    }

    @Override
    public String StringTipo() {
        return "Flash";
    }

}
