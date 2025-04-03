package com.example.hello;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.server.ResponseStatusException;

import java.net.DatagramSocket;
import java.net.InetAddress;
import java.time.LocalDateTime;
import java.util.UUID;
import java.util.concurrent.atomic.AtomicBoolean;

@RestController
@SpringBootApplication
public class HelloApplication {

	LocalDateTime startTime = LocalDateTime.now();
	String runIdentifier = UUID.randomUUID().toString();
	AtomicBoolean isUp = new AtomicBoolean(true);

	public static void main(String[] args) {
		SpringApplication.run(HelloApplication.class, args);
	}

	@GetMapping("/")
	public String hello() {
		String ip = getLocalIP();
		String hello = "Hello, this service was started at " +startTime.toLocalTime().withNano(0).toString()+ " on " +ip+ ". The run identifier is " +runIdentifier+ ".";
		return hello;
	}

	@GetMapping("/health")
	public ResponseEntity<String> health() {
		if(isUp.get()) {
			return new ResponseEntity<String>("UP", HttpStatus.OK);
		} else {
			return new ResponseEntity<String>("DOWN", HttpStatus.SERVICE_UNAVAILABLE);
		}
	}

	@GetMapping("/down")
	public String down() {
		isUp.set(false);
		return "DOWN";
	}

	@GetMapping("/up")
	public String up() {
		isUp.set(true);
		return "UP";
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
