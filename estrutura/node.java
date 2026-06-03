public class Node<T> {
    
    // 2. O T maiúsculo define o tipo do dado
    T data; 
    
    // 3. O próximo nó também é um "Node<T>" (com T maiúsculo)
    Node<T> proximo; 
    Node<T> antes;

    // 4. No get, o retorno é simplesmente "T"
    public T getData() {
        return data;
    }

    // 5. No set, o argumento recebido é do tipo "T"
    public void setData(T data) {
        this.data = data;
    }

    // 6. O retorno do nó seguinte é um "Node<T>" completo, e não apenas T
    public Node<T> getProximo() {
        return proximo;
    }

    // 7. Para alterar o próximo, você recebe um "Node<T>"
    public void setProximo(Node<T> proximo) {
        this.proximo = proximo;
    }

    public Node<T> getAntes() {
        return antes;
    }

    public void setAntes(Node<T> antes) {
        this.antes = antes;
    }
}