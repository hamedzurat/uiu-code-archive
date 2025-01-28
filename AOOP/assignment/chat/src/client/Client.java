package client;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) {
        try (Socket socket = new Socket("localhost", 8888); //
             DataInputStream in = new DataInputStream(socket.getInputStream()); //
             DataOutputStream out = new DataOutputStream(socket.getOutputStream()) //
        ) {

            new Thread(() -> {
                try {
                    while (true) {
                        int size = in.readInt();
                        byte[] buffer = new byte[size];
                        in.readFully(buffer);

                        System.out.println(new String(buffer));
                    }
                } catch (IOException e) {
                    System.out.println("Disconnected from server");
                }
            }).start();

            Scanner scanner = new Scanner(System.in);
            boolean running = true;
            while (running) {
                String input = scanner.nextLine();
                try {
                    byte[] bytes = input.getBytes(StandardCharsets.UTF_8);

                    if (bytes.length > 4096) {
                        System.err.println("Message too large");
                        continue;
                    }

                    out.writeInt(bytes.length);
                    out.write(bytes);
                } catch (IOException e) {
                    System.err.println("Connection error: " + e.getMessage());
                    running = false;
                }
            }
        } catch (IOException e) {
            System.err.println("Connection error: " + e.getMessage());
        }
    }
}
