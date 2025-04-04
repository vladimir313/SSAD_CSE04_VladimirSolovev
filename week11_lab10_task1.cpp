#include <iostream>
using namespace std;

class Light {
public:
    void on() { cout << "Lights on\n"; }
    void off() { cout << "Lights off\n"; }
};

class Thermostat {
public:
    void setTemperature(int temp) { 
        cout << "Thermostat set to " << temp << "°C\n"; 
    }
};

class SecurityCamera {
public:
    void activate() { cout << "Security cameras activated\n"; }
    void deactivate() { cout << "Security cameras deactivated\n"; }
};

class SmartHomeFacade {
    Light light;
    Thermostat thermostat;
    SecurityCamera camera;
public:
    void leavingHome() {
        light.off();
        thermostat.setTemperature(18);
        camera.activate();
    }
    void arrivingHome() {
        light.on();
        thermostat.setTemperature(22);
        camera.deactivate();
    }
};

int main() {
    SmartHomeFacade home;
    home.leavingHome();
    home.arrivingHome();
    return 0;
}
