package Console;

import Geradores.*;
import Robos.*;

public class MainJogos {

    public static void main(String[] args) {

        Robo ganhador;

        System.out.println("Gerando arquivo ...");
        gravarArquivo("nome-robo.txt", "100km", 10);

        System.out.println("Alocando na memoria ...");
        Configuracao config = new Configuracao("nome-robo.txt");

        System.out.println("Criando jogo ...");
        DentroDoJogo jogo = new DentroDoJogo(config.getTabuleiro(), config.getRobos());

        /*
         System.out.println("Informações do jogo");
         jogo.printInfo();
         */
        System.out.println("Jogando ...");
        ganhador = jogo.jogar();

        System.out.println("\nInformções do ganhador\n");
        ganhador.printNome();
        System.out.println("Posicao final :" + ganhador.getPosicao());
        ganhador.tipo();
    }

    public static void gravarArquivo(String nomeArquivo, String tamanho, int numeroGerar) {
        GeradorConfig gen = new GeradorConfig(nomeArquivo, tamanho, numeroGerar);
        gen.Gravar();
    }

}
