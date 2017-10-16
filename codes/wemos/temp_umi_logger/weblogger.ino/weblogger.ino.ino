     #include <ESP8266WiFi.h>
     
    const char* ssid = "wezner";
    const char* password = "8005irt2004";
    
    int dht11pin = 8;
    int ledPin = 9;

    WiFiServer server(80);
    
    void setup() 
    {
      Serial.begin(115200);
      delay(10);
      pinMode(ledPin, OUTPUT);
      digitalWrite(ledPin, LOW);
        // Connect to WiFi network
      Serial.println();
      Serial.println();
      Serial.print("Connecting to ");
      Serial.println(ssid);
      WiFi.begin(ssid, password);
      while (WiFi.status() != WL_CONNECTED) 
      {
        delay(500);
        Serial.print(".");
      }
      
      Serial.println("");
      Serial.println("WiFi connected");  
      connectWifi();
      openServer();
    }

    
    void loop() {
    // Check if a client has connected
    WiFiClient client = server.available();
    
    if (!client) 
    {
      return;
    }
    // Wait until the client sends some data
    Serial.println("new client");
    
    while (!client.available()) 
    {
      delay(1);
    }
    
    // Read the first line of the request
    String request = client.readStringUntil('\r');
    Serial.println(request);
    client.flush();
    // Match the request
    int value = LOW;
    int value2 = LOW;
    
    if (request.indexOf("/LED=ON") != -1) {
    digitalWrite(ledPin, HIGH);
    value = HIGH;
    }
    
    if (request.indexOf("/LED=OFF") != -1) {
    digitalWrite(ledPin, LOW);
    value = LOW;
    }

    printpage(client);
    
    Serial.println("Client disonnected");
    Serial.println("");
    }

    void connectWifi()
    {
      // Connect to WiFi network
      Serial.println();
      Serial.println();
      Serial.print("Connecting to ");
      Serial.println(ssid);
      WiFi.begin(ssid, password);
      while (WiFi.status() != WL_CONNECTED) 
      {
        delay(500);
        Serial.print(".");
      }
      
      Serial.println("");
      Serial.println("WiFi connected");  
    }

    void openServer()
    {
      // Start the server
      server.begin();
      Serial.println("Server started");
    
      // Print the IP address
      Serial.print("Use this URL to connect: ");
      Serial.print("http://");
      Serial.print(WiFi.localIP());
      Serial.println("/");
    
    }

    void printpage(WiFiClient client)
    {
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println(""); // do not forget this one
      client.println("<!DOCTYPE HTML>");
      client.println("<html>");
      client.println("<meta charset ='utf-8'/>");
      client.println("<meta name = 'viewport' content = 'width=device-width, initial-scale=1'>");
      client.println(F("<link href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.1/css/bootstrap.min.css' rel='stylesheet'></link>"));
      client.println("<div class='jumbotron'>");
      client.println("<h1 class='text-center'>Temperatura e umidade logger</h1>");
      client.println("<h2 class='text-center'>ESP8266</h2>");
      client.println("</div>");
      client.println("<div class='col-md-6'>");
      client.println("<div class='alert alert-info text-center' role='alert'>Temperatura:</div>");
      client.println("<a class='btn btn-danger btn-lg center-block' href=\"/LED=OFF\"> Desligar </a>");
      client.println("<br>");
      client.println("<div class='alert alert-info text-center' role='alert'>Umidade:</div>");
      client.println("<a class='btn btn-success btn-lg center-block' href=\"/LED=ON\"> Ligar </a>");
      client.println("</div>");
      client.println("</html>");
      delay(1);
    }
 

