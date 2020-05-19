public class bestfit {
    static void bestFit(int blockSize[], int m, int processSize[], int n) {
        // Stores block id of the block allocated to a
        // process
        int allocation[] = new int[n];
        int block[] = new int[n];

        // Initially no block is assigned to any process
        for (int i = 0; i < allocation.length; i++)
            allocation[i] = -1;

        // pick each process and find suitable blocks
        // according to its size ad assign to it
        for (int i=0; i<n; i++) {
            // Find the best fit block for current process
            int bestIdx = -1;
            for (int j=0; j<m; j++) {
                if (blockSize[j] >= processSize[i]) {
                    if (bestIdx == -1)
                        bestIdx = j;
                    else if (blockSize[bestIdx] > blockSize[j])
                        bestIdx = j;
                }
            }

            // If we could find a block for current process
            if (bestIdx != -1) {
                // allocate block j to p[i] process
                allocation[i] = bestIdx;
                block[i] = blockSize[bestIdx];

                // Reduce available memory in this block.
                blockSize[bestIdx] -= processSize[i];
            }
        }

        System.out.println("\nProcess No.\tProcess Size\tBlock no.\tBlock Size.");
        for (int i = 0; i < n; i++) {
            System.out.print("   " + (i+1) + "\t\t\t" + processSize[i] + "\t\t\t\t");
            if (allocation[i] != -1)
                System.out.print(allocation[i] + 1 + "\t\t\t" + block[i]);
            else
                System.out.print("\t\t" + "Not Allocated");
            System.out.println();
        }
    }

    // Driver Method
    public static void main(String[] args) {
        int blockSize[] = {300, 600, 750, 200, 125};
        int processSize[] = {115, 500, 358, 200, 375};
        int m = blockSize.length;
        int n = processSize.length;

        bestFit(blockSize, m, processSize, n);
    }
}
