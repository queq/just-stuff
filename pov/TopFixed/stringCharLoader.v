module stringCharLoader (StringPOV, LoadString, LoadNextChar, clk, Reset, String, Char);
//módulo que copia el registro de entrada de 77 bits, además de generar los corrimientos sobre ésta
//para crear el registro Char de 7 bits
input [0:76] StringPOV;//registro de 77 bits que entra al módulo
input LoadString;//señal de control
input LoadNextChar;//señal de control
input Reset;//señal externa para reiniciar el módulo
input clk;
output reg [0:76] String;
output reg [0:6] Char;

always @(posedge clk)begin

	if(Reset)begin
		String <=0;//reinicia el registro
		Char <= 0;//reinicia el registro
	end
	else begin
	
		if (LoadString==1'b1)begin//cuando la señal de control esté en alto
				String<=StringPOV;//se genera la copia de la entrada
		end
		if (LoadNextChar==1'b1)begin//cuando la señal de control esté en alto
				Char<=String[0:6];  //copia el primer grupo de 7 bits de la cadena String
				String <= {String[7:76],7'b0000000};//hace un corrimiento de la cadena
		end
	end
end
		
endmodule
