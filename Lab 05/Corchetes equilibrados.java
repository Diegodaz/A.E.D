import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

//Corchetes equilibrados
public class CorchetesEquilibrados {
	static Stack<Integer> pila = new Stack<>();
	static Queue<Integer> cola = new LinkedList<Integer>();
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String cadenaLlaves = null;//almacena cadena de corchetes
		System.out.println("CORCHETES EQUILIBRADOS: ");
		System.out.println("Ingrese la Cadena  --->  Puede Usar:  ( )  { }  [ ]");
		System.out.println("  ");
		System.out.print(" Cadena :");
		cadenaLlaves = sc.next(); 
		System.out.println(" ");
		System.out.println(isBalanced(cadenaLlaves));
		System.out.println(" ");
	}
	
	public static String isBalanced(String s) {		
		if (s.length()%2==0) {
			llenarColaYPila(s);
			while (pila.empty()==false && cola.isEmpty()==false) {
				if ((pila.peek() + cola.peek()==0)&& pila.peek()>=1) {
				pila.pop();
				cola.poll();
				}else {
					return "NO";
				}
			}
			return "SI";
		}else {
			return "NO";
		}
	}
	
	public static void llenarColaYPila(String cadena) {
		for (int i = 0; i < cadena.length(); i++) {
			if ((i<cadena.length()/2)) {
				pila.push(relacionarLLaves(cadena.charAt(i)));
			}else {
				cola.offer(relacionarLLaves(cadena.charAt(i)));
			}
		}
	}
	public static int relacionarLLaves(char c) {
		int valor=0;
		char [] corchetes = {'{','}','[',']','(',')'};
		int  [] valorNum = {1,-1,2,-2,3,-3};
		for (int i = 0; i < corchetes.length; i++) {
			if (c==corchetes[i]) {
			valor= valorNum[i];
			}
		}
		return valor;
	}
}
