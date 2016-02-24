# ScreenBasedSimulator2
The next generation of screen based simulation.

How to Run Hub:

Run main method under com.cmu.sbs

How to run BioGearServer on Mac:

1. Install homebrew
2. Install boost and google-perftools
3. Compile BioGears Server under biogears folder

```
ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
brew install boost google-perftools
make mac
```

4. cd to `/bin`
5. run `./BioGearsServer`


How to run BioGears on Centos:

0. Install Boost??
1. Compile BioGears Server under biogears folder

```
make linux
```


***

## Hub HTTP Protocol
Port: 26666

Address  |Method | Function | Success Return Value
---------|-------|----------|---------------------
/unity/status/{patientHash} | GET | retrieve patient status | UnityReply1
/unity/create/{patientHash} (not used currently)| POST | create patient | UnityReply
/unity/action/{patientHash}/{actionType} | POST | perform action | UnityReply 

### UnityReply1
```
{"heart_rate":72.0,"respiration_rate":16.3636,"systolic_arterial_pressure":106.955,"diastolic_arterialpressure":63.8649,"oxygen_saturation":0.968268}
```

### UnityReply
```
Create Successful -> "Success"
Create Failure    -> "Failure"
```
