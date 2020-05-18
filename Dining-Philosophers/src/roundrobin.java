class roundrobin {
    public static void roundRobin(String p[], int a[],
                                  int b[], int n)
    {
        int res = 0;
        int resc = 0;

        String seq = new String();

        int res_b[] = new int[b.length];
        int res_a[] = new int[a.length];

        for (int i = 0; i < res_b.length; i++) {
            res_b[i] = b[i];
            res_a[i] = a[i];
        }

        int t = 0;

        int w[] = new int[p.length];

        int comp[] = new int[p.length];

        while (true) {
            boolean flag = true;
            for (int i = 0; i < p.length; i++) {
                if (res_a[i] <= t) {
                    if (res_a[i] <= n) {
                        if (res_b[i] > 0) {
                            flag = false;
                            if (res_b[i] > n) {
                                t = t + n;
                                res_b[i] = res_b[i] - n;
                                res_a[i] = res_a[i] + n;
                                seq += "->" + p[i];
                            }
                            else {
                                t = t + res_b[i];

                                comp[i] = t - a[i];

                                w[i] = t - b[i] - a[i];
                                res_b[i] = 0;

                                seq += "->" + p[i];
                            }
                        }
                    }
                    else if (res_a[i] > n) {
                        for (int j = 0; j < p.length; j++) {
                            if (res_a[j] < res_a[i]) {
                                if (res_b[j] > 0) {
                                    flag = false;
                                    if (res_b[j] > n) {
                                        t = t + n;
                                        res_b[j] = res_b[j] - n;
                                        res_a[j] = res_a[j] + n;
                                        seq += "->" + p[j];
                                    }
                                    else {
                                        t = t + res_b[j];
                                        comp[j] = t - a[j];
                                        w[j] = t - b[j] - a[j];
                                        res_b[j] = 0;
                                        seq += "->" + p[j];
                                    }
                                }
                            }
                        }

                        if (res_b[i] > 0) {
                            flag = false;

                            if (res_b[i] > n) {
                                t = t + n;
                                res_b[i] = res_b[i] - n;
                                res_a[i] = res_a[i] + n;
                                seq += "->" + p[i];
                            }
                            else {
                                t = t + res_b[i];
                                comp[i] = t - a[i];
                                w[i] = t - b[i] - a[i];
                                res_b[i] = 0;
                                seq += "->" + p[i];
                            }
                        }
                    }
                }
                else if (res_a[i] > t) {
                    t++;
                    i--;
                }
            }
            if (flag) {
                break;
            }
        }
        System.out.println("Tien trinh  Thoi gian hoan thanh  Thoi gian cho");
        for (int i = 0; i < p.length; i++) {
            System.out.println(" " + p[i] + "           " + comp[i]
                    + "                     " + w[i]);

            res = res + w[i];
            resc = resc + comp[i];
        }
        System.out.println("Thoi gian cho trung binh "
                + (float)res / p.length);
        System.out.println("Thoi gian hoan thanh trung binh "
                + (float)resc / p.length);
        System.out.println("Chuoi tien trinh " + seq);
    }

    // Driver Code 
    public static void main(String args[])
    {
        String name[] = { "p1", "p2", "p3", "p4" };

        int arrivaltime[] = { 0, 1, 2, 3 };

        int bursttime[] = { 10, 4, 5, 3 };

        int q = 5;

        roundRobin(name, arrivaltime, bursttime, q);
    }
} 