public class Carro {

    private int id;
    private String modelo;
    private int ano;
    private String marca;
    private String cor;


    public Carro(int id,String modelo,int ano, String marca,String cor){
        this.id= id;
        this.modelo=modelo;
        this.ano=ano;
        this.marca=marca;
        this.cor=cor;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public int getAno() {
        return ano;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public String getCor() {
        return cor;
    }

    public void setCor(String cor) {
        this.cor = cor;
    }

    @Override
    public String toString() {
        return "ID: " + id +
           ", Modelo: " + modelo +
           ", Marca: " + marca +
           ", Ano: " + ano +
           ", Cor: " + cor;
}
    
}