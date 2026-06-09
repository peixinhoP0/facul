public class CircularLinkedList<T extends Comparable<T>> {

    // Primeiro nó da lista
    private Node<T> head;

    // Último nó da lista
    private Node<T> tail;

    // Quantidade de elementos
    private int size;

    /*
     * Construtor
     * Inicializa uma lista vazia
     */
    public CircularLinkedList() {
        head = null;
        tail = null;
        size = 0;
    }

    /*
     * Verifica se a lista está vazia
     */
    public boolean isEmpty() {
        return size == 0;
    }

    /*
     * Retorna a quantidade de elementos
     */
    public int getSize() {
        return size;
    }

    /*
     * Insere no início da lista
     */
    public void insertHead(T data) {

        Node<T> node = new Node<>(data);

        // Caso especial: lista vazia
        if (isEmpty()) {

            head = node;
            tail = node;

            // Circularidade
            head.setProximo(head);
            head.setAntes(head);

        } else {

            node.setProximo(head);
            node.setAntes(tail);

            head.setAntes(node);
            tail.setProximo(node);

            head = node;
        }

        size++;

        System.out.println("Elemento inserido no início.\n");
    }

    /*
     * Insere no final da lista
     */
    public void insertEnd(T data) {

        Node<T> node = new Node<>(data);

        // Caso especial: lista vazia
        if (isEmpty()) {

            head = node;
            tail = node;

            head.setProximo(head);
            head.setAntes(head);

        } else {

            node.setAntes(tail);
            node.setProximo(head);

            tail.setProximo(node);
            head.setAntes(node);

            tail = node;
        }

        size++;

        System.out.println("Elemento inserido no final.\n");
    }

    /*
     * Insere em qualquer posição
     *
     * Exemplo:
     * [10][20][30]
     *
     * insertPos(99,1)
     *
     * [10][99][20][30]
     */
    public Node<T> getPos(int pos){
        Node<T> atual = head;

        int count = 0;

        while (count < pos) {
            atual = atual.getProximo();
            count++;
        }

        return atual;
    }


    public void insertPos(T data, int pos) {

        if (pos < 0 || pos > size) {
            System.out.println("Posição inválida.\n");
            return;
        }

        if (pos == 0) {
            insertHead(data);
            return;
        }

        if (pos == size) {
            insertEnd(data);
            return;
        }

        Node<T> node = new Node<>(data);

        // Nó que irá parar na posição desejada

        Node <T> atual = getPos(pos);
        Node<T> anterior = atual.getAntes();

        // Faz as ligações
        anterior.setProximo(node);
        node.setAntes(anterior);

        node.setProximo(atual);
        atual.setAntes(node);

        size++;

        System.out.println("Elemento inserido na posição " + pos+"\n");
    }

    public void removeEnd(){
        if(size==0){System.out.println("lista vazia\n"); return;}

        if(size==1){
            head=null;
            tail=null;
            size=0;
        }

        tail=tail.getAntes();
        tail.getAntes().setAntes(null);
        tail.setProximo(head);
        head.setAntes(tail);
        size--;
        return;
    }

    public void removeHead(){
        if (size==0){ System.out.println("lista vazia\n"); return;}

        if (size==1){removeEnd(); return;}

        head.getProximo().setAntes(tail);
        tail.setProximo(head.getProximo());
        head=head.getProximo();
        size--;
    }

    public void removePos(int pos){
        if (size==0){System.out.println("lista vazia \n"); return;}

        if(size==1|| pos==size){removeEnd(); return;}

        else if(pos==0){removeHead(); return;}
        else{
            Node <T> node= getPos(pos);

            node.getAntes().setProximo(node.getProximo());
            node.getProximo().setAntes(node.getAntes());
            node.setProximo(null);
            node.setAntes(null);
            size--;
        }

    }
    public void show(){
        int count=0;
        Node <T> atual = head;
        do{
            System.out.println("nó "+ count + ": "+ atual.getData()+"\n");
            atual=atual.getProximo();
            count++;

        }while(count!=size);

    }
    public void showTraz(){
        int count=0;
        Node <T> atual = tail;
        do{
            System.out.println("nó "+ count + ": "+ atual.getData()+"\n");
            atual=atual.getAntes();
            count++;

        }while(count!=size);

    }

    public int buscarPorId(int id){
        if (isEmpty()){return -1;}
        Node <T> atual=head;
        
        
        for(int i=0;i<size;i++){
            Carro carroAtual = (Carro) atual.getData();
            if (carroAtual.getId()==id){
                System.out.println(carroAtual);
                return i;
            }
            atual=atual.getProximo();
        }
        System.out.println("Id não encontrado");
        return -1;

        
    }
}