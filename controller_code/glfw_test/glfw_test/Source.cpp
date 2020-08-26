
//#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;
#include <string.h>
#include <string>

#include <cstdlib>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int motor_0_pwm = 0;
int motor_1_pwm = 0;
int motor_2_pwm = 0;
int motor_3_pwm = 0;
int motor_4_pwm = 0;
int motor_5_pwm = 0;
//The s before motor just means the string conversion of the motor pwm value
string smotor_0_pwm;
string smotor_1_pwm;
string smotor_2_pwm;
string smotor_3_pwm;
string smotor_4_pwm;
string smotor_5_pwm;

string drive_command;

     string turnRight(float axisValue) {
         //Note to make efficient remove declaration of motors 1-3 as seperate and motors 3-5 as seperate, as they are the same.
        int mapped_value = int(axisValue * 128);
        motor_0_pwm = 127 + mapped_value;
        smotor_0_pwm = to_string(motor_0_pwm);
        smotor_1_pwm = to_string(motor_0_pwm); //Since the pwm values of motors 0-2 are the same we can reuse one variable for all their pwm values
        smotor_2_pwm = to_string(motor_0_pwm);
        motor_3_pwm = 128 - mapped_value;
        if (motor_3_pwm < 100 && motor_3_pwm >= 10) {
            smotor_3_pwm = "0" + to_string(motor_3_pwm);
            smotor_4_pwm = "0" + to_string(motor_3_pwm);
            smotor_5_pwm = "0" + to_string(motor_3_pwm);
        }
        else if (motor_3_pwm < 10 && motor_3_pwm >= 0) {
            smotor_3_pwm = "00" + to_string(motor_3_pwm);
            smotor_4_pwm = "00" + to_string(motor_3_pwm);
            smotor_5_pwm = "00" + to_string(motor_3_pwm);
        }
        else {
            smotor_3_pwm = motor_3_pwm;
            smotor_4_pwm = motor_3_pwm;
            smotor_5_pwm = motor_3_pwm;
        }

        drive_command = "d" + smotor_0_pwm + smotor_1_pwm + smotor_2_pwm + smotor_3_pwm + smotor_4_pwm + smotor_5_pwm;
        return drive_command;
    }
     string turnLeft(float axisValue) {
         int mappedValue = int(abs(axisValue) * 128);

         motor_3_pwm = 127 + mappedValue;
         smotor_3_pwm = to_string(motor_3_pwm);
         smotor_4_pwm = to_string(motor_3_pwm);
         smotor_5_pwm = to_string(motor_3_pwm);

         motor_0_pwm = 128 - mappedValue;
         if (motor_0_pwm < 100 && motor_0_pwm >= 10) {
             smotor_0_pwm = "0" + to_string(motor_0_pwm);
             smotor_1_pwm = "0" + to_string(motor_0_pwm);
             smotor_2_pwm = "0" + to_string(motor_0_pwm);
         }
         else if (motor_0_pwm < 10 && motor_0_pwm >= 0) {
             smotor_0_pwm = "00" + to_string(motor_0_pwm);
             smotor_1_pwm = "00" + to_string(motor_0_pwm);
             smotor_2_pwm = "00" + to_string(motor_0_pwm);
         }
         else {
             smotor_0_pwm = to_string(motor_0_pwm);
             smotor_1_pwm = to_string(motor_0_pwm);
             smotor_2_pwm = to_string(motor_0_pwm);
         }

         drive_command = "d" + smotor_0_pwm + smotor_1_pwm + smotor_2_pwm + smotor_3_pwm + smotor_4_pwm + smotor_5_pwm;
         //cout << "\n\n\n" << drive_command ;
         return drive_command;
    }
     string goForward(float axisValue) {
         int mappedValue = int(abs(axisValue * 128));
         motor_0_pwm = 127 + mappedValue;
         if (motor_0_pwm <= 100 && motor_0_pwm >= 10) {
             smotor_0_pwm = "0" + to_string(motor_0_pwm);
             smotor_1_pwm = "0" + to_string(motor_0_pwm);
             smotor_2_pwm = "0" + to_string(motor_0_pwm);
             smotor_3_pwm = "0" + to_string(motor_0_pwm);
             smotor_4_pwm = "0" + to_string(motor_0_pwm);
             smotor_5_pwm = "0" + to_string(motor_0_pwm);
         }
         else if (motor_0_pwm < 10 && motor_0_pwm >= 0) {
             smotor_0_pwm = "00" + to_string(motor_0_pwm);
             smotor_1_pwm = "00" + to_string(motor_0_pwm);
             smotor_2_pwm = "00" + to_string(motor_0_pwm);
             smotor_3_pwm = "00" + to_string(motor_0_pwm);
             smotor_4_pwm = "00" + to_string(motor_0_pwm);
             smotor_5_pwm = "00" + to_string(motor_0_pwm);
         }
         else {
             smotor_0_pwm = to_string(motor_0_pwm);
             smotor_1_pwm = to_string(motor_0_pwm);
             smotor_2_pwm = to_string(motor_0_pwm);
             smotor_3_pwm = to_string(motor_0_pwm);
             smotor_4_pwm = to_string(motor_0_pwm);
             smotor_5_pwm = to_string(motor_0_pwm);
         }
         drive_command = "d" + smotor_0_pwm + smotor_1_pwm + smotor_2_pwm + smotor_3_pwm + smotor_4_pwm + smotor_5_pwm;
         return drive_command;
     }
     string goBackwards(float axisValue) {
         int mappedValue = int(axisValue * 128);
         motor_0_pwm = 128 - mappedValue;
         if (motor_0_pwm <= 100 && motor_0_pwm >= 10) {
             smotor_0_pwm = "0" + to_string(motor_0_pwm);
             smotor_1_pwm = "0" + to_string(motor_0_pwm);
             smotor_2_pwm = "0" + to_string(motor_0_pwm);
             smotor_3_pwm = "0" + to_string(motor_0_pwm);
             smotor_4_pwm = "0" + to_string(motor_0_pwm);
             smotor_5_pwm = "0" + to_string(motor_0_pwm);
         }
         else if (motor_0_pwm < 10 && motor_0_pwm >= 0) {
             smotor_0_pwm = "00" + to_string(motor_0_pwm);
             smotor_1_pwm = "00" + to_string(motor_0_pwm);
             smotor_2_pwm = "00" + to_string(motor_0_pwm);
             smotor_3_pwm = "00" + to_string(motor_0_pwm);
             smotor_4_pwm = "00" + to_string(motor_0_pwm);
             smotor_5_pwm = "00" + to_string(motor_0_pwm);
         }
         else {
             smotor_0_pwm = to_string(motor_0_pwm);
             smotor_1_pwm = to_string(motor_0_pwm);
             smotor_2_pwm = to_string(motor_0_pwm);
             smotor_3_pwm = to_string(motor_0_pwm);
             smotor_4_pwm = to_string(motor_0_pwm);
             smotor_5_pwm = to_string(motor_0_pwm);
         }
         drive_command = "d" + smotor_0_pwm + smotor_1_pwm + smotor_2_pwm + smotor_3_pwm + smotor_4_pwm + smotor_5_pwm;
         return drive_command;
     }
     string stop(void) {
         drive_command = "d128128128128128128";
         return drive_command;
     }
    

    int main(void)
    {
        //drive_command = "Hello the number is " + to_string(motor_1_pwm);
        //cout << drive_command;

        GLFWwindow* window;

        // Initialize the library
        if (!glfwInit())
        {
            return -1;
        }

        // Create a windowed mode window and its OpenGL context
        window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL);

        int screenWidth, screenHeight;
        glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

        if (!window)
        {
            glfwTerminate();
            return -1;
        }

        // Make the window's context current
        glfwMakeContextCurrent(window);

       


        // Loop until the user closes the window
        while (!glfwWindowShouldClose(window))
        {
            int present = glfwJoystickPresent(GLFW_JOYSTICK_1);
            //std::cout << "Joystick is connected" << present << std::endl;


            if (1 == present)
            {
                int axesCount;
                const float* axes = glfwGetJoystickAxes(GLFW_JOYSTICK_1, &axesCount);
                //std::cout << "\nNumber of Axises Available " << axesCount << std::endl;

                //Axis 0 is the X axis on left analog Left is -1, Right is 1
                //Axis 1 is the Y axis on left analog Down is 1, Up is -1
                //Axis 2 is the X axis on right analog Left is -1, Right is 1
                //Axis 3 is the Y axis on right analog *doesn't work properly
                //Axis 4 is the R2 -1 is unpressed, 1 is pressed
                //Axis 5 is the L2 -1 is unpressed, 1 is pressed
                
                //Turning Right
                if (axes[0] > 0.25) { //We can change this 0.25 value based on where we want to start the axis movement
                    //cout << "\n\n\nturn right";
                    drive_command = turnRight(axes[0]);
                    cout << "\n\n\n" << drive_command;
                }
                //Turning Left
                else if(axes[0] < -0.25) {
                    drive_command = turnLeft(axes[0]);
                    cout << "\n\n\n" << drive_command;
                }
                //Going Forward
                else if(axes[1] < -0.25) {
                    drive_command = goForward(axes[1]);
                    cout << "\n\n\n" << drive_command;
                }
                //Going Backwards
                else if (axes[1] > 0.25) {
                    drive_command = goBackwards(axes[1]);
                    cout << "\n\n\n" << drive_command;
                }
                else{
                    stop();
                    cout << "\n\n\n" << drive_command;
                }






                // Swap front and back buffers
                glfwSwapBuffers(window);

                // Poll for and process events
                glfwPollEvents();

            }



        }
        glfwTerminate();

        return 0;
    }



