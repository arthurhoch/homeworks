package Robos;

import java.util.Random;

public class RoboAleatorio extends Robo {

    private Random r;

    public RoboAleatorio(String name) {
        super(name);
        r = new Random();
    }

    private double sortTipo() {
        if (r.nextBoolean()) {
            return 2;
        }
        return 0.5;
    }

    @Override
    public void tipo() {
        System.out.println("Aleatorio");
    }

    @Override
    public void atualizaPosicao() {
        int posicao = (int) (sortTipo() * sortearSalto());
        setPosicao(posicao + getPosicao());
    }

    @Override
    public void sorteOuReves(int ajuste) {
        setPosicao((int) sortTipo() * ajuste + getPosicao());
    }

    @Override
    public String StringTipo() {
        return "Aleatorio";
    }

}
