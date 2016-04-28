package Robos;

public class RoboEnferrujado extends Robo {

    public RoboEnferrujado(String name) {
        super(name);
    }

    @Override
    public void tipo() {
        System.out.println("Enferrujado");
    }

    @Override
    public void atualizaPosicao() {
        int posicao = sortearSalto();
        setPosicao((int) (0.5 * posicao) + getPosicao());
    }

    @Override
    public void sorteOuReves(int ajuste) {
        int novaPosicao = ajuste / 2 + getPosicao();
        setPosicao(novaPosicao);
    }

    @Override
    public String StringTipo() {
        return "Enferrujado";
    }

}
