
public class A {
    public static void main(String args[]) {
        int[] b = new int[100];
        int[] a = b;
        b[10] = 1;
        System.out.println("asd" + a[10]);
    }
}