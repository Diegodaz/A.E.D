public class Test{
	public static void main(String[] args){
		AVL<Integer> arbol = new AVL<Integer>();
		arbol.add(11);
		System.out.println(arbol.inOrder());
		arbol.add(12);
		System.out.println(arbol.inOrder());
		arbol.add(14);
		System.out.println(arbol.inOrder());
	}
}

