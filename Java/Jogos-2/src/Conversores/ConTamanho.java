package Conversores;

public class ConTamanho {

    private String tamanho;
    private int tamanhoCm;

    public ConTamanho(String tamanho) {
        this.tamanho = tamanho;
        genTamanho();
    }

    public ConTamanho() {

    }

    public int getTamanhoCm() {
        return tamanhoCm;
    }

    private void genTamanho() {

        String valorLimpo;

        if (tamanho.contains("km")) {
            valorLimpo = (String) tamanho.subSequence(0, tamanho.length() - 2);
            tamanhoCm = Integer.parseInt(valorLimpo);
            tamanhoCm *= 10000;
        } else if (tamanho.contains("cm")) {
            valorLimpo = (String) tamanho.subSequence(0, tamanho.length() - 2);
            tamanhoCm = Integer.parseInt(valorLimpo);
        } else {
            valorLimpo = (String) tamanho.subSequence(0, tamanho.length() - 1);
            tamanhoCm = Integer.parseInt(valorLimpo);
            tamanhoCm *= 100;
        }
    }
}
