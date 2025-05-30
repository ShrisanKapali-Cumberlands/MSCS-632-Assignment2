// Creating a DataObject class to demonstrate memory management in Java
// This example illustrates how Java's garbage collector works with heap memory
class DataObject {
    private int[] largeArray;
    private String name;

    // Constructor to initialize the DataObject with a name and a large array
    public DataObject(String name, int size) {
        this.name = name;
        this.largeArray = new int[size]; // Allocating a large array on the heap
        System.out.println("DataObject '" + name + "' created with array of size " + size);
    }

    // This method will be called by the garbage collector before an object is
    // removed
    @Override
    protected void finalize() throws Throwable {
        System.out.println("DataObject '" + name + "' is being garbage collected.");
    }
}

public class JavaMemoryManagement {

    public static void main(String[] args) {
        System.out.println("--- Java Memory Management ---");

        // Create a scope to let objects become eligible for GC
        {
            System.out.println("Creating 10 DataObjects...");
            for (int i = 0; i < 10; i++) {
                // Each DataObject and its largeArray are allocated on the heap
                new DataObject("Object_" + i, 10); // Creating objects without holding references
            }
            System.out.println("Finished creating DataObjects in inner scope.");
            // At this point, many DataObject instances become unreachable.
            // The JVM's garbage collector will eventually reclaim their memory.
        } // End of inner scope

        System.out.println("\nSuggesting garbage collection...");
        // Hint to the JVM to run GC, but not guaranteed
        System.gc(); // This is just a suggestion, not a command.

        System.out.println("\nCreating a long-lived object:");
        DataObject longLivedObject = new DataObject("LongLived", 15); // This object will persist

        // Let the program run for a bit to allow GC to occur
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }

        System.out.println("Long-lived object still active.");

        // Nullifying the reference to the long-lived object makes it eligible for GC
        System.out.println("Nullifying long-lived object reference.");
        longLivedObject = null;
        System.gc(); // Another suggestion for GC

        try {
            Thread.sleep(2000); // Give GC time to run
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }

        System.out.println("--- End of Java program ---");
    }
}