public class Pilha {
    private int arr[];
    private int tam;

    public void pilha(int capacidade){
        int[] arr= new int[capacidade];
        this.tam=0;
    }
    public boolean isEmpty(){
        if(tam==0){return true;}
        return false;
    }

    public void push(int data){
        arr[tam]=data;
        tam++;
    }

    public int top(){
        return arr[tam];
    }

    public int pop(){
        int aux=arr[tam];
        tam--;
        return aux;
    }

    public void show(){
        int[] aux = new int[tam];
        int count=0;
        int a,tAux=tam;
        for(int i=0;i<=tam-1;i++){
            aux[count]=arr[tAux];
            count++;
            tAux--;
        }
        System.out.println("posição dos elementos\n");
        for(int i=0; i<=tam-1;i++){
            a=aux[count];
            count--;
            System.out.println((count+1)+ "º " +a);
            arr[i]=a;
            
        }
    }
    
}
