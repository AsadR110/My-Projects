import processing.serial.*;
Serial mySerial;

Table table;

void setup() {
  mySerial = new Serial(this, "COM4", 9600);
  table = new Table();
  
  table.addColumn("PWM");
  table.addColumn("RPM");
  table.addColumn("Velocity");
  table.addColumn("Acceleration");
  table.addColumn("Torque");
  table.addColumn("Power");
}

void draw()
{
  
  if(mySerial.available() > 0){
    String value = mySerial.readStringUntil('\n');
    //TableRow newRow = table.addRow();
    if (value != null) {
      value = trim(value);
      //println(value);
      float sensorValues[] = float(split(value,','));
      TableRow newRow = table.addRow();
      
      newRow.setFloat("PWM", sensorValues[0]);
      newRow.setFloat("RPM", sensorValues[1]);
      newRow.setFloat("Velocity", sensorValues[2]);
      newRow.setFloat("Acceleration", sensorValues[3]);
      newRow.setFloat("Torque", sensorValues[4]);
      newRow.setFloat("Power", sensorValues[5]);
      
      //float PWM = table.getFloat(1,"RPM");
      //println(PWM);
      
    }
  }
}

void keyPressed()
{
  // this will save the .csv file to the same directory as this file in the data folder
  saveTable(table, "data/dyno.csv");
  exit();
}
