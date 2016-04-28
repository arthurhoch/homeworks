package Console;

public class Tabela {

    private int tamanho;
    private int quantidadeRobos;

    Tabela(int tamanho, int quantidadeRobos) {
        this.tamanho = tamanho;
        this.quantidadeRobos = quantidadeRobos;
    }

    Tabela(int tamanho) {
        this.tamanho = tamanho;
    }

    Tabela() {

    }

    public void setQuantidadeRobos(int quantidadeRobos) {
        this.quantidadeRobos = quantidadeRobos;
    }

    public void setTamanho(int tamanho) {
        this.tamanho = tamanho;
    }

    public int getTamanho() {
        return tamanho;
    }

    public int getQuantidadeRobos() {
        return quantidadeRobos;
    }
}
