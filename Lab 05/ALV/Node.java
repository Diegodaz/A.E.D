public class Node<T extends Comparable<T>>{
	private T data;
	private Node<T> right;
	private Node<T> left;

	public Node(T data){
		this.data = data;
		this.right = null;
		this.left = null;
	}
	public Node(T data, Node<T> right, Node<T> left){
		this.data = data;
		this.right = right;
		this.left = left;
	}

	public Node<T> getRight(){
		return this.right;
	}
	public Node<T> getLeft(){
		return this.left;
	}
	public void setRight(Node<T> nodo){
		this.right = nodo;
	}
	public void setLeft(Node<T> nodo){
		this.left = nodo;
	}
	public T getData(){
		return this.data;
	}
	public void setData(T data){
		this.data = data;
	}

	public String toString(){
		return data.toString();
	}
}

