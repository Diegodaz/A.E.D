public class AVL<T extends Comparable<T>>{
	private Node<T> root;

	public AVL(){
		root = null;
	}

	public boolean isEmpty(){
		return root == null;
	}
	public void add(T nuevo){
		if(this.isEmpty()){
			this.root = new Node<T>(nuevo);
		} else {
			addNew(root, nuevo);
		}
	}
	private void addNew(Node<T> actual, T nuevo){
		int comp = actual.getData().compareTo(nuevo);
		if(comp < 0){
			Node<T> actualRight = actual.getRight();
			if(actualRight == null){
				actual.setRight(new Node<T>(nuevo));
			} else {
				addNew(actualRight, nuevo);
			}
		} else if (comp > 0){
			Node<T> actualLeft = actual.getLeft();
			if(actualLeft == null){
				actual.setLeft(new Node<T>(nuevo));
			} else {
				addNew(actualLeft, nuevo);
			}
		} else {
			System.out.println("Elemento repetido");
		}
	}

	public String inOrder(){
		return inOrder(root);
	}
	private String inOrder(Node<T> nodo){
		String str = "";
		Node<T> aux = nodo.getLeft();
		if(aux != null){
			str += this.inOrder(aux) + ", ";
		}
		str += nodo.toString();
		aux = nodo.getRight();
		if(aux != null){
			str += ", " + this.inOrder(aux);
		}
		return str;
	}
}

