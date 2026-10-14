import java.rmi.Remote;
import java.rmi.RemoteException;

public interface HRInterface extends Remote {
    String checkAvailability() throws RemoteException;
    String makeReservation(String type, int number, String name) throws RemoteException;
    String getGuests() throws RemoteException;
    String cancelReservation(String type, int number, String name) throws RemoteException;
    void addListener(HRListener listener, String type) throws RemoteException;
    void removeListener(HRListener listener, String type) throws RemoteException;
}
