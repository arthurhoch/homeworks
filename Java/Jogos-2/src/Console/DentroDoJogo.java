package Console;

import Robos.Robo;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;
import Geradores.GeradorLog;

public class DentroDoJogo {

    private static final int porcentagemSR = 2;

    private final Tabela tabuleiro;
    private final Robo[] robos;
    private final Map sorte;
    private final Map reves;
    private final Random r;

    private final GeradorLog log;

    DentroDoJogo(Tabela tabuleiro, Robo[] robos) {
        this.tabuleiro = tabuleiro;
        this.robos = robos;
        this.r = new Random();

        sorte = new HashMap();
        reves = new HashMap();

        genSorte();
        genRevez();

        log = new GeradorLog("relatorio.txt");
    }

    private void printRobos() {
        for (int i = 0; i < robos.length; i++) {
            System.out.print("NUMEROBO_" + i + "=");
            robos[i].printNome();
            System.out.print("TIPOROBO_" + i + "=");
            robos[i].tipo();
            System.out.println();
        }
    }

    private void printTabuleiro() {
        System.out.println("TAMANHO=" + tabuleiro.getTamanho());
        System.out.println("QUANTIDADE=" + tabuleiro.getQuantidadeRobos() + "\n");

    }

    public void printInfo() {
        System.out.println("Class DentroDoJogo");
        printTabuleiro();
        printRobos();
    }

    public void printMaps() {
        //sorte.
    }

    private int numeroCasasComSR() {
        return (int) (tabuleiro.getTamanho() * porcentagemSR);
    }

    private boolean tem() {
        return (r.nextInt(100) + 1) <= porcentagemSR;
    }

    private int genCasas() {
        return r.nextInt(100) + 1;
    }

    private void genSorte() {
        for (int i = 0; i < tabuleiro.getTamanho(); i += 2) {
            if (tem()) {
                int par = genCasas();
                if ((par % 2) != 0) {
                    par++;
                }
                sorte.put(i, par);
            }
        }
    }

    private void genRevez() {
        for (int i = 1; i < tabuleiro.getTamanho(); i += 2) {
            if (tem()) {
                int par = -1 * genCasas();
                if ((par % 2) == 0) {
                    par++;
                }
                reves.put(i, par);
            }
        }
    }

    public Robo jogar() {

        log.gerarCabecalho(tabuleiro.getTamanho(), tabuleiro.getQuantidadeRobos());

        while (true) {
            for (int i = 0; i < robos.length; i++) {

                log.adcionarLinha("\nNome robo    : " + robos[i].getName());
                log.adcionarLinha("Numero robo  : " + i);
                log.adcionarLinha("Posicao      : " + robos[i].getPosicao());

                robos[i].atualizaPosicao();

                while ((reves.get(robos[i].getPosicao())) != null) {
                    int posicao = robos[i].getPosicao();
                    int result = (int) reves.get(robos[i].getPosicao());
                    robos[i].sorteOuReves(result);
                    log.adcionarLinha("Revez        : " + result);
                    if (robos[i].getPosicao() == posicao) {
                        break;
                    }
                }

                while ((sorte.get(robos[i].getPosicao())) != null) {
                    int result = (int) sorte.get(robos[i].getPosicao());
                    robos[i].sorteOuReves(result);
                    log.adcionarLinha("Sorte        : " + result);
                }
                log.adcionarLinha("Nova Posicao : " + robos[i].getPosicao());
                if (robos[i].getPosicao() >= tabuleiro.getTamanho()) {
                    String ganhador = "\n";
                    ganhador += "\nRobo ganhador  : " + robos[i].getName();
                    ganhador += "\nNumero robo    : " + i;
                    ganhador += "\nPosicao        : " + robos[i].getPosicao();
                    ganhador += "\nTipo           : " + robos[i].StringTipo();
                    ganhador += "\nNumero Jogadas : " + robos[i].getNumeroJogadas();
                    log.adcionarLinha(ganhador);
                    return robos[i];
                }

            }
        }
    }

}
