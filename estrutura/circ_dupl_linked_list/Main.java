public class Main {

    public static void main(String[] args) {

        // Cria a lista de carros
        CircularLinkedList<Carro> carros = new CircularLinkedList<>();

        // Adiciona carros
        carros.insertEnd(new Carro(1,"Celta",2005,"Chevrolet","Prata"));

        carros.insertEnd(new Carro(2,"Gol",2010,"Volkswagen","Branco"));

        carros.insertHead(new Carro(3,"Uno",2008,"Fiat","Vermelho"));

        // Mostra todos os carros
        System.out.println("Lista de carros:");
        carros.show();

        System.out.println();

        // Remove o primeiro carro
        carros.removeHead();

        System.out.println("Após remover o primeiro:");
        carros.show();

        System.out.println();

        // Remove o último carro
        carros.removeEnd();

        System.out.println("Após remover o último:");
        carros.show();

        System.out.println();

        // Mostra o tamanho da lista
        System.out.println("Quantidade de carros: "+ carros.getSize());
    }
}
