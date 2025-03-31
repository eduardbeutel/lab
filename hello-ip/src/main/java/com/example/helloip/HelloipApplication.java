package com.example.helloip;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import java.net.DatagramSocket;
import java.net.InetAddress;

@RestController
@SpringBootApplication
public class HelloipApplication {

	public static void main(String[] args) {
		SpringApplication.run(HelloipApplication.class, args);
	}

	@GetMapping("/")
	public String hello() {
		String ip = myLocalIP();
		return "Hello from " + ip;
	}

	public static String myLocalIP() {
        try {
			final DatagramSocket socket = new DatagramSocket();
			socket.connect(InetAddress.getByName("8.8.8.8"), 10002);
			return socket.getLocalAddress().getHostAddress();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
	}

}
