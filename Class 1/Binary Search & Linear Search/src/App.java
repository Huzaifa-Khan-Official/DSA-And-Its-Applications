import java.util.Scanner;
import java.util.ArrayList;

class Main {
    int binarySearch(int a[], int l, int r, int x) {
        while (l <= r) {
            int m = (l + r) / 2;

            if (a[m] == x) {
                return m;
            } else if (a[m] > x) {
                r = m - 1;
            } else {
                l = m + 1;
            }  
        }
        return -1;
    }

    void findAllOccurrences(int a[], int n, int x) {
        int index = binarySearch(a, 0, n - 1, x);
        if (index == -1) {
            System.out.println("Element not present");
            return;
        }

        ArrayList<Integer> indices = new ArrayList<>();
        
        int left = index;
        while (left >= 0 && a[left] == x) {
            indices.add(left);
            left--;
        }

        int right = index + 1;
        while (right < n && a[right] == x) {
            indices.add(right);
            right++;
        }

        for (int i = 0; i < indices.size(); i++) {
            for (int j = 0; j < indices.size() - 1 - i; j++) {
                if (indices.get(j) > indices.get(j + 1)) {
                    
                    int temp = indices.get(j);
                    indices.set(j, indices.get(j + 1));
                    indices.set(j + 1, temp);
                }
            }
        }
        
        System.out.println("Element found at indices: " + indices);
    }

    public static void main(String args[]) {
        Main ob = new Main();
        Scanner scan = new Scanner(System.in);

        int a[] = { 2, 3, 5, 5, 5, 5, 5, 6, 7, 8, 8, 10 };
        int n = a.length;
        System.out.println("Enter a number to find in the array: ");
        int x = scan.nextInt();
      
        ob.findAllOccurrences(a, n, x);
    }
}
