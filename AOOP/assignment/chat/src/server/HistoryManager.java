package server;

import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.LinkedList;

public class HistoryManager {
    private static final HistoryManager           instance       = new HistoryManager();
    private final        LinkedList<String>       messageHistory = new LinkedList<>();
    private final        ArrayList<ClientHandler> subscribers    = new ArrayList<>();

    private HistoryManager() {}

    public static HistoryManager getInstance() {
        return instance;
    }

    public synchronized void addMessage(String message, ClientHandler sender) {
        messageHistory.add(message);
        byte[] msgBytes = message.getBytes(StandardCharsets.UTF_8);

        subscribers.stream().filter(user -> user != sender).forEach(user -> user.sendMessage(msgBytes));
    }

    public synchronized void subscribe(ClientHandler user) {
        System.out.println("[SERVER] sending " + messageHistory.size() + " messages as history to " + user.getName());
        messageHistory.stream().map(msg -> msg.getBytes(StandardCharsets.UTF_8)).forEach(user::sendMessage);

        subscribers.add(user);
    }

    public synchronized void unsubscribe(ClientHandler user) {
        subscribers.remove(user);
    }
}
