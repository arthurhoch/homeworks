package Geradores;

import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.logging.Level;
import java.util.logging.Logger;

public class GeradorLog {

    private String nomeArquivo;
    private FileWriter FILE;
    private BufferedWriter buff;

    public GeradorLog(String nomeArquivo) {
        this.nomeArquivo = nomeArquivo;
    }

    public void gerarCabecalho(int tamanhoMapa, int quantidadeRobos) {
        try {
            String info = "";

            FILE = new FileWriter(nomeArquivo);
            buff = new BufferedWriter(FILE);

            info = "#Arquivo de log do trabalho de POO";
            info += "\n\n";
            info += "Tamanho do mapa :" + tamanhoMapa;
            info += "\n";
            info += "Quantidade de robos :" + quantidadeRobos;
            info += "\n\n";

            try {
                buff.write(info);
            } finally {
                buff.close();
            }

        } catch (IOException ex) {
            Logger.getLogger(GeradorLog.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    public void adcionarLinha(String linha) {

        try {
            FILE = new FileWriter(nomeArquivo, true);

            try (PrintWriter gravarLinha = new PrintWriter(FILE)) {
                gravarLinha.println(linha);
                gravarLinha.flush();
                gravarLinha.close();
            }

        } catch (IOException ex) {
            Logger.getLogger(GeradorLog.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

}
