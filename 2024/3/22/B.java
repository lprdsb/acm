public class B {
    static int x = 1;

    public static void main(String[] args) {
        C tem = new C();
        tem.fun();
        System.out.printf("%d", tem.x);
    }
}

class C {
    class D {
        int y = 3;
    }

    int x = 2;
    D y = new D();

    public C() {
    }

    public void fun() {
        System.out.printf("%d %d", x, y.y);
    }
}