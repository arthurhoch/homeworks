package Geradores;

import Robos.TipoRobo;
import java.util.Random;

public class GeradorRobo {

    private static final int quantidadeDeLetras = 10;

    private int tipo;
    private String[] fixName;
    private Random r;
    private TipoRobo a;

    GeradorRobo(int quantidade) {
        a = TipoRobo.ALEATORIO;
        r = new Random();
        fixName = new String[quantidade];
    }

    public String Gen() {

        GerarNomes();

        String config = "QUANTIDADE=" + fixName.length + "\n\n";
        int tipo = 0;

        for (int i = 0; i < fixName.length; i++) {
            config += "NOMEROBO_" + i + "=" + fixName[i] + "\n";
            config += "TIPOROBO_" + i + "=" + randomRobo(TipoRobo.class) + "\n";
            config += "\n";
        }

        return config;
    }

    private void GerarNomes() {
        int numeroInicial = 65;
        char letra;
        for (int i = 0; i < fixName.length; i++) {
            fixName[i] = "";
            for (int j = 0; j < quantidadeDeLetras; j++) {
                letra = (char) (numeroInicial + r.nextInt(25));
                if (j > 0) {
                    letra += 32;
                }
                fixName[i] += letra;
            }
        }

    }

    public <T extends Enum<?>> T randomRobo(Class<T> tp) {
        int x = r.nextInt(tp.getEnumConstants().length);
        return tp.getEnumConstants()[x];
    }
}
