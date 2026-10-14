import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.*;

public class HRImpl extends UnicastRemoteObject implements HRInterface {
    private Map<String, Integer> rooms;
    private Map<String, Integer> roomPrices;
    private Map<String, List<String>> reservations;
    private Map<String, List<HRListener>> notificationLists;

    protected HRImpl() throws RemoteException {
        super();
        rooms = new HashMap<>();
        roomPrices = new HashMap<>();
        reservations = new HashMap<>();
        notificationLists = new HashMap<>();
        initializeRooms();
    }

    private void initializeRooms() {
        rooms.put("A", 40);
        roomPrices.put("A", 75);
        rooms.put("B", 35);
        roomPrices.put("B", 110);
        rooms.put("C", 25);
        roomPrices.put("C", 120);
        rooms.put("D", 30);
        roomPrices.put("D", 150);
        rooms.put("E", 20);
        roomPrices.put("E", 200);
    }

    @Override
    public synchronized String checkAvailability() throws RemoteException {
        StringBuilder availability = new StringBuilder();
        for (Map.Entry<String, Integer> entry : rooms.entrySet()) {
            availability.append(entry.getValue()).append(" δωμάτια τύπου ")
                        .append(entry.getKey()).append(" - τιμή: ")
                        .append(roomPrices.get(entry.getKey())).append(" Ευρώ τη βραδιά\n");
        }
        return availability.toString();
    }

    @Override
    public synchronized String makeReservation(String type, int number, String name) throws RemoteException {
        if (!rooms.containsKey(type) || rooms.get(type) < number) {
            return "Ανεπαρκής διαθεσιμότητα δωματίων.";
        }

        rooms.put(type, rooms.get(type) - number);
        reservations.computeIfAbsent(name, k -> new ArrayList<>()).add(number + "x " + type);

        notifyListeners(type, "New reservation: " + number + " room(s) of type " + type + " by " + name);

        int totalPrice = number * roomPrices.get(type);
        return "Κράτηση επιτυχής. Συνολικό κόστος: " + totalPrice + " Ευρώ.";
    }

    @Override
    public synchronized String getGuests() throws RemoteException {
        StringBuilder guestList = new StringBuilder();
        for (Map.Entry<String, List<String>> entry : reservations.entrySet()) {
            guestList.append(entry.getKey()).append(": ").append(entry.getValue()).append("\n");
        }
        return guestList.toString();
    }

    @Override
    public synchronized String cancelReservation(String type, int number, String name) throws RemoteException {
        List<String> userReservations = reservations.get(name);
        if (userReservations == null) {
            return "No reservation found for " + name;
        }

        boolean found = false;
        Iterator<String> iterator = userReservations.iterator();
        while (iterator.hasNext()) {
            String reservation = iterator.next();
            if (reservation.equals(number + "x " + type)) {
                iterator.remove();
                found = true;
                break;
            }
        }

        if (!found) {
            return "No reservation found for " + name + " with " + number + " rooms of type " + type;
        }

        rooms.put(type, rooms.get(type) + number);
        notifyListeners(type, "Cancellation: " + number + " room(s) of type " + type + " by " + name);

        return "Cancellation successful. Remaining reservations: " + userReservations;
    }

    @Override
    public synchronized void addListener(HRListener listener, String type) throws RemoteException {
        notificationLists.computeIfAbsent(type, k -> new ArrayList<>()).add(listener);
    }

    @Override
    public synchronized void removeListener(HRListener listener, String type) throws RemoteException {
        List<HRListener> listeners = notificationLists.get(type);
        if (listeners != null) {
            listeners.remove(listener);
        }
    }

    private void notifyListeners(String type, String message) throws RemoteException {
        List<HRListener> listeners = notificationLists.get(type);
        if (listeners != null) {
            for (HRListener listener : listeners) {
                listener.notifyUpdate(message);
            }
        }
    }
}