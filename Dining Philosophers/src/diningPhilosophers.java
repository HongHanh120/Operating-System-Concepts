import java.util.concurrent.Semaphore;

public class diningPhilosophers {
    static int philosophersNumber = 5;
    static Philosopher philosophers[] = new Philosopher[philosophersNumber];
    static Chopstick chopsticks[] = new Chopstick[philosophersNumber];

    static class Chopstick {
        public Semaphore mutex = new Semaphore(1);
        void grab() {
            try {
                mutex.acquire();
            } catch (Exception e){
                e.printStackTrace(System.out);
            }
        }
        void release(){
            mutex.release();
        }
        boolean isFree(){
            return mutex.availablePermits() > 0;
        }
    }

    static class Philosopher extends Thread {
        public int number;
        public Chopstick left_chopstick;
        public Chopstick right_chopstick;

        Philosopher(int number, Chopstick left, Chopstick right){
            this.number = number;
            this.left_chopstick = left;
            this.right_chopstick = right;
        }

        public void run(){
            while (true) {
                if (number % 2 == 1){
                    right_chopstick.grab();
                    System.out.println("Philosopher " + (number + 1) + " grabs right chopstick");
                    left_chopstick.grab();
                    System.out.println("Philosopher " + (number + 1) + " grabs left chopstick");
                    eat();
                }
                else {
                    left_chopstick.grab();
                    System.out.println("Philosopher " + (number + 1) + " grabs left chopstick");
                    right_chopstick.grab();
                    System.out.println("Philosopher " + (number + 1) + " grabs right chopstick");
                    eat();
                }
                left_chopstick.release();
                System.out.println("Philosopher " + (number + 1) + " releases left chopstick");
                right_chopstick.release();
                System.out.println("Philosopher " + (number + 1) + " releases right chopstick");
            }
        }

        void eat(){
            try {
                int sleepTime = 5;
                System.out.println("Philosopher " + (number + 1) + " eats for " + sleepTime + "ms");
                Thread.sleep(sleepTime);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public static void main (String argv[]){
        System.out.println("Dining philosopher");
        for (int i = 0; i < philosophersNumber; i++){
            chopsticks[i] = new Chopstick();
        }
        for (int i = 0; i < philosophersNumber; i++){
            philosophers[i] = new Philosopher(i, chopsticks[i], chopsticks[(i+1) % philosophersNumber]);
            philosophers[i].start();
        }
        while(true) {
            try {
                Thread.sleep(5);
                //check for deadlock
                boolean deadlock = true;
                for( Chopstick f : chopsticks){
                    if (f.isFree()){
                        deadlock = false;
                        break;
                    }
                }
                if(deadlock){
                    Thread.sleep(5);
                    System.out.println("This is a deadlock");
                    break;
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        System.out.println("Exit the program!");
        System.exit(0);
    }
}
