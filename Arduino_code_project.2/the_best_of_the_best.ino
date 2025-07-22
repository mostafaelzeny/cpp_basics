#include <Servo.h>

Servo baseServo;
Servo shoulderServo;
Servo elbowServo;
Servo wristServo;
Servo gripperServo;

#define BASE_PIN 5
#define SHOULDER_PIN 6
#define ELBOW_PIN 9
#define WRIST_PIN 10
#define GRIPPER_PIN 11

float angles[4] = {90, 90, 90, 90}; // default angles for 4 DOF
int gripper_diameter = 0;
int ripeness = -1;
String inputString = "";
bool newData = false;
bool isExecuting = false;  // Flag to prevent command overlap

// Function to read current servo position before proper attachment
int readServoPosition(int pin) {
  // Temporarily attach servo to read its position
  Servo tempServo;
  tempServo.attach(pin);
  delay(50); // Small delay for servo to respond
  int currentPos = tempServo.read();
  tempServo.detach(); // Detach to avoid interference
  return currentPos;
}

// Smooth movement function with customizable step delay
void smoothMove(Servo &servo, int targetAngle, int stepDelay = 20) {
  int currentAngle = servo.read();
  int adjustedTarget = targetAngle + 90;  // Adjust for servo range
  
  // Constrain to valid servo range
  adjustedTarget = constrain(adjustedTarget, 0, 180);
  
  int step = (adjustedTarget > currentAngle) ? 1 : -1;
  
  for (int angle = currentAngle; angle != adjustedTarget; angle += step) {
    servo.write(angle);
    delay(stepDelay);
  }
  servo.write(adjustedTarget);  // Ensure exact target
}

void setup() {
  Serial.begin(9600);
  
  // Clear serial buffer
  while (Serial.available()) {
    Serial.read();
  }
  
  Serial.println("Reading current servo positions...");
  
  // Read current physical positions before proper attachment
  int currentBasePos = readServoPosition(BASE_PIN);
  int currentShoulderPos = readServoPosition(SHOULDER_PIN);
  int currentElbowPos = readServoPosition(ELBOW_PIN);
  int currentWristPos = readServoPosition(WRIST_PIN);
  int currentGripperPos = readServoPosition(GRIPPER_PIN);
  
  // Debug: Print current positions
  Serial.print("Current positions - Base: ");
  Serial.print(currentBasePos);
  Serial.print(", Shoulder: ");
  Serial.print(currentShoulderPos);
  Serial.print(", Elbow: ");
  Serial.print(currentElbowPos);
  Serial.print(", Wrist: ");
  Serial.print(currentWristPos);
  Serial.print(", Gripper: ");
  Serial.println(currentGripperPos);
  
  // Now attach servos and set them to their current positions
  baseServo.attach(BASE_PIN);
  baseServo.write(currentBasePos);
  
  shoulderServo.attach(SHOULDER_PIN);
  shoulderServo.write(currentShoulderPos);
  
  elbowServo.attach(ELBOW_PIN);
  elbowServo.write(currentElbowPos);
  
  wristServo.attach(WRIST_PIN);
  wristServo.write(currentWristPos);
  
  gripperServo.attach(GRIPPER_PIN);
  gripperServo.write(currentGripperPos);
  
  // Small delay to ensure servos are stable at current positions
  delay(500);
  
  Serial.println("Moving to default positions smoothly...");
  
  // Now smoothly move to desired positions with slower movement
  smoothMove(baseServo, angles[0], 40);    // Slow movement (40ms delay)
  smoothMove(shoulderServo, angles[1], 40);
  smoothMove(elbowServo, angles[2], 40);
  smoothMove(wristServo, angles[3], 40);
  
  // Set gripper to stop position
  gripperServo.write(90);
  
  // Wait for all movements to complete
  delay(1000);
  
  // Send ready signal
  Serial.println("READY");
  Serial.flush();
}

void loop() {
  if (!isExecuting) {  // Only process new commands if not busy
    recvWithStartEndMarkers();
    if (newData) {
      newData = false;
      isExecuting = true;
      parseCommand(inputString);
      isExecuting = false;
    }
  }
}

void recvWithStartEndMarkers() {
  static boolean recvInProgress = false;
  char startMarker = '<';
  char endMarker = '>';
  char rc;
  
  // Clear the input string when starting fresh
  if (!recvInProgress) {
    inputString = "";
  }
  
  while (Serial.available() > 0 && newData == false) {
    rc = Serial.read();
    if (recvInProgress == true) {
      if (rc != endMarker) {
        inputString += rc;
      } else {
        recvInProgress = false;
        newData = true;
      }
    } else if (rc == startMarker) {
      inputString = "";  // Clear any previous partial data
      recvInProgress = true;
    }
  }
}

void parseCommand(String cmd) {
  if (cmd.startsWith("ANGLES")) {
    // Parse integers instead of floats to match Python's integer sending
    int tempAngles[4];
    if (sscanf(cmd.c_str(), "ANGLES,%d,%d,%d,%d", &tempAngles[0], &tempAngles[1], &tempAngles[2], &tempAngles[3]) == 4) {
      // Convert to floats for internal use
      for (int i = 0; i < 4; i++) {
        angles[i] = (float)tempAngles[i];
      }
      moveToAngles();
      Serial.println("ACK_ANGLES");
    } else {
      Serial.println("ERROR_ANGLES");
    }
  } 
  else if (cmd.startsWith("GRIPPER")) {
    if (sscanf(cmd.c_str(), "GRIPPER,%d", &gripper_diameter) == 1) {
      gripObject();
      Serial.println("ACK_GRIPPER");
    } else {
      Serial.println("ERROR_GRIPPER");
    }
  } 
  else if (cmd.startsWith("RIPENESS")) {
    if (sscanf(cmd.c_str(), "RIPENESS,%d", &ripeness) == 1) {
      placeObject();
      Serial.println("ACK_RIPENESS");
    } else {
      Serial.println("ERROR_RIPENESS");
    }
  } 
  else if (cmd == "HOME") {
    goHome();
    Serial.println("ACK_HOME");
  } 
  else {
    Serial.println("UNKNOWN_COMMAND");
  }
  
  // Ensure response is sent immediately
  Serial.flush();
}

void moveToAngles() {
  smoothMove(baseServo, angles[0]);
  smoothMove(elbowServo, angles[2]);
  smoothMove(wristServo, angles[3]);
  smoothMove(shoulderServo, angles[1]);
  delay(1000);  // Wait for all movements to complete
}

void leaveObject() {
  if (gripper_diameter > 5 && gripper_diameter < 13) {
    float t = (-0.136 * gripper_diameter) + 2.161;
    int time_ms = t * 1000;
    
    gripperServo.write(45);  // Move backward
    delay(time_ms);
    gripperServo.write(90);  // Stop
  }
  delay(500);  // Settling time
}

void gripObject() {
  if (gripper_diameter > 5 && gripper_diameter < 13) {
    float t = (-0.136 * gripper_diameter) + 2.361;
    int time_ms = t * 1000;
    
    gripperServo.write(145); // Move forward
    delay(time_ms);
    gripperServo.write(90);  // Stop
  }
  delay(500);  // Settling time
}

void placeObject() {
  if (ripeness == 1) {
    // Move to ripe bin position
    smoothMove(shoulderServo, 85);
    smoothMove(baseServo, 0);
    smoothMove(elbowServo, 60);
    smoothMove(wristServo, 80);
    delay(500);  // Settle before releasing
    leaveObject();
  } else if (ripeness == 0) {
    // Move to unripe bin position
    smoothMove(shoulderServo, 80);
    smoothMove(baseServo, -70);
    smoothMove(elbowServo, 60);
    smoothMove(wristServo, 85);
    delay(500);  // Settle before releasing
    leaveObject();
  }
  
  delay(1000);  // Wait after placing
  goHome();     // Return to home after placing
}

void goHome() {
  smoothMove(baseServo, 0);
  smoothMove(shoulderServo, 80);
  smoothMove(elbowServo, 30);
  smoothMove(wristServo, 15);
  gripperServo.write(90); // Stop gripper
  delay(1000);  // Settling time at home
}
