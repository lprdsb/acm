import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;

public class ArrayUtils {

    // 泛型方法：用于打印任意类型的一维或多维数组
    public static <T> void printArray(T array) {
        if (array == null) {
            System.out.println("null");
            return;
        }

        // 检查是否为数组类型
        if (array.getClass().isArray()) {
            int length = Array.getLength(array);
            System.out.print("[");
            for (int i = 0; i < length; i++) {
                Object element = Array.get(array, i);
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
            System.out.print("]");
        } else {
            System.out.println(array);
        }
    }

    // 重载方法：用于打印 ArrayList
    public static <T> void printArray(ArrayList<T> list) {
        if (list == null) {
            System.out.println("null");
        } else {
            System.out.println(list);
        }
    }

    public static void main(String[] args) {
        // 测试一维数组
        Integer[] oneDimArray = { 1, 2, 3, 4, 5 };
        printArray(oneDimArray); // 输出: [1, 2, 3, 4, 5]

        // 测试二维数组
        Integer[][] twoDimArray = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
        printArray(twoDimArray); // 输出: [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

        // 测试三维数组
        Integer[][][] threeDimArray = { { { 1, 2 }, { 3, 4 } }, { { 5, 6 }, { 7, 8 } } };
        printArray(threeDimArray); // 输出: [[[1, 2], [3, 4]], [[5, 6], [7, 8]]]

        // 测试 ArrayList
        ArrayList<Integer> arrayList = new ArrayList<>(Arrays.asList(10, 20, 30));
    }
}
