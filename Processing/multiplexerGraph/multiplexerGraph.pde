import processing.serial.*; //import the Serial library
import java.lang.Math.*;
float plotT1, plotBox1Y1, plotBox2Y1, plotBox3Y1;
float plotT2, plotBox1Y2, plotBox2Y2, plotBox3Y2;
float boxHeight;

float[] dataPointTop = {0, 0};
float[] dataPointMiddle = {0, 0};
float[] dataPointBottom = {0, 0};

Serial myPort;
String val;
boolean firstContact = false;
float array[] = { 0, 0, 0 };
boolean newData = false;

void setup(  ) {
  // initalize port
  String portName = "COM4"; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600);
  myPort.bufferUntil('\n');
  noLoop();
  //

  size(1000, 1000);

  // Corners of the plotted time series
  plotT1 = 200;
  plotT2 = width - 100;

  //box 1 dimensions (top)
  plotBox1Y1 = 30;
  plotBox1Y2 = round(height/3) - plotBox1Y1;

  //box 2 dimensions (middle)
  plotBox2Y1 = plotBox1Y2 + plotBox1Y1; 
  plotBox2Y2 = round(2*height/3) - plotBox1Y1;

  //box 3 dimensions (bottom)
  plotBox3Y1 = plotBox2Y2 + plotBox1Y1; 
  plotBox3Y2 = round(3*height/3) - plotBox1Y1;

  boxHeight =   plotBox3Y2 -  plotBox3Y1;

  dataPointTop[0] = int(plotT1);

  refreshBox();

  smooth(  );
}

void draw(  ) {

  strokeWeight(5);
  stroke(#5679C1);

  dataPointTop = mapLineTop(dataPointTop);
  dataPointMiddle[0] = dataPointTop[0];

  dataPointMiddle = mapLineMiddle(dataPointMiddle);
  dataPointBottom[0] = dataPointMiddle[0];

  dataPointBottom = mapLineBottom(dataPointBottom);
  dataPointTop[0] = dataPointBottom[0];

  if (dataPointTop[0] > plotT2) { 
    refreshBox();
    dataPointTop[0] = int(plotT1);
  } else if (dataPointMiddle[0] > plotT2) {
    refreshBox();
    dataPointMiddle[0] = int(plotT1);
  } else if (dataPointBottom[0] > plotT2) {
    refreshBox();
    dataPointBottom[0] = int(plotT1);
  }
  //y = mapLineY(y);
}

void serialEvent(Serial myPort) {
  //put the incoming data into a String - 
  //the '\n' is our end delimiter indicating the end of a complete packet
  val = myPort.readStringUntil('\n');
  String[] data = split(val, ',');
  //make sure our data isn't empty before continuing
  if (val != null) {
    //trim whitespace and formatting characters (like carriage return)
    //look for our 'A' string to start the handshake
    //if it's there, clear the buffer, and send a request for data

    val = trim(val);
    if (firstContact == false) {
      if (val.equals("A")) {
        myPort.clear();
        firstContact = true;
        myPort.write("A");
        println("contact");
      }
    } else { //if we've already established contact, keep getting and parsing data
      //print(data.length); 
      //print("\t"); 
      //println(val);
      if (data.length == 3) {
        array[0] = float(data[0]);
        array[1] = float(data[1]);
        array[2] = float(data[2]);
        redraw();
        newData = true;
      }
      // when you've parsed the data you have, ask for more:
      myPort.write("A");
    }
  }
}

float[] mapLineTop(float[] data) {
  float oldX;
  float oldMouse;
  float xVal = mapX(array[0]);
  if ( xVal > plotBox1Y1 && xVal < plotBox1Y2) {
    oldMouse = data[1];
    data[1] = xVal;
    oldX = data[0];
    line(oldX, oldMouse, data[0]++, data[1]);
  }
  return data;
}

float[] mapLineMiddle(float[] data) {
  float oldX;
  float oldMouse;
  float yVal = mapY(array[1]);
  if ( yVal > plotBox2Y1 && yVal < plotBox2Y2) {
    oldMouse = data[1];
    data[1] = yVal;
    oldX = data[0];
    line(oldX, oldMouse, data[0]++, data[1]);
  }
  return data;
}

float[] mapLineBottom(float[] data) {
  float oldX;
  float oldMouse;
  float zVal = mapZ(array[2]);
  if ( zVal > plotBox3Y1 && zVal < plotBox3Y2) {
    oldMouse = data[1];
    data[1] = zVal;
    oldX = data[0];
    line(oldX, oldMouse, data[0]++, data[1]);
  }
  return data;
}

void refreshBox() {
  //
  background(224);

  // Show the plot area as a white box.
  fill(255);
  rectMode(CORNERS);
  noStroke(  );
  //divide into three sections
  rect(plotT1, plotBox1Y1, plotT2, plotBox1Y2);
  rect(plotT1, plotBox2Y1, plotT2, plotBox2Y2);
  rect(plotT1, plotBox3Y1, plotT2, plotBox3Y2);

  drawTimeLabel(plotBox1Y2);
  drawTimeLabel(plotBox2Y2);
  drawTimeLabel(plotBox3Y2);

  labelBoxTop();
  labelBoxMiddle();
  labelBoxBottom();
}

void drawTimeLabel(float yPos) {
  fill(0);
  textSize(25);
  textAlign(LEFT);
  text("time", plotT2, yPos);
}

void labelBoxTop() { 
  fill(0);
  textSize(25);
  textAlign(CENTER, CENTER);
  text("x-value", plotT1/2, (plotBox1Y1 + plotBox1Y2) / 2);
  labelValues(plotBox1Y1);
}

void labelBoxMiddle() { 
  fill(0);
  textSize(25);
  textAlign(CENTER, CENTER);
  text("y-value", plotT1/2, (plotBox2Y1 + plotBox2Y2) / 2);
  labelValues(plotBox2Y1);
}

void labelBoxBottom() { 
  fill(0);
  textSize(25);
  textAlign(CENTER, CENTER);
  text("z-value", plotT1/2, (plotBox3Y1 + plotBox3Y2) / 2);
  labelValues(plotBox3Y1);
}

void labelValues(float startPoint) {
  int i;
  float yPos;
  int[] data = {10, 8, 6, 4, 2, 0, -2, -4, -6, -8, -10}; //change labels to accurate
  fill(0);
  textSize(15);
  textAlign(RIGHT);
  stroke(224);
  strokeWeight(1);

  for (i = 0; i < data.length; i++) {
    yPos = startPoint + i * boxHeight/data.length;
    line(plotT1, yPos, plotT2, yPos);
    text(data[i], plotT1 - 10, 5 + yPos);
  }
}

float mapX(float val) { 
  float high = 20, low = -20;
  return ( val + high ) * boxHeight / (high - low) + plotBox1Y1 ;
}

float mapY(float val) { 
  float high = 20, low = -20;
  return ( val + high ) * boxHeight / (high - low) + plotBox2Y1 ;
}

float mapZ(float val) { 
  float high = 20, low = -20;
  return ( val + high ) * boxHeight / (high - low) + plotBox3Y1 ;
}