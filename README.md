# ScreenBasedSimulator2
The next generation of screen based simulation.

How to Run Hub:

Run main method under com.cmu.sbs

How to run BioGearServer on Mac:

1. Clone and import the project as maven project to Eclipse
2. Select /src/main/resources/lib-osx as Native Library Location
3. Run Main class.


How to run BioGears on Windows:

1. Clone and import the project as maven project to Eclipse.
2. Select /src/main/resources/windows as Native Library Location
3. Append absolute path of /src/main/resources/windows to environment variables using [this](http://stackoverflow.com/questions/7048216/environment-variables-in-eclipse)

***

## Hub HTTP Protocol
Port: 26666

Address  |Method | Service | Function | Success Return Value
---------|-------|---------|----------|---------------------
/biogears/update | POST | Biogears | update patient status |  BiogearsReply1
/unity/status | GET | Unity | retrieve patient status | UnityReply1
/unity/create | GET | Unity | create patient | UnityReply2

### UnityReply1
```
{"heart_rate":72.0,"respiration_rate":16.3636,"systolic_arterial_pressure":106.955,"diastolic_arterialpressure":63.8649,"oxygen_saturation":0.968268}
```

### UnityReply2
```
Create Successful -> "Success"
Create Failure    -> "Failure"
```
