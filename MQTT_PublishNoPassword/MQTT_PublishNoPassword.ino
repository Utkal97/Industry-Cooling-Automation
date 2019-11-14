#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define wifi_ssid "pocof1"
#define wifi_password "damian123"
#define MQTTpubQos          2

#define mqtt_server "192.168.43.113"
#define topic "Machine1"
WiFiClient espClient;
PubSubClient client(espClient);
float temperature;
String message(100);
void setup() {
  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  // Serial.println();
  Serial.print("Connecting to ");
  Serial.println(wifi_ssid);

  WiFi.begin(wifi_ssid, wifi_password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    // If you do not want to use a username and password, change next line to
     if (client.connect("ESP8266Client")) {
    //if (client.connect("ESP8266Client", mqtt_user, mqtt_password)) {
      Serial.println("connected");
    } 
    else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

int packet_number = 1;
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  
  client.loop();
  temperature=random(100);
  message=String(temperature)+":"+String(packet_number);
  client.publish(topic, message.c_str() ,1 ,true);
  packet_number+=1;
  Serial.println("Sending " + message);
  delay(2000);  
}
