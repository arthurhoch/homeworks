package Console;

import Robos.*;
import java.io.FileReader;
import java.io.BufferedReader;
import Conversores.*;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Configuracao {

    private FileReader FILE;
    private BufferedReader buff;
    private int tamanho;
    private int numeroRobos;
    private Robo[] robos;
    private String nomeArquivo;
    private final Tabela tabuleiro;

    Configuracao(String nomeArquivo) {
        this.tabuleiro = new Tabela();
        this.nomeArquivo = nomeArquivo;
        alocarMemoria();
    }

    private void alocarMemoria() {
        int valor = 0, roboAtual = -1, ultimoValor = -1;

        boolean primeiraVez = true;
        try {
            String line = "";
            String token = "";
            String nome = "";

            FILE = new FileReader(nomeArquivo);
            buff = new BufferedReader(FILE);

            try {
                while ((line = buff.readLine()) != null) {
                    StringTokenizer t = new StringTokenizer(line);
                    while (t.hasMoreElements()) {

                        token = t.nextToken("=");
                        valor++;
                    }
                    if ((valor % 2) == 0) {
                        if (valor == 2) {
                            ConTamanho con = new ConTamanho(token);
                            tabuleiro.setTamanho(con.getTamanhoCm());
                        } else if (valor == 4) {
                            tabuleiro.setQuantidadeRobos(Integer.parseInt(token));
                            robos = new Robo[tabuleiro.getQuantidadeRobos()];
                        } else if (ultimoValor != valor) {
                            ultimoValor = valor;
                            if (primeiraVez) {
                                nome = token;
                                primeiraVez = false;
                            } else {
                                ultimoValor = valor;
                                switch (TipoRobo.valueOf(token)) {
                                    case ENFERRUJADO:
                                        robos[++roboAtual] = new RoboEnferrujado(nome);
                                        break;
                                    case FLASH:
                                        robos[++roboAtual] = new RoboFlash(nome);
                                        break;
                                    case REVOLTADO:
                                        robos[++roboAtual] = new RoboRevoltado(nome);
                                        break;
                                    case ALEATORIO:
                                        robos[++roboAtual] = new RoboAleatorio(nome);
                                        break;
                                    case TELEPORTER:
                                        robos[++roboAtual] = new RoboTeleporter(nome);
                                        break;
                                    default:
                                        break;
                                }

                                primeiraVez = true;
                            }
                        }
                    }
                }
            } catch (IOException ex) {
                Logger.getLogger(Configuracao.class.getName()).log(Level.SEVERE, null, ex);
            }

            try {
                buff.close();
            } catch (IOException ex) {
                Logger.getLogger(Configuracao.class.getName()).log(Level.SEVERE, null, ex);
            }

        } catch (FileNotFoundException ex) {
            Logger.getLogger(Configuracao.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public Robo[] getRobos() {
        return robos;
    }

    public Tabela getTabuleiro() {
        return tabuleiro;
    }

}
