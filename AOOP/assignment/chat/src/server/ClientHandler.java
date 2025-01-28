package server;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

public class ClientHandler extends Thread {
    private final String name;
    private final Socket socket;

    public ClientHandler(String name, Socket socket) throws IOException {
        this.name = name;
        this.socket = socket;
    }

    @Override
    public void run() {
        try {
            sendMessage(("Connected as: " + name).getBytes(StandardCharsets.UTF_8));
            HistoryManager.getInstance().subscribe(this);

            DataInputStream in = new DataInputStream(socket.getInputStream());
            boolean isConnected = true;

            while (isConnected) {
                try {
                    int size = in.readInt();

                    if (size > 4096) throw new IOException("Message size exceeded");

                    byte[] buffer = new byte[size];
                    in.readFully(buffer);
                    String message = new String(buffer, StandardCharsets.UTF_8);

                    System.out.println("[CLIENT] <" + Thread.currentThread().getName() + "> " + name + " said: " + message);
                    HistoryManager.getInstance().addMessage(name + ": " + message, this);
                } catch (IOException e) {
                    isConnected = false;
                }
            }
        } catch (IOException e) {
            System.out.println("[SERVER] " + name + " disconnected during setup");
        } finally {
            System.out.println("[SERVER] " + name + " disconnected");
            HistoryManager.getInstance().unsubscribe(this);
        }
    }

    public void sendMessage(byte[] message) {
        try {
            DataOutputStream out = new DataOutputStream(socket.getOutputStream());
            out.writeInt(message.length);
            out.write(message);
            out.flush();
        } catch (IOException e) {
            System.err.println("Error sending message to " + name);
        }
    }
}
