# Web server

<!-- link : https://medium.com/from-the-scratch/http-server-what-do-you-need-to-know-to-build-a-simple-http-server-from-scratch-d1ef8945e4fa -->

## OSI (open system interconnection model)

## OSI model

### The OSI model is a conceptual framework used to understand and implement network protocols in seven layers

### Each layer serves a specific function and communicates with the layers directly above and below it

### The seven layers of the OSI model are:

1. Physical Layer: Deals with the physical connection between devices, including cables, switches, and other hardware.
2. Data Link Layer: Responsible for node-to-node data transfer and error detection/correction.
3. Network Layer: Manages routing and forwarding of data packets across networks.
4. Transport Layer: Ensures reliable data transfer between end systems, providing error recovery and flow control.
5. Session Layer: Manages sessions between applications, establishing, maintaining, and terminating connections.
6. Presentation Layer: Transforms data into a format suitable for the application layer,
including encryption, compression, and translation.
7. Application Layer: Provides network services to end-user applications, such as web browsers and email clients.

### The OSI model helps standardize network communication and provides a framework for understanding how different protocols interact

### we have to understand the fourth layer of the OSI model, which is the Transport Layer

## Transport Layer

### The Transport Layer is responsible for end-to-end communication between devices, ensuring that data is delivered reliably and in the correct order

### It provides services such as error detection, flow control, and segmentation of data into smaller packets

### The Transport Layer can be implemented using two main protocols:

1. Transmission Control Protocol (TCP): A connection-oriented protocol that ensures reliable data transfer by establishing a connection before transmitting data, providing error recovery, and maintaining the order of packets.
2. User Datagram Protocol (UDP): A connectionless protocol that allows for faster data transfer without the overhead of establishing a connection or ensuring reliability, making it suitable for applications like video streaming and online gaming.

### The choice between TCP and UDP depends on the specific requirements of the application, such as the need for reliability, speed, and order of data delivery

### In summary, the Transport Layer plays a crucial role in ensuring that data is transmitted accurately and efficiently between devices, making it a fundamental part of network communication

## Web Server

### A web server is a software application or hardware device that serves web content to clients over the internet
