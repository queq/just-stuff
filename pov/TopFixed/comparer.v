module comparer ( String, CompareString, NullString, DataChar, NullDataChar);
//módulo que determina ciertas señales para enviarlas a control -NullString -NullDataChar,
//dependiendo del registro String o de DataChar
input [0:76] String;
input CompareString;
output reg NullString;

input [0:9] DataChar;
output reg  NullDataChar;


always @(posedge CompareString) begin//Señal que proviene de control
	if (String == 0) NullString <= 1;
	else NullString <= 0;
end

always @(DataChar) begin
	if (DataChar == 0) NullDataChar <= 1;
	else NullDataChar <= 0;
end

endmodule
