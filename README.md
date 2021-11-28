[日本語版README](./README-jp.md)
# SSIDLoader  
Arduino library that loads multiple SSIDs and passwords from a MicroSD card.  

## Usage  
Create a CSV file named aps.csv. Write SSIDs and passwords into it.  
```
SSID1,password_of_ssid1
SSID2,password_of_ssid2
SSID3,password_of_ssid3
```
Put aps.csv at the root directory of a MicroSD card.  
To register SSID, call `addAPfromSD()` from your program.  
Next, call `connectToAP()` in order to connect to the access point.  

## Description of the Functions  
### `addAPfromSD` 
It loads a CSV file specified by the `fileName` argument and registers SSIDs and passwords of the CSV file.  
You can omit `fileName`, then the file aps.csv will be loaded, which is located in the root directory of the MicroSD card.  
#### Syntax  
`void addAPfromSD()`  
`void addAPfromSD(const char* fileName="/aps.csv")`  

### `connectToAP()`  
It connects to the access point registered with `addAPfromSD`.  
If `numberOfTrials` is specified, the connection is abandoned if no connection to the access point can be established after the specified number of attempts.  
#### Syntax  
`bool connectToAP()`  
`bool connectToAP(const uint8_t numberOfTrials)`  
