package Geradores;

import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

public class GeradorConfig {

    private FileWriter FILE;
    private BufferedWriter buffer;
    private String localArquivo;
    private String tamanho;
    private int numeroRobos;

    private GeradorRobo robos;

    public GeradorConfig(String localArquivo, String tamanho, int numeroRobos) {
        this.localArquivo = localArquivo;
        this.tamanho = tamanho;
        this.numeroRobos = numeroRobos;
        robos = new GeradorRobo(numeroRobos);
    }

    private String GerarInfo() {
        String info = "";

        info = "TAMANHO=" + tamanho + "\n";
        info += robos.Gen();

        return info;
    }

    public void Gravar() {

        String info = GerarInfo();
        //System.out.println("Class GeradorConfig");
        //System.out.print(info);

        try {
            FILE = new FileWriter(localArquivo);
            buffer = new BufferedWriter(FILE);

            try {

                buffer.write(info);

            } finally {
                buffer.close();
            }

        } catch (IOException ex) {
            Logger.getLogger(GeradorConfig.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

}
