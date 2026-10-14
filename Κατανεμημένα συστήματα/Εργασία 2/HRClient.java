import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.Scanner;

public class HRClient extends UnicastRemoteObject implements HRListener { 
    private String clientName;

    protected HRClient(String clientName) throws RemoteException {
        super();
        this.clientName = clientName;
    }

    @Override
    public void notifyUpdate(String message) throws RemoteException {
        System.out.println("Notification:\n" + message);
    }

    @Override
    public String getClientName() throws RemoteException {
        return clientName;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            if (args.length == 0) {
                printUsage();
                return;
            }

            Registry registry = LocateRegistry.getRegistry("localhost");
            HRInterface stub = (HRInterface) registry.lookup("HotelReservation");

            if (args.length == 1 && args[0].equals("list")) {
                String availability = stub.checkAvailability();
                System.out.println(availability); 
                return;
            }

            if (args.length == 4 && args[0].equals("book")) {
                HRClient client = new HRClient(args[3]);
                stub.addListener(client, args[1]);
                String response = stub.makeReservation(args[1], Integer.parseInt(args[2]), args[3]);
                System.out.println(response);

                if (response.contains("Ανεπαρκής διαθεσιμότητα")) {
                    System.out.println("Θέλετε να εγγραφείτε στη λίστα ειδοποιήσεων για αυτόν τον τύπο δωματίου; (yes/no)");
                    String answer = scanner.nextLine();
                    if (answer.equalsIgnoreCase("yes")) {
                        stub.addListener(client, args[1]);
                        System.out.println("Έχετε εγγραφεί στη λίστα ειδοποιήσεων.");
                    } else {
                        stub.removeListener(client, args[1]);
                    }
                }
                return;
            }

            if (args.length == 1 && args[0].equals("guests")) {
                String guests = stub.getGuests();
                System.out.println(guests);
                return;
            }

            if (args.length == 4 && args[0].equals("cancel")) {
                String response = stub.cancelReservation(args[1], Integer.parseInt(args[2]), args[3]);
                System.out.println(response);
                return;
            }
        } catch (Exception e) {
            System.err.println("HRClient exception: " + e.toString());
            e.printStackTrace();
        }
    }

    private static void printUsage() {
        System.out.println("Usage:");
        System.out.println("java HRClient list");
        System.out.println("java HRClient book <type> <number> <name>");
        System.out.println("java HRClient cancel <type> <number> <name>");
        System.out.println("java HRClient guests");
    }
}