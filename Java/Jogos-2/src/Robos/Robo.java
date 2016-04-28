package Robos;

import java.util.Random;

public abstract class Robo {

    private String name;
    private Random r;
    private int posicao;
    private int numeroJogadas;

    public Robo(String name) {
        r = new Random();
        this.name = name;
        posicao = 0;
        numeroJogadas = 0;
    }

    public int sortearSalto() {
        novaJogada();
        return r.nextInt(100) + 1;
    }

    public void atualizaPosicao() {
        posicao += sortearSalto();
    }

    public void sorteOuReves(int ajuste) {
        posicao += ajuste;
    }

    public void printNome() {
        System.out.println(name);
    }

    public int getPosicao() {
        return posicao;
    }

    public String getName() {
        return name;
    }

    void setPosicao(int posicao) {
        this.posicao = posicao;
    }

    public void novaJogada() {
        numeroJogadas++;
    }

    public int getNumeroJogadas() {
        return numeroJogadas;
    }

    public abstract String StringTipo();

    public abstract void tipo();
}
