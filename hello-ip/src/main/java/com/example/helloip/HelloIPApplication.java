package com.example.helloip;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import java.net.DatagramSocket;
import java.net.InetAddress;

@RestController
@SpringBootApplication
public class HelloIPApplication {

	public static void main(String[] args) {
		SpringApplication.run(HelloIPApplication.class, args);
	}

	@GetMapping("/")
	public String hello() {
		String ip = getLocalIP();
		return "Hello from " + ip;
	}

	public static String getLocalIP() {
        try {
			final DatagramSocket socket = new DatagramSocket();
			socket.connect(InetAddress.getByName("8.8.8.8"), 10002);
			return socket.getLocalAddress().getHostAddress();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
	}

}
