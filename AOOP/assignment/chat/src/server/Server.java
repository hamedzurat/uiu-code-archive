package server;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.concurrent.atomic.AtomicInteger;

public class Server {
    public static void main(String[] args) {
        AtomicInteger clientCounter = new AtomicInteger(0);

        try (ServerSocket serverSocket = new ServerSocket(8888)) {
            System.out.println("[SERVER] Started on port 8888");

            while (true) {
                Socket socket = serverSocket.accept();
                String clientName = "Client-" + clientCounter.getAndIncrement();

                ClientHandler user = new ClientHandler(clientName, socket);
                user.start();

                System.out.println("[SERVER] " + clientName + " connected");
            }
        } catch (IOException e) {
            System.err.println("[SERVER] Error: " + e.getMessage());
        }
    }
}
