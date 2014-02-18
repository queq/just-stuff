//Debouncing routine ( detection of a true 1 to 0 transtion in Pport.pin)
//called periodically by the main function

extern char Debounce(char port, char pin, char nticks); // in Debounce module

// Parameters:
// port: Port number 1 or 2
// pin:  Pin number 0 - 7  
// nticks: Bouncing time: integer multiples(1-255) of calling period

// Return Value
// 0: Debouncing in process
// 1: True 1 to 0 transtion detected
// 2: No true transition detected