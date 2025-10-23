import java.lang.reflect.Array;

class tmp {
    public static <T> void printArray(T t) {
        if (t.getClass().isArray()) {
            int length = Array.getLength(t);
            for (int i = 0; i < length; i++) {
                Object element = Array.get(t, i);
                if (i > 0) {
                    System.out.print(", ");
                }
                // 如果元素也是数组，递归调用 printArray
                if (element != null && element.getClass().isArray()) {
                    printArray(element);
                } else {
                    System.out.print(element);
                }
            }
        }
    }

    public static void main(String[] args) {
        Integer[][] integerArray = { { 1, 2 }, { 1, 2 } };
        Double[] doubleArray = { 1.1, 2.2, 3.3, 4.4, 5.5 };
        String[] stringArray = { "Hello", "World" };
        // Array.mian(doubleArray);
        // Array.mian(stringArray);
        printArray(integerArray);
    }
}